// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppStringVector.h: Rcpp R/C++ interface class library -- string vector support
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
// Copyright (C) 2010	     Dirk Eddelbuettel and Romain Francois
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

#ifndef RcppStringVector_h
#define RcppStringVector_h

#include <RcppCommon.h>

class RcppStringVector {
public:
	typedef std::string* iterator ;
	typedef const std::string* const_iterator ;
	
    RcppStringVector(SEXP vec);
    ~RcppStringVector();
    std::string& operator()(int i) const;
    int size() const;
    std::vector<std::string> stlVector() const;
    
    inline const_iterator begin() const { return v ; }
    inline const_iterator end() const { return v + length ; }
    inline iterator begin() { return v ; }
    inline iterator end() { return v + length ; }
    
private:
    std::string *v;
    int length;
};

#endif
