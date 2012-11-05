// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Attributes.cpp: Rcpp R/C++ interface class library -- Rcpp attributes
//
// Copyright (C) 2012 JJ Allaire, Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.


#include <fstream>
#include <cstring>
#include <map>
#include <algorithm>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <Rcpp.h>
#include <Rcpp/exceptions.h>

#include "AttributesParser.h"

using namespace Rcpp::attributes_parser;

namespace {

    // Utility class for getting file existence and last modified time
    class FileInfo {
    public:    
        explicit FileInfo(const std::string& path) 
            : path_(path), exists_(false), lastModified_(0)
        {
    #ifdef _WIN32
            struct _stat buffer;
            int result = _stat(path.c_str(), &buffer);
    #else
            struct stat buffer;
            int result = stat(path.c_str(), &buffer);
    #endif  
            if (result != 0) {
                if (errno == ENOENT)
                    exists_ = false;
                else
                    throw Rcpp::file_io_error(errno, path);
            } else {
                exists_ = true;
                lastModified_ = buffer.st_mtime;
            }
        }
        
        std::string path() const { return path_; }
        bool exists() const { return exists_; }
        time_t lastModified() const { return lastModified_; }
        
    private:
        std::string path_;
        bool exists_;
        time_t lastModified_;
    };
    
    // Generate the preamble for a C++ file (headers)
    std::string generateCppPreamble(const std::vector<std::string>& includes){
        
        std::ostringstream ostr;
        for (std::size_t i=0;i<includes.size(); i++)
            ostr << includes[i] << std::endl;
        
        return ostr.str();
    }
    
    // Check if the passed attribute represents an exported function
    bool isExportedFunction(const Attribute& attribute) {
        return (attribute.name() == kExportAttribute) &&
               !attribute.function().empty();
    }
    
    // Determine the exported name for a function 
    std::string exportedName(const Attribute& attribute) {   
        if (!attribute.params().empty())
            return attribute.params()[0].name();
        else
            return attribute.function().name();
    }
 
    // Generate a module declaration
    std::string generateCppModule(const std::string& moduleName, 
                                  const SourceFileAttributes& attributes,
                                  bool includeTypeInfo,
                                  bool verbose) {
        
        std::ostringstream ostr;
           
        // module header
        ostr << std::endl << "// Module: " << moduleName << std::endl;  
        
        // include namespace imports and function prototypes if requested
        if (includeTypeInfo) {
            
            if (!attributes.namespaces().empty()) {
                for (std::size_t i=0;i<attributes.namespaces().size(); i++)
                    ostr << attributes.namespaces()[i] << std::endl;
            }
        
            if (!attributes.prototypes().empty()) {
                for (std::size_t i=0;i<attributes.prototypes().size(); i++)
                    ostr << attributes.prototypes()[i] << ";" << std::endl;
            }
        }
        
        // output the module
        ostr << "RCPP_MODULE(" << moduleName  << ") {" << std::endl;
        for(std::vector<Attribute>::const_iterator 
                it = attributes.begin(); it != attributes.end(); ++it) {
            
            // verify this is an exported function 
            if (isExportedFunction(*it)) {
                     
                // verbose output
                const Function& function = it->function();
                if (verbose)
                    Rcpp::Rcout << "  " << function << std::endl;
              
                // add module function export
                ostr << "    Rcpp::function(\"" << exportedName(*it) << "\", &"
                     << function.name() << ");" << std::endl;
                      
            } 
        }
        ostr << "}" << std::endl;
        
        return ostr.str();    
    }    
    
    // Class that manages generation of source code for the sourceCpp dynlib
    class SourceCppDynlib {
    public:
        SourceCppDynlib() {}
        
        SourceCppDynlib(const std::string& cppSourcePath, Rcpp::List platform) 
            :  cppSourcePath_(cppSourcePath)
        {
            // get cpp source file info 
            FileInfo cppSourceFilenameInfo(cppSourcePath_);
            if (!cppSourceFilenameInfo.exists())
                throw Rcpp::file_not_found(cppSourcePath_);
                    
            // get last modified time        
            cppSourceLastModified_ = cppSourceFilenameInfo.lastModified();
            
            // record the base name of the source file
            Rcpp::Function basename = Rcpp::Environment::base_env()["basename"];
            cppSourceFilename_ = Rcpp::as<std::string>(basename(cppSourcePath_));
            
            // get platform info
            fileSep_ = Rcpp::as<std::string>(platform["file.sep"]);
            dynlibExt_ = Rcpp::as<std::string>(platform["dynlib.ext"]);
            
            // generate temp directory 
            Rcpp::Function tempfile = Rcpp::Environment::base_env()["tempfile"];
            buildDirectory_ = Rcpp::as<std::string>(tempfile("sourcecpp_"));
            std::replace(buildDirectory_.begin(), buildDirectory_.end(), '\\', '/');
            Rcpp::Function dircreate = Rcpp::Environment::base_env()["dir.create"];
            dircreate(buildDirectory_);
            
            // generate a random module name
            Rcpp::Function sample = Rcpp::Environment::base_env()["sample"];
            std::ostringstream ostr;
            ostr << "sourceCpp_" << Rcpp::as<int>(sample(100000, 1));
            moduleName_ = ostr.str();
            
            // regenerate the source code
            regenerateSource();
        }
        
        bool isEmpty() const { return cppSourcePath_.empty(); }
        
        bool isBuilt() const { return FileInfo(dynlibPath()).exists(); };
                
        bool isSourceDirty() const {          
            // source file out of date means we're dirty
            if (FileInfo(cppSourcePath_).lastModified() > 
                FileInfo(generatedCppSourcePath()).lastModified())
                return true;
                     
            // no dynlib means we're dirty
            if (!FileInfo(dynlibPath()).exists())
                return true;
                
            // not dirty
            return false;
        }
        
        void regenerateSource() {
            
            // copy the source file to the build dir
            Rcpp::Function filecopy = Rcpp::Environment::base_env()["file.copy"];
            filecopy(cppSourcePath_, generatedCppSourcePath(), true);
            
            // parse attributes
            SourceFileAttributes sourceAttributes(cppSourcePath_);
        
            // generate RCPP module
            generatedCpp_ = generateCppModule(moduleName(), 
                                              sourceAttributes, 
                                              false,    // no typeinfo 
                                              false);   // not verbose
            
            // open source file and append module
            std::ofstream cppOfs(generatedCppSourcePath().c_str(), 
                                 std::ofstream::out | std::ofstream::app);
            if (cppOfs.fail())
                throw Rcpp::file_io_error(generatedCppSourcePath());
            cppOfs << std::endl;
            cppOfs << generatedCpp_;
            cppOfs.close();
            
            // enumerate exported functions and dependencies
            exportedFunctions_.clear();
            depends_.clear();
            for (SourceFileAttributes::const_iterator 
              it = sourceAttributes.begin(); it != sourceAttributes.end(); ++it) {
                 if (it->name() == kExportAttribute && !it->function().empty()) 
                    exportedFunctions_.push_back(exportedName(*it));
                
                 else if (it->name() == kDependsAttribute) {
                     for (size_t i = 0; i<it->params().size(); ++i)
                        depends_.push_back(it->params()[i].name());
                 }   
            }
        }
        
        const std::string& moduleName() const {
            return moduleName_;
        }
        
        const std::string& cppSourcePath() const {
            return cppSourcePath_;
        }
        
        std::string buildDirectory() const {
            return buildDirectory_;
        }
        
        std::string generatedCpp() const {
            return generatedCpp_;
        }
        
        std::string cppSourceFilename() const {
            return cppSourceFilename_;
        }
         
        std::string dynlibFilename() const {
            return moduleName() + dynlibExt_;
        }
        
        std::string dynlibPath() const {
            return buildDirectory_ + fileSep_ + dynlibFilename();
        }
        
        const std::vector<std::string>& exportedFunctions() const {
            return exportedFunctions_;
        }
        
        const std::vector<std::string>& depends() const { return depends_; };
          
    private:
    
        std::string generatedCppSourcePath() const {
           return buildDirectory_ + fileSep_ + cppSourceFilename(); 
        }
        
    private:
        std::string cppSourcePath_;
        time_t cppSourceLastModified_;
        std::string generatedCpp_;
        std::string cppSourceFilename_;
        std::string moduleName_;
        std::string buildDirectory_;
        std::string fileSep_;
        std::string dynlibExt_;
        std::vector<std::string> exportedFunctions_;
        std::vector<std::string> depends_;
    };
    
    // Dynlib cache that allows lookup by either file path or code contents
    class SourceCppDynlibCache {
      
    public:
        SourceCppDynlibCache() {}
        
    private:
        // prohibit copying
        SourceCppDynlibCache(const SourceCppDynlibCache&);
        SourceCppDynlibCache& operator=(const SourceCppDynlibCache&); 
      
    public:
        // Insert into cache by file name
        void insertFile(const std::string& file, const SourceCppDynlib& dynlib) {
            Entry entry;
            entry.file = file;
            entry.dynlib = dynlib;
            entries_.push_back(entry);
        }
        
        // Insert into cache by code
        void insertCode(const std::string& code, const SourceCppDynlib& dynlib) {
            Entry entry;
            entry.code = code;
            entry.dynlib = dynlib;
            entries_.push_back(entry);
        }
    
        // Lookup by file
        SourceCppDynlib lookupByFile(const std::string& file) {
            for (std::size_t i = 0; i < entries_.size(); i++) {
                if (entries_[i].file == file)
                    return entries_[i].dynlib;
            }
            
            return SourceCppDynlib();
        }
        
        // Lookup by code
        SourceCppDynlib lookupByCode(const std::string& code) {
            for (std::size_t i = 0; i < entries_.size(); i++) {
                if (entries_[i].code == code)
                    return entries_[i].dynlib;
            }
            
            return SourceCppDynlib();
        }
      
    private:
        struct Entry {
            std::string file;
            std::string code;
            SourceCppDynlib dynlib;
        };
        std::vector<Entry> entries_;
    };
    
    // Class which manages writing of code for compileAttributes
    class ExportsStream {
    public:
        ExportsStream(const std::string& targetFile, 
                      const std::string& commentPrefix) 
            : targetFile_(targetFile), commentPrefix_(commentPrefix) {
            
            // read the existing target file if it exists
            if (FileInfo(targetFile_).exists()) {
                std::ifstream ifs(targetFile_.c_str());
                if (ifs.fail())
                    throw Rcpp::file_io_error(targetFile_);
                std::stringstream buffer;
                buffer << ifs.rdbuf();
                existingCode_ = buffer.str();
            }
            
            // see if this is safe to overwite and throw if it isn't
            if (!isSafeToOverwrite())
                throw Rcpp::file_exists(targetFile_);
        }
        
    private:
        // prohibit copying
        ExportsStream(const ExportsStream&);
        ExportsStream& operator=(const ExportsStream&); 
        
    public:
        // Stream code into the buffer
        template <typename T>
        std::ostream& operator<<(const T& data) {
            codeStream_ << data;
            return codeStream_;
        }
        
        // Commit the stream -- is a no-op if the existing code is identical
        // to the generated code. Returns true if data was written and false
        // if it wasn't (throws exception on io error)
        bool commit(const std::string& preamble = std::string()) {
            
            // get the generated code
            std::string code = codeStream_.str();
            
            // if there is no generated code AND the exports file does not 
            // currently exist then do nothing
            if (code.empty() && !FileInfo(targetFile_).exists())
                return false;
            
            // write header/preamble
            std::ostringstream headerStream;
            headerStream << commentPrefix_ << " This file was generated by "
                         << "Rcpp::compileAttributes" << std::endl;
            headerStream << commentPrefix_ << " Generator token: " 
                         << generatorToken() << std::endl << std::endl;      
            if (!preamble.empty())
                headerStream << preamble << std::endl;
                
            // get generated code and only write it if there was a change
            std::string generatedCode = headerStream.str() + code;        
            if (generatedCode != existingCode_) {
                // open the file
                std::ofstream ofs(targetFile_.c_str(), 
                                  std::ofstream::out | std::ofstream::trunc);
                if (ofs.fail())
                    throw Rcpp::file_io_error(targetFile_);
                
                // write generated code and return
                ofs << generatedCode;
                ofs.close();
                return true;
            } 
            else {
                return false;
            }
        }
        
    private:
    
        // Check whether it's safe to overwrite this file (i.e. whether we 
        // generated the file in the first place)
        bool isSafeToOverwrite() const {
            return existingCode_.empty() || 
                   (existingCode_.find(generatorToken()) != std::string::npos);
        }
        
        // UUID that we write into a comment within the file (so that we can 
        // strongly identify that a file was generated by us before overwriting it)
        std::string generatorToken() const {
            return "10BE3573-1514-4C36-9D1C-5A225CD40393";
        }
    
    private:
        std::string targetFile_;
        std::string commentPrefix_;
        std::string existingCode_;
        std::ostringstream codeStream_;
    };
    
    class CppExportsStream : public ExportsStream {
    public:
        explicit CppExportsStream(const std::string& targetFile)
            : ExportsStream(targetFile, "//")
        {
        }
    };
    
    class RExportsStream : public ExportsStream {
    public:
        explicit RExportsStream(const std::string& targetFile)
            : ExportsStream(targetFile, "#")
        {
        }
    };

} // anonymous namespace


// Create temporary build directory, generate code as necessary, and return
// the context required for the sourceCpp function to complete it's work
RcppExport SEXP sourceCppContext(SEXP sFile, SEXP sCode, SEXP sPlatform) {
BEGIN_RCPP
    // parameters
    std::string file = Rcpp::as<std::string>(sFile);
    std::string code = sCode != R_NilValue ? Rcpp::as<std::string>(sCode) : "";
    Rcpp::List platform = Rcpp::as<Rcpp::List>(sPlatform);
    
    // get dynlib (using cache if possible)
    static SourceCppDynlibCache s_dynlibCache;
    SourceCppDynlib dynlib;
    if (!code.empty())
        dynlib = s_dynlibCache.lookupByCode(code);
    else
        dynlib = s_dynlibCache.lookupByFile(file);
  
    // check dynlib build state
    bool buildRequired = false;
    
    // if there is no dynlib in the cache then create one
    if (dynlib.isEmpty()) {   
        buildRequired = true;
        dynlib = SourceCppDynlib(file, platform);
        if (!code.empty())
            s_dynlibCache.insertCode(code, dynlib);
        else
            s_dynlibCache.insertFile(file, dynlib);
    }    
        
    // if the cached dynlib is dirty then regenerate the source
    else if (dynlib.isSourceDirty()) {
        buildRequired = true;    
        dynlib.regenerateSource();
    }
    
    // if the dynlib hasn't yet been built then note that
    else if (!dynlib.isBuilt()) {
        buildRequired = true; 
    }
    
    // return context as a list
    Rcpp::List context;
    context["moduleName"] = dynlib.moduleName();
    context["cppSourcePath"] = dynlib.cppSourcePath();
    context["buildRequired"] = buildRequired;
    context["buildDirectory"] = dynlib.buildDirectory();
    context["generatedCpp"] = dynlib.generatedCpp();
    context["exportedFunctions"] = dynlib.exportedFunctions();
    context["cppSourceFilename"] = dynlib.cppSourceFilename();
    context["dynlibFilename"] = dynlib.dynlibFilename();
    context["dynlibPath"] = dynlib.dynlibPath();
    context["depends"] = dynlib.depends();
    return Rcpp::wrap(context);
END_RCPP
}

// Compile the attributes within the specified package directory into 
// RcppExports.cpp and RcppExports.R
RcppExport SEXP compileAttributes(SEXP sPackageDir, 
                                  SEXP sPackageName,
                                  SEXP sCppFiles,
                                  SEXP sCppFileBasenames,
                                  SEXP sIncludes,
                                  SEXP sVerbose,
                                  SEXP sPlatform) {
BEGIN_RCPP
    // arguments
    std::string packageDir = Rcpp::as<std::string>(sPackageDir);
    std::string packageName = Rcpp::as<std::string>(sPackageName);
    std::vector<std::string> cppFiles = 
                    Rcpp::as<std::vector<std::string> >(sCppFiles);
    std::vector<std::string> cppFileBasenames = 
                    Rcpp::as<std::vector<std::string> >(sCppFileBasenames);
    std::vector<std::string> includes = 
                    Rcpp::as<std::vector<std::string> >(sIncludes);
    bool verbose = Rcpp::as<bool>(sVerbose);
    Rcpp::List platform = Rcpp::as<Rcpp::List>(sPlatform);
     
    // Establish stream for Cpp code
    std::string fileSep = Rcpp::as<std::string>(platform["file.sep"]);
    std::string cppExportsFile = packageDir + fileSep + "src" + 
                                 fileSep + "RcppExports.cpp";
    CppExportsStream cppStream(cppExportsFile);
    
    // Establish stream for R code
    std::string rExportsFile = packageDir + fileSep + "R" + 
                               fileSep + "RcppExports.R";
    RExportsStream rStream(rExportsFile);
     
    // Parse attributes from each file and generate code as required. 
    for (std::size_t i=0; i<cppFiles.size(); i++) {
        
        // parse attributes (continue if there are none)
        std::string cppFile = cppFiles[i];
        SourceFileAttributes attributes(cppFile);
        if (attributes.empty())
            continue;
                  
        // verbose output if requested
        if (!attributes.empty() && verbose)
            Rcpp::Rcout << "Exports from " << cppFile << ":" << std::endl;
        
        // generate C++ module
        std::string moduleName = "RcppExports_" + cppFileBasenames[i];
        cppStream << generateCppModule(moduleName, attributes, true, verbose);
        
        // genereate R loadModule 
        rStream << "loadModule(\"" << moduleName << "\", what = TRUE)" 
                << std::endl;
      
        // verbose if requested
        if (!attributes.empty() && verbose)
            Rcpp::Rcout << std::endl;
    }
                           
    // commit the code
    bool wroteCpp = cppStream.commit(generateCppPreamble(includes));     
    bool wroteR = rStream.commit();
    
    // verbose outputs
    if (verbose) {
        Rcpp::Rcout << "Generating exports files:" << std::endl;
        Rcpp::Rcout << "  RcppExports.cpp (" <<  
           (wroteCpp ? "updated" : "already up to date") << ")" << std::endl;
        Rcpp::Rcout << "  RcppExports.R (" <<  
           (wroteR ? "updated" : "already up to date") << ")" << std::endl;
    }
    
    // return status
    return Rcpp::wrap(wroteCpp || wroteR);
END_RCPP
}
