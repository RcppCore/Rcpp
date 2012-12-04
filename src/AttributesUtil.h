// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// AttributesUtil.h: Rcpp R/C++ interface class library -- Rcpp attributes
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


#ifndef Rcpp__AttributesUtil__h
#define Rcpp__AttributesUtil__h

#include <string>

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

#endif // Rcpp__AttributesUtil__h