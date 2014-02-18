// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// attributes.cpp: Rcpp R/C++ interface class library -- Rcpp attributes
//
// Copyright (C) 2012 - 2013 JJ Allaire, Dirk Eddelbuettel and Romain Francois
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
        explicit FileInfo(const std::string& path);
        
        std::string path() const { return path_; }
        bool exists() const { return exists_; }
        time_t lastModified() const { return lastModified_; }
        
    private:
        std::string path_;
        bool exists_;
        time_t lastModified_;
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
    
    // Strip balanced quotes from around a string (assumes already trimmed)
    void stripQuotes(std::string* pStr); 
    
    // is the passed string quoted?
    bool isQuoted(const std::string& str);
    
    // show a warning message
    void showWarning(const std::string& msg);
    
} // namespace attributes
} // namespace Rcpp


/*******************************************************************
 * AttributesTypes.h
 *******************************************************************/

namespace Rcpp {
namespace attributes {
     
    // Known attribute names & parameters
    const char * const kExportAttribute = "export";
    const char * const kDependsAttribute = "depends";
    const char * const kPluginsAttribute = "plugins";
    const char * const kInterfacesAttribute = "interfaces";
    const char * const kInterfaceR = "r";
    const char * const kInterfaceCpp = "cpp";
     
    // Type info
    class Type {
    public:
        Type() {}
        Type(const std::string& name, bool isConst, bool isReference)
            : name_(name), isConst_(isConst), isReference_(isReference)
        {
        }
        bool empty() const { return name().empty(); }
        
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
                 const std::vector<Argument>& arguments,
                 const std::string& source)
            : type_(type), name_(name), arguments_(arguments), source_(source)
        {
        }
        
        Function renamedTo(const std::string& name) const {
            return Function(type(), name, arguments(), source());
        }
        
        std::string signature() const { return signature(name()); }
        std::string signature(const std::string& name) const;
        
        bool isHidden() const {
            return name().find_first_of('.') == 0;
        }
        
        bool empty() const { return name().empty(); }
        
        const Type& type() const { return type_; }
        const std::string& name() const { return name_; }
        const std::vector<Argument>& arguments() const { return arguments_; }
        const std::string& source() const { return source_; }
        
    private:
        Type type_;
        std::string name_;
        std::vector<Argument> arguments_;
        std::string source_;
    };
    
    // Attribute parameter (with optional value)
    class Param {
    public:
        Param() {}
        explicit Param(const std::string& paramText);
        bool empty() const { return name().empty(); }
        
        const std::string& name() const { return name_; }
        const std::string& value() const { return value_; }
       
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
        
        bool empty() const { return name().empty(); }
        
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
            if (!params().empty())
                return params()[0].name();
            else
                return function().name();
        }
        
        const std::vector<std::string>& roxygen() const { return roxygen_; }
        
    private:
        std::string name_;
        std::vector<Param> params_;
        Function function_;
        std::vector<std::string> roxygen_;
    };

    class FunctionMap {
        std::map< std::string, std::vector<Function> > map_ ;
        
    public:
        FunctionMap(){};
        ~FunctionMap(){} ;
        
        void insert( const Function& fun ){
            map_[ fun.name() ].push_back( fun ) ;
        }
    } ;
    
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
        explicit SourceFileAttributesParser(const std::string& sourceFile);
        
    private:
        // prohibit copying
        SourceFileAttributesParser(const SourceFileAttributesParser&);
        SourceFileAttributesParser& operator=(const SourceFileAttributesParser&); 
        
    public:
        // implemetnation of SourceFileAttributes interface
        virtual const std::string& sourceFile() const { 
            return sourceFile_; 
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
                    return it->hasParameter(name);
                }
            }
            
            // if there's no interfaces attrbute we default to R
            if (name == kInterfaceR)
                return true;
            else
                return false;            
        }
        
        // Get lines of embedded R code
        const std::vector<std::string>& embeddedR() const {
            return embeddedR_;
        }
         
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
        FunctionMap functionMap_ ;
        std::vector<std::string> modules_;
        std::vector<std::string> embeddedR_;
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
        
        // Abstract interface for code generation
        virtual void writeBegin() = 0;
        void writeFunctions(const SourceFileAttributes& attributes,
                            bool verbose); // see doWriteFunctions below
        virtual void writeEnd() = 0;
        
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
            return package() + "_" + exportValidationFunction();
        } 
        std::string registerCCallableExportedName() {
            return package() + "_RcppExport_registerCCallable";
        }

        // Commit the stream -- is a no-op if the existing code is identical
        // to the generated code. Returns true if data was written and false
        // if it wasn't (throws exception on io error)
        bool commit(const std::string& preamble = std::string()); 
        
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
        virtual void writeEnd();
        virtual bool commit(const std::vector<std::string>& includes); 
        
    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose);
                                    
        std::string registerCCallable(size_t indent,
                                      const std::string& exportedName,
                                      const std::string& name) const;
        
    private:
        std::vector<Attribute> cppExports_;
    };
       
    // Class which manages generating PackageName_RcppExports.h header file
    class CppExportsIncludeGenerator : public ExportsGenerator {
    public:
        CppExportsIncludeGenerator(const std::string& packageDir, 
                                   const std::string& package,
                                   const std::string& fileSep);
         
        virtual void writeBegin(); 
        virtual void writeEnd(); 
        virtual bool commit(const std::vector<std::string>& includes); 
        
    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose);
        std::string getCCallable(const std::string& function) const; 
        std::string getHeaderGuard() const; 
        
    private:
        std::string includeDir_;
    };
    
    // Class which manages generating PackageName_RcppExports.h header file
    class CppPackageIncludeGenerator : public ExportsGenerator {
    public:
        CppPackageIncludeGenerator(const std::string& packageDir, 
                                   const std::string& package,
                                   const std::string& fileSep);
            
        virtual void writeBegin() {}
        virtual void writeEnd(); 
        virtual bool commit(const std::vector<std::string>& includes); 
        
    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose) {}
        std::string getHeaderGuard() const; 
        
    private:
        std::string includeDir_;
    };
    
    
    // Class which manages generator RcppExports.R
    class RExportsGenerator : public ExportsGenerator {
    public:
        RExportsGenerator(const std::string& packageDir,
                          const std::string& package,
                          const std::string& fileSep);
        
        virtual void writeBegin() {}
        virtual void writeEnd(); 
        virtual bool commit(const std::vector<std::string>& includes); 
        
    private:
        virtual void doWriteFunctions(const SourceFileAttributes& attributes,
                                      bool verbose);

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
        void writeEnd(); 
        
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
        
        // Parse embedded R code chunks from a file (receives the lines of the 
        // file as a CharcterVector for using with regexec and as a standard
        // stl vector for traversal/insepection)
        std::vector<std::string> parseEmbeddedR(
                                        Rcpp::CharacterVector linesVector,
                                        const std::deque<std::string>& lines) {
            Rcpp::List matches = regexMatches(linesVector, 
                                              "^\\s*/\\*{3,}\\s+[Rr]\\s*$");
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
                    withinRBlock = true;
                } 
                else if (withinRBlock) {
                    if (commentState.inComment())
                        embeddedR.push_back(line);
                    else
                        withinRBlock = false;
                }
            }
              
            return embeddedR;
        }
        
    } // anonymous namespace
    
    
    // Generate a type signature for the function with the provided name
    // (type signature == function pointer declaration)
    std::string Function::signature(const std::string& name) const {
        
        std::ostringstream ostr;
        
        ostr << type() << "(*" << name << ")(";
        
        const std::vector<Argument>& args = arguments();
        for (std::size_t i = 0; i<args.size(); i++) {
            ostr << args[i].type();
            if (i != (args.size()-1))
                ostr << ",";
        }
        ostr << ")";
        
        return ostr.str();
    }
    

    // Parse attribute parameter from parameter text
    Param::Param(const std::string& paramText)
    {
        // parse out name/value pair if there is one 
        std::string::size_type pos = paramText.find("=") ;
        if ( pos != std::string::npos ) {
            // name
            name_ = paramText.substr(0, pos);
            trimWhitespace(&name_);
            // value
            value_ = paramText.substr(pos + 1) ;
            trimWhitespace(&value_);
            stripQuotes(&value_);
        }
        else {
            name_ = paramText;  
            stripQuotes(&name_);
        }
    }
    
    // Check if the attribute has a parameter of a paricular name
    Param Attribute::paramNamed(const std::string& name) const {
        for (std::vector<Param>::const_iterator 
          it = params_.begin(); it != params_.end(); ++it) {
            if (it->name() == name)
                return *it;
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
    
    // Argument operator <<
    std::ostream& operator<<(std::ostream& os, const Argument& argument) {
        if (!argument.empty()) {
            os << argument.type();
            if (!argument.name().empty()) {
                os << " ";
                os << argument.name();
                if (!argument.defaultValue().empty())
                    os << " = " << argument.defaultValue();
            }
        }
        return os;
    }
        
    // Function operator <<
    std::ostream& operator<<(std::ostream& os, const Function& function) {
        if (!function.empty()) {
            if (!function.type().empty()) {
                os << function.type();
                os << " ";
            }
            os << function.name();
            os << "(";
            const std::vector<Argument>& arguments = function.arguments();
            for (std::size_t i = 0; i<arguments.size(); i++) {
                os << arguments[i];
                if (i != (arguments.size()-1))
                    os << ", ";
            }
            os << ")";
        }
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
        return os;
    }
      
    // Parse the attributes from a source file
    SourceFileAttributesParser::SourceFileAttributesParser
                                            (const std::string& sourceFile)
        : sourceFile_(sourceFile)
    { 
        // First read the entire file into a std::stringstream so we can check
        // it for attributes (we don't want to do any of our more expensive 
        // processing steps if there are no attributes to parse)
        std::ifstream ifs(sourceFile_.c_str());
        if (ifs.fail())
            throw Rcpp::file_io_error(sourceFile_);
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string contents = buffer.str();
        
        // Check for attribute signature
        if (contents.find("[[Rcpp::") != std::string::npos ||
            contents.find("RCPP_MODULE") != std::string::npos) { 
            
            // Now read into a list of strings (which we can pass to regexec)
            // First read into a std::deque (which will handle lots of append
            // operations efficiently) then copy into an R chracter vector
            std::string line;
            std::deque<std::string> lines;
            while(std::getline(buffer, line)) {
                // strip \r (for the case of windows line terminators on posix)
                if (line.length() > 0 && *line.rbegin() == '\r')
                    line.erase(line.length()-1, 1);
                lines.push_back(line);
            }
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
                        continue;
                    
                    // add the attribute
                    Attribute attr = parseAttribute(
                        Rcpp::as<std::vector<std::string> >(match),  i); 
                    attributes_.push_back(attr);
                    
                    if( attr.isExportedFunction() ){
                        functionMap_.insert(attr.function());
                    }
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
                        roxygenChunks_.push_back(roxygenBuffer_);   
                        roxygenBuffer_.clear();
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
            
            // Parse embedded R
            embeddedR_ = parseEmbeddedR(lines_, lines);
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
            attributeWarning("Unrecognized attribute Rcpp::" + name, 
                             lineNumber);
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
        
        // special handling for export
        if (name == kExportAttribute) {
             
            // parse the function (unless we are at the end of the file in
            // which case we print a warning)
            if ((lineNumber + 1) < lines_.size())
                function = parseFunction(lineNumber + 1);
            else 
                rcppExportWarning("No function found", lineNumber);    
        }  
        
        // validate interfaces parameter
        else if (name == kInterfacesAttribute) {
            if (params.empty()) {
                rcppInterfacesWarning("No interfaces specified", lineNumber);
            }
            else {
                for (std::size_t i=0; i<params.size(); i++) {
                    std::string param = params[i].name();
                    if (param != kInterfaceR && param != kInterfaceCpp) {
                        rcppInterfacesWarning(
                            "Unknown interface '" + param + "'", lineNumber);
                    }
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
    
        const std::string delimiters(" ,");
        
        std::vector<Param> params;
        std::string::size_type current;
        std::string::size_type next = -1;
        do {
            next = input.find_first_not_of(delimiters, next + 1);
            if (next == std::string::npos)
                break;
            next -= 1;
            current = next + 1;
            next = input.find_first_of(delimiters, current);
            params.push_back(Param(input.substr(current, next - current)));
        } while(next != std::string::npos);
        
        return params;
    }

    // Parse a function from the specified spot in the source file
    Function SourceFileAttributesParser::parseFunction(size_t lineNumber) {
        
        // Establish the text to parse for the signature 
        std::string signature = parseSignature(lineNumber);
        if (signature.empty()) {
            rcppExportNoFunctionFoundWarning(lineNumber);  
            return Function();
        }
            
        // Start at the end and look for the () that deliniates the arguments
        // (bail with an empty result if we can't find them)
        std::string::size_type endParenLoc = signature.find_last_of(')');
        std::string::size_type beginParenLoc = signature.find_first_of('(');
        if (endParenLoc == std::string::npos || 
            beginParenLoc == std::string::npos ||
            endParenLoc < beginParenLoc) {
                
            rcppExportNoFunctionFoundWarning(lineNumber);  
            return Function(); 
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
                    continue;
            } else { 
                name.insert(0U, 1U, ch);
            }
        }
        
        // If we didn't find a name then bail
        if (name.empty()) {
            rcppExportNoFunctionFoundWarning(lineNumber); 
            return Function();
        }
        
        // If we didn't find a type then bail
        if (type.empty()) {
            rcppExportWarning("No function return type found", lineNumber);
            return Function();
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
                continue;
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
                name = arg.substr(pos);
                trimWhitespace(&name);
            }
            if (name.empty()) {
                rcppExportInvalidParameterWarning(arg, lineNumber);
                return Function();
            }
            
            // check for type string
            Type type = parseType(arg.substr(0, pos));
            if (type.empty()) {
                rcppExportInvalidParameterWarning(arg, lineNumber);
                return Function();
            }
            
            // add argument
            arguments.push_back(Argument(name, type, defaultValue));
        }
        
        return Function(type, name, arguments, signature);
    }
    
    
    // Parse the text of a function signature from the specified line
    std::string SourceFileAttributesParser::parseSignature(size_t lineNumber) {
        
        // Look for the next {
        std::string signature;
        for (int i = lineNumber; i<lines_.size(); i++) {
            std::string line;
            line = lines_[i];
            std::string::size_type bracePos = line.find('{');
            if (bracePos == std::string::npos) {
                signature.append(line);
                signature.push_back(' ');
            } else {
                signature.append(line.substr(0, bracePos));
                return signature;
            }
        }
        
        // Not found
        return std::string();
    }


    // Parse arguments from function signature. This is tricky because commas
    // are used to delimit arguments but are also valid inside template type
    // qualifiers.
    std::vector<std::string> SourceFileAttributesParser::parseArguments(
                                                const std::string& argText) {
        
        int templateCount = 0;
        int parenCount = 0;
        bool insideQuotes = false;
        std::string currentArg;
        std::vector<std::string> args;
        char prevChar = 0;
        for (std::string::const_iterator 
                            it = argText.begin(); it != argText.end(); ++it) {
            char ch = *it;
            
            if (ch == '"' && prevChar != '\\') {
                insideQuotes = !insideQuotes;
            }
              
            if ((ch == ',') && 
                (templateCount == 0) &&
                (parenCount == 0) &&
                !insideQuotes) {
                args.push_back(currentArg);
                currentArg.clear();
                continue;
            } else {
                currentArg.push_back(ch); 
                switch(ch) {
                    case '<':
                        templateCount++;
                        break;
                    case '>':
                        templateCount--;
                        break;
                    case '(':
                        parenCount++;
                        break;
                    case ')':
                        parenCount--;
                        break;
                }
            }
            
            prevChar = ch;
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
            return Type();
        
        if (type.find(referenceQualifier) == 
            (type.length() - referenceQualifier.length())) {
            isReference = true;
            type.erase(type.length() - referenceQualifier.length());
        }
        trimWhitespace(&type);
        
        // if the type is now empty because of some strange parse then bail
        if (type.empty())
            return Type();
          
        return Type(type, isConst, isReference);
    }
    
    // Validation helpers
    
    bool SourceFileAttributesParser::isKnownAttribute(const std::string& name) 
                                                                        const {
        return name == kExportAttribute || 
               name == kDependsAttribute ||
               name == kPluginsAttribute ||
               name == kInterfacesAttribute;
    }

    // Print an attribute parsing related warning
    void SourceFileAttributesParser::attributeWarning(
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
    }
    

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
                    break;
                
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
          commentPrefix_(commentPrefix),
          hasCppInterface_(false) {
        
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
    
    void ExportsGenerator::writeFunctions(
                                const SourceFileAttributes& attributes,
                                bool verbose) {
        
        if (attributes.hasInterface(kInterfaceCpp))
            hasCppInterface_ = true;
            
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
    
    // Remove the generated file entirely
    bool ExportsGenerator::remove() {
        return removeFile(targetFile_);
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
                    package());
         
        // track cppExports and signatures (we use these at the end to
        // generate the ValidateSignature and RegisterCCallable functions)
        if (attributes.hasInterface(kInterfaceCpp)) {
            for (SourceFileAttributes::const_iterator 
                       it = attributes.begin(); it != attributes.end(); ++it) {
                if (it->isExportedFunction()) {
                    // add it to the list if it's not hidden
                    Function fun = it->function().renamedTo(it->exportedName());
                    if (!fun.isHidden())
                        cppExports_.push_back(*it);
                }
            }
        }
     
        // verbose if requested
        if (verbose) {
            Rcpp::Rcout << "Exports from " << attributes.sourceFile() << ":" 
                        << std::endl;
            for (std::vector<Attribute>::const_iterator 
                    it = attributes.begin(); it != attributes.end(); ++it) {
                if (it->isExportedFunction())
                    Rcpp::Rcout << "   " << it->function() << std::endl; 
            }
            Rcpp::Rcout << std::endl;   
        }
    }
    
    void CppExportsGenerator::writeEnd()
    {
        // generate a function that can be used to validate exported
        // functions and their signatures prior to looking up with
        // GetCppCallable (otherwise inconsistent signatures between
        // client and library would cause a crash)
        if (hasCppInterface()) {
            
            ostr() << std::endl;
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
                std::string name = package() + "_" + attr.exportedName();
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
    }
    
    std::string CppExportsGenerator::registerCCallable(
                                        size_t indent,
                                        const std::string& exportedName,
                                        const std::string& name) const {
        std::ostringstream ostr;
        std::string indentStr(indent, ' ');
        ostr <<  indentStr << "R_RegisterCCallable(\"" << package() << "\", "
              << "\"" << package() << "_" << exportedName << "\", "
              << "(DL_FUNC)" << package() << "_" << name << ");";  
        return ostr.str();                  
    }
    
    bool CppExportsGenerator::commit(const std::vector<std::string>& includes) {
                   
        // includes 
        std::ostringstream ostr;
        if (!includes.empty()) {
            for (std::size_t i=0;i<includes.size(); i++)
                ostr << includes[i] << std::endl;
        }
        if (hasCppInterface()) {
            ostr << "#include <string>" << std::endl;
            ostr << "#include <set>" << std::endl;
        }
        ostr << std::endl;
        
        // always bring in Rcpp
        ostr << "using namespace Rcpp;" << std::endl << std::endl;
        
        // commit with preamble
        return ExportsGenerator::commit(ostr.str());                  
    }
    
    CppExportsIncludeGenerator::CppExportsIncludeGenerator(
                                            const std::string& packageDir, 
                                            const std::string& package,
                                            const std::string& fileSep)
        : ExportsGenerator( 
            packageDir +  fileSep + "inst" +  fileSep + "include" +
            fileSep + package + kRcppExportsSuffix, 
            package,
            "//")
    {
        includeDir_ = packageDir +  fileSep + "inst" +  fileSep + "include";
    }
        
    void CppExportsIncludeGenerator::writeBegin() {
        
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
                                    bool verbose) {
                                    
        // don't write anything if there is no C++ interface
        if (!attributes.hasInterface(kInterfaceCpp)) 
            return;
                                    
        for(std::vector<Attribute>::const_iterator 
            it = attributes.begin(); it != attributes.end(); ++it) {
     
            if (it->isExportedFunction()) {
                
                Function function = 
                    it->function().renamedTo(it->exportedName());
                    
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
                       << getCCallable(package() + "_" + function.name()) << ";" 
                       << std::endl;
                ostr() << "        }" << std::endl;
                ostr() << "        RObject __result;" << std::endl;
                ostr() << "        {" << std::endl;
                ostr() << "            RNGScope __rngScope;" << std::endl;
                ostr() << "            __result = " << ptrName << "(";
                
                const std::vector<Argument>& args = function.arguments();
                for (std::size_t i = 0; i<args.size(); i++) {
                    ostr() << "Rcpp::wrap(" << args[i].name() << ")";
                    if (i != (args.size()-1))
                        ostr() << ", ";
                }
                       
                ostr() << ");" << std::endl;
                ostr() << "        }" << std::endl;
                
                ostr() << "        if (__result.inherits(\"interrupted-error\"))" 
                       << std::endl
                       << "            throw Rcpp::internal::InterruptedException();"
                       << std::endl;
                ostr() << "        if (__result.inherits(\"try-error\"))" 
                       << std::endl
                       << "            throw Rcpp::exception(as<std::string>("
                       << "__result).c_str());"
                       << std::endl;
                ostr() << "        return Rcpp::as<" << function.type() << " >"
                       << "(__result);" << std::endl;
                
                ostr() << "    }" << std::endl << std::endl;
            } 
        }                           
    }
    
    void CppExportsIncludeGenerator::writeEnd() {
        ostr() << "}" << std::endl;
        ostr() << std::endl;
        ostr() << "#endif // " << getHeaderGuard() << std::endl;
    }
    
    bool CppExportsIncludeGenerator::commit(
                                    const std::vector<std::string>& includes) {
        
        if (hasCppInterface()) {
            
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
                {
                    // don't do inst/include here
                    if (includes[i].find("#include \"../inst/include/")
                                                       == std::string::npos)
                    {
                        ostr << includes[i] << std::endl;
                    }
                }
                ostr << std::endl;
            }
            
            // commit with preamble
            return ExportsGenerator::commit(ostr.str());
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
        return "__" + package() + "_RcppExports_h__";
    }
    
    CppPackageIncludeGenerator::CppPackageIncludeGenerator(
                                            const std::string& packageDir, 
                                            const std::string& package,
                                            const std::string& fileSep)
        : ExportsGenerator( 
            packageDir +  fileSep + "inst" +  fileSep + "include" +
            fileSep + package + ".h", 
            package,
            "//")
    {
        includeDir_ = packageDir +  fileSep + "inst" +  fileSep + "include";
    }
    
    void CppPackageIncludeGenerator::writeEnd() {
        if (hasCppInterface()) {
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
    
    bool CppPackageIncludeGenerator::commit(
                                const std::vector<std::string>& includes) {
        
        if (hasCppInterface()) {
            
            // create the include dir if necessary
            createDirectory(includeDir_);
            
            // commit 
            return ExportsGenerator::commit();
        }
        else {
            return ExportsGenerator::remove();
        }
    }
    
    std::string CppPackageIncludeGenerator::getHeaderGuard() const {
        return "__" + package() + "_h__";
    }
    
    RExportsGenerator::RExportsGenerator(const std::string& packageDir,
                                         const std::string& package,
                                         const std::string& fileSep)
        : ExportsGenerator(
            packageDir + fileSep + "R" +  fileSep + "RcppExports.R", 
            package,
            "#")
    {
    }
    
    void RExportsGenerator::doWriteFunctions(
                                        const SourceFileAttributes& attributes,
                                        bool verbose) {
        
        // write standalone roxygen chunks
        const std::vector<std::vector<std::string> >& roxygenChunks = 
                                                    attributes.roxygenChunks();
        for (std::size_t i = 0; i<roxygenChunks.size(); i++) {
            const std::vector<std::string>& chunk = roxygenChunks[i];
            for (std::size_t l = 0; l < chunk.size(); l++)
                ostr() << chunk[l] << std::endl;
            ostr() << "NULL" << std::endl << std::endl;
        }
        
        // write exported functions
        if (attributes.hasInterface(kInterfaceR)) {    
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
                    ostr() << attribute.roxygen()[i] << std::endl;
                        
                // build the parameter list 
                std::string args = generateRArgList(function);
                
                // determine the function name
                std::string name = attribute.exportedName();
                    
                // write the function
                ostr() << name << " <- function(" << args << ") {" 
                       << std::endl;
                ostr() << "    ";
                if (function.type().isVoid())
                    ostr() << "invisible(";
                ostr() << ".Call(";
                ostr() << "'" << package() << "_" << function.name() << "', "
                       << "PACKAGE = '" << package() << "'";
                
                // add arguments
                const std::vector<Argument>& arguments = function.arguments();
                for (size_t i = 0; i<arguments.size(); i++)
                    ostr() << ", " << arguments[i].name();
                ostr() << ")";
                if (function.type().isVoid())
                    ostr() << ")";
                ostr() << std::endl;
            
                ostr() << "}" << std::endl << std::endl;
            }           
        }                      
    }
    
    void RExportsGenerator::writeEnd() { 
        if (hasCppInterface()) {
             // register all C-callable functions
            ostr() << "# Register entry points for exported C++ functions"
                   << std::endl;
            ostr() << "methods::setLoadAction(function(ns) {" << std::endl;
            ostr() << "    .Call('" << registerCCallableExportedName()
                   << "', PACKAGE = '" << package() << "')" 
                   << std::endl << "})" << std::endl;
        }
    }
    
    bool RExportsGenerator::commit(const std::vector<std::string>& includes) {
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
    
    void ExportsGenerators::writeEnd() {
        for(Itr it = generators_.begin(); it != generators_.end(); ++it)
            (*it)->writeEnd();
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
    std::vector<std::string> ExportsGenerators::remove() {
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
            return "matrix" + args;
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
            else if (cppArg == "NA_STRING")
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
            
            return std::string();
            
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
            rArg = cppCreateArgToRArg(cppArg);
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
            return std::string();
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
                    showWarning("Unable to parse C++ default value '" +
                                argument.defaultValue() + "' for argument "+
                                argument.name() + " of function " +
                                function.name());
                }
            }
               
            if (i != (arguments.size()-1))
                argsOstr << ", ";
        }
        return argsOstr.str();
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
                ostr << function << ";";
            }
               
            // write the C++ callable SEXP-based function (this version
            // returns errors via "try-error")
            ostr << std::endl;
            ostr << (cppInterface ? "static" : "RcppExport"); 
            ostr << " SEXP ";
            std::string funcName = contextId + "_" + function.name();
            ostr << funcName;
            if (cppInterface)
                ostr << kTrySuffix;
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
                ostr << "    SEXP __sexp_result;" << std::endl;
            ostr << "    {" << std::endl;
            if (!cppInterface)
                ostr << "        Rcpp::RNGScope __rngScope;" << std::endl;
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                
                ostr << "        Rcpp::traits::input_parameter< " 
                     << argument.type().full_name() << " >::type " << argument.name() 
                     << "(" << argument.name() << "SEXP );" << std::endl;
            }
            
            ostr << "        ";
            if (!function.type().isVoid())
                ostr << function.type() << " __result = ";
            ostr << function.name() << "(";
            for (size_t i = 0; i<arguments.size(); i++) {
                const Argument& argument = arguments[i];
                ostr << argument.name();
                if (i != (arguments.size()-1))
                    ostr << ", ";
            }
            ostr << ");" << std::endl;
        
            if (!function.type().isVoid())
            {
                ostr << "        PROTECT(__sexp_result = Rcpp::wrap(__result));"
                     << std::endl;
            }
            ostr << "    }" << std::endl;
            if (!function.type().isVoid())
            {
                ostr << "    UNPROTECT(1);" << std::endl;
                ostr << "    return __sexp_result;" << std::endl;
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
                ostr << "RcppExport SEXP " << funcName << "(" << args << ") {"
                     << std::endl;
                ostr << "    SEXP __result;" << std::endl;
                ostr << "    {" << std::endl;
                ostr << "        Rcpp::RNGScope __rngScope;" << std::endl;
                ostr << "        __result = PROTECT(" << funcName 
                     << kTrySuffix << "(";
                for (size_t i = 0; i<arguments.size(); i++) {
                    const Argument& argument = arguments[i];
                    ostr << argument.name() << "SEXP";
                    if (i != (arguments.size()-1))
                        ostr << ", ";
                }
                ostr << "));" << std::endl;
                ostr << "    }" << std::endl;
                ostr << "    Rboolean __isInterrupt = Rf_inherits(__result, \"interrupted-error\");"
                     << std::endl
                     << "    if (__isInterrupt) {" << std::endl
                     << "        UNPROTECT(1);" << std::endl
                     << "        Rf_onintr();" << std::endl
                     << "    }" << std::endl
                     << "    Rboolean __isError = Rf_inherits(__result, \"try-error\");"
                     << std::endl
                     << "    if (__isError) {" << std::endl
                     << "        SEXP __msgSEXP = Rf_asChar(__result);" << std::endl
                     << "        UNPROTECT(1);" << std::endl
                     << "        Rf_error(CHAR(__msgSEXP));" << std::endl
                     << "    }" << std::endl
                     << "    UNPROTECT(1);" << std::endl
                     << "    return __result;" << std::endl
                     << "}" << std::endl;
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
            contextId_ = "sourceCpp_" + createRandomizer();
            
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
            
            // create new dynlib filename
            previousDynlibFilename_ = dynlibFilename_;
            dynlibFilename_ = "sourceCpp_" + createRandomizer() + dynlibExt_;
            
            // copy the source file to the build dir
            Rcpp::Function filecopy = Rcpp::Environment::base_env()["file.copy"];
            filecopy(cppSourcePath_, generatedCppSourcePath(), true);
            
            // parse attributes
            SourceFileAttributesParser sourceAttributes(cppSourcePath_);
        
            // generate cpp for attributes and append them 
            std::ostringstream ostr;
            // always include Rcpp.h in case the user didn't
            ostr << std::endl << std::endl;
            ostr << "#include <Rcpp.h>" << std::endl;
            generateCpp(ostr, sourceAttributes, false, false, contextId_);
            generatedCpp_ = ostr.str();
            std::ofstream cppOfs(generatedCppSourcePath().c_str(), 
                                 std::ofstream::out | std::ofstream::app);
            if (cppOfs.fail())
                throw Rcpp::file_io_error(generatedCppSourcePath());
            cppOfs << generatedCpp_;
            cppOfs.close();
        
            // generate R for attributes and write it into the build directory
            std::ofstream rOfs(generatedRSourcePath().c_str(), 
                               std::ofstream::out | std::ofstream::trunc);
            if (rOfs.fail())
                throw Rcpp::file_io_error(generatedRSourcePath());
                
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
                     for (size_t i = 0; i<it->params().size(); ++i)
                        depends_.push_back(it->params()[i].name());
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
            return dynlibFilename_;
        }
        
        std::string dynlibPath() const {
            return buildDirectory_ + fileSep_ + dynlibFilename();
        }
        
        std::string previousDynlibPath() const {
            if (!previousDynlibFilename_.empty())
                return buildDirectory_ + fileSep_ + previousDynlibFilename_;
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
        
                // export the function
                ostr <<  attribute.exportedName()
                     << " <- Rcpp:::sourceCppFunction("
                     << "function(" << generateRArgList(function) << ") {}, " 
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
        
        std::string createRandomizer() {
            Rcpp::Function sample = Rcpp::Environment::base_env()["sample"];
            std::ostringstream ostr;
            ostr << Rcpp::as<int>(sample(100000, 1));
            return ostr.str();
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
RcppExport SEXP sourceCppContext(SEXP sFile, SEXP sCode, 
                                 SEXP sRebuild, SEXP sPlatform) {
BEGIN_RCPP
    // parameters
    std::string file = Rcpp::as<std::string>(sFile);
    std::string code = sCode != R_NilValue ? Rcpp::as<std::string>(sCode) : "";
    bool rebuild = Rcpp::as<bool>(sRebuild);
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
    else if (rebuild || pDynlib->isSourceDirty()) {
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
        _["modules"] = pDynlib->modules(),
        _["cppSourceFilename"] = pDynlib->cppSourceFilename(),
        _["rSourceFilename"] = pDynlib->rSourceFilename(),
        _["dynlibFilename"] = pDynlib->dynlibFilename(),
        _["dynlibPath"] = pDynlib->dynlibPath(),
        _["previousDynlibPath"] = pDynlib->previousDynlibPath(),
        _["depends"] = pDynlib->depends(),
        _["plugins"] = pDynlib->plugins(),
        _["embeddedR"] = pDynlib->embeddedR());
END_RCPP
}

// Compile the attributes within the specified package directory into 
// RcppExports.cpp and RcppExports.R
RcppExport SEXP compileAttributes(SEXP sPackageDir, 
                                  SEXP sPackageName,
                                  SEXP sDepends,
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
    std::set<std::string> dependsAttribs;
    for (std::size_t i=0; i<cppFiles.size(); i++) {
        
        // parse file (continue if there is no generator output)
        std::string cppFile = cppFiles[i];
        SourceFileAttributesParser attributes(cppFile);
        if (!attributes.hasGeneratorOutput())
            continue;
            
        // confirm we have attributes
        haveAttributes = true;
               
        // write functions
        generators.writeFunctions(attributes, verbose);
        
        // track depends
        for (SourceFileAttributesParser::const_iterator 
                     it = attributes.begin(); it != attributes.end(); ++it) {
            if (it->name() == kDependsAttribute) {
                for (size_t i = 0; i<it->params().size(); ++i)
                    dependsAttribs.insert(it->params()[i].name());
            }   
        }
    }
    
    // write end
    generators.writeEnd();

    // commit or remove
    std::vector<std::string> updated;
    if (haveAttributes)
        updated = generators.commit(includes);  
    else
        updated = generators.remove();
           
    // print warning if there are depends attributes that don't have 
    // corresponding entries in the DESCRIPTION file
    std::vector<std::string> diff;
    std::set_difference(dependsAttribs.begin(), dependsAttribs.end(),
                        depends.begin(), depends.end(), 
                        std::back_inserter(diff));
    if (!diff.empty()) {
        std::string msg = 
           "The following packages are referenced using Rcpp::depends "
           "attributes however are not listed in the Depends and LinkingTo "
           "fields of the package DESCRIPTION file: ";
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
            Rcpp::Rcout << updated[i] << " updated." << std::endl;
    }
    
    // return files updated
    return Rcpp::wrap<std::vector<std::string> >(updated);
END_RCPP
}

