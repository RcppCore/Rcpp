// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Symbol.h: Rcpp R/C++ interface class library -- access R environments
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Symbol_h
#define Rcpp_Symbol_h

#include <RcppCommon.h>

namespace Rcpp{ 

class Symbol: public RObject{
public:

    /**
     * wraps the SEXP into a Symbol object. 
     * 
     * @param m_sexp Accepted SEXP types are SYMSXP, CHARSXP and STRSXP
     * in the last case, the first element of the character vector 
     * is silently used
     */
    Symbol(SEXP x) throw(not_compatible) ;
    
    /**
     *
     */
    Symbol(const std::string& symbol) ;
    
    Symbol( const Symbol& other) ;
    Symbol& operator=(const Symbol& other) ;
    
    /**
     * Nothing specific
     */ 
    ~Symbol() ;

};

} // namespace Rcpp

#endif
