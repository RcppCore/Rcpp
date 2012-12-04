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

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <fstream>
#include <cstring>
#include <map>
#include <algorithm>

#include <Rcpp.h>

#include "AttributesGen.h"
#include "AttributesParser.h"
#include "AttributesUtil.h"

// provide implementations for util 
namespace Rcpp {
namespace attributes {
    
    // Utility class for getting file existence and last modified time
    FileInfo::FileInfo(const std::string& path) 
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
  
    // Remove a file (call back into R for this)
    bool removeFile(const std::string& path) {
        if (FileInfo(path).exists()) {
            Rcpp::Function rm = Rcpp::Environment::base_env()["file.remove"];
            rm(path);
            return true;
        }
        else {
            return false;
        }
    }
    
    // Recursively create a directory (call back into R for this)
    void createDirectory(const std::string& path) {
        if (!FileInfo(path).exists()) {
            Rcpp::Function mkdir = Rcpp::Environment::base_env()["dir.create"];
            mkdir(path, Rcpp::Named("recursive") = true);
        }
    }    
    
     // Known whitespace chars
    const char * const kWhitespaceChars = " \f\n\r\t\v";
      
    // Query whether a character is whitespace
    bool isWhitespace(char ch) {
        return std::strchr(kWhitespaceChars, ch) != NULL;
    }
    
    // Trim a string
    void trimWhitespace(std::string* pStr) {   
        
        // skip empty case
        if (pStr->empty())
            return;
        
        // trim right
        std::string::size_type pos = pStr->find_last_not_of(kWhitespaceChars);
        if (pos != std::string::npos)
            pStr->erase(pos + 1);    
            
        // trim left
        pos = pStr->find_first_not_of(kWhitespaceChars);
        pStr->erase(0, pos);
    }
    
    // Strip balanced quotes from around a string (assumes already trimmed)
    void stripQuotes(std::string* pStr) {
        if (pStr->length() < 2)
            return;       
        char quote = *(pStr->begin());
        if ( (quote == '\'' || quote == '\"') && (*(pStr->rbegin()) == quote) )
            *pStr = pStr->substr(1, pStr->length()-2);
    }
    
    // is the passed string quoted?
    bool isQuoted(const std::string& str) {
        if (str.length() < 2)
            return false;
        char quote = *(str.begin());
        return (quote == '\'' || quote == '\"') && (*(str.rbegin()) == quote);
    }
    
    // show a warning message
    void showWarning(const std::string& msg) {
        Rcpp::Function warning = Rcpp::Environment::base_env()["warning"];     
        warning(msg, Rcpp::Named("call.") = false);
    }
    
} // namespace attributes
} // namespace Rcpp


using namespace Rcpp::attributes;

// Generator helpers
namespace {
    
    // Generate the C++ code required to make [[Rcpp::export]] functions
    // available as C symbols with SEXP parameters and return
    std::string generateCpp(const SourceFileAttributes& attributes,
                            bool includePrototype,
                            const std::string& contextId) {
      
        // source code we will build up
        std::ostringstream ostr;    
      
        // process each attribute
        for(std::vector<Attribute>::const_iterator 
            it = attributes.begin(); it != attributes.end(); ++it) {
            
            // alias the attribute and function (bail if not export)
            const Attribute& attribute = *it;
            if (!attribute.isExportedFunction())
                continue;
            const Function& function = attribute.function();
                      
            // include prototype if requested
            if (includePrototype) {
                ostr << "// " << function.name() << std::endl;
                ostr << function << ";";
            }
               
            // write the SEXP-based function
            ostr << std::endl << "RcppExport SEXP ";
            if (!contextId.empty())
                ostr << contextId << "_";
            ostr << function.name() << "(";
            const std::vector<Argument>& arguments = function.arguments();
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                ostr << "SEXP " << argument.name() << "SEXP";
                if (i != (arguments.size()-1))
                    ostr << ", ";
            }
            ostr << ") {" << std::endl;
            ostr << "BEGIN_RCPP" << std::endl;
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                
                // Rcpp::as to c++ type
                ostr << "    " << argument.type().name() << " " << argument.name() 
                     << " = " << "Rcpp::as<"  << argument.type().name() << " >(" 
                     << argument.name() << "SEXP);" << std::endl;
            }
            
            ostr << "    ";
            if (!function.type().isVoid())
                ostr << function.type() << " result = ";
            ostr << function.name() << "(";
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                ostr << argument.name();
                if (i != (arguments.size()-1))
                    ostr << ", ";
            }
            ostr << ");" << std::endl;
            
            std::string res = function.type().isVoid() ? "R_NilValue" : 
                                                         "Rcpp::wrap(result)";
            ostr << "    return " << res << ";" << std::endl;
            ostr << "END_RCPP" << std::endl;
            ostr << "}" << std::endl;
        }
        
        return ostr.str();
    }
        
    // Generate R functions from the passed attributes
    std::string generateRFunctions(const SourceFileAttributes& attributes,
                                   const std::string& contextId,
                                   const std::string& dllInfo = std::string()) {
     
        // source code we will build up
        std::ostringstream ostr;
         
        // process each attribute
        for(std::vector<Attribute>::const_iterator 
            it = attributes.begin(); it != attributes.end(); ++it) {
            
            // alias the attribute and function (bail if not export)
            const Attribute& attribute = *it;
            if (!attribute.isExportedFunction())
                continue;
            const Function& function = attribute.function();
                
            // print roxygen lines
            for (size_t i=0; i<attribute.roxygen().size(); i++)
                ostr << attribute.roxygen()[i] << std::endl;
                    
            // build the parameter list 
            std::ostringstream argsOstr;
            const std::vector<Argument>& arguments = function.arguments();
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                argsOstr << argument.name();
                if (!argument.defaultValue().empty()) {
                    std::string rArg = cppArgToRArg(argument.type().name(), 
                                                    argument.defaultValue());
                    if (!rArg.empty()) {
                        argsOstr << " = " << rArg;
                    } else {
                        showWarning("Unable to parse C++ default value '" +
                                    argument.defaultValue() + "' for argument "+
                                    argument.name() + " of function " +
                                    function.name());
                    }
                }
                   
                if (i != (arguments.size()-1))
                    argsOstr << ", ";
            }
            std::string args = argsOstr.str();
            
            // determine the function name
            std::string name = attribute.exportedName();
                
            // write the function - use contextId to ensure symbol uniqueness
            ostr << name << " <- function(" << args << ") {" 
                 << std::endl;
            ostr << "    ";
            if (function.type().isVoid())
                ostr << "invisible(";
            ostr << ".Call(";
            
            // Two .Call styles are suppported -- if dllInfo is provided then
            // do a direct call to getNativeSymbolInfo; otherwise we assume that
            // the contextId is a package name and use the PACKAGE argument
            if (!dllInfo.empty()) {
                ostr << "getNativeSymbolInfo('"
                     <<  contextId << "_" << function.name() 
                     << "', " << dllInfo << ")";
            } 
            else {
                ostr << "'" << contextId << "_" << function.name() << "', "
                     << "PACKAGE = '" << contextId << "'";
            }
            
            // add arguments
            for (size_t i = 0; i<arguments.size(); i++) 
                ostr << ", " << arguments[i].name();   
            ostr << ")";
            if (function.type().isVoid())
                ostr << ")";
            ostr << std::endl;
        
            ostr << "}" << std::endl << std::endl;
        }
        
        return ostr.str();                                
    }
    
    // Generate the R code used to .Call the exported C symbols
    std::string generateR(const SourceFileAttributes& attributes,
                          const std::string& contextId,
                          const std::string& dynlibPath) {
            
        // source code we will build up
        std::ostringstream ostr;
        
        // DLLInfo - hide using . and ensure uniqueness using contextId
        std::string dllInfo = "`." + contextId + "_DLLInfo`";
        ostr << dllInfo << " <- dyn.load('" << dynlibPath << "')" 
             << std::endl << std::endl;
        
        // Generate R functions and return
        ostr << generateRFunctions(attributes, contextId, dllInfo);
        return ostr.str();
    }
    
    
    
} // anonymous namespace



// Implementation helpers for sourceCppContext
namespace {
    
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
            
            // generate a random context id
            Rcpp::Function sample = Rcpp::Environment::base_env()["sample"];
            std::ostringstream ostr;
            ostr << "sourceCpp_" << Rcpp::as<int>(sample(100000, 1));
            contextId_ = ostr.str();
            
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
            SourceFileAttributesParser sourceAttributes(cppSourcePath_);
        
            // generate cpp for attributes and append them 
            generatedCpp_ = generateCpp(sourceAttributes, false, contextId_);
            std::ofstream cppOfs(generatedCppSourcePath().c_str(), 
                                 std::ofstream::out | std::ofstream::app);
            if (cppOfs.fail())
                throw Rcpp::file_io_error(generatedCppSourcePath());
            cppOfs << generatedCpp_;
            cppOfs.close();
        
            // generate R for attributes and write it into the build directory
            std::string rCode = generateR(sourceAttributes, 
                                          contextId_, 
                                          dynlibPath());
            std::ofstream rOfs(generatedRSourcePath().c_str(), 
                               std::ofstream::out | std::ofstream::trunc);
             if (cppOfs.fail())
                throw Rcpp::file_io_error(generatedRSourcePath());
            rOfs << rCode;
            rOfs.close();
               
            // discover exported functions, and dependencies
            exportedFunctions_.clear();
            depends_.clear();
            for (SourceFileAttributesParser::const_iterator 
              it = sourceAttributes.begin(); it != sourceAttributes.end(); ++it) {
                 if (it->name() == kExportAttribute && !it->function().empty()) 
                    exportedFunctions_.push_back(it->exportedName());
                
                 else if (it->name() == kDependsAttribute) {
                     for (size_t i = 0; i<it->params().size(); ++i)
                        depends_.push_back(it->params()[i].name());
                 }   
            }
            
            // capture embededded R
            embeddedR_ = sourceAttributes.embeddedR();
        }
        
        const std::string& contextId() const {
            return contextId_;
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
        
        std::string rSourceFilename() const {
            return cppSourceFilename() + ".R";    
        }
         
        std::string dynlibFilename() const {
            return contextId() + dynlibExt_;
        }
        
        std::string dynlibPath() const {
            return buildDirectory_ + fileSep_ + dynlibFilename();
        }
       
        const std::vector<std::string>& exportedFunctions() const {
            return exportedFunctions_;
        }
        
        const std::vector<std::string>& depends() const { return depends_; };
        
        const std::vector<std::string>& embeddedR() const { return embeddedR_; }
          
    private:
    
        std::string generatedCppSourcePath() const {
           return buildDirectory_ + fileSep_ + cppSourceFilename(); 
        }
        
         std::string generatedRSourcePath() const {
           return buildDirectory_ + fileSep_ + rSourceFilename(); 
        }
        
    private:
        std::string cppSourcePath_;
        std::string generatedCpp_;
        std::string cppSourceFilename_;
        std::string contextId_;
        std::string buildDirectory_;
        std::string fileSep_;
        std::string dynlibExt_;
        std::vector<std::string> exportedFunctions_;
        std::vector<std::string> depends_;
        std::vector<std::string> embeddedR_;
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
        SourceCppDynlib* insertFile(const std::string& file, 
                                    const SourceCppDynlib& dynlib) {
            Entry entry;
            entry.file = file;
            entry.dynlib = dynlib;
            entries_.push_back(entry);
            return &(entries_.rbegin()->dynlib);
        }
        
        // Insert into cache by code
        SourceCppDynlib* insertCode(const std::string& code, 
                                    const SourceCppDynlib& dynlib) {
            Entry entry;
            entry.code = code;
            entry.dynlib = dynlib;
            entries_.push_back(entry);
            return &(entries_.rbegin()->dynlib);
        }
    
        // Lookup by file
        SourceCppDynlib* lookupByFile(const std::string& file) {
            for (std::size_t i = 0; i < entries_.size(); i++) {
                if (entries_[i].file == file)
                    return &(entries_[i].dynlib);
            }
            
            return NULL;
        }
        
        // Lookup by code
        SourceCppDynlib* lookupByCode(const std::string& code) {
            for (std::size_t i = 0; i < entries_.size(); i++) {
                if (entries_[i].code == code)
                    return &(entries_[i].dynlib);
            }
            
            return NULL;
        }
      
    private:
        struct Entry {
            std::string file;
            std::string code;
            SourceCppDynlib dynlib;
        };
        std::vector<Entry> entries_;
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
    SourceCppDynlib* pDynlib = !code.empty() ? s_dynlibCache.lookupByCode(code) 
                                             : s_dynlibCache.lookupByFile(file);
   
    // check dynlib build state
    bool buildRequired = false;
    
    // if there is no dynlib in the cache then create one
    if (pDynlib == NULL) {   
        buildRequired = true;
        SourceCppDynlib newDynlib(file, platform);
        if (!code.empty())
            pDynlib = s_dynlibCache.insertCode(code, newDynlib);
        else
            pDynlib = s_dynlibCache.insertFile(file, newDynlib);
    }    
        
    // if the cached dynlib is dirty then regenerate the source
    else if (pDynlib->isSourceDirty()) {
        buildRequired = true;    
        pDynlib->regenerateSource();
    }
    
    // if the dynlib hasn't yet been built then note that
    else if (!pDynlib->isBuilt()) {
        buildRequired = true; 
    }
    
    // return context as a list
    using namespace Rcpp;
    return List::create(
        _["contextId"] = pDynlib->contextId(),
        _["cppSourcePath"] = pDynlib->cppSourcePath(),
        _["buildRequired"] = buildRequired,
        _["buildDirectory"] = pDynlib->buildDirectory(),
        _["generatedCpp"] = pDynlib->generatedCpp(),
        _["exportedFunctions"] = pDynlib->exportedFunctions(),
        _["cppSourceFilename"] = pDynlib->cppSourceFilename(),
        _["rSourceFilename"] = pDynlib->rSourceFilename(),
        _["dynlibFilename"] = pDynlib->dynlibFilename(),
        _["dynlibPath"] = pDynlib->dynlibPath(),
        _["depends"] = pDynlib->depends(),
        _["embeddedR"] = pDynlib->embeddedR());
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
    std::string fileSep = Rcpp::as<std::string>(platform["file.sep"]); 
     
    // initialize generators
    ExportsGenerators generators;
    generators.add(new CppExportsGenerator(packageDir, packageName, fileSep));
    generators.add(new RExportsGenerator(packageDir, packageName, fileSep));
    
    // catch file exists exception if the include file already exists
    // and we are unable to overwrite it
    try {
        generators.add(new CppExportsIncludeGenerator(packageDir, 
                                                      packageName, 
                                                      fileSep));
    }
    catch(const Rcpp::file_exists& e) {
        std::string msg = 
            "The header file '" + e.filePath() + "' already exists so "
            "cannot be overwritten by Rcpp::interfaces";
        throw Rcpp::exception(msg.c_str(), __FILE__, __LINE__);
    }
    
    // catch file exists exception for package include (because if it 
    // already exists we simply leave it alone)
    try {
        generators.add(new CppPackageIncludeGenerator(packageDir, 
                                                      packageName, 
                                                      fileSep));
    }
    catch(const Rcpp::file_exists& e) {}
    
    // write begin
    generators.writeBegin();
     
    // Parse attributes from each file and generate code as required. 
    bool haveAttributes = false;
    for (std::size_t i=0; i<cppFiles.size(); i++) {
        
        // parse attributes (continue if there are none)
        std::string cppFile = cppFiles[i];
        SourceFileAttributesParser attributes(cppFile);
        if (attributes.empty())
            continue;
            
        // confirm we have attributes
        haveAttributes = true;
               
        // write functions
        generators.writeFunctions(attributes, verbose);
    }
    
    // write end
    generators.writeEnd();

    // commit or remove
    std::vector<std::string> updated;
    if (haveAttributes)
        updated = generators.commit(includes);  
    else
        updated = generators.remove();
                                                                                                                   
    // verbose output
    if (verbose) {
        for (size_t i=0; i<updated.size(); i++)
            Rcpp::Rcout << updated[i] << " updated." << std::endl;
    }
    
    // return files updated
    return Rcpp::wrap<std::vector<std::string> >(updated);
END_RCPP
}

