// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// AttributesTypes.h: Rcpp R/C++ interface class library -- Rcpp attributes
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


#ifndef Rcpp__AttributesTypes__h
#define Rcpp__AttributesTypes__h

#include <string>
#include <vector>
#include <iosfwd>

namespace Rcpp {
namespace attributes {
     
    // Known attribute names & parameters
    extern const char * const kExportAttribute;
    extern const char * const kDependsAttribute;
    extern const char * const kInterfacesAttribute;
    extern const char * const kInterfaceR;
    extern const char * const kInterfaceCpp; 
     
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
        virtual bool empty() const = 0;  
    };
    

} // namespace attributes
} // namespace Rcpp

#endif // Rcpp__AttributesTypes__h