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

namespace {

// Some parsing utilities

#define kWhitespaceChars " \f\n\r\t\v"

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
    
    bool isVoid() const { return name() == "void"; }
    bool isConst() const { return isConst_; }
    bool isReference() const { return isReference_; }
    
private:
    std::string name_;
    bool isConst_;
    bool isReference_;
};

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
  
// Argument info
class Argument {
public:
    Argument() {}
    Argument(const std::string& name, const Type& type) 
        : name_(name), type_(type) 
    {
    }
    
    bool empty() const { return type().empty(); }
    
    const std::string& name() const { return name_; }
    const Type& type() const { return type_; }
    
private:
    std::string name_;
    Type type_;
};

std::ostream& operator<<(std::ostream& os, const Argument& argument) {
    if (!argument.empty()) {
        os << argument.type();
        if (!argument.name().empty()) {
            os << " ";
            os << argument.name();
        }
    }
    return os;
}

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

// Attribute parameter (with optional value)
class Param {
public:
    Param() {}
    explicit Param(const std::string& paramText)
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
    
    bool empty() const { return name().empty(); }
    
    const std::string& name() const { return name_; }
    const std::string& value() const { return value_; }
   
private:
    std::string name_;
    std::string value_;
};

std::ostream& operator<<(std::ostream& os, const Param& param) {
    if (!param.empty()) {
        os << param.name();
        if (!param.value().empty())
            os << "=" << param.value();
    }
    return os;    
}

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
     
    Param paramNamed(const std::string& name) const {
        for (std::vector<Param>::const_iterator 
          it = params_.begin(); it != params_.end(); ++it) {
            if (it->name() == name)
                return *it;
        }
        return Param();
    }
     
    bool hasParameter(const std::string& name) const {
        return !paramNamed(name).empty();
    }
    
    const Function& function() const { return function_; }
    
    const std::vector<std::string>& roxygen() const { return roxygen_; }
    
private:
    std::string name_;
    std::vector<Param> params_;
    Function function_;
    std::vector<std::string> roxygen_;
};

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

// Known attribute and param names
#define kExportAttribute        "export"
#define kDependsAttribute       "depends"

// Class used to parse and return attribute information from a source file
class SourceFileAttributes {
public:
    explicit SourceFileAttributes(const std::string& sourceFile)
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
        if (contents.find("[[Rcpp::") != std::string::npos) { 
            
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
            Rcpp::Environment base("package:base");
            Rcpp::Function regexec = base["regexec"];
            Rcpp::Function regmatches = base["regmatches"];
            Rcpp::RObject result =  regexec(
                "^\\s*//\\s+\\[\\[Rcpp::(\\w+)(\\(.*?\\))?\\]\\]\\s*$", lines_);
            Rcpp::List matches = regmatches(lines_, result);
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
                    attributes_.push_back(parseAttribute(
                        Rcpp::as<std::vector<std::string> >(match),  i));
                } 
                
                // if it's not an attribute line then it could still be a 
                // line of interest (using namespace or roxygen comment)
                else {
                    
                    // save global namespace imports (need to bring these over
                    // to RcppExports.cpp to ensure type names all work)
                    if (line.find("using namespace") == 0) {
                        std::string namespaceLine = line;
                        trimWhitespace(&namespaceLine);
                        if (*(namespaceLine.rbegin()) == ';')
                            namespaces_.push_back(namespaceLine);
                    }
                    
                    // look for roxygen comments
                    else if (line.find("//'") == 0) {
                        std::string roxLine = "#" + line.substr(2);
                        roxygenBuffer_.push_back(roxLine);
                    }
                } 
            }
        }       
    }
 
private:
    // prohibit copying
    SourceFileAttributes(const SourceFileAttributes&);
    SourceFileAttributes& operator=(const SourceFileAttributes&); 
    
public:
    const std::string& sourceFile() const { 
        return sourceFile_; 
    }
    
    // Iteration over attributes
    typedef std::vector<Attribute>::const_iterator const_iterator;
    const_iterator begin() const { return attributes_.begin(); }
    const_iterator end() const { return attributes_.end(); }
    bool empty() const { return attributes_.empty(); }
    
    // namespace imports
    const std::vector<std::string>& namespaces() const {
        return namespaces_;
    }
   
private:

    // Parse an attribute from the vector returned by regmatches
    Attribute parseAttribute(const std::vector<std::string>& match,
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
            
            // we know from the regex that it's enclosed in parens so remove them
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
        
        // Return attribute
        Attribute attribute = Attribute(name, params, function, roxygenBuffer_);
        roxygenBuffer_.clear();
        return attribute;
    }
    
    // Parse attribute parameters 
    std::vector<Param> parseParameters(const std::string& input) {
    
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
    Function parseFunction(size_t lineNumber) {
        
        // Establish the text to parse for the signature 
        std::string signature = parseSignature(lineNumber);
        if (signature.empty()) {
            rcppExportNoFunctionFoundWarning(lineNumber);  
            return Function();
        }
            
        // Start at the end and look for the () that deliniates the arguments
        // (bail with an empty result if we can't find them)
        std::string::size_type endParenLoc = signature.find_last_of(')');
        std::string::size_type beginParenLoc = signature.find_last_of('(');
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
        std::string preambleText = signature.substr(0, beginParenLoc);
        for (std::string::const_reverse_iterator 
            it = preambleText.rbegin(); it != preambleText.rend(); ++it) {
            char ch = *it;
            if (isWhitespace(ch)) {
                if (!name.empty()) {
                    // we are at the break between type and name so we can also
                    // extract the type
                    std::string typeText;
                    while (++it != preambleText.rend())
                        typeText.insert(0, 1, *it);    
                    type = parseType(typeText);
                    
                    // break (since we now have the name and the type)
                    break;   
                }
                else
                    continue;
            } else { 
                name.insert(0, 1, ch);
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
            arguments.push_back(Argument(name, type));
        }
        
        return Function(type, name, arguments, signature);
    }
    
    
    // Parse the text of a function signature from the specified line
    std::string parseSignature(size_t lineNumber) {
        
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
    std::vector<std::string> parseArguments(const std::string& argText) {
        
        int templateCount = 0;
        std::string currentArg;
        std::vector<std::string> args;
        for (std::string::const_iterator 
                            it = argText.begin(); it != argText.end(); ++it) {
            char ch = *it;
            
            if (ch == ',' && templateCount == 0) {
                args.push_back(currentArg);
                currentArg.clear();
                continue;
            } else {
                currentArg.push_back(ch);   
                if (ch == '<')
                    templateCount++;
                else if (ch == '>')
                    templateCount--;
            }
        }
        
        if (!currentArg.empty())
            args.push_back(currentArg);
        
        return args;
    }
    
    Type parseType(const std::string& text) {
        
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
        
        // again, if the type is now empty because of some strange parse then bail
        if (type.empty())
            return Type();
            
        return Type(type, isConst, isReference);
    }
    
    // Validation helpers
    
    bool isKnownAttribute(const std::string& name) const {
        return name == kExportAttribute || 
               name == kDependsAttribute;
    }

    // Print an attribute parsing related warning
    void attributeWarning(const std::string& message, 
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
             
        Rcpp::Function warning = Rcpp::Environment::base_env()["warning"];     
        warning(ostr.str(), Rcpp::Named("call.") = false);
    }
    
    void attributeWarning(const std::string& message, size_t lineNumber) {
        attributeWarning(message, "", lineNumber);
    }
    
    void rcppExportWarning(const std::string& message, size_t lineNumber) {
        attributeWarning(message, "Rcpp::export", lineNumber);
    }

    void rcppExportNoFunctionFoundWarning(size_t lineNumber) {
        rcppExportWarning("No function found", lineNumber);
    }

    void rcppExportInvalidParameterWarning(const std::string& param, 
                                           size_t lineNumber) {
        rcppExportWarning("Invalid parameter declaration: "
                          "'" + param + "'", lineNumber);
    }
    
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
        
        void submitLine(const std::string& line) {
            std::size_t pos = 0;
            while (pos != std::string::npos) {
                std::string token = inComment() ? "*/" : "/*";
                pos = line.find(token, pos);
                if (pos != std::string::npos) {
                    inComment_ = !inComment_;
                    pos += token.size();
                }
            }    
        }
        
    private:
        bool inComment_;
    };
  
private:
    std::string sourceFile_;
    Rcpp::CharacterVector lines_;
    std::vector<Attribute> attributes_;
    std::vector<std::string> namespaces_;
    std::vector<std::string> roxygenBuffer_;
};

// Generate the preamble for a C++ file (headers and using directives)
std::string generateCppPreamble(const std::vector<std::string>& includes,
                                const std::vector<std::string>& namespaces) {
    std::ostringstream ostr;
    for (std::size_t i=0;i<includes.size(); i++)
        ostr << includes[i] << std::endl;
    
    ostr << std::endl;
    
    for (std::size_t i=0;i<namespaces.size(); i++)
        ostr << namespaces[i] << std::endl;
    
    return ostr.str();
}

// Generate the C++ code required to make [[Rcpp::export]] functions
// available as C symbols with SEXP parameters and return
std::string generateCpp(const SourceFileAttributes& attributes,
                        bool includePrototype,
                        const std::string& contextId,
                        bool verbose = false) {
  
    // source code we will build up
    std::ostringstream ostr;    
  
    // process each attribute
    for(std::vector<Attribute>::const_iterator 
        it = attributes.begin(); it != attributes.end(); ++it) {
        
        // alias the attribute (bail if not export)
        const Attribute& attribute = *it;
        if (attribute.name() != kExportAttribute)
            continue;
        
        // alias the function (bail if empty)
        const Function& function = attribute.function();
        if (function.empty())
            continue;
           
        // verbose output
        if (verbose)
            Rcpp::Rcout << "  " << function << std::endl;
           
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
        
        std::string result = function.type().isVoid() ? "R_NilValue" : 
                                                        "Rcpp::wrap(result)";
        ostr << "    return " << result << ";" << std::endl;
        ostr << "END_RCPP" << std::endl;
        ostr << "}" << std::endl << std::endl;
    }
    
    return ostr.str();
}

// Determine the exported name for a function 
std::string exportedName(const Attribute& attribute) {   
    if (!attribute.params().empty())
        return attribute.params()[0].name();
    else
        return attribute.function().name();
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
        
        // alias the attribute (bail if not export)
        const Attribute& attribute = *it;
        if (attribute.name() != kExportAttribute)
            continue;
        
        // alias the function (bail if empty)
        const Function& function = attribute.function();
        if (function.empty())
            continue;
        
        // print roxygen lines
        for (size_t i=0; i<attribute.roxygen().size(); i++)
            ostr << attribute.roxygen()[i] << std::endl;
        
        // build the parameter list 
        std::ostringstream argsOstr;
        const std::vector<Argument>& arguments = function.arguments();
        for (size_t i = 0; i<arguments.size(); i++) {
            const Argument& argument = arguments[i];
            argsOstr << argument.name();
            if (i != (arguments.size()-1))
                argsOstr << ", ";
        }
        std::string args = argsOstr.str();
        
        // determine the function name
        std::string name = exportedName(attribute);
            
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
        if (!args.empty())
            ostr << ", " << args;
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
        
        // use the directory name as a unique context id (need this to uniquely
        // name functions, DLLInfo objects, and the shared library itself)
        contextId_ = Rcpp::as<std::string>(basename(buildDirectory_));
        
        // regenerate the source code
        regenerateSource();
    }
    
    bool isEmpty() const { return cppSourcePath_.empty(); }
    
    bool isBuilt() const { return FileInfo(dynlibPath()).exists(); };
            
    bool isSourceDirty() const {
        
        // source file out of date means we're dirty
        if (FileInfo(cppSourcePath_).lastModified() != cppSourceLastModified_)
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
        return contextId_ + dynlibExt_;
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
    
    std::string generatedRSourcePath() const {
       return buildDirectory_ + fileSep_ + rSourceFilename(); 
    }
    
private:
    std::string cppSourcePath_;
    time_t cppSourceLastModified_;
    std::string generatedCpp_;
    std::string cppSourceFilename_;
    std::string contextId_;
    std::string buildDirectory_;
    std::string fileSep_;
    std::string dynlibExt_;
    std::vector<std::string> exportedFunctions_;
    std::vector<std::string> depends_;
};

// Dynlib cache that allows lookup by either file path or code contents
class SourceCppDynlibCache {
  
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
    context["cppSourcePath"] = dynlib.cppSourcePath();
    context["buildRequired"] = buildRequired;
    context["buildDirectory"] = dynlib.buildDirectory();
    context["generatedCpp"] = dynlib.generatedCpp();
    context["exportedFunctions"] = dynlib.exportedFunctions();
    context["cppSourceFilename"] = dynlib.cppSourceFilename();
    context["rSourceFilename"] = dynlib.rSourceFilename();
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
                                  SEXP sIncludes,
                                  SEXP sVerbose,
                                  SEXP sPlatform) {
BEGIN_RCPP
    // arguments
    std::string packageDir = Rcpp::as<std::string>(sPackageDir);
    std::string packageName = Rcpp::as<std::string>(sPackageName);
    std::vector<std::string> cppFiles = 
                    Rcpp::as<std::vector<std::string> >(sCppFiles);
    std::vector<std::string> includes = 
                    Rcpp::as<std::vector<std::string> >(sIncludes);
    bool verbose = Rcpp::as<bool>(sVerbose);
    Rcpp::List platform = Rcpp::as<Rcpp::List>(sPlatform);
     
    // Establish stream and namespace list for CPP code
    std::string fileSep = Rcpp::as<std::string>(platform["file.sep"]);
    std::string cppExportsFile = packageDir + fileSep + "src" + 
                                 fileSep + "RcppExports.cpp";
    CppExportsStream cppStream(cppExportsFile);
    std::vector<std::string> namespaces;
    
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
        
        // generate C++ code -- use the package name as a context id to ensure
        // unique symbol names for platforms where R can't do a local dyn.load
        cppStream << generateCpp(attributes, true, packageName, verbose);
        
        // track namespaces
        std::copy(attributes.namespaces().begin(),
                  attributes.namespaces().end(),
                  std::back_inserter(namespaces));
        
        // generate R code
        rStream << generateRFunctions(attributes, packageName);
        
        // verbose if requested
        if (!attributes.empty() && verbose)
            Rcpp::Rcout << std::endl;
    }
    
    // eliminate namespace duplicates
    std::sort(namespaces.begin(), namespaces.end());
    std::vector<std::string>::const_iterator it = 
                        std::unique(namespaces.begin(), namespaces.end());
    namespaces.resize( it - namespaces.begin());
                        
    
    // commit the code
    bool wroteCpp = cppStream.commit(generateCppPreamble(includes, namespaces));     
    bool wroteR = rStream.commit();
    
    // verbose output
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
