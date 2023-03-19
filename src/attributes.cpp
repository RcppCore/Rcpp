// attributes.cpp: Rcpp R/C++ interface class library -- Rcpp attributes
//
// Copyright (C) 2012 - 2020  JJ Allaire, Dirk Eddelbuettel and Romain Francois
// Copyright (C) 2021 - 2023  JJ Allaire, Dirk Eddelbuettel, Romain Francois, Iñaki Ucar and Travers Ching
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

#define COMPILING_RCPP

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <cstring>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>

#define RCPP_NO_SUGAR
#include <Rcpp.h>

/*******************************************************************
 * AttributesUtil.h
 *******************************************************************/

namespace Rcpp {
namespace attributes {

    // Utility class for getting file existence and last modified time
    class FileInfo {
    public:

        // create from path
        explicit FileInfo(const std::string& path);

        // create from R list
        explicit FileInfo(const List& fileInfo) {		// #nocov start
            path_ = as<std::string>(fileInfo["path"]);
            exists_ = as<bool>(fileInfo["exists"]);
            lastModified_ = as<double>(fileInfo["lastModified"]);
        }							// #nocov end

        // convert to R list
        List toList() const {
            List fileInfo;
            fileInfo["path"] = path_;
            fileInfo["exists"] = exists_;
            fileInfo["lastModified"] = lastModified_;
            return fileInfo;
        }

        std::string path() const { return path_; }
        bool exists() const { return exists_; }
        double lastModified() const { return lastModified_; }

        std::string extension() const {
            std::string::size_type pos = path_.find_last_of('.');
            if (pos != std::string::npos)
                return path_.substr(pos);
            else
                return "";					// #nocov
        }

        bool operator<(const FileInfo& other) const {
            return path_ < other.path_;
        };

        bool operator==(const FileInfo& other) const {
            return path_ == other.path_ &&
                   exists_ == other.exists_ &&
                   lastModified_ == other.lastModified_;
        };

        bool operator!=(const FileInfo& other) const {
            return ! (*this == other);
        };

        std::ostream& operator<<(std::ostream& os) const {
            os << path_;
            return os;
        }

    private:
        std::string path_;
        bool exists_;
        double lastModified_;
    };

    // Remove a file
    bool removeFile(const std::string& path);

    // Recursively create a directory
    void createDirectory(const std::string& path);

    // Known whitespace chars
    extern const char * const kWhitespaceChars;

    // Query whether a character is whitespace
    bool isWhitespace(char ch);

    // Trim a string
    void trimWhitespace(std::string* pStr);

    // Strip trailing line comments
    void stripTrailingLineComments(std::string* pStr);

    // Strip balanced quotes from around a string (assumes already trimmed)
    void stripQuotes(std::string* pStr);

    // is the passed string quoted?
    bool isQuoted(const std::string& str);

    // does a string end with another string?
    bool endsWith(const std::string& str, const std::string& suffix);

    // show a warning message
    void showWarning(const std::string& msg);

    // is the line a C++ roxygen comment? (started with //')
    bool isRoxygenCpp(const std::string& str);

} // namespace attributes
} // namespace Rcpp


/*******************************************************************
 * AttributesTypes.h
 *******************************************************************/

namespace Rcpp {
namespace attributes {

    // Known attribute names & parameters
    const char * const kExportAttribute = "export";
    const char * const kExportName = "name";
    const char * const kExportRng = "rng";
    const char * const kExportInvisible = "invisible";
    const char * const kExportSignature = "signature";
    const char * const kInitAttribute = "init";
    const char * const kDependsAttribute = "depends";
    const char * const kPluginsAttribute = "plugins";
    const char * const kInterfacesAttribute = "interfaces";
    const char * const kInterfaceR = "r";
    const char * const kInterfaceCpp = "cpp";
    const char * const kParamValueFalse = "false";
    const char * const kParamValueTrue = "true";
    const char * const kParamValueFALSE = "FALSE";
    const char * const kParamValueTRUE = "TRUE";
    const char * const kParamBlockStart = "{;";
    const char * const kParamBlockEnd = "}";

    // Type info
    class Type {
    public:
        Type(): isConst_(false), isReference_(false) {}
        Type(const std::string& name, bool isConst, bool isReference)
            : name_(name), isConst_(isConst), isReference_(isReference)
        {
        }
        bool empty() const { return name().empty(); }

        bool operator==(const Type& other) const {		// #nocov start
            return name_ == other.name_ &&
                   isConst_ == other.isConst_ &&
                   isReference_ == other.isReference_;
        };							// #nocov end

        bool operator!=(const Type& other) const {
            return !(*this == other);
        };

        const std::string& name() const { return name_; }
        std::string full_name() const {
            std::string res ;
            if( isConst() ) res += "const " ;
            res += name() ;
            if( isReference() ) res += "&" ;
            return res ;
        }

        bool isVoid() const { return name() == "void"; }
        bool isConst() const { return isConst_; }
        bool isReference() const { return isReference_; }

    private:
        std::string name_;
        bool isConst_;
        bool isReference_;
    };

    // Argument info
    class Argument {
    public:
        Argument() {}
        Argument(const std::string& name,
                 const Type& type,
                 const std::string& defaultValue)
            : name_(name), type_(type), defaultValue_(defaultValue)
        {
        }

        bool empty() const { return type().empty(); }

        bool operator==(const Argument& other) const {		// #nocov start
            return name_ == other.name_ &&
                   type_ == other.type_ &&
                   defaultValue_ == other.defaultValue_;
        };							// #nocov end

        bool operator!=(const Argument& other) const {
            return !(*this == other);
        };


        const std::string& name() const { return name_; }
        const Type& type() const { return type_; }
        const std::string& defaultValue() const { return defaultValue_; }

    private:
        std::string name_;
        Type type_;
        std::string defaultValue_;
    };

    // Function info
    class Function {
    public:
        Function() {}
        Function(const Type& type,
                 const std::string& name,
                 const std::vector<Argument>& arguments)
            : type_(type), name_(name), arguments_(arguments)
        {
        }

        Function renamedTo(const std::string& name) const {	// #nocov start
            return Function(type(), name, arguments());
        }

        std::string signature() const { return signature(name()); }
        std::string signature(const std::string& name) const;

        bool isHidden() const {
            return name().find_first_of('.') == 0;
        }							// #nocov end

        bool empty() const { return name().empty(); }

        bool operator==(const Function& other) const {		// #nocov start
            return type_ == other.type_ &&
                   name_ == other.name_ &&
                   arguments_ == other.arguments_;
        };							// #nocov end

        bool operator!=(const Function& other) const {
            return !(*this == other);
        };

        const Type& type() const { return type_; }
        const std::string& name() const { return name_; }
        const std::vector<Argument>& arguments() const { return arguments_; }

    private:
        Type type_;
        std::string name_;
        std::vector<Argument> arguments_;
    };

    // Attribute parameter (with optional value)
    class Param {
    public:
        Param() {}
        explicit Param(const std::string& paramText);
        bool empty() const { return name().empty(); }

        bool operator==(const Param& other) const {		// #nocov start
            return name_ == other.name_ &&
                   value_ == other.value_;
        };							// #nocov end

        bool operator!=(const Param& other) const {
            return !(*this == other);
        };


        const std::string& name() const { return name_; }
        const std::string& value() const { return value_; }	// #nocov

    private:
        std::string name_;
        std::string value_;
    };

    // Attribute (w/ optional params and signature of function it qualifies)
    class Attribute {
    public:
        Attribute() {}
        Attribute(const std::string& name,
                  const std::vector<Param>& params,
                  const Function& function,
                  const std::vector<std::string>& roxygen)
            : name_(name), params_(params), function_(function), roxygen_(roxygen)
        {
        }

        bool empty() const { return name().empty(); }		// #nocov start

        bool operator==(const Attribute& other) const {
            return name_ == other.name_ &&
                   params_ == other.params_ &&
                   function_ == other.function_ &&
                   roxygen_ == other.roxygen_;
        };							// #nocov end

        bool operator!=(const Attribute& other) const {
            return !(*this == other);
        };


        const std::string& name() const { return name_; }

        const std::vector<Param>& params() const { return params_; }

        Param paramNamed(const std::string& name) const;

        bool hasParameter(const std::string& name) const {
            return !paramNamed(name).empty();
        }

        const Function& function() const { return function_; }

        bool isExportedFunction() const {
            return (name() == kExportAttribute) && !function().empty();
        }

        std::string exportedName() const {

            // check for explicit name parameter
            if (hasParameter(kExportName))
            {
                return paramNamed(kExportName).value();		// #nocov
            }
            // otherwise un-named parameter in the first slot
            else if (!params().empty() && params()[0].value().empty())
            {
                return params()[0].name();			// #nocov
            }
            // otherwise the actual function name
            {
                return function().name();
            }
        }

        std::string exportedCppName() const {			// #nocov start
            std::string name = exportedName();
            std::replace(name.begin(), name.end(), '.', '_');
            return name;
        }							// #nocov end

        bool rng() const {
            Param rngParam = paramNamed(kExportRng);
            if (!rngParam.empty())
                return rngParam.value() == kParamValueTrue ||	// #nocov
                       rngParam.value() == kParamValueTRUE;  	// #nocov
            else
                return true;
        }

        bool invisible() const {
            Param invisibleParam = paramNamed(kExportInvisible);
            if (!invisibleParam.empty())
                return invisibleParam.value() == kParamValueTrue ||	// #nocov
                       invisibleParam.value() == kParamValueTRUE;  	// #nocov
            else
                return false;
        }

        const std::vector<std::string>& roxygen() const { return roxygen_; }

        std::string customRSignature() const {
            Param sigParam = paramNamed(kExportSignature);
            std::string sig = sigParam.value();
            trimWhitespace(&sig);
            if (sig.empty()) return sig;
#if __cplusplus < 201103L
            if (sig[sig.size() - 1] == '}')
#else
            if (sig.back() == '}')
#endif
                sig = sig.substr(0, sig.size()-1);
            // check sig.empty again since we deleted an element
            if (sig.empty()) return sig;
#if __cplusplus < 201103L
            if (sig[0] == '{')
#else
            if (sig.front() == '{')
#endif
                sig.erase(0,1);
            return sig;
        }

    private:
        std::string name_;
        std::vector<Param> params_;
        Function function_;
        std::vector<std::string> roxygen_;
    };

    // Operator << for parsed types
    std::ostream& operator<<(std::ostream& os, const Type& type);
    std::ostream& operator<<(std::ostream& os, const Argument& argument);
    std::ostream& operator<<(std::ostream& os, const Function& function);
    std::ostream& operator<<(std::ostream& os, const Param& param);
    std::ostream& operator<<(std::ostream& os, const Attribute& attribute);

    // interface to source file attributes
    class SourceFileAttributes
    {
    public:
        virtual ~SourceFileAttributes() {};
        virtual const std::string& sourceFile() const = 0;
        virtual bool hasInterface(const std::string& name) const = 0;

        typedef std::vector<Attribute>::const_iterator const_iterator;
        virtual const_iterator begin() const = 0;
        virtual const_iterator end() const = 0;

        virtual const std::vector<std::string>& modules() const = 0;

        virtual const std::vector<std::vector<std::string> >& roxygenChunks() const = 0;

        virtual bool hasGeneratorOutput() const = 0;

        virtual bool hasPackageInit() const = 0;
    };


} // namespace attributes
} // namespace Rcpp



/*******************************************************************
 * AttributesParser.h
 *******************************************************************/

namespace Rcpp {
namespace attributes {

    // Helper class for determining whether we are in a comment
    class CommentState {
    public:
        CommentState() : inComment_(false) {}
    private:
        // prohibit copying
        CommentState(const CommentState&);
        CommentState& operator=(const CommentState&);
    public:
        bool inComment() const { return inComment_; }
        void submitLine(const std::string& line);
        void reset() { inComment_ = false; }
    private:
        bool inComment_;
    };

    // Class used to parse and return attribute information from a source file
    class SourceFileAttributesParser : public SourceFileAttributes {
    public:
        explicit SourceFileAttributesParser(const std::string& sourceFile,
                                            const std::string& packageFile,
                                            bool parseDependencies);

    private:
        // prohibit copying
        SourceFileAttributesParser(const SourceFileAttributesParser&);
        SourceFileAttributesParser& operator=(const SourceFileAttributesParser&);

    public:
        // implemetnation of SourceFileAttributes interface
        virtual const std::string& sourceFile() const {		// #nocov
            return sourceFile_;					// #nocov
        }
        virtual const_iterator begin() const { return attributes_.begin(); }
        virtual const_iterator end() const { return attributes_.end(); }

        virtual const std::vector<std::string>& modules() const
        {
            return modules_;
        }

        virtual const std::vector<std::vector<std::string> >& roxygenChunks() const {
            return roxygenChunks_;
        }

        virtual bool hasGeneratorOutput() const
        {
            return !attributes_.empty() ||
                   !modules_.empty() ||
                   !roxygenChunks_.empty();
        }

        virtual bool hasInterface(const std::string& name) const {

            for (const_iterator it=begin(); it != end(); ++it) {
                if (it->name() == kInterfacesAttribute) {
                    return it->hasParameter(name);		// #nocov
                }
            }

            // if there's no interfaces attrbute we default to R
            if (name == kInterfaceR)
                return true;
            else
                return false;
        }

        // Was a package init function found?
        bool hasPackageInit() const {
            return hasPackageInit_;
        }

        // Get lines of embedded R code
        const std::vector<std::string>& embeddedR() const {
            return embeddedR_;
        }

        // Get source dependencies
        const std::vector<FileInfo>& sourceDependencies() const {
            return sourceDependencies_;
        };

    private:

        // Parsing helpers
        Attribute parseAttribute(const std::vector<std::string>& match,
                                 int lineNumber);
        std::vector<Param> parseParameters(const std::string& input);
        Function parseFunction(size_t lineNumber);
        std::string parseSignature(size_t lineNumber);
        std::vector<std::string> parseArguments(const std::string& argText);
        Type parseType(const std::string& text);

        // Validation helpers
        bool isKnownAttribute(const std::string& name) const;
        void attributeWarning(const std::string& message,
                              const std::string& attribute,
                              size_t lineNumber);
        void attributeWarning(const std::string& message, size_t lineNumber);
        void rcppExportWarning(const std::string& message, size_t lineNumber);
        void rcppExportNoFunctionFoundWarning(size_t lineNumber);
        void rcppExportInvalidParameterWarning(const std::string& param,
                                               size_t lineNumber);
        void rcppInterfacesWarning(const std::string& message,
                                   size_t lineNumber);

    private:
        std::string sourceFile_;
        CharacterVector lines_;
        std::vector<Attribute> attributes_;
        std::vector<std::string> modules_;
        bool hasPackageInit_;
        std::vector<std::string> embeddedR_;
        std::vector<FileInfo> sourceDependencies_;
        std::vector<std::vector<std::string> > roxygenChunks_;
        std::vector<std::string> roxygenBuffer_;
    };

} // namespace attributes
} // namespace Rcpp


/*******************************************************************
 * AttributesGen.h
 *******************************************************************/

namespace Rcpp {
namespace attributes {

    // Abstract class which manages writing of code for compileAttributes
    class ExportsGenerator {
    protected:
        ExportsGenerator(const std::string& targetFile,
                         const std::string& package,
                         const std::string& commentPrefix);

    private:
        // prohibit copying
        ExportsGenerator(const ExportsGenerator&);
        ExportsGenerator& operator=(const ExportsGenerator&);

    public:
        virtual ~ExportsGenerator() {}

        // Name of target file and package
        const std::string& targetFile() const { return targetFile_; }
        const std::string& package() const { return package_; }
        const std::string& packageCpp() const { return packageCpp_; }
        const std::string packageCppPrefix() const { return "_" + packageCpp(); }

        // Abstract interface for code generation
        virtual void writeBegin() = 0;
        void writeFunctions(const SourceFileAttributes& attributes,
                            bool verbose); // see doWriteFunctions below
        virtual void writeEnd(bool hasPackageInit) = 0;

        virtual bool commit(const std::vector<std::string>& includes) = 0;

        // Remove the generated file entirely
        bool remove();

        // Allow generator to appear as a std::ostream&
        operator std::ostream&() {
            return codeStream_;
        }

    protected:

        // Allow access to the output stream
        std::ostream& ostr() {
            return codeStream_;
        }

        bool hasCppInterface() const {
            return hasCppInterface_;
        }

        // Shared knowledge about function namees
        std::string exportValidationFunction() {
            return "RcppExport_validate";
        }
        std::string exportValidationFunctionRegisteredName() {
            return packageCppPrefix() + "_" + exportValidationFunction();
        }
        std::string registerCCallableExportedName() {			// #nocov
            return packageCppPrefix() + "_RcppExport_registerCCallable";	// #nocov
        }

        // Commit the stream -- is a no-op if the existing code is identical
        // to the generated code. Returns true if data was written and false
        // if it wasn't (throws exception on io error)
        bool commit(const std::string& preamble = std::string());

        // Convert a dot in package name to underscore for use in header file name
        std::string dotNameHelper(const std::string & name) const;

    private:

        // Private virtual for doWriteFunctions so the base class
        // can always intercept writeFunctions
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose) = 0;

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
        std::string packageCpp_;
        std::string commentPrefix_;
        std::string existingCode_;
        std::ostringstream codeStream_;
        bool hasCppInterface_;
    };

    // Class which manages generating RcppExports.cpp
    class CppExportsGenerator : public ExportsGenerator {
    public:
        explicit CppExportsGenerator(const std::string& packageDir,
                                     const std::string& package,
                                     const std::string& fileSep);

        virtual void writeBegin() {};
        virtual void writeEnd(bool hasPackageInit);
        virtual bool commit(const std::vector<std::string>& includes);

    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose);

        std::string registerCCallable(size_t indent,
                                      const std::string& exportedName,
                                      const std::string& name) const;

    private:
        // for generating calls to init functions
        std::vector<Attribute> initFunctions_;

        // for generating C++ interfaces
        std::vector<Attribute> cppExports_;

        // for generating Rcpp::export native routine registration
        std::vector<Attribute> nativeRoutines_;

        // for generating module native routine registration
        std::vector<std::string> modules_;
    };

    // Class which manages generating PackageName_RcppExports.h header file
    class CppExportsIncludeGenerator : public ExportsGenerator {
    public:
        CppExportsIncludeGenerator(const std::string& packageDir,
                                   const std::string& package,
                                   const std::string& fileSep);

        virtual void writeBegin();
        virtual void writeEnd(bool hasPackageInit);
        virtual bool commit(const std::vector<std::string>& includes);

    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose);
        std::string getCCallable(const std::string& function) const;
        std::string getHeaderGuard() const;

    private:
        std::string includeDir_;
    };

    // Class which manages generating PackageName.h header file
    class CppPackageIncludeGenerator : public ExportsGenerator {
    public:
        CppPackageIncludeGenerator(const std::string& packageDir,
                                   const std::string& package,
                                   const std::string& fileSep);

        virtual void writeBegin() {}
        virtual void writeEnd(bool hasPackageInit);
        virtual bool commit(const std::vector<std::string>& includes);

    private:
        virtual void doWriteFunctions(const SourceFileAttributes&, bool) {}
        std::string getHeaderGuard() const;

    private:
        std::string includeDir_;
    };


    // Class which manages generator RcppExports.R
    class RExportsGenerator : public ExportsGenerator {
    public:
        RExportsGenerator(const std::string& packageDir,
                          const std::string& package,
                          bool registration,
                          const std::string& fileSep);

        virtual void writeBegin() {}
        virtual void writeEnd(bool hasPackageInit);
        virtual bool commit(const std::vector<std::string>& includes);

    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose);

        bool registration_;

    };

    // Class to manage and dispatch to a list of generators
    class ExportsGenerators {
    public:
        typedef std::vector<ExportsGenerator*>::iterator Itr;

        ExportsGenerators() {}
        virtual ~ExportsGenerators();

        void add(ExportsGenerator* pGenerator);

        void writeBegin();
        void writeFunctions(const SourceFileAttributes& attributes,
                            bool verbose);
        void writeEnd(bool hasPackageInit);

        // Commit and return a list of the files that were updated
        std::vector<std::string> commit(
                                const std::vector<std::string>& includes);

        // Remove and return a list of files that were removed
        std::vector<std::string> remove();

    private:
        // prohibit copying
        ExportsGenerators(const ExportsGenerators&);
        ExportsGenerators& operator=(const ExportsGenerators&);

    private:
        std::vector<ExportsGenerator*> generators_;
    };

    // Standalone generation helpers (used by sourceCpp)

    std::string generateRArgList(const Function& function);

    bool checkRSignature(const Function& function, std::string args);

    void initializeGlobals(std::ostream& ostr);

    void generateCpp(std::ostream& ostr,
                     const SourceFileAttributes& attributes,
                     bool includePrototype,
                     bool cppInterface,
                     const std::string& contextId);

} // namespace attributes
} // namespace Rcpp


/*******************************************************************
 * AttributesParser.cpp
 *******************************************************************/

namespace Rcpp {
namespace attributes {

    namespace {

        Rcpp::List regexMatches(Rcpp::CharacterVector lines,
                                const std::string& regex)
        {
            Rcpp::Environment base("package:base");
            Rcpp::Function regexec = base["regexec"];
            Rcpp::Function regmatches = base["regmatches"];
            Rcpp::RObject result =  regexec(regex, lines);
            Rcpp::List matches = regmatches(lines, result);
            return matches;
        }

        template <typename Stream>
        void readFile(const std::string& file, Stream& os) {
            std::ifstream ifs(file.c_str());
            if (ifs.fail())
                throw Rcpp::file_io_error(file);		// #nocov
            os << ifs.rdbuf();
            ifs.close();
        }

        template <typename Collection>
        void readLines(std::istream& is, Collection* pLines) {
            pLines->clear();
            std::string line;
            while(std::getline(is, line)) {
                // strip \r (for the case of windows line terminators on posix)
                if (line.length() > 0 && *line.rbegin() == '\r')
                    line.erase(line.length()-1, 1);
                stripTrailingLineComments(&line);
                pLines->push_back(line);
            }
        }

        bool addUniqueDependency(Rcpp::CharacterVector include,
                                 std::vector<FileInfo>* pDependencies) {

            // return false if we already have this include
            std::string path = Rcpp::as<std::string>(include);
            for (size_t i = 0; i<pDependencies->size(); ++i) {
                if (pDependencies->at(i).path() == path)
                    return false;
            }

            // add it and return true
            pDependencies->push_back(FileInfo(path));
            return true;
        }

        void parseSourceDependencies(const std::string& sourceFile,
                                     std::vector<FileInfo>* pDependencies) {

            // import R functions
            Rcpp::Environment baseEnv = Rcpp::Environment::base_env();
            Rcpp::Function dirname = baseEnv["dirname"];
            Rcpp::Function filepath = baseEnv["file.path"];
            Rcpp::Function normalizePath = baseEnv["normalizePath"];
            Rcpp::Function fileExists = baseEnv["file.exists"];
            Rcpp::Environment toolsEnv = Rcpp::Environment::namespace_env(
                                                                    "tools");
            Rcpp::Function filePathSansExt = toolsEnv["file_path_sans_ext"];

            // get the path to the source file's directory
            Rcpp::CharacterVector sourceDir = dirname(sourceFile);

            // read the source file into a buffer
            std::stringstream buffer;
            readFile(sourceFile, buffer);

            // Now read into a list of strings (which we can pass to regexec)
            // First read into a std::deque (which will handle lots of append
            // operations efficiently) then copy into an R chracter vector
            std::deque<std::string> lines;
            readLines(buffer, &lines);
            Rcpp::CharacterVector linesVector = Rcpp::wrap(lines);

            // look for local includes
            Rcpp::List matches = regexMatches(
                            linesVector, "^\\s*#include\\s*\"([^\"]+)\"\\s*$");

            // accumulate local includes (skip commented sections)
            CommentState commentState;
            std::vector<FileInfo> newDependencies;
            for (int i = 0; i<matches.size(); i++) {
                std::string line = lines[i];
                commentState.submitLine(line);
                if (!commentState.inComment()) {
                    // get the match
                    const Rcpp::CharacterVector match = matches[i];
                    if (match.size() == 2) {
                        // compose a full file path for the match
                        Rcpp::CharacterVector include =
                            filepath(sourceDir, std::string(match[1]));
                        // if it exists then normalize and add to our list
                        LogicalVector exists = fileExists(include);
                        if (exists[0]) {
                            include = normalizePath(include, "/");
                            if (addUniqueDependency(include, pDependencies)) {
                                newDependencies.push_back(
                                    FileInfo(Rcpp::as<std::string>(include)));
                            }

                            std::vector<std::string> exts;
                            exts.push_back(".cc");
                            exts.push_back(".cpp");
                            for (size_t i = 0; i<exts.size(); ++i) {

                                // look for corresponding cpp file and add it
                                std::string file = Rcpp::as<std::string>(		// #nocov
                                    filePathSansExt(include)) + exts[i];

                                exists = fileExists(file);
                                if (exists[0]) {
                                    if (addUniqueDependency(file,
                                                            pDependencies)) {
                                        FileInfo fileInfo(file);
                                        newDependencies.push_back(fileInfo);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // look for dependencies recursively
            for (size_t i = 0; i<newDependencies.size(); i++) {
                FileInfo dependency = newDependencies[i];
                parseSourceDependencies(dependency.path(), pDependencies);
            }
        }

        // parse the source dependencies from the passed lines
        std::vector<FileInfo> parseSourceDependencies(
                                         std::string sourceFile) {

            // normalize source file
            Rcpp::Environment baseEnv = Rcpp::Environment::base_env();
            Rcpp::Function normalizePath = baseEnv["normalizePath"];
            sourceFile = Rcpp::as<std::string>(normalizePath(sourceFile, "/"));

            // parse dependencies
            std::vector<FileInfo> dependencies;
            parseSourceDependencies(sourceFile, &dependencies);

            // remove main source file
            dependencies.erase(std::remove(dependencies.begin(),	// #nocov
                                           dependencies.end(),
                                           FileInfo(sourceFile)),
                               dependencies.end());

            return dependencies;
        }

        // Parse embedded R code chunks from a file (receives the lines of the
        // file as a CharcterVector for using with regexec and as a standard
        // stl vector for traversal/insepection)
        std::vector<std::string> parseEmbeddedR(
                                        Rcpp::CharacterVector linesVector,
                                        const std::deque<std::string>& lines) {
            Rcpp::List matches = regexMatches(linesVector,
                                              "^\\s*/\\*{3,}\\s*[Rr]\\s*$");
            bool withinRBlock = false;
            CommentState commentState;
            std::vector<std::string> embeddedR;

            for (int i = 0; i<matches.size(); i++) {

                // track comment state
                std::string line = lines[i];
                commentState.submitLine(line);

                // is this a line that begins an R code block?
                const Rcpp::CharacterVector match = matches[i];
                bool beginRBlock = match.size() > 0;

                // check state and do the right thing
                if (beginRBlock) {
                    withinRBlock = true;				// #nocov
                }
                else if (withinRBlock) {
                    if (commentState.inComment())			// #nocov start
                        embeddedR.push_back(line);
                    else
                        withinRBlock = false;				// #nocov end
                }
            }

            return embeddedR;
        }

    } // anonymous namespace


    // Generate a type signature for the function with the provided name
    // (type signature == function pointer declaration)
    std::string Function::signature(const std::string& name) const {	// #nocov start

        std::ostringstream ostr;

        ostr << type() << "(*" << name << ")(";

        const std::vector<Argument>& args = arguments();
        for (std::size_t i = 0; i<args.size(); i++) {
            ostr << args[i].type();
            if (i != (args.size()-1))
                ostr << ",";
        }
        ostr << ")";

        return ostr.str();						// #nocov end
    }


    // Parse attribute parameter from parameter text
    Param::Param(const std::string& paramText)
    {
        // parse out name/value pair if there is one
        std::string::size_type pos = paramText.find("=") ;
        if ( pos != std::string::npos ) {
            // name
            name_ = paramText.substr(0, pos);				// #nocov start
            trimWhitespace(&name_);
            // value
            value_ = paramText.substr(pos + 1) ;
            trimWhitespace(&value_);
            stripQuotes(&value_);					// #nocov end
        }
        else {
            name_ = paramText;
            trimWhitespace(&name_);
            stripQuotes(&name_);
        }
    }

    // Check if the attribute has a parameter of a paricular name
    Param Attribute::paramNamed(const std::string& name) const {
        for (std::vector<Param>::const_iterator
          it = params_.begin(); it != params_.end(); ++it) {
            if (it->name() == name)					// #nocov
                return *it;						// #nocov
        }
        return Param();
    }

    // Type operator <<
    std::ostream& operator<<(std::ostream& os, const Type& type) {
        if (!type.empty()) {
            if (type.isConst())
                os << "const ";
            os << type.name();
            if (type.isReference())
                os << "&";
        }
        return os;
    }

    // Print argument
    void printArgument(std::ostream& os,
                       const Argument& argument,
                       bool printDefault = true) {
        if (!argument.empty()) {
            os << argument.type();
            if (!argument.name().empty()) {
                os << " ";
                os << argument.name();
                if (printDefault && !argument.defaultValue().empty())
                    os << " = " << argument.defaultValue();		// #nocov
            }
        }
    }

    // Argument operator <<
    std::ostream& operator<<(std::ostream& os, const Argument& argument) {// #nocov start
        printArgument(os, argument);
        return os;							// #nocov end
    }

    // Print function
    void printFunction(std::ostream& os,
                       const Function& function,
                       bool printArgDefaults = true) {

        if (!function.empty()) {
            if (!function.type().empty()) {
                os << function.type();
                os << " ";
            }
            os << function.name();
            os << "(";
            const std::vector<Argument>& arguments = function.arguments();
            for (std::size_t i = 0; i<arguments.size(); i++) {
                printArgument(os, arguments[i], printArgDefaults);
                if (i != (arguments.size()-1))
                    os << ", ";
            }
            os << ")";
        }
    }

    // Function operator <<
    std::ostream& operator<<(std::ostream& os, const Function& function) {// #nocov start
        printFunction(os, function);
        return os;
    }

    // Param operator <<
    std::ostream& operator<<(std::ostream& os, const Param& param) {
        if (!param.empty()) {
            os << param.name();
            if (!param.value().empty())
                os << "=" << param.value();
        }
        return os;
    }

    // Attribute operator <<
    std::ostream& operator<<(std::ostream& os, const Attribute& attribute) {
        if (!attribute.empty()) {
            os << "[[Rcpp::" << attribute.name();
            const std::vector<Param>& params = attribute.params();
            if (params.size() > 0) {
                os << "(";
                for (std::size_t i = 0; i<params.size(); i++) {
                    os << params[i];
                    if (i != (params.size()-1))
                        os << ",";
                }
                os << ")";
            }
            os << "]]";

            if (!attribute.function().empty())
                os << " " << attribute.function();
        }
        return os;							// #nocov end
    }

    // Parse the attributes from a source file
    SourceFileAttributesParser::SourceFileAttributesParser(
                                             const std::string& sourceFile,
                                             const std::string& packageName,
                                             bool parseDependencies)
        : sourceFile_(sourceFile), hasPackageInit_(false)
    {

        // transform packageName to valid C++ symbol
        std::string packageNameCpp = packageName;
        std::replace(packageNameCpp.begin(), packageNameCpp.end(), '.', '_');

        // First read the entire file into a std::stringstream so we can check
        // it for attributes (we don't want to do any of our more expensive
        // processing steps if there are no attributes to parse)
        std::stringstream buffer;
        readFile(sourceFile_, buffer);
        std::string contents = buffer.str();

        // Check for attribute signature
        if (contents.find("[[Rcpp::") != std::string::npos ||
            contents.find("RCPP_MODULE") != std::string::npos ||
            contents.find("R_init_" + packageNameCpp) != std::string::npos) {

            // Now read into a list of strings (which we can pass to regexec)
            // First read into a std::deque (which will handle lots of append
            // operations efficiently) then copy into an R character vector
            std::deque<std::string> lines;
            readLines(buffer, &lines);
            lines_ = Rcpp::wrap(lines);

            // Scan for attributes
            CommentState commentState;
            Rcpp::List matches = regexMatches(lines_,
                "^\\s*//\\s*\\[\\[Rcpp::(\\w+)(\\(.*?\\))?\\]\\]\\s*$");
            for (int i = 0; i<matches.size(); i++) {

                // track whether we are in a comment and bail if we are in one
                std::string line = lines[i];
                commentState.submitLine(line);
                if (commentState.inComment())
                    continue;

                // attribute line
                const Rcpp::CharacterVector match = matches[i];
                if (match.size() > 0) {

                    // if the match size isn't 3 then regmatches has not behaved
                    // as expected (it should return a vector of either 0 or 3
                    // elements). we don't ever expect this to occur but if it
                    // does let's not crash
                    if (match.size() != 3)
                        continue;					// #nocov

                    // add the attribute
                    Attribute attr = parseAttribute(
                        Rcpp::as<std::vector<std::string> >(match),  i);
                    attributes_.push_back(attr);
                }

                // if it's not an attribute line then it could still be a
                // line of interest (e.g. roxygen comment)
                else {

                    // save roxygen comments
                    if (line.find("//'") == 0) {
                        std::string roxLine = "#" + line.substr(2);
                        roxygenBuffer_.push_back(roxLine);
                    }

                    // a non-roxygen line causes us to clear the roxygen buffer
                    else if (!roxygenBuffer_.empty()) {
                        roxygenChunks_.push_back(roxygenBuffer_);	// #nocov
                        roxygenBuffer_.clear();				// #nocov
                    }
                }
            }

            // Scan for Rcpp modules
            commentState.reset();
            Rcpp::List modMatches = regexMatches(lines_,
                "^\\s*RCPP_MODULE\\s*\\(\\s*(\\w+)\\s*\\).*$");
            for (int i = 0; i<modMatches.size(); i++) {

                // track whether we are in a comment and bail if we are in one
                std::string line = lines[i];
                commentState.submitLine(line);
                if (commentState.inComment())
                    continue;

                // get the module declaration
                Rcpp::CharacterVector match = modMatches[i];
                if (match.size() > 0) {
                    const char * name = match[1];
                    modules_.push_back(name);
                }
            }

            // Scan for package init function
            hasPackageInit_ = false;
            commentState.reset();
            std::string pkgInit = "R_init_" + packageNameCpp;
            Rcpp::List initMatches = regexMatches(lines_, "^[^/]+" + pkgInit + ".*DllInfo.*$");
            for (int i = 0; i<initMatches.size(); i++) {

                // track whether we are in a comment and bail if we are in one
                std::string line = lines[i];
                commentState.submitLine(line);
                if (commentState.inComment())
                    continue;

                // check for a match
                Rcpp::CharacterVector match = initMatches[i];
                if (match.size() > 0) {
                    hasPackageInit_ = true;		// #nocov start
                    break;
                }					// #nocov end
            }

            // Parse embedded R
            embeddedR_ = parseEmbeddedR(lines_, lines);

            // Recursively parse dependencies if requested
            if (parseDependencies) {

                // get source dependencies
                sourceDependencies_ = parseSourceDependencies(sourceFile);

                // parse attributes and modules from each dependent file
                for (size_t i = 0; i<sourceDependencies_.size(); i++) {

                    // perform parse
                    std::string dependency = sourceDependencies_[i].path();
                    SourceFileAttributesParser parser(dependency, packageName, false);

                    // copy to base attributes (if it's a new attribute)
                    for (SourceFileAttributesParser::const_iterator	// #nocov start
                            it = parser.begin(); it != parser.end(); ++it) {
                        if (std::find(attributes_.begin(),
                                      attributes_.end(),
                                      *it) == attributes_.end()) {
                            attributes_.push_back(*it);			// #nocov end
                        }
                    }

                    // copy to base modules
                    std::copy(parser.modules().begin(),
                              parser.modules().end(),
                              std::back_inserter(modules_));
                }
            }
        }
    }

    // Parse an attribute from the vector returned by regmatches
    Attribute SourceFileAttributesParser::parseAttribute(
                                    const std::vector<std::string>& match,
                                    int lineNumber) {
        // Attribute name
        std::string name = match[1];

        // Warn if this is an unknown attribute
        if (!isKnownAttribute(name)) {
            attributeWarning("Unrecognized attribute Rcpp::" + name,	// #nocov
                             lineNumber);				// #nocov
        }

        // Extract params if we've got them
        std::vector<Param> params;
        std::string paramsText = match[2];
        if (!paramsText.empty()) {

            // we know from the regex that it's enclosed in parens so remove
            // trim before we do this just in case someone updates the regex
            // to allow for whitespace around the call
            trimWhitespace(&paramsText);

            paramsText = paramsText.substr(1, paramsText.size()-2);

            // parse the parameters
            params = parseParameters(paramsText);
        }

        // Extract function signature if this is a function attribute
        // and it doesn't appear at the end of the file
        Function function;

        // special handling for export and init
        if (name == kExportAttribute || name == kInitAttribute) {

            // parse the function (unless we are at the end of the file in
            // which case we print a warning)
            if ((lineNumber + 1) < lines_.size())
                function = parseFunction(lineNumber + 1);
            else
                rcppExportWarning("No function found", lineNumber);	// #nocov

            // validate parameters
            for (std::size_t i=0; i<params.size(); i++) {

                std::string name = params[i].name();			// #nocov start
                std::string value = params[i].value();

                // un-named parameter that isn't the first parameter
                if (value.empty() && (i > 0)) {
                    rcppExportWarning("No value specified for parameter '" +
                                      name + "'",
                                      lineNumber);
                }
                // parameter that isn't name or rng
                else if (!value.empty() &&
                         (name != kExportName) &&
                         (name != kExportRng) &&
                         (name != kExportInvisible) &&
                         (name != kExportSignature)) {
                    rcppExportWarning("Unrecognized parameter '" + name + "'",
                                      lineNumber);
                }
                // rng that isn't true or false
                else if (name == kExportRng) {
                    if (value != kParamValueFalse &&
                        value != kParamValueTrue &&
                        value != kParamValueFALSE &&
                        value != kParamValueTRUE) {
                        rcppExportWarning("rng value must be true or false",
                                          lineNumber);
                    }
                }
                // invisible that isn't true of false
                else if (name == kExportInvisible) {
                    if (value != kParamValueFalse &&
                        value != kParamValueTrue &&
                        value != kParamValueFALSE &&
                        value != kParamValueTRUE) {
                        rcppExportWarning("invisible value must be true or false",
                                          lineNumber);			// #nocov end
                    }
                }
            }
        }

        // validate interfaces parameter
        else if (name == kInterfacesAttribute) {
            if (params.empty()) {					// #nocov start
                rcppInterfacesWarning("No interfaces specified", lineNumber);//
            }
            else {
                for (std::size_t i=0; i<params.size(); i++) {
                    std::string param = params[i].name();
                    if (param != kInterfaceR && param != kInterfaceCpp) {
                        rcppInterfacesWarning(
                            "Unknown interface '" + param + "'", lineNumber);
                    }							// #nocov end
                }
            }


        }

        // Return attribute
        Attribute attribute = Attribute(name, params, function, roxygenBuffer_);
        roxygenBuffer_.clear();
        return attribute;
    }

    // Parse attribute parameters
    std::vector<Param> SourceFileAttributesParser::parseParameters(
                                                    const std::string& input) {
        std::string::size_type blockstart = input.find_first_of(kParamBlockStart);
        std::string::size_type blockend = input.find_last_of(kParamBlockEnd);

        const std::string delimiters(",");
        std::vector<Param> params;
        std::string::size_type current;
        std::string::size_type next = std::string::npos;
        std::string::size_type signature_param_start = std::string::npos;
        do {								// #nocov
            next = input.find_first_not_of(delimiters, next + 1);
            if (next == std::string::npos)
                break;							// #nocov
            current = next;
            do {
                next = input.find_first_of(delimiters, next + 1);
            } while((next >= blockstart) && (next <= blockend) &&
                (next != std::string::npos));
            params.push_back(Param(input.substr(current, next - current)));
            if(params.back().name() == kExportSignature) {
                signature_param_start = current;
            }
        } while(next != std::string::npos);

        // if the signature param was found, then check that the name,
        // start block and end block exist and are in the correct order
        if(signature_param_start !=  std::string::npos) {
            bool sigchecks =
                signature_param_start < blockstart &&
                blockstart < blockend &&
                blockstart != std::string::npos &&
                blockend != std::string::npos;
            if(!sigchecks) {
                throw Rcpp::exception("signature parameter found but missing {}");
            }
        }
        return params;
    }

    // Parse a function from the specified spot in the source file
    Function SourceFileAttributesParser::parseFunction(size_t lineNumber) {

        // Establish the text to parse for the signature
        std::string signature = parseSignature(lineNumber);
        if (signature.empty()) {
            rcppExportNoFunctionFoundWarning(lineNumber);		// #nocov
            return Function();						// #nocov
        }

        // Start at the end and look for the () that deliniates the arguments
        // (bail with an empty result if we can't find them)
        std::string::size_type endParenLoc = signature.find_last_of(')');
        std::string::size_type beginParenLoc = signature.find_first_of('(');
        if (endParenLoc == std::string::npos ||
            beginParenLoc == std::string::npos ||
            endParenLoc < beginParenLoc) {

            rcppExportNoFunctionFoundWarning(lineNumber);		// #nocov
            return Function();						// #nocov
        }

        // Find the type and name by scanning backwards for the whitespace that
        // delimites the type and name
        Type type;
        std::string name;
        const std::string preambleText = signature.substr(0, beginParenLoc);
        for (std::string::const_reverse_iterator
            it = preambleText.rbegin(); it != preambleText.rend(); ++it) {
            char ch = *it;
            if (isWhitespace(ch)) {
                if (!name.empty()) {
                    // we are at the break between type and name so we can also
                    // extract the type
                    std::string typeText;
                    while (++it != preambleText.rend())
                        typeText.insert(0U, 1U, *it);
                    type = parseType(typeText);

                    // break (since we now have the name and the type)
                    break;
                }
                else
                    continue;					// #nocov
            } else {
                name.insert(0U, 1U, ch);
            }
        }

        // If we didn't find a name then bail
        if (name.empty()) {
            rcppExportNoFunctionFoundWarning(lineNumber);	// #nocov
            return Function();					// #nocov
        }

        // If we didn't find a type then bail
        if (type.empty()) {					// #nocov start
            rcppExportWarning("No function return type found", lineNumber);
            return Function();					// #nocov end
        }

        // Now scan for arguments
        std::vector<Argument> arguments;
        std::string argsText = signature.substr(beginParenLoc + 1,
                                                 endParenLoc-beginParenLoc-1);
        std::vector<std::string> args = parseArguments(argsText);
        for (std::vector<std::string>::const_iterator it =
                                        args.begin(); it != args.end(); ++it) {

            // Get argument sans whitespace (bail if the arg is empty)
            std::string arg = *it;
            trimWhitespace(&arg);
            if (arg.empty()) {
                // we don't warn here because the compilation will fail anyway
                continue;					// #nocov
            }

            // If the argument has an = within it then it has a default value
            std::string defaultValue;
            std::string::size_type eqPos = arg.find_first_of('=');
            if ( (eqPos != std::string::npos) && ((eqPos + 1) < arg.size()) ) {
                defaultValue = arg.substr(eqPos+1);
                trimWhitespace(&defaultValue);
                arg = arg.substr(0, eqPos);
                trimWhitespace(&arg);
            }

            // Scan backwards for whitespace to determine where the type ends
            // (we go backwards because whitespace is valid inside the type
            // identifier but invalid inside the variable name). Note that if
            // there is no whitespace we'll end up taking the whole string,
            // which allows us to capture a type with no variable (but note
            // we'll ultimately fail to parse types with no variable if they
            // have embedded whitespace)
            std::string::size_type pos = arg.find_last_of(kWhitespaceChars);

            // check for name
            std::string name;
            if (pos != std::string::npos) {
                // insert whitespace if variables are joint with '&'
                std::string::size_type ref_pos = arg.substr(pos).find_last_of("&");
                if (ref_pos != std::string::npos) {
                    pos += ref_pos + 1;				// #nocov
                    arg.insert(pos, " ");			// #nocov
                }

                name = arg.substr(pos);
                trimWhitespace(&name);
            }
            if (name.empty()) {					// #nocov start
                rcppExportInvalidParameterWarning(arg, lineNumber);
                return Function();				// #nocov end
            }

            // check for type string
            Type type = parseType(arg.substr(0, pos));
            if (type.empty()) {					// #nocov start
                rcppExportInvalidParameterWarning(arg, lineNumber);
                return Function();				// #nocov end
            }

            // add argument
            arguments.push_back(Argument(name, type, defaultValue));
        }

        return Function(type, name, arguments);
    }


    // Parse the text of a function signature from the specified line
    std::string SourceFileAttributesParser::parseSignature(size_t lineNumber) {

        // Look for the signature termination ({ or ; not inside quotes)
        // on this line and then subsequent lines if necessary
        std::string signature;
        for (size_t i = lineNumber; i < (size_t)lines_.size(); i++) {
            std::string line;
            line = lines_[i];
            bool insideQuotes = false;
            char prevChar = 0;
            // scan for { or ; not inside quotes
            for (size_t c = 0; c < line.length(); ++c) {
                // alias character
                char ch = line.at(c);
                // update quotes state
                if (ch == '"' && prevChar != '\\')
                    insideQuotes = !insideQuotes;
                // found signature termination, append and return
                if (!insideQuotes && ((ch == '{') || (ch == ';'))) {
                    signature.append(line.substr(0, c));
                    return signature;
                }
                // record prev char (used to check for escaped quote i.e. \")
                prevChar = ch;
            }

            // if we didn't find a terminator on this line then just append the line
            // and move on to the next line
            signature.append(line);
            signature.push_back(' ');
        }

        // Not found
        return std::string();						// #nocov
    }


    // Parse arguments from function signature. This is tricky because commas
    // are used to delimit arguments but are also valid inside template type
    // qualifiers.
    std::vector<std::string> SourceFileAttributesParser::parseArguments(
                                                const std::string& argText) {

        int templateCount = 0;
        int parenCount = 0;
        std::string currentArg;
        std::vector<std::string> args;
        char quote = 0;
        bool escaped = false;
        typedef std::string::const_iterator it_t;
        for (it_t it = argText.begin(); it != argText.end(); ++it) {

            // Store current character
            char ch = *it;

            // Ignore quoted strings and character values in single quotes
            if ( ! quote && (ch == '"' || ch == '\''))
                quote = ch;
            else if (quote && ch == quote && ! escaped)
                quote = 0;

            // Escaped character inside quotes
            if (escaped)
                escaped = false;
            else if (quote && ch == '\\')
                escaped = true;

            // Detect end of argument declaration
            if ( ! quote &&
                (ch == ',') &&
                (templateCount == 0) &&
                (parenCount == 0)) {
                args.push_back(currentArg);
                currentArg.clear();
                continue;
            }

            // Append current character if not a space at start
            if ( ! currentArg.empty() || ch != ' ')
                currentArg.push_back(ch);

            // Count use of potentially enclosed brackets
            if ( ! quote) {
                switch(ch) {
                    case '<':
                        templateCount++;
                        break;
                    case '>':
                        templateCount--;
                        break;
                    case '(':				// #nocov start
                        parenCount++;
                        break;
                    case ')':
                        parenCount--;
                        break;				// #nocov end
                }
            }
        }

        if (!currentArg.empty())
            args.push_back(currentArg);

        return args;
    }

    Type SourceFileAttributesParser::parseType(const std::string& text) {

        const std::string constQualifier("const");
        const std::string referenceQualifier("&");

        // trim whitespace
        std::string type = text;
        trimWhitespace(&type);

        // check for const and reference
        bool isConst = false;
        bool isReference = false;
        if (type.find(constQualifier) == 0) {
            isConst = true;
            type.erase(0, constQualifier.length());
        }

        // if the type is now empty (because it was detected as only const)
        // then this is an invalid state so we bail
        if (type.empty())
            return Type();					// #nocov

        if (type.find(referenceQualifier) ==
            (type.length() - referenceQualifier.length())) {
            isReference = true;
            type.erase(type.length() - referenceQualifier.length());
        }
        trimWhitespace(&type);

        // if the type is now empty because of some strange parse then bail
        if (type.empty())
            return Type();					// #nocov

        return Type(type, isConst, isReference);
    }

    // Validation helpers

    bool SourceFileAttributesParser::isKnownAttribute(const std::string& name)
                                                                        const {
        return name == kExportAttribute ||
               name == kInitAttribute ||
               name == kDependsAttribute ||
               name == kPluginsAttribute ||
               name == kInterfacesAttribute;
    }

    // Print an attribute parsing related warning
    void SourceFileAttributesParser::attributeWarning(		// #nocov start
                                                const std::string& message,
                                                const std::string& attribute,
                                                size_t lineNumber) {

        // get basename of source file for warning message
        Rcpp::Function basename = Rcpp::Environment::base_env()["basename"];
        std::string file = Rcpp::as<std::string>(basename(sourceFile_));

        std::ostringstream ostr;
        ostr << message;
        if (!attribute.empty())
            ostr << " for " << attribute << " attribute";
        ostr << " at " << file << ":" << lineNumber;

        showWarning(ostr.str());
    }

    void SourceFileAttributesParser::attributeWarning(
                                            const std::string& message,
                                            size_t lineNumber) {
        attributeWarning(message, "", lineNumber);
    }

    void SourceFileAttributesParser::rcppExportWarning(
                                             const std::string& message,
                                             size_t lineNumber) {
        attributeWarning(message, "Rcpp::export", lineNumber);
    }

    void SourceFileAttributesParser::rcppExportNoFunctionFoundWarning(
                                                          size_t lineNumber) {
        rcppExportWarning("No function found", lineNumber);
    }

    void SourceFileAttributesParser::rcppExportInvalidParameterWarning(
                                                    const std::string& param,
                                                    size_t lineNumber) {
        rcppExportWarning("Invalid parameter: "
                          "'" + param + "'", lineNumber);
    }

    void SourceFileAttributesParser::rcppInterfacesWarning(
                                                    const std::string& message,
                                                    size_t lineNumber) {
        attributeWarning(message + " (valid interfaces are 'r' and 'cpp')",
                        "Rcpp::interfaces", lineNumber);
    }							// #nocov end


    // Track /* */ comment state
    void CommentState::submitLine(const std::string& line) {
        std::size_t pos = 0;
        while (pos != std::string::npos) {

            // check for a // which would invalidate any other token found
            std::size_t lineCommentPos = line.find("//", pos);

            // look for the next token
            std::string token = inComment() ? "*/" : "/*";
            pos = line.find(token, pos);

            // process the comment token if found
            if (pos != std::string::npos) {

                // break if the line comment precedes the comment token
                if (lineCommentPos != std::string::npos && lineCommentPos < pos)
                    break;				// #nocov

                inComment_ = !inComment_;
                pos += token.size();
            }
        }
    }

} // namespace attributes
} // namespace Rcpp


/*******************************************************************
 * AttributesGen.cpp
 *******************************************************************/

namespace Rcpp {
namespace attributes {

    // constants
    namespace {
        const char * const kRcppExportsSuffix = "_RcppExports.h";
        const char * const kTrySuffix = "_try";
    }

    ExportsGenerator::ExportsGenerator(const std::string& targetFile,
                                       const std::string& package,
                                       const std::string& commentPrefix)
        : targetFile_(targetFile),
          package_(package),
          packageCpp_(package),
          commentPrefix_(commentPrefix),
          hasCppInterface_(false) {

        // read the existing target file if it exists
        if (FileInfo(targetFile_).exists()) {
            std::ifstream ifs(targetFile_.c_str());		// #nocov start
            if (ifs.fail())
                throw Rcpp::file_io_error(targetFile_);
            std::stringstream buffer;
            buffer << ifs.rdbuf();
            existingCode_ = buffer.str();			// #nocov end
        }

        std::replace(packageCpp_.begin(), packageCpp_.end(), '.', '_');

        // see if this is safe to overwite and throw if it isn't
        if (!isSafeToOverwrite())
            throw Rcpp::file_exists(targetFile_);		// #nocov
    }

    void ExportsGenerator::writeFunctions(
                                const SourceFileAttributes& attributes,
                                bool verbose) {

        if (attributes.hasInterface(kInterfaceCpp))
            hasCppInterface_ = true;				// #nocov

        doWriteFunctions(attributes, verbose);
    }

    // Commit the stream -- is a no-op if the existing code is identical
    // to the generated code. Returns true if data was written and false
    // if it wasn't (throws exception on io error)
    bool ExportsGenerator::commit(const std::string& preamble) {

        // get the generated code
        std::string code = codeStream_.str();

        // if there is no generated code AND the exports file does not
        // currently exist then do nothing
        if (code.empty() && !FileInfo(targetFile_).exists())
            return false;					// #nocov

        // write header/preamble
        std::ostringstream headerStream;
        headerStream << commentPrefix_ << " Generated by using "
                     << "Rcpp::compileAttributes()"
                     << " -> do not edit by hand" << std::endl;
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
                throw Rcpp::file_io_error(targetFile_);		// #nocov

            // write generated code and return
            ofs << generatedCode;
            ofs.close();
            return true;
        }
        else {
            return false;					// #nocov
        }
    }

    // Remove the generated file entirely
    bool ExportsGenerator::remove() {
        return removeFile(targetFile_);
    }

    // Convert a possible dot in package name to underscore as needed for header file
    std::string ExportsGenerator::dotNameHelper(const std::string & name) const {
        std::string newname(name);
        std::replace(newname.begin(), newname.end(), '.', '_');
        return newname;
    }

    CppExportsGenerator::CppExportsGenerator(const std::string& packageDir,
                                             const std::string& package,
                                             const std::string& fileSep)
        : ExportsGenerator(
            packageDir + fileSep + "src" +  fileSep + "RcppExports.cpp",
            package,
            "//")
    {
    }

    void CppExportsGenerator::doWriteFunctions(
                                 const SourceFileAttributes& attributes,
                                 bool verbose) {

        // generate functions
        generateCpp(ostr(),
                    attributes,
                    true,
                    attributes.hasInterface(kInterfaceCpp),
                    packageCppPrefix());

        // track cppExports, signatures, and native routines (we use these
        // at the end to generate the ValidateSignature and RegisterCCallable
        // functions, and to generate a package init function with native
        // routine registration)
        for (SourceFileAttributes::const_iterator		// #nocov start
                   it = attributes.begin(); it != attributes.end(); ++it) {

            if (it->isExportedFunction()) {

                // add it to the cpp exports list if we are generating
                // a C++ interface and it's not hidden
                if (attributes.hasInterface(kInterfaceCpp)) {
                    Function fun = it->function().renamedTo(it->exportedCppName());
                    if (!fun.isHidden())
                        cppExports_.push_back(*it);
                }

                // add it to the native routines list
                nativeRoutines_.push_back(*it);
            } else if (it->name() == kInitAttribute) {
                initFunctions_.push_back(*it);
            }
        }                                               // #nocov end

        // record modules
        const std::vector<std::string>& modules = attributes.modules();
        modules_.insert(modules_.end(), modules.begin(), modules.end());

        // verbose if requested
        if (verbose) {						// #nocov start
            Rcpp::Rcout << "Exports from " << attributes.sourceFile() << ":"
                        << std::endl;
            for (std::vector<Attribute>::const_iterator
                    it = attributes.begin(); it != attributes.end(); ++it) {
                if (it->isExportedFunction())
                    Rcpp::Rcout << "   " << it->function() << std::endl;
            }
            Rcpp::Rcout << std::endl;				// #nocov end
        }
    }

    void CppExportsGenerator::writeEnd(bool hasPackageInit)
    {
        // generate a function that can be used to validate exported
        // functions and their signatures prior to looking up with
        // GetCppCallable (otherwise inconsistent signatures between
        // client and library would cause a crash)
        if (hasCppInterface()) {

            ostr() << std::endl;				// #nocov start
            ostr() << "// validate"
                   << " (ensure exported C++ functions exist before "
                   << "calling them)" << std::endl;
            ostr() << "static int " << exportValidationFunctionRegisteredName()
                   << "(const char* sig) { " << std::endl;
            ostr() << "    static std::set<std::string> signatures;"
                   << std::endl;
            ostr() << "    if (signatures.empty()) {" << std::endl;

            for (std::size_t i=0;i<cppExports_.size(); i++) {
                const Attribute& attr = cppExports_[i];
                ostr() << "        signatures.insert(\""
                       << attr.function().signature(attr.exportedName())
                       << "\");" << std::endl;
            }
            ostr() << "    }" << std::endl;
            ostr() << "    return signatures.find(sig) != signatures.end();"
                   << std::endl;
            ostr() << "}" << std::endl;

            // generate a function that will register all of our C++
            // exports as C-callable from other packages
            ostr() << std::endl;
            ostr() << "// registerCCallable (register entry points for "
                      "exported C++ functions)" << std::endl;
            ostr() << "RcppExport SEXP " << registerCCallableExportedName()
                   << "() { " << std::endl;
            for (std::size_t i=0;i<cppExports_.size(); i++) {
                const Attribute& attr = cppExports_[i];
                ostr() << registerCCallable(
                              4,
                              attr.exportedName(),
                              attr.function().name() + kTrySuffix);
                ostr() << std::endl;
            }
            ostr() << registerCCallable(4,
                                        exportValidationFunction(),
                                        exportValidationFunction());
            ostr() << std::endl;
            ostr() << "    return R_NilValue;" << std::endl;
            ostr() << "}" << std::endl;
         }

         // write native routines
         if (!hasPackageInit && (!nativeRoutines_.empty() || !modules_.empty() || !initFunctions_.empty())) {

            // build list of routines we will register
            std::vector<std::string> routineNames;
            std::vector<std::size_t> routineArgs;
            for (std::size_t i=0;i<nativeRoutines_.size(); i++) {
                const Attribute& attr = nativeRoutines_[i];
                routineNames.push_back(packageCppPrefix() + "_" + attr.function().name());
                routineArgs.push_back(attr.function().arguments().size());
            }
            std::string kRcppModuleBoot = "_rcpp_module_boot_";
            for (std::size_t i=0;i<modules_.size(); i++) {
                routineNames.push_back(kRcppModuleBoot + modules_[i]);
                routineArgs.push_back(0);
            }
            if (hasCppInterface()) {
                routineNames.push_back(registerCCallableExportedName());
                routineArgs.push_back(0);
            }

            // see if there are additional registrations to perform
            Rcpp::Function extraRoutinesFunc = Environment::namespace_env("Rcpp")[".extraRoutineRegistrations"];
            List extraRoutines = extraRoutinesFunc(targetFile(), routineNames);
            std::vector<std::string> declarations = extraRoutines["declarations"];
            std::vector<std::string> callEntries = extraRoutines["call_entries"];

            // add declarations for modules
            for (std::size_t i=0;i<modules_.size(); i++) {
                declarations.push_back("RcppExport SEXP " + kRcppModuleBoot + modules_[i] + "();");
            }

            // generate declarations
            if (declarations.size() > 0) {
                ostr() << std::endl;
                for (std::size_t i = 0; i<declarations.size(); i++)
                    ostr() << declarations[i] << std::endl;
            }

            // generate registration code
            ostr() << std::endl;
            ostr() << "static const R_CallMethodDef CallEntries[] = {" << std::endl;
            for (std::size_t i=0;i<routineNames.size(); i++) {
                ostr() << "    {\"" << routineNames[i] <<  "\", " <<
                    "(DL_FUNC) &" << routineNames[i] << ", " <<
                        routineArgs[i] <<  "}," << std::endl;
            }
            if (callEntries.size() > 0) {
                for (std::size_t i = 0; i<callEntries.size(); i++)
                    ostr() << callEntries[i] << std::endl;
            }
            ostr() << "    {NULL, NULL, 0}" << std::endl;
            ostr() << "};" << std::endl;

            ostr() << std::endl;

            // write prototypes for init functions
            for (std::size_t i = 0; i<initFunctions_.size(); i++) {
                const Function& function = initFunctions_[i].function();
                printFunction(ostr(), function, false);
                ostr() << ";" << std::endl;
            }

            ostr() << "RcppExport void R_init_" << packageCpp() << "(DllInfo *dll) {" << std::endl;
            ostr() << "    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);" << std::endl;
            ostr() << "    R_useDynamicSymbols(dll, FALSE);" << std::endl;
            // call init functions
            for (std::size_t i = 0; i<initFunctions_.size(); i++) {
                const Function& function = initFunctions_[i].function();
                ostr() << "    " << function.name() << "(dll);" << std::endl;
            }
            ostr() << "}" << std::endl;
         }

         // warn if both a hand-written package init function and Rcpp::init are used
         if (hasPackageInit && !initFunctions_.empty()) {
            showWarning("[[Rcpp::init]] attribute used in a package with an explicit "
                        "R_init function (Rcpp::init functions will not be called)");
         }
    }

    std::string CppExportsGenerator::registerCCallable(
                                        size_t indent,
                                        const std::string& exportedName,
                                        const std::string& name) const {
        std::ostringstream ostr;
        std::string indentStr(indent, ' ');
        ostr <<  indentStr << "R_RegisterCCallable(\"" << package() << "\", "
              << "\"" << packageCppPrefix() << "_" << exportedName << "\", "
              << "(DL_FUNC)" << packageCppPrefix() << "_" << name << ");";
        return ostr.str();					// #nocov end
    }

    bool CppExportsGenerator::commit(const std::vector<std::string>& includes) {

        // includes
        std::ostringstream ostr;
        if (!includes.empty()) {
            for (std::size_t i=0;i<includes.size(); i++)
                ostr << includes[i] << std::endl;
        }
        if (hasCppInterface()) {
            ostr << "#include <string>" << std::endl;		// #nocov
            ostr << "#include <set>" << std::endl;		// #nocov
        }
        ostr << std::endl;

        // always bring in Rcpp
        ostr << "using namespace Rcpp;" << std::endl << std::endl;
        // initialize references to global Rostreams
        initializeGlobals(ostr);

        // commit with preamble
        return ExportsGenerator::commit(ostr.str());
    }

    CppExportsIncludeGenerator::CppExportsIncludeGenerator(
                                            const std::string& packageDir,
                                            const std::string& package,
                                            const std::string& fileSep)
        : ExportsGenerator(
            packageDir +  fileSep + "inst" +  fileSep + "include" +
            fileSep + dotNameHelper(package) + kRcppExportsSuffix,
            package,
            "//")
    {
        includeDir_ = packageDir +  fileSep + "inst" +  fileSep + "include";
    }

    void CppExportsIncludeGenerator::writeBegin() {

        ostr() << "namespace " << packageCpp() << " {"
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
        ostr() << "        void validateSignature(const char* sig) {"
               << std::endl;
        ostr() << "            Rcpp::Function require = "
               << "Rcpp::Environment::base_env()[\"require\"];"
               << std::endl;
        ostr() << "            require(\"" << package() << "\", "
               << "Rcpp::Named(\"quietly\") = true);"
               << std::endl;

        std::string validate = "validate";
        std::string fnType = "Ptr_" + validate;
        ostr() << "            typedef int(*" << fnType << ")(const char*);"
               << std::endl;

        std::string ptrName = "p_" + validate;
        ostr() << "            static " << fnType << " " << ptrName << " = "
               << "(" << fnType << ")" << std::endl
               << "                "
               << getCCallable(exportValidationFunctionRegisteredName())
               << ";" << std::endl;
        ostr() << "            if (!" << ptrName << "(sig)) {" << std::endl;
        ostr() << "                throw Rcpp::function_not_exported("
               << std::endl
               << "                    "
               << "\"C++ function with signature '\" + std::string(sig) + \"' not found in " << package()
               << "\");" << std::endl;
        ostr() << "            }" << std::endl;
        ostr() << "        }" << std::endl;

        ostr() << "    }" << std::endl << std::endl;
    }

    void CppExportsIncludeGenerator::doWriteFunctions(
                                    const SourceFileAttributes& attributes,
                                    bool) {

        // don't write anything if there is no C++ interface
        if (!attributes.hasInterface(kInterfaceCpp))
            return;

        for(std::vector<Attribute>::const_iterator		// #nocov start
            it = attributes.begin(); it != attributes.end(); ++it) {

            if (it->isExportedFunction()) {

                Function function =
                    it->function().renamedTo(it->exportedCppName());

                // if it's hidden then don't generate a C++ interface
                if (function.isHidden())
                    continue;

                ostr() << "    inline " << function << " {"
                        << std::endl;

                std::string fnType = "Ptr_" + function.name();
                ostr() << "        typedef SEXP(*" << fnType << ")(";
                for (size_t i=0; i<function.arguments().size(); i++) {
                    ostr() << "SEXP";
                    if (i != (function.arguments().size()-1))
                        ostr() << ",";
                }
                ostr() << ");" << std::endl;

                std::string ptrName = "p_" + function.name();
                ostr() << "        static " << fnType << " "
                       << ptrName << " = NULL;"
                       << std::endl;
                ostr() << "        if (" << ptrName << " == NULL) {"
                       << std::endl;
                ostr() << "            validateSignature"
                       << "(\"" << function.signature() << "\");"
                       << std::endl;
                ostr() << "            " << ptrName << " = "
                       << "(" << fnType << ")"
                       << getCCallable(packageCppPrefix() + "_" + function.name()) << ";"
                       << std::endl;
                ostr() << "        }" << std::endl;
                ostr() << "        RObject rcpp_result_gen;" << std::endl;
                ostr() << "        {" << std::endl;
                if (it->rng())
                    ostr() << "            RNGScope RCPP_rngScope_gen;" << std::endl;
                ostr() << "            rcpp_result_gen = " << ptrName << "(";

                const std::vector<Argument>& args = function.arguments();
                for (std::size_t i = 0; i<args.size(); i++) {
                    ostr() << "Shield<SEXP>(Rcpp::wrap(" << args[i].name() << "))";
                    if (i != (args.size()-1))
                        ostr() << ", ";
                }

                ostr() << ");" << std::endl;
                ostr() << "        }" << std::endl;

                ostr() << "        if (rcpp_result_gen.inherits(\"interrupted-error\"))"
                       << std::endl
                       << "            throw Rcpp::internal::InterruptedException();"
                       << std::endl;
                ostr() << "        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))"
                       << std::endl
                       << "            throw Rcpp::LongjumpException(rcpp_result_gen);"
                       << std::endl;
                ostr() << "        if (rcpp_result_gen.inherits(\"try-error\"))"
                       << std::endl
                       << "            throw Rcpp::exception(Rcpp::as<std::string>("
                       << "rcpp_result_gen).c_str());"
                       << std::endl;
                if (!function.type().isVoid()) {
                    ostr() << "        return Rcpp::as<" << function.type() << " >"
                           << "(rcpp_result_gen);" << std::endl;
                }

                ostr() << "    }" << std::endl << std::endl;	// #nocov end
            }
        }
    }

    void CppExportsIncludeGenerator::writeEnd(bool) {
        ostr() << "}" << std::endl;
        ostr() << std::endl;
        ostr() << "#endif // " << getHeaderGuard() << std::endl;
    }

    bool CppExportsIncludeGenerator::commit(
                                    const std::vector<std::string>& includes) {

        if (hasCppInterface()) {

            // create the include dir if necessary
            createDirectory(includeDir_);			// #nocov start

            // generate preamble
            std::ostringstream ostr;

            // header guard
            std::string guard = getHeaderGuard();
            ostr << "#ifndef " << guard << std::endl;
            ostr << "#define " << guard << std::endl << std::endl;

            // includes
            if (!includes.empty()) {
                for (std::size_t i=0;i<includes.size(); i++)
                {
                    // some special processing is required here. we exclude
                    // the package header file (since it includes this file)
                    // and we transorm _types includes into local includes
                    std::string preamble = "#include \"../inst/include/";
                    std::string pkgInclude = preamble + packageCpp() + ".h\"";
                    if (includes[i] == pkgInclude)
                        continue;

                    // check for _types
                    std::string typesInclude = preamble + packageCpp() + "_types.h";
                    if (includes[i].find(typesInclude) != std::string::npos)
                    {
                        std::string include = "#include \"" +
                                      includes[i].substr(preamble.length());
                        ostr << include << std::endl;
                    }
                    else
                    {
                        ostr << includes[i] << std::endl;
                    }
                }
                ostr << std::endl;
            }

            // commit with preamble
            return ExportsGenerator::commit(ostr.str());		// #nocov end
        }
        else {
            return ExportsGenerator::remove();
        }
    }

    std::string CppExportsIncludeGenerator::getCCallable(
                                        const std::string& function) const {
        std::ostringstream ostr;
        ostr << "R_GetCCallable"
             << "(\"" << package() << "\", "
             << "\"" << function << "\")";
        return ostr.str();
    }

    std::string CppExportsIncludeGenerator::getHeaderGuard() const {
        return "RCPP_" + packageCpp() + "_RCPPEXPORTS_H_GEN_";
    }

    CppPackageIncludeGenerator::CppPackageIncludeGenerator(
                                            const std::string& packageDir,
                                            const std::string& package,
                                            const std::string& fileSep)
        : ExportsGenerator(
            packageDir +  fileSep + "inst" +  fileSep + "include" +
            fileSep + dotNameHelper(package) + ".h",
            package,
            "//")
    {
        includeDir_ = packageDir +  fileSep + "inst" +  fileSep + "include";
    }

    void CppPackageIncludeGenerator::writeEnd(bool) {
        if (hasCppInterface()) {
            // header guard
            std::string guard = getHeaderGuard();			// #nocov start
            ostr() << "#ifndef " << guard << std::endl;
            ostr() << "#define " << guard << std::endl << std::endl;
            ostr() << "#include \"" << packageCpp() << kRcppExportsSuffix
                   << "\"" << std::endl;

            ostr() << std::endl;
            ostr() << "#endif // " << getHeaderGuard() << std::endl;	// #nocov end
        }
    }

    bool CppPackageIncludeGenerator::commit(const std::vector<std::string>&) {
        if (hasCppInterface()) {

            // create the include dir if necessary
            createDirectory(includeDir_);				// #nocov

            // commit
            return ExportsGenerator::commit();				// #nocov
        }
        else {
            return ExportsGenerator::remove();
        }
    }

    std::string CppPackageIncludeGenerator::getHeaderGuard() const {	// #nocov
        return "RCPP_" + packageCpp() + "_H_GEN_";			// #nocov
    }

    RExportsGenerator::RExportsGenerator(const std::string& packageDir,
                                         const std::string& package,
                                         bool registration,
                                         const std::string& fileSep)
        : ExportsGenerator(
            packageDir + fileSep + "R" +  fileSep + "RcppExports.R",
            package,
            "#"),
          registration_(registration)
    {
    }

    void RExportsGenerator::doWriteFunctions(
                                        const SourceFileAttributes& attributes,
                                        bool) {
        // write standalone roxygen chunks
        const std::vector<std::vector<std::string> >& roxygenChunks =
                                                    attributes.roxygenChunks();
        for (std::size_t i = 0; i<roxygenChunks.size(); i++) {
            const std::vector<std::string>& chunk = roxygenChunks[i];	// #nocov start
            for (std::size_t l = 0; l < chunk.size(); l++)
                ostr() << chunk[l] << std::endl;
            ostr() << "NULL" << std::endl << std::endl;			// #nocov end
        }

        // write exported functions
        if (attributes.hasInterface(kInterfaceR)) {
            // process each attribute
            for(std::vector<Attribute>::const_iterator
                it = attributes.begin(); it != attributes.end(); ++it) {

                // alias the attribute and function (bail if not export)
                const Attribute& attribute = *it;
                if (!attribute.isExportedFunction())
                    continue;					// #nocov
                const Function& function = attribute.function();

                // print roxygen lines
                for (size_t i=0; i<attribute.roxygen().size(); i++)
                    ostr() << attribute.roxygen()[i] << std::endl; // #nocov

                // build the parameter list
                std::string args = generateRArgList(function);
                // check if has a custom signature
                if(attribute.hasParameter(kExportSignature)) {
                    args = attribute.customRSignature();
                    if(!checkRSignature(function, args)) {
                        std::string rsig_err_msg = "Missing args in " + args;
                        throw Rcpp::exception(rsig_err_msg.c_str());
                    }
                }
                // determine the function name
                std::string name = attribute.exportedName();

                // determine if return invisible
                bool  isInvisibleOrVoid = function.type().isVoid() || attribute.invisible();

                // write the function
                ostr() << name << " <- function(" << args << ") {"
                       << std::endl;
                ostr() << "    ";
                if (isInvisibleOrVoid)
                    ostr() << "invisible(";			// #nocov
                ostr() << ".Call(";
                if (!registration_)
                    ostr() << "'";				// #nocov
                else
                    ostr() << "`";
                ostr() << packageCppPrefix() << "_" << function.name();
                if (!registration_)
                    ostr() << "', " << "PACKAGE = '" << package() << "'";  // #nocov
                else
                    ostr() << "`";

                // add arguments
                const std::vector<Argument>& arguments = function.arguments();
                for (size_t i = 0; i<arguments.size(); i++)
                    ostr() << ", " << arguments[i].name();	// #nocov
                ostr() << ")";
                if (isInvisibleOrVoid)
                    ostr() << ")";				// #nocov
                ostr() << std::endl;

                ostr() << "}" << std::endl << std::endl;
            }
        }
    }

    void RExportsGenerator::writeEnd(bool) {
        if (hasCppInterface()) {				// #nocov start
             // register all C-callable functions
            ostr() << "# Register entry points for exported C++ functions"
                   << std::endl;
            ostr() << "methods::setLoadAction(function(ns) {" << std::endl;
            ostr() << "    .Call("
                   << (registration_ ? "`" : "'")
                   << registerCCallableExportedName()
                   << (registration_ ? "`" : "'");
            if (!registration_)
                ostr() << ", PACKAGE = '" << package() << "'";
            ostr() << ")"
                   << std::endl << "})" << std::endl;		// #nocov end
        }
    }

    bool RExportsGenerator::commit(const std::vector<std::string>&) {
        return ExportsGenerator::commit();
    }

    ExportsGenerators::~ExportsGenerators() {
        try {
            for(Itr it = generators_.begin(); it != generators_.end(); ++it)
                delete *it;
            generators_.clear();
        }
        catch(...) {}
    }

    void ExportsGenerators::add(ExportsGenerator* pGenerator) {
        generators_.push_back(pGenerator);
    }

    void ExportsGenerators::writeBegin() {
        for(Itr it = generators_.begin(); it != generators_.end(); ++it)
            (*it)->writeBegin();
    }

    void ExportsGenerators::writeFunctions(
                                const SourceFileAttributes& attributes,
                                bool verbose) {
        for(Itr it = generators_.begin(); it != generators_.end(); ++it)
            (*it)->writeFunctions(attributes, verbose);
    }

    void ExportsGenerators::writeEnd(bool hasPackageInit) {
        for(Itr it = generators_.begin(); it != generators_.end(); ++it)
            (*it)->writeEnd(hasPackageInit);
    }

    // Commit and return a list of the files that were updated
    std::vector<std::string> ExportsGenerators::commit(
                            const std::vector<std::string>& includes) {

        std::vector<std::string> updated;

        for(Itr it = generators_.begin(); it != generators_.end(); ++it) {
            if ((*it)->commit(includes))
                updated.push_back((*it)->targetFile());
        }

        return updated;
    }

    // Remove and return a list of files that were removed
    std::vector<std::string> ExportsGenerators::remove() {	// #nocov start
        std::vector<std::string> removed;
        for(Itr it = generators_.begin(); it != generators_.end(); ++it) {
            if ((*it)->remove())
                removed.push_back((*it)->targetFile());
        }
        return removed;
    }


    // Helpers for converting C++  default arguments to R default arguments
    namespace {

        // convert a C++ numeric argument to an R argument value
        // (returns empty string if no conversion is possible)
        std::string cppNumericArgToRArg(const std::string& type,
                                        const std::string& cppArg) {
            // check for a number
            double num;
            std::stringstream argStream(cppArg);
            if ((argStream >> num)) {

                // L suffix means return the value literally
                if (!argStream.eof()) {
                    std::string suffix;
                    argStream >> suffix;
                    if (argStream.eof() && suffix == "L")
                        return cppArg;
                }

                // no decimal and the type isn't explicitly double or
                // float means integer
                if (cppArg.find('.') == std::string::npos &&
                    type != "double" && type != "float")
                    return cppArg + "L";

                // otherwise return arg literally
                else
                    return cppArg;
            }
            else {
                return std::string();
            }
        }

        // convert a C++ ::create style argument value to an R argument
        // value (returns empty string if no conversion is possible)
        std::string cppCreateArgToRArg(const std::string& cppArg) {

            std::string create = "::create";
            size_t createLoc = cppArg.find(create);
            if (createLoc == std::string::npos ||
                ((createLoc + create.length()) >= cppArg.size())) {
                return std::string();
            }

            std::string type = cppArg.substr(0, createLoc);
            std::string rcppScope = "Rcpp::";
            size_t rcppLoc = type.find(rcppScope);
            if (rcppLoc == 0 && type.size() > rcppScope.length())
                type = type.substr(rcppScope.length());

            std::string args = cppArg.substr(createLoc + create.length());
            if (type == "CharacterVector")
                return "as.character( c" + args + ")";
            if (type == "IntegerVector")
                return "as.integer( c" + args + ")";
            if (type == "NumericVector")
                return "as.numeric( c" + args + ")";
            if (type == "LogicalVector")
                return "as.logical( c" + args + ")";

            return std::string();
        }

        // convert a C++ Matrix to an R argument (returns empty string
        // if no conversion possible)
        std::string cppMatrixArgToRArg(const std::string& cppArg) {

            // look for Matrix
            std::string matrix = "Matrix";
            size_t matrixLoc = cppArg.find(matrix);
            if (matrixLoc == std::string::npos ||
                ((matrixLoc + matrix.length()) >= cppArg.size())) {
                return std::string();
            }

            std::string args = cppArg.substr(matrixLoc + matrix.length());
            return "matrix" + args;				// #nocov end
        }

        // convert a C++ literal to an R argument (returns empty string
        // if no conversion possible)
        std::string cppLiteralArgToRArg(const std::string& cppArg) {
            if (cppArg == "true")
                return "TRUE";
            else if (cppArg == "false")
                return "FALSE";
            else if (cppArg == "R_NilValue")
                return "NULL";
            else if (cppArg == "NA_STRING")			// #nocov start
                return "NA_character_";
            else if (cppArg == "NA_INTEGER")
                return "NA_integer_";
            else if (cppArg == "NA_LOGICAL")
                return "NA_integer_";
            else if (cppArg == "NA_REAL")
                return "NA_real_";
            else
                return std::string();
        }

        // convert an Rcpp container constructor to an R argument
        // (returns empty string if no conversion possible)
        std::string cppConstructorArgToRArg(const std::string& cppArg) {

            // map Rcpp containers to R default initializers
            static std::map<std::string, std::string> RcppContainerToR;
            RcppContainerToR.insert(std::make_pair("NumericVector", "numeric"));
            RcppContainerToR.insert(std::make_pair("DoubleVector", "numeric"));
            RcppContainerToR.insert(std::make_pair("CharacterVector", "character"));
            RcppContainerToR.insert(std::make_pair("IntegerVector", "integer"));
            RcppContainerToR.insert(std::make_pair("LogicalVector", "logical"));
            RcppContainerToR.insert(std::make_pair("ComplexVector", "complex"));

            // for each entry in the map above, see if we find it; if we do,
            // return the R version
            typedef std::map<std::string, std::string>::const_iterator Iterator;
            for (Iterator it = RcppContainerToR.begin(); it != RcppContainerToR.end(); ++it) {
                size_t loc = cppArg.find(it->first);
                if (loc != std::string::npos) {
                    return it->second + cppArg.substr(it->first.size(), std::string::npos);
                }
            }

            return std::string();				// #nocov end

        }

        // convert a C++ argument value to an R argument value (returns empty
        // string if no conversion is possible)
        std::string cppArgToRArg(const std::string& type,
                                 const std::string& cppArg) {

            // try for quoted string
            if (isQuoted(cppArg))
                return cppArg;

            // try for literal
            std::string rArg = cppLiteralArgToRArg(cppArg);
            if (!rArg.empty())
                return rArg;

            // try for a create arg
            rArg = cppCreateArgToRArg(cppArg);	    		// #nocov start
            if (!rArg.empty())
                return rArg;

            // try for a matrix arg
            rArg = cppMatrixArgToRArg(cppArg);
            if (!rArg.empty())
                return rArg;

            // try for a numeric arg
            rArg = cppNumericArgToRArg(type, cppArg);
            if (!rArg.empty())
                return rArg;

            // try for a constructor arg
            rArg = cppConstructorArgToRArg(cppArg);
            if (!rArg.empty())
                return rArg;

            // couldn't parse the arg
            return std::string();				// #nocov end
        }

    } // anonymous namespace

    // Generate an R argument list for a function
    std::string generateRArgList(const Function& function) {
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
                    showWarning("Unable to parse C++ default value '" +		// #nocov start
                                argument.defaultValue() + "' for argument "+
                                argument.name() + " of function " +
                                function.name());				// #nocov end
                }
            }

            if (i != (arguments.size()-1))
                argsOstr << ", ";
        }
        return argsOstr.str();
    }

    bool checkRSignature(const Function& function,
                                             std::string args) {
        std::vector<std::string> required_args;
        const std::vector<Argument>& arguments = function.arguments();
        for (size_t i = 0; i<arguments.size(); i++) {
            const Argument& argument = arguments[i];
            required_args.push_back(argument.name());
        }
        args = "function(" + args + ") {}";
        Rcpp::Function parse = Rcpp::Environment::base_env()["parse"];
        Rcpp::Function eval = Rcpp::Environment::base_env()["eval"];
        Rcpp::Function formalArgs =
            Rcpp::Environment::namespace_env("methods")["formalArgs"];

        // If signature fails to parse, allow error to fall through
        // as the error message is generally more descriptive
        CharacterVector pargs_cv = formalArgs(eval(parse(_["text"] = args)));
        std::vector<std::string> parsed_args =
            Rcpp::as<std::vector<std::string> >(pargs_cv);

        for(size_t i=0; i<required_args.size(); ++i) {
            if(std::find(parsed_args.begin(), parsed_args.end(),
                         required_args[i]) == parsed_args.end())
                return false;
        }
        return true;
    }

    // Generate the C++ code required to initialize global objects
    void initializeGlobals(std::ostream& ostr) {
        ostr << "#ifdef RCPP_USE_GLOBAL_ROSTREAM" << std::endl;
        ostr << "Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();";
        ostr << std::endl;
        ostr << "Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();";
        ostr << std::endl;
        ostr << "#endif" << std::endl << std::endl;
    }

    // Generate the C++ code required to make [[Rcpp::export]] functions
    // available as C symbols with SEXP parameters and return
    void generateCpp(std::ostream& ostr,
                     const SourceFileAttributes& attributes,
                     bool includePrototype,
                     bool cppInterface,
                     const std::string& contextId) {

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
                printFunction(ostr, function, false);
                ostr << ";";
            }

            // write the C++ callable SEXP-based function (this version
            // returns errors via "try-error")
            ostr << std::endl;
            ostr << (cppInterface ? "static" : "RcppExport");
            ostr << " SEXP ";
            std::string funcName = contextId + "_" + function.name();
            ostr << funcName;
            if (cppInterface)
                ostr << kTrySuffix;				// #nocov
            ostr << "(";
            std::ostringstream ostrArgs;
            const std::vector<Argument>& arguments = function.arguments();
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                ostrArgs << "SEXP " << argument.name() << "SEXP";
                if (i != (arguments.size()-1))
                    ostrArgs << ", ";
            }
            std::string args = ostrArgs.str();
            ostr << args << ") {" << std::endl;
            ostr << "BEGIN_RCPP" << std::endl;
            if (!function.type().isVoid())
                ostr << "    Rcpp::RObject rcpp_result_gen;" << std::endl;
            if (!cppInterface && attribute.rng())
                ostr << "    Rcpp::RNGScope rcpp_rngScope_gen;" << std::endl;
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];

                ostr << "    Rcpp::traits::input_parameter< "
                     << argument.type().full_name() << " >::type " << argument.name()
                     << "(" << argument.name() << "SEXP);" << std::endl;
            }

            ostr << "    ";
            if (!function.type().isVoid())
                ostr << "rcpp_result_gen = Rcpp::wrap(";
            ostr << function.name() << "(";
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                ostr << argument.name();
                if (i != (arguments.size()-1))
                    ostr << ", ";
            }
            if (!function.type().isVoid())
                ostr << ")";
            ostr << ");" << std::endl;

            if (!function.type().isVoid())
            {
                ostr << "    return rcpp_result_gen;" << std::endl;
            }
            else
            {
                ostr << "    return R_NilValue;" << std::endl;
            }
            ostr << (cppInterface ? "END_RCPP_RETURN_ERROR" : "END_RCPP")
                 << std::endl;
            ostr << "}" << std::endl;

            // Now write an R wrapper that returns error via Rf_error
            if (cppInterface) {
                ostr << "RcppExport SEXP " << funcName << "(" << args << ") {"	// #nocov start
                     << std::endl;
                ostr << "    SEXP rcpp_result_gen;" << std::endl;
                ostr << "    {" << std::endl;
                if (attribute.rng())
                    ostr << "        Rcpp::RNGScope rcpp_rngScope_gen;" << std::endl;
                ostr << "        rcpp_result_gen = PROTECT(" << funcName
                     << kTrySuffix << "(";
                for (size_t i = 0; i<arguments.size(); i++) {
                    const Argument& argument = arguments[i];
                    ostr << argument.name() << "SEXP";
                    if (i != (arguments.size()-1))
                        ostr << ", ";
                }
                ostr << "));" << std::endl;
                ostr << "    }" << std::endl;
                ostr << "    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, \"interrupted-error\");"
                     << std::endl
                     << "    if (rcpp_isInterrupt_gen) {" << std::endl
                     << "        UNPROTECT(1);" << std::endl
                     << "        Rf_onintr();" << std::endl
                     << "    }" << std::endl
                     << "    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);" << std::endl
                     << "    if (rcpp_isLongjump_gen) {" << std::endl
                                 // No need to unprotect before jump
                     << "        Rcpp::internal::resumeJump(rcpp_result_gen);" << std::endl
                     << "    }" << std::endl
                     << "    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, \"try-error\");"
                     << std::endl
                     << "    if (rcpp_isError_gen) {" << std::endl
                     << "        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);" << std::endl
                     << "        UNPROTECT(1);" << std::endl
                     << "        Rf_error(CHAR(rcpp_msgSEXP_gen));" << std::endl
                     << "    }" << std::endl
                     << "    UNPROTECT(1);" << std::endl
                     << "    return rcpp_result_gen;" << std::endl
                     << "}" << std::endl;				// #nocov end
            }
        }
    }

} // namespace attributes
} // namespace Rcpp





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
                throw Rcpp::file_io_error(errno, path);				// #nocov
        } else {
            exists_ = true;
            lastModified_ = static_cast<double>(buffer.st_mtime);
        }
    }

    // Remove a file (call back into R for this)
    bool removeFile(const std::string& path) {
        if (FileInfo(path).exists()) {
            Rcpp::Function rm = Rcpp::Environment::base_env()["file.remove"];	// #nocov start
            rm(path);
            return true;							// #nocov end
        }
        else {
            return false;
        }
    }

    // Recursively create a directory (call back into R for this)
    void createDirectory(const std::string& path) {				// #nocov start
        if (!FileInfo(path).exists()) {
            Rcpp::Function mkdir = Rcpp::Environment::base_env()["dir.create"];
            mkdir(path, Rcpp::Named("recursive") = true);
        }
    }										// #nocov end

     // Known whitespace chars
    const char * const kWhitespaceChars = " \f\n\r\t\v";

    // Query whether a character is whitespace
    bool isWhitespace(char ch) {
        return std::strchr(kWhitespaceChars, ch) != NULL;
    }

    // Remove trailing line comments -- ie, find comments that don't begin
    // a line, and remove them. We avoid stripping attributes.
    void stripTrailingLineComments(std::string* pStr) {

        if (pStr->empty()) return;

        size_t len = pStr->length();
        bool inString = false;
        size_t idx = 0;

        // if this is an roxygen comment, then bail
        if (isRoxygenCpp(*pStr)) return;

        // skip over initial whitespace
        idx = pStr->find_first_not_of(kWhitespaceChars);
        if (idx == std::string::npos) return;

        // skip over a first comment
        if (idx + 1 < len && pStr->at(idx) == '/' && pStr->at(idx + 1) == '/') {
            idx = idx + 2;
        }

        // since we are searching for "//", we iterate up to 2nd last character
        while (idx < len - 1) {

            if (inString) {
                if (pStr->at(idx) == '"' && pStr->at(idx - 1) != '\\') {
                    inString = false;
                }
            } else {
                if (pStr->at(idx) == '"') {
                    inString = true;
                }
            }

            if (!inString &&
                pStr->at(idx) == '/' &&
                pStr->at(idx + 1) == '/') {
                pStr->erase(idx);
                return;
            }
            ++idx;
        }
    }

    // Trim a string
    void trimWhitespace(std::string* pStr) {

        // skip empty case
        if (pStr->empty())
            return;							// #nocov

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
            *pStr = pStr->substr(1, pStr->length()-2);			// #nocov
    }

    // is the passed string quoted?
    bool isQuoted(const std::string& str) {
        if (str.length() < 2)
            return false;						// #nocov
        char quote = *(str.begin());
        return (quote == '\'' || quote == '\"') && (*(str.rbegin()) == quote);
    }

    // does a string end with another string?
    bool endsWith(const std::string& str, const std::string& suffix)
    {
        return str.size() >= suffix.size() &&
               str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    // show a warning message
    void showWarning(const std::string& msg) {				// #nocov start
        Rcpp::Function warning = Rcpp::Environment::base_env()["warning"];
        warning(msg, Rcpp::Named("call.") = false);
    }									// #nocov end

    bool isRoxygenCpp(const std::string& str) {
        size_t len = str.length();
        if (len < 3) return false;
        size_t idx = str.find_first_not_of(kWhitespaceChars);
        if (idx == std::string::npos) return false;

        // make sure there are characters to check
        if (len - 2 < idx) return false;

        if (str[idx] == '/' &&
            str[idx + 1] == '/' &&
            str[idx + 2] == '\'') {
            return true;
        }

        return false;

    }

} // namespace attributes
} // namespace Rcpp


/*******************************************************************
 * Attributes.cpp
 *******************************************************************/

using namespace Rcpp::attributes;

// Implementation helpers for sourceCppContext
namespace {

    // Class that manages generation of source code for the sourceCpp dynlib
    class SourceCppDynlib {
    public:
        SourceCppDynlib() {}

        SourceCppDynlib(const std::string& cacheDir,
                        const std::string& cppSourcePath,
                        Rcpp::List platform)
            :  cppSourcePath_(cppSourcePath)

        {
            // get cpp source file info
            FileInfo cppSourceFilenameInfo(cppSourcePath_);
            if (!cppSourceFilenameInfo.exists())
                throw Rcpp::file_not_found(cppSourcePath_);		// #nocov

            // record the base name of the source file
            Rcpp::Function basename = Rcpp::Environment::base_env()["basename"];
            cppSourceFilename_ = Rcpp::as<std::string>(basename(cppSourcePath_));

            // get platform info
            fileSep_ = Rcpp::as<std::string>(platform["file.sep"]);
            dynlibExt_ = Rcpp::as<std::string>(platform["dynlib.ext"]);

            // generate temp directory
            Rcpp::Function tempfile = Rcpp::Environment::base_env()["tempfile"];
            buildDirectory_ = Rcpp::as<std::string>(tempfile("sourcecpp_", cacheDir));
            std::replace(buildDirectory_.begin(), buildDirectory_.end(), '\\', '/');
            Rcpp::Function dircreate = Rcpp::Environment::base_env()["dir.create"];
            dircreate(buildDirectory_);

            // generate a random context id
            contextId_ = "sourceCpp_" + uniqueToken(cacheDir);

            // regenerate the source code
            regenerateSource(cacheDir);
        }

        // create from list
        explicit SourceCppDynlib(const Rcpp::List& dynlib)
        {
            using namespace Rcpp;

            cppSourcePath_ = as<std::string>(dynlib["cppSourcePath"]);
            generatedCpp_ = as<std::string>(dynlib["generatedCpp"]);
            cppSourceFilename_ = as<std::string>(dynlib["cppSourceFilename"]);
            contextId_ = as<std::string>(dynlib["contextId"]);
            buildDirectory_ = as<std::string>(dynlib["buildDirectory"]);
            fileSep_ = as<std::string>(dynlib["fileSep"]);
            dynlibFilename_ = as<std::string>(dynlib["dynlibFilename"]);
            previousDynlibFilename_ = as<std::string>(dynlib["previousDynlibFilename"]);
            dynlibExt_ = as<std::string>(dynlib["dynlibExt"]);
            exportedFunctions_ = as<std::vector<std::string> >(dynlib["exportedFunctions"]);
            modules_ = as<std::vector<std::string> >(dynlib["modules"]);
            depends_ = as<std::vector<std::string> >(dynlib["depends"]);
            plugins_ = as<std::vector<std::string> >(dynlib["plugins"]);
            embeddedR_ = as<std::vector<std::string> >(dynlib["embeddedR"]);
            List sourceDependencies = as<List>(dynlib["sourceDependencies"]);
            for (R_xlen_t i = 0; i<sourceDependencies.length(); i++) {
                List fileInfo = as<List>(sourceDependencies.at(i));	// #nocov
                sourceDependencies_.push_back(FileInfo(fileInfo)); 	// #nocov
            }
        }

        // convert to list
        Rcpp::List toList() const {
            using namespace Rcpp;
            List dynlib;
            dynlib["cppSourcePath"] = cppSourcePath_;
            dynlib["generatedCpp"] = generatedCpp_;
            dynlib["cppSourceFilename"] = cppSourceFilename_;
            dynlib["contextId"] = contextId_;
            dynlib["buildDirectory"] = buildDirectory_;
            dynlib["fileSep"] = fileSep_;
            dynlib["dynlibFilename"] = dynlibFilename_;
            dynlib["previousDynlibFilename"] = previousDynlibFilename_;
            dynlib["dynlibExt"] = dynlibExt_;
            dynlib["exportedFunctions"] = exportedFunctions_;
            dynlib["modules"] = modules_;
            dynlib["depends"] = depends_;
            dynlib["plugins"] = plugins_;
            dynlib["embeddedR"] = embeddedR_;
            List sourceDependencies;
            for (std::size_t i = 0; i<sourceDependencies_.size(); i++) {
                FileInfo fileInfo = sourceDependencies_.at(i);
                sourceDependencies.push_back(fileInfo.toList());
            }
            dynlib["sourceDependencies"] = sourceDependencies;

            return dynlib;
        }

        bool isEmpty() const { return cppSourcePath_.empty(); }

        bool isBuilt() const { return FileInfo(dynlibPath()).exists(); };

        bool isSourceDirty() const {
            // source file out of date means we're dirty
            if (FileInfo(cppSourcePath_).lastModified() >
                FileInfo(generatedCppSourcePath()).lastModified())
                return true;				// #nocov

            // no dynlib means we're dirty
            if (!FileInfo(dynlibPath()).exists())
                return true;				// #nocov

            // variation in source dependencies means we're dirty
            std::vector<FileInfo> sourceDependencies = parseSourceDependencies(
                                                            cppSourcePath_);
            if (sourceDependencies != sourceDependencies_)
                return true;				// #nocov

            // not dirty
            return false;
        }

        void regenerateSource(const std::string& cacheDir) {

            // create new dynlib filename
            previousDynlibFilename_ = dynlibFilename_;
            dynlibFilename_ = "sourceCpp_" + uniqueToken(cacheDir) + dynlibExt_;

            // copy the source file to the build dir
            Rcpp::Function filecopy = Rcpp::Environment::base_env()["file.copy"];
            filecopy(cppSourcePath_, generatedCppSourcePath(), true);

            // parse attributes
            SourceFileAttributesParser sourceAttributes(cppSourcePath_, "", true);

            // generate cpp for attributes and append them
            std::ostringstream ostr;
            // always include Rcpp.h in case the user didn't
            ostr << std::endl << std::endl;
            ostr << "#include <Rcpp.h>" << std::endl;
            // initialize references to global Rostreams
            initializeGlobals(ostr);
            generateCpp(ostr, sourceAttributes, true, false, contextId_);
            generatedCpp_ = ostr.str();
            std::ofstream cppOfs(generatedCppSourcePath().c_str(),
                                 std::ofstream::out | std::ofstream::app);
            if (cppOfs.fail())
                throw Rcpp::file_io_error(generatedCppSourcePath());	// #nocov
            cppOfs << generatedCpp_;
            cppOfs.close();

            // generate R for attributes and write it into the build directory
            std::ofstream rOfs(generatedRSourcePath().c_str(),
                               std::ofstream::out | std::ofstream::trunc);
            if (rOfs.fail())
                throw Rcpp::file_io_error(generatedRSourcePath());	// #nocov

            // DLLInfo - hide using . and ensure uniqueness using contextId
            std::string dllInfo = "`." + contextId_ + "_DLLInfo`";
            rOfs << dllInfo << " <- dyn.load('" << dynlibPath() << "')"
                 << std::endl << std::endl;

            // Generate R functions
            generateR(rOfs, sourceAttributes, dllInfo);

            // remove the DLLInfo
            rOfs << std::endl << "rm(" << dllInfo << ")"
                 << std::endl;

            rOfs.close();

            // discover exported functions and dependencies
            exportedFunctions_.clear();
            depends_.clear();
            plugins_.clear();
            for (SourceFileAttributesParser::const_iterator
              it = sourceAttributes.begin(); it != sourceAttributes.end(); ++it) {

                 if (it->name() == kExportAttribute && !it->function().empty())
                    exportedFunctions_.push_back(it->exportedName());

                 else if (it->name() == kDependsAttribute) {
                     for (size_t i = 0; i<it->params().size(); ++i)	// #nocov
                        depends_.push_back(it->params()[i].name());	// #nocov
                 }

                 else if (it->name() == kPluginsAttribute) {
                     for (size_t i = 0; i<it->params().size(); ++i)
                        plugins_.push_back(it->params()[i].name());
                 }
            }

            // capture modules
            modules_ = sourceAttributes.modules();

            // capture embededded R
            embeddedR_ = sourceAttributes.embeddedR();

            // capture source dependencies
            sourceDependencies_ = sourceAttributes.sourceDependencies();
        }

        const std::string& contextId() const {
            return contextId_;
        }

        const std::string& cppSourcePath() const {
            return cppSourcePath_;
        }

        const std::vector<std::string> cppDependencySourcePaths() {
            std::vector<std::string> dependencies;
            for (size_t i = 0; i<sourceDependencies_.size(); ++i) {
                FileInfo dep = sourceDependencies_[i];
                if (dep.extension() == ".cc" || dep.extension() == ".cpp") {
                    dependencies.push_back(dep.path());			// #nocov
                }
            }
            return dependencies;
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
            return dynlibFilename_;
        }

        std::string dynlibPath() const {
            return buildDirectory_ + fileSep_ + dynlibFilename();
        }

        std::string previousDynlibPath() const {
            if (!previousDynlibFilename_.empty())
                return buildDirectory_ + fileSep_ + previousDynlibFilename_;	// #nocov
            else
                return std::string();
        }

        const std::vector<std::string>& exportedFunctions() const {
            return exportedFunctions_;
        }

        const std::vector<std::string>& modules() const {
            return modules_;
        }

        const std::vector<std::string>& depends() const { return depends_; };

        const std::vector<std::string>& plugins() const { return plugins_; };

        const std::vector<std::string>& embeddedR() const { return embeddedR_; }

    private:

        std::string generatedCppSourcePath() const {
           return buildDirectory_ + fileSep_ + cppSourceFilename();
        }

         std::string generatedRSourcePath() const {
           return buildDirectory_ + fileSep_ + rSourceFilename();
        }

        void generateR(std::ostream& ostr,
                       const SourceFileAttributes& attributes,
                       const std::string& dllInfo) const
        {
            // process each attribute
            for(std::vector<Attribute>::const_iterator
                it = attributes.begin(); it != attributes.end(); ++it) {

                // alias the attribute and function (bail if not export)
                const Attribute& attribute = *it;
                if (!attribute.isExportedFunction())
                    continue;
                const Function& function = attribute.function();

                // build the parameter list
                std::string args = generateRArgList(function);

                // check if has a custom signature
                if(attribute.hasParameter(kExportSignature)) {
                    args = attribute.customRSignature();
                    if(!checkRSignature(function, args)) {
                        std::string rsig_err_msg = "Missing args in " + args;
                        throw Rcpp::exception(rsig_err_msg.c_str());
                    }
                }

                // export the function
                ostr <<  attribute.exportedName()
                     << " <- Rcpp:::sourceCppFunction("
                     << "function(" << args << ") {}, "
                     << (function.type().isVoid() ? "TRUE" : "FALSE") << ", "
                     << dllInfo << ", "
                     << "'" << contextId_ + "_" + function.name()
                     << "')" << std::endl;
            }

            // modules
            std::vector<std::string> modules = attributes.modules();
            if (modules.size() > 0)
            {
                // modules require definition of C++Object to be loaded
                ostr << "library(Rcpp)" << std::endl;

                // load each module
                for (std::vector<std::string>::const_iterator
                    it = modules.begin(); it != modules.end(); ++it)
                {
                    ostr << " populate( Rcpp::Module(\"" << *it << "\","
                         << dllInfo << "), environment() ) " << std::endl;
                }
            }

        }

        std::string uniqueToken(const std::string& cacheDir) {
            Rcpp::Environment rcppEnv = Rcpp::Environment::namespace_env("Rcpp");
            Rcpp::Function uniqueTokenFunc = rcppEnv[".sourceCppDynlibUniqueToken"];
            return Rcpp::as<std::string>(uniqueTokenFunc(cacheDir));
        }

    private:
        std::string cppSourcePath_;
        std::string generatedCpp_;
        std::string cppSourceFilename_;
        std::string contextId_;
        std::string buildDirectory_;
        std::string fileSep_;
        std::string dynlibFilename_;
        std::string previousDynlibFilename_;
        std::string dynlibExt_;
        std::vector<std::string> exportedFunctions_;
        std::vector<std::string> modules_;
        std::vector<std::string> depends_;
        std::vector<std::string> plugins_;
        std::vector<std::string> embeddedR_;
        std::vector<FileInfo> sourceDependencies_;
    };

    // Dynlib cache that allows lookup by either file path or code contents

    void dynlibCacheInsert(const std::string& cacheDir,
                           const std::string& file,
                           const std::string& code,
                           const SourceCppDynlib& dynlib)
    {
        Rcpp::Environment rcppEnv = Rcpp::Environment::namespace_env("Rcpp");
        Rcpp::Function dynlibInsertFunc = rcppEnv[".sourceCppDynlibInsert"];
        dynlibInsertFunc(cacheDir, file, code, dynlib.toList());
    }

    void dynlibCacheInsertFile(const std::string& cacheDir,
                               const std::string& file,
                               const SourceCppDynlib& dynlib)
    {
        dynlibCacheInsert(cacheDir, file, "", dynlib);
    }

    void dynlibCacheInsertCode(const std::string& cacheDir,
                               const std::string& code,
                               const SourceCppDynlib& dynlib)
    {
        dynlibCacheInsert(cacheDir, "", code, dynlib);
    }

    SourceCppDynlib dynlibCacheLookup(const std::string& cacheDir,
                                      const std::string& file,
                                      const std::string& code)
    {
        Rcpp::Environment rcppEnv = Rcpp::Environment::namespace_env("Rcpp");
        Rcpp::Function dynlibLookupFunc = rcppEnv[".sourceCppDynlibLookup"];
        Rcpp::List dynlibList = dynlibLookupFunc(cacheDir, file, code);
        if (dynlibList.length() > 0)
            return SourceCppDynlib(dynlibList);
        else
            return SourceCppDynlib();
    }

    SourceCppDynlib dynlibCacheLookupByFile(const std::string& cacheDir,
                                            const std::string& file)
    {
        return dynlibCacheLookup(cacheDir, file, "");
    }

    SourceCppDynlib dynlibCacheLookupByCode(const std::string& cacheDir,
                                            const std::string& code)
    {
        return dynlibCacheLookup(cacheDir, "", code);
    }

} // anonymous namespace

// Create temporary build directory, generate code as necessary, and return
// the context required for the sourceCpp function to complete it's work
RcppExport SEXP sourceCppContext(SEXP sFile, SEXP sCode,
                                 SEXP sRebuild, SEXP sCacheDir, SEXP sPlatform) {
BEGIN_RCPP
    // parameters
    std::string file = Rcpp::as<std::string>(sFile);
    std::string code = sCode != R_NilValue ? Rcpp::as<std::string>(sCode) : "";
    bool rebuild = Rcpp::as<bool>(sRebuild);
    std::string cacheDir = Rcpp::as<std::string>(sCacheDir);
    Rcpp::List platform = Rcpp::as<Rcpp::List>(sPlatform);

    // get dynlib (using cache if possible)
    SourceCppDynlib dynlib = !code.empty() ? dynlibCacheLookupByCode(cacheDir, code)
                                           : dynlibCacheLookupByFile(cacheDir, file);

    // check dynlib build state
    bool buildRequired = false;

    // if there is no dynlib in the cache then create a new one
    if (dynlib.isEmpty()) {
        buildRequired = true;
        dynlib = SourceCppDynlib(cacheDir, file, platform);
    }

    // if the cached dynlib is dirty then regenerate the source
    else if (rebuild || dynlib.isSourceDirty()) {
        buildRequired = true;				// #nocov
        dynlib.regenerateSource(cacheDir);		// #nocov
    }

    // if the dynlib hasn't yet been built then note that
    else if (!dynlib.isBuilt()) {
        buildRequired = true;				// #nocov
    }

    // save the dynlib to the cache
    if (!code.empty())
        dynlibCacheInsertCode(cacheDir, code, dynlib);
    else
        dynlibCacheInsertFile(cacheDir, file, dynlib);

    // return context as a list
    using namespace Rcpp;
    return List::create(
        _["contextId"] = dynlib.contextId(),
        _["cppSourcePath"] = dynlib.cppSourcePath(),
        _["cppDependencySourcePaths"] = dynlib.cppDependencySourcePaths(),
        _["buildRequired"] = buildRequired,
        _["buildDirectory"] = dynlib.buildDirectory(),
        _["generatedCpp"] = dynlib.generatedCpp(),
        _["exportedFunctions"] = dynlib.exportedFunctions(),
        _["modules"] = dynlib.modules(),
        _["cppSourceFilename"] = dynlib.cppSourceFilename(),
        _["rSourceFilename"] = dynlib.rSourceFilename(),
        _["dynlibFilename"] = dynlib.dynlibFilename(),
        _["dynlibPath"] = dynlib.dynlibPath(),
        _["previousDynlibPath"] = dynlib.previousDynlibPath(),
        _["depends"] = dynlib.depends(),
        _["plugins"] = dynlib.plugins(),
        _["embeddedR"] = dynlib.embeddedR());
END_RCPP
}

// Compile the attributes within the specified package directory into
// RcppExports.cpp and RcppExports.R
RcppExport SEXP compileAttributes(SEXP sPackageDir,
                                  SEXP sPackageName,
                                  SEXP sDepends,
                                  SEXP sRegistration,
                                  SEXP sCppFiles,
                                  SEXP sCppFileBasenames,
                                  SEXP sIncludes,
                                  SEXP sVerbose,
                                  SEXP sPlatform) {
BEGIN_RCPP
    // arguments
    std::string packageDir = Rcpp::as<std::string>(sPackageDir);
    std::string packageName = Rcpp::as<std::string>(sPackageName);

    Rcpp::CharacterVector vDepends = Rcpp::as<Rcpp::CharacterVector>(sDepends);
    std::set<std::string> depends;
    for (Rcpp::CharacterVector::iterator
                        it = vDepends.begin(); it != vDepends.end(); ++it) {
        depends.insert(std::string(*it));
    }

    bool registration = Rcpp::as<bool>(sRegistration);

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
    generators.add(new RExportsGenerator(packageDir, packageName, registration, fileSep));

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
    bool hasPackageInit = false;
    bool haveAttributes = false;
    std::set<std::string> dependsAttribs;
    for (std::size_t i=0; i<cppFiles.size(); i++) {

        // don't process RcppExports.cpp
        std::string cppFile = cppFiles[i];
        if (endsWith(cppFile, "RcppExports.cpp"))
            continue;						// #nocov

        // parse file
        SourceFileAttributesParser attributes(cppFile, packageName, false);

        // note if we found a package init function
        if (!hasPackageInit && attributes.hasPackageInit())
            hasPackageInit = true;				// #nocov

        // continue if no generator output
        if (!attributes.hasGeneratorOutput())
            continue;						// #nocov

        // confirm we have attributes
        haveAttributes = true;

        // write functions
        generators.writeFunctions(attributes, verbose);

        // track depends
        for (SourceFileAttributesParser::const_iterator
                     it = attributes.begin(); it != attributes.end(); ++it) {
            if (it->name() == kDependsAttribute) {
                for (size_t i = 0; i<it->params().size(); ++i)		// #nocov
                    dependsAttribs.insert(it->params()[i].name());	// #nocov
            }
        }
    }

    // write end
    generators.writeEnd(hasPackageInit);

    // commit or remove
    std::vector<std::string> updated;
    if (haveAttributes)
        updated = generators.commit(includes);
    else
        updated = generators.remove();					// #nocov

    // print warning if there are depends attributes that don't have
    // corresponding entries in the DESCRIPTION file
    std::vector<std::string> diff;
    std::set_difference(dependsAttribs.begin(), dependsAttribs.end(),
                        depends.begin(), depends.end(),
                        std::back_inserter(diff));
    if (!diff.empty()) {
        std::string msg =						// #nocov start
           "The following packages are referenced using Rcpp::depends "
           "attributes however are not listed in the Depends, Imports or "
           "LinkingTo fields of the package DESCRIPTION file: ";
        for (size_t i=0; i<diff.size(); i++) {
            msg += diff[i];
            if (i != (diff.size()-1))
                msg += ", ";
        }
        showWarning(msg);
    }

    // verbose output
    if (verbose) {
        for (size_t i=0; i<updated.size(); i++)
            Rcpp::Rcout << updated[i] << " updated." << std::endl;	// #nocov end
    }

    // return files updated
    return Rcpp::wrap<std::vector<std::string> >(updated);
END_RCPP
}
