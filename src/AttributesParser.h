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

#include <string>
#include <vector>
#include <iosfwd>

#include <Rcpp.h>

namespace Rcpp {
namespace attributes_parser {
     
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
        
        const std::vector<std::string>& roxygen() const { return roxygen_; }
        
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

    // Known attribute names
    extern const char * const kExportAttribute;
    extern const char * const kDependsAttribute;
   
    // Class used to parse and return attribute information from a source file
    class SourceFileAttributes {
    public:
        explicit SourceFileAttributes(const std::string& sourceFile);
        
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
        private:
            bool inComment_;
        };
      
    private:
        std::string sourceFile_;
        CharacterVector lines_;
        std::vector<Attribute> attributes_;
        std::vector<std::string> namespaces_;
        std::vector<std::string> roxygenBuffer_;
    };

} // namespace attributes_parser
} // namespace Rcpp

