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

#include <Rcpp/Function.h>
#include <Rcpp/Environment.h>
#include <Rcpp/exceptions.h>

#include "AttributesParser.h"

using namespace Rcpp::attributes_parser;

// General utilities
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
    
    // Generate function entries for passed attributes
    void generateCppModuleFunctions(std::ostream& ostr,
                                    const SourceFileAttributes& attributes,
                                    bool verbose)
    {
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
                     << function.name();
                     
                    // add information on arguments
                    const std::vector<Argument>& args = 
                                        it->function().arguments();
                    ostr << ", Rcpp::List::create("; 
                    for (size_t i=0; i<args.size(); i++) {
                        const Argument& arg = args[i];
                        ostr << "Rcpp::Named(\"" << arg.name() << "\")";
                        if (!arg.defaultValue().empty())
                            ostr << " = " << arg.defaultValue();
                        if (i != (args.size()-1))
                            ostr << ", ";
                    }
                    ostr << ")"; 
                    ostr << ");" << std::endl;
                      
            } 
        }
    }
} // anonymous namespace


// Implementation helpers for compileAttributes
namespace {
    
    // Generate placeholder function declaration (for roxygen)
    void generateRoxygenPlaceholder(std::ostream& ostr,
                                    const Attribute& attribute) {
        
        ostr << exportedName(attribute) << "<- function(";
        const std::vector<Argument>& args = attribute.function().arguments();
        for (std::size_t i=0; i<args.size(); i++) {
            ostr << args[i].name();
            if (i != (args.size()-1))
                ostr << ", ";
        }
        ostr << ") {}" << std::endl;
    }
    
    // Generate roxygen
    void generateRoxygen(std::ostream& ostr,
                         const SourceFileAttributes& attributes) {
        
        for(std::vector<Attribute>::const_iterator 
                it = attributes.begin(); it != attributes.end(); ++it) {
         
            if (isExportedFunction(*it) && !it->roxygen().empty()) {
                ostr << std::endl;
                for (std::size_t i=0; i<it->roxygen().size(); i++)
                    ostr << it->roxygen()[i] << std::endl;
                generateRoxygenPlaceholder(ostr, *it);
                ostr << std::endl;
            } 
        }
    }
    
    // Abstract class which manages writing of code for compileAttributes
    class ExportsGenerator {
    protected:
        ExportsGenerator(const std::string& targetFile, 
                         const std::string& package,
                         const std::string& commentPrefix) 
            : targetFile_(targetFile), 
              package_(package),
              commentPrefix_(commentPrefix) {
            
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
        ExportsGenerator(const ExportsGenerator&);
        ExportsGenerator& operator=(const ExportsGenerator&); 
        
    public:
        virtual ~ExportsGenerator() {}
        
        // Name of target file
        const std::string& targetFile() const {
            return targetFile_;
        }
        
        // Name of package
        const std::string& package() const {
            return package_;
        }
        
        // Abstract interface for code generation
        virtual void writeBegin() = 0;
        virtual void writeFunctions(const SourceFileAttributes &attributes,
                                    bool verbose) = 0;
        virtual void writeEnd() = 0;
        
        virtual bool commit(const std::vector<std::string>& includes) = 0;
        
        // Remove the generated file entirely
        bool remove() {
            return removeFile(targetFile_);
        }
        
        // Allow generator to appear as a std::ostream&
        operator std::ostream&() {
            return codeStream_;
        }
        
    protected: 
    
        // Allow access to the output stream 
        std::ostream& ostr() {
            return codeStream_;
        }
        
        // Shared knowledge about the special export validation function
        std::string exportValidationFunction() {
            return "validateExported";
        } 
        std::string exportValidationFunctionRegisteredName() {
            return "RcppExports_" + exportValidationFunction();
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
                headerStream << preamble;
                
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
        std::string package_;
        std::string commentPrefix_;
        std::string existingCode_;
        std::ostringstream codeStream_;
    };
    
    // Class which manages generating RcppExports.cpp
    class CppExportsGenerator : public ExportsGenerator {
    public:
        explicit CppExportsGenerator(const std::string& packageDir, 
                                     const std::string& package,
                                     const std::string& fileSep)
            : ExportsGenerator( 
                packageDir + fileSep + "src" +  fileSep + "RcppExports.cpp", 
                package,
                "//")
        {
        }
        
        virtual void writeBegin() {
            ostr() << "RCPP_MODULE(" << package() << "_RcppExports) {" 
                    << std::endl;
        }
        
        virtual void writeFunctions(const SourceFileAttributes &attributes,
                                    bool verbose) {
            // verbose output if requested
            if (verbose) {
                Rcpp::Rcout << "Exports from " << attributes.sourceFile() << ":" 
                            << std::endl;
            }
        
            // generate functions
            generateCppModuleFunctions(ostr(), attributes, verbose);
            
            // track prototypes/signatures for inclusion in the preamble
            for (SourceFileAttributes::const_iterator 
                it = attributes.begin(); it != attributes.end(); ++it) {
                if (isExportedFunction(*it)) {
                    
                    // prototypes
                    std::ostringstream ostr;
                    ostr << it->function();
                    prototypes_.push_back(ostr.str());   
                    
                    // signatures
                    if (!it->function().isHidden()) {
                        signatures_.push_back(
                            it->function().signature(exportedName(*it)));
                    }
                }
            }
         
            // verbose if requested
            if (verbose)
                Rcpp::Rcout << std::endl;                           
        }
    
        virtual void writeEnd() {
            
            // add our export validation helper
            ostr() << "    Rcpp::function(\"" 
                   << exportValidationFunctionRegisteredName() << "\", &" 
                   << exportValidationFunction() << ");" << std::endl;

            ostr() << "}" << std::endl;   
        }
        
        virtual bool commit(const std::vector<std::string>& includes) {
                       
            // includes 
            std::ostringstream ostr;
            if (!includes.empty()) {
                for (std::size_t i=0;i<includes.size(); i++)
                    ostr << includes[i] << std::endl;
            }
            ostr << "#include <string>" << std::endl;
            ostr << "#include <set>" << std::endl;
            ostr << std::endl;
            
            // always bring in Rcpp
            ostr << "using namespace Rcpp;" << std::endl << std::endl;
            
            // prototypes
            if (!prototypes_.empty()) {
                for (std::size_t i=0;i<prototypes_.size(); i++)
                    ostr << prototypes_[i] << ";" << std::endl;
                ostr << std::endl;
            }
            
            // generate a function that can be used to validate exported
            // functions and their signatures prior to looking up with
            // GetCppCallable (otherwise inconsistent signatures between
            // client and library would cause a crash)
            ostr << "static bool " << exportValidationFunction() 
                 << "(const std::string& sig)" << " {" << std::endl;
            ostr << "    static std::set<std::string> signatures;" 
                 << std::endl;
            ostr << "    if (signatures.empty()) {" << std::endl;
            for (std::size_t i=0;i<signatures_.size(); i++) {
                ostr << "        signatures.insert(\"" << signatures_[i] 
                     << "\");" << std::endl;
            }
            ostr << "    }" << std::endl;
            ostr << "    return signatures.find(sig) != signatures.end();"
                 << std::endl;
            ostr << "}" << std::endl << std::endl;
            
            // commit with preamble
            return ExportsGenerator::commit(ostr.str());                  
        }
        
    private:
        std::vector<std::string> prototypes_;
        std::vector<std::string> signatures_;
    };
       
    // Class which manages generating PackageName_RcppExports.h header file
    const char * const kRcppExportsSuffix = "_RcppExports.h";
    class CppExportsIncludeGenerator : public ExportsGenerator {
    public:
        CppExportsIncludeGenerator(const std::string& packageDir, 
                                   const std::string& package,
                                   const std::string& fileSep)
            : ExportsGenerator( 
                packageDir +  fileSep + "inst" +  fileSep + "include" +
                fileSep + package + kRcppExportsSuffix, 
                package,
                "//")
        {
            includeDir_ = packageDir +  fileSep + "inst" +  fileSep + "include";
            hasCppInterface_ = false; 
        }
        
        virtual void writeBegin() {
            ostr() << "namespace " << package() << " {" 
                   << std::endl << std::endl;
            
            // Import Rcpp into this namespace. This allows declarations to
            // be written without fully qualifying all Rcpp types. The only
            // negative side-effect is that when this package's namespace
            // is imported it will also pull in Rcpp. However since this is
            // opt-in and represents a general desire to do namespace aliasing
            // this seems okay
            ostr() << "    using namespace Rcpp;" << std::endl << std::endl;
          
            // Write our export validation helper function. Putting it in 
            // an anonymous namespace will hide it from callers and give
            // it per-translation unit linkage
            ostr() << "    namespace {" << std::endl;
            ostr() << "        void " << exportValidationFunction()  
                   << "(const std::string& sig) {" << std::endl;
            std::string ptrName = "p_" + exportValidationFunction();
            ostr() << "            static bool(" << "*" << ptrName 
                   << ")(const std::string&) = "
                   << getCppCallable(exportValidationFunctionRegisteredName())
                   << ";" << std::endl;
            ostr() << "            if (!" << ptrName << "(sig))" << std::endl;
            ostr() << "                throw Rcpp::function_not_exported(\""
                   << "Function '\" + sig + \"' not found in " << package()
                   << "\");" << std::endl;
            ostr() << "        }" << std::endl;
            
            ostr() << "    }" << std::endl << std::endl;
        }
        
        virtual void writeFunctions(const SourceFileAttributes &attributes,
                                    bool verbose) {
                                        
            // don't write anything if there is no C++ interface
            if (!attributes.hasInterface(kInterfaceCpp)) 
                return;
            
            // there is a C++ interface so set flag indicating so
            hasCppInterface_ = true;
                                        
            for(std::vector<Attribute>::const_iterator 
                it = attributes.begin(); it != attributes.end(); ++it) {
         
                if (isExportedFunction(*it)) {
                    
                    Function function = 
                        it->function().renamedTo(exportedName(*it));
                        
                    // if it's hidden then don't generate a C++ interface
                    if (function.isHidden())
                        continue;  
                    
                    ostr() << "    inline " << function << " {" 
                            << std::endl;
                    
                    std::string ptrName = "p_" + function.name();
                    ostr() << "        static " << function.signature(ptrName);
                    ostr() << " = NULL;" << std::endl;
                    ostr() << "        if (" << ptrName << " == NULL) {" 
                           << std::endl;
                    ostr() << "            " << exportValidationFunction()
                           << "(\"" << function.signature() << "\");" 
                           << std::endl;
                    ostr() << "            " << ptrName << " = " 
                           << getCppCallable(function.name()) << ";" 
                           << std::endl;
                    ostr() << "        }" << std::endl;
                    ostr() << "        return " << ptrName  << "(";
                    
                    const std::vector<Argument>& args = function.arguments();
                    for (std::size_t i = 0; i<args.size(); i++) {
                        ostr() << args[i].name();
                        if (i != (args.size()-1))
                            ostr() << ",";
                    }
                           
                    ostr() << ");" << std::endl;
                    ostr() << "    }" << std::endl << std::endl;
                } 
            }                           
        }
        
        virtual void writeEnd() {
            ostr() << "}" << std::endl;
            ostr() << std::endl;
            ostr() << "#endif // " << getHeaderGuard() << std::endl;
         }
        
        virtual bool commit(const std::vector<std::string>& includes) {
            
            if (hasCppInterface_) {
                
                // create the include dir if necessary
                createDirectory(includeDir_);
                
                // generate preamble 
                std::ostringstream ostr;
                
                // header guard
                std::string guard = getHeaderGuard();
                ostr << "#ifndef " << guard << std::endl;
                ostr << "#define " << guard << std::endl << std::endl; 
                
                // includes
                if (!includes.empty()) {
                    for (std::size_t i=0;i<includes.size(); i++)
                        ostr << includes[i] << std::endl;
                    ostr << std::endl;
                }
                
                // commit with preamble
                return ExportsGenerator::commit(ostr.str());
            }
            else {
                return ExportsGenerator::remove();
            }
        }
        
    private:
        
        std::string getCppCallable(const std::string& function) const {
            std::ostringstream ostr;
            ostr << "Rcpp::GetCppCallable"
                 << "(\"" << package() << "\", "
                 << "\"" << package() + "_RcppExports\", "
                 << "\"" << function << "\")";
            return ostr.str();
        }
        
        std::string getHeaderGuard() const {
            return package() + "_RcppExports_h";
        }
        
    private:
        std::string includeDir_;
        bool hasCppInterface_;
    };
    
     // Class which manages generating PackageName_RcppExports.h header file
    class CppPackageIncludeGenerator : public ExportsGenerator {
    public:
        CppPackageIncludeGenerator(const std::string& packageDir, 
                                   const std::string& package,
                                   const std::string& fileSep)
            : ExportsGenerator( 
                packageDir +  fileSep + "inst" +  fileSep + "include" +
                fileSep + package + ".h", 
                package,
                "//")
        {
            includeDir_ = packageDir +  fileSep + "inst" +  fileSep + "include";
            hasCppInterface_ = false; 
        }
        
        virtual void writeBegin() {
        }
        
        virtual void writeFunctions(const SourceFileAttributes &attributes,
                                    bool verbose) {     
            // See if there is a C++ interface exported by any attributes
            if (attributes.hasInterface(kInterfaceCpp)) 
                hasCppInterface_ = true;  
        }
        
        virtual void writeEnd() {
            if (hasCppInterface_) {
                // header guard
                std::string guard = getHeaderGuard();
                ostr() << "#ifndef " << guard << std::endl;
                ostr() << "#define " << guard << std::endl << std::endl; 
                
                ostr() << "#include \"" << package() << kRcppExportsSuffix 
                       << "\"" << std::endl;
                
                ostr() << std::endl;
                ostr() << "#endif // " << getHeaderGuard() << std::endl;
            }
        }
        
        virtual bool commit(const std::vector<std::string>& includes) {
            
            if (hasCppInterface_) {
                
                // create the include dir if necessary
                createDirectory(includeDir_);
                
                // commit 
                return ExportsGenerator::commit();
            }
            else {
                return ExportsGenerator::remove();
            }
        }
        
    private:
    
        std::string getHeaderGuard() const {
            return package() + "_h";
        }
        
    private:
        std::string includeDir_;
        bool hasCppInterface_;
    };
    
    
    // Class which manages generator RcppExports.R
    class RExportsGenerator : public ExportsGenerator {
    public:
        explicit RExportsGenerator(const std::string& packageDir,
                                   const std::string& package,
                                   const std::string& fileSep)
            : ExportsGenerator(
                packageDir + fileSep + "R" +  fileSep + "RcppExports.R", 
                package,
                "#")
        {
        }
        
        virtual void writeBegin() {
        }
        
        virtual void writeFunctions(const SourceFileAttributes &attributes,
                                    bool verbose) {
                                        
            // add to exported functions if we have an R interface
            if (attributes.hasInterface(kInterfaceR)) {
                
                // track exported functions
                for (SourceFileAttributes::const_iterator 
                     it = attributes.begin(); it != attributes.end(); ++it) {
                    if (isExportedFunction(*it)) {
                        rExports_.push_back(exportedName(*it));
                    }
                }
                
                // generate roxygen 
                generateRoxygen(ostr(), attributes);      
            }                      
        }
        
        virtual void writeEnd() { 
            
            ostr() << "Rcpp::loadModule(\"" << package() << "_RcppExports\", ";
            if (rExports_.size() > 0) {
                ostr() << std::endl;
                ostr() << "    what = c(";
                for (size_t i=0; i<rExports_.size(); i++) {
                    if (i != 0)
                        ostr() << "             ";
                    ostr() << "\"" << rExports_[i] << "\"";
                    if (i != (rExports_.size()-1))
                        ostr() << "," << std::endl;
                }
                ostr() << "))" << std::endl;
            }
            else {
                ostr() << "what = character())";
            }
        }
        
        virtual bool commit(const std::vector<std::string>& includes) {
            return ExportsGenerator::commit();                    
        }
    
    private:
        std::vector<std::string> rExports_;
    };
    
    // Class to manage and dispatch to a list of generators
    class ExportsGenerators {
    public:
        typedef std::vector<ExportsGenerator*>::iterator Itr;
        
        ExportsGenerators() {}
        
        virtual ~ExportsGenerators() {
            try {
                for(Itr it = generators_.begin(); it != generators_.end(); ++it)
                    delete *it;
                generators_.clear(); 
            }
            catch(...) {}
        }
        
        void add(ExportsGenerator* pGenerator) {
            generators_.push_back(pGenerator);
        }
        
        void writeBegin() {
            for(Itr it = generators_.begin(); it != generators_.end(); ++it)
                (*it)->writeBegin();
        }
        
        void writeFunctions(const SourceFileAttributes &attributes,
                            bool verbose) {
            for(Itr it = generators_.begin(); it != generators_.end(); ++it)
                (*it)->writeFunctions(attributes, verbose);
        }
        
        void writeEnd() {
            for(Itr it = generators_.begin(); it != generators_.end(); ++it)
                (*it)->writeEnd();
        }
        
        // Commit and return a list of the files that were updated
        std::vector<std::string> commit(
                                const std::vector<std::string>& includes) {
            
            std::vector<std::string> updated;
            
            for(Itr it = generators_.begin(); it != generators_.end(); ++it) {
                if ((*it)->commit(includes))
                    updated.push_back((*it)->targetFile());
            }
               
            return updated;
        }
        
        // Remove and return a list of files that were removed
        std::vector<std::string> remove() {
            std::vector<std::string> removed;
            for(Itr it = generators_.begin(); it != generators_.end(); ++it) {
                if ((*it)->remove())
                    removed.push_back((*it)->targetFile());
            }
            return removed;
        }
                 
    private:
        // prohibit copying
        ExportsGenerators(const ExportsGenerators&);
        ExportsGenerators& operator=(const ExportsGenerators&); 
        
    private:
        std::vector<ExportsGenerator*> generators_;
    };

} // anonymous namespace


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
        SourceFileAttributes attributes(cppFile);
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
            generatedCpp_.clear();
            if (!sourceAttributes.empty()) {
                std::ostringstream ostr;
                ostr << "#include <Rcpp.h>" << std::endl;
                ostr << "RCPP_MODULE(" << moduleName()  << ") {" << std::endl;
                generateCppModuleFunctions(ostr, sourceAttributes, false);
                ostr << "}" << std::endl;
                generatedCpp_ = ostr.str();
            }
            
            // open source file and append module
            std::ofstream cppOfs(generatedCppSourcePath().c_str(), 
                                 std::ofstream::out | std::ofstream::app);
            if (cppOfs.fail())
                throw Rcpp::file_io_error(generatedCppSourcePath());
            cppOfs << std::endl;
            cppOfs << generatedCpp_;
            cppOfs.close();
               
            // discover exported functions, and dependencies
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
            
            // capture embededded R
            embeddedR_ = sourceAttributes.embeddedR();
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
        
        const std::vector<std::string>& embeddedR() const { return embeddedR_; }
          
    private:
    
        std::string generatedCppSourcePath() const {
           return buildDirectory_ + fileSep_ + cppSourceFilename(); 
        }
        
    private:
        std::string cppSourcePath_;
        std::string generatedCpp_;
        std::string cppSourceFilename_;
        std::string moduleName_;
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
        _["moduleName"] = pDynlib->moduleName(),
        _["cppSourcePath"] = pDynlib->cppSourcePath(),
        _["buildRequired"] = buildRequired,
        _["buildDirectory"] = pDynlib->buildDirectory(),
        _["generatedCpp"] = pDynlib->generatedCpp(),
        _["exportedFunctions"] = pDynlib->exportedFunctions(),
        _["cppSourceFilename"] = pDynlib->cppSourceFilename(),
        _["dynlibFilename"] = pDynlib->dynlibFilename(),
        _["dynlibPath"] = pDynlib->dynlibPath(),
        _["depends"] = pDynlib->depends(),
        _["embeddedR"] = pDynlib->embeddedR());
END_RCPP
}
