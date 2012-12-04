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


#ifndef Rcpp__AttributesParser__h
#define Rcpp__AttributesParser__h

#include "AttributesTypes.h"

#include <Rcpp/Vector.h>

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
        virtual bool empty() const { return attributes_.empty(); }
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
        std::vector<std::string> embeddedR_;
        std::vector<std::string> roxygenBuffer_;
    };

} // namespace attributes
} // namespace Rcpp

#endif // Rcpp__AttributesParser__h