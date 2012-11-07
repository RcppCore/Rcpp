// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// AttributesParser.cpp: Rcpp R/C++ interface class library -- Rcpp attributes
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

#include "AttributesParser.h"

#include <iostream>
#include <fstream>
#include <cstring>

namespace {
     
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
      
} // anonymous namespace

namespace Rcpp {
namespace attributes_parser {
    
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
    
    // Known attribute names
    const char * const kExportAttribute = "export";
    const char * const kDependsAttribute = "depends";
    const char * const kInterfacesAttribute = "interfaces";
    const char * const kInterfaceR = "r";
    const char * const kInterfaceCpp = "cpp";
      
    // Parse the attributes from a source file
    SourceFileAttributes::SourceFileAttributes(const std::string& sourceFile)
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
                // line of interest (e.g. roxygen comment)
                else {
                    
                    // save roxygen comments
                    if (line.find("//'") == 0) {
                        std::string roxLine = "#" + line.substr(2);
                        roxygenBuffer_.push_back(roxLine);
                    }
                } 
            }
        }       
    }
   
    // Parse an attribute from the vector returned by regmatches
    Attribute SourceFileAttributes::parseAttribute(
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
    std::vector<Param> SourceFileAttributes::parseParameters(
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
    Function SourceFileAttributes::parseFunction(size_t lineNumber) {
        
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
    std::string SourceFileAttributes::parseSignature(size_t lineNumber) {
        
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
    std::vector<std::string> SourceFileAttributes::parseArguments(
                                                const std::string& argText) {
        
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
    
    Type SourceFileAttributes::parseType(const std::string& text) {
        
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
    
    bool SourceFileAttributes::isKnownAttribute(const std::string& name) const {
        return name == kExportAttribute || 
               name == kDependsAttribute ||
               name == kInterfacesAttribute;
    }

    // Print an attribute parsing related warning
    void SourceFileAttributes::attributeWarning(const std::string& message, 
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
    
    void SourceFileAttributes::attributeWarning(const std::string& message, 
                                            size_t lineNumber) {
        attributeWarning(message, "", lineNumber);
    }
    
    void SourceFileAttributes::rcppExportWarning(const std::string& message, 
                                             size_t lineNumber) {
        attributeWarning(message, "Rcpp::export", lineNumber);
    }

    void SourceFileAttributes::rcppExportNoFunctionFoundWarning(size_t lineNumber) {
        rcppExportWarning("No function found", lineNumber);
    }

    void SourceFileAttributes::rcppExportInvalidParameterWarning(
                                                    const std::string& param, 
                                                    size_t lineNumber) {
        rcppExportWarning("Invalid parameter: "
                          "'" + param + "'", lineNumber);
    }
    
    void SourceFileAttributes::rcppInterfacesWarning(const std::string& message,
                                                     size_t lineNumber) {
        attributeWarning(message + " (valid interfaces are 'r' and 'cpp')", 
                        "Rcpp::interfaces", lineNumber);                                                     
    }
    

    // Track /* */ comment state     
    void SourceFileAttributes::CommentState::submitLine(const std::string& line) {
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
  
} // namespace attributes_parser
} // namespace Rcpp

