// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Symbol.cpp: Rcpp R/C++ interface class library -- Symbols
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
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

#include <Rcpp/Symbol.h>

namespace Rcpp {

    Symbol::Symbol( SEXP x ) : RObject() {
        if( x != R_NilValue ){
            int type = TYPEOF(x) ;
            switch( type ){
            case SYMSXP:
                setSEXP( x ) ;
                break; /* nothing to do */
            case CHARSXP: {
                SEXP charSym = Rf_install(CHAR(x));     // cannot be gc()'ed  once in symbol table
                setSEXP( charSym ) ;
                break ;
            }
            case STRSXP: {
                /* FIXME: check that there is at least one element */
                SEXP charSym = Rf_install( CHAR(STRING_ELT(x, 0 )) ); // cannot be gc()'ed  once in symbol table
                setSEXP( charSym );
                break ;
            }
            default:
                throw not_compatible("cannot convert to symbol (SYMSXP)") ;
            }
        } 
    }
        
    Symbol::Symbol(const std::string& symbol): RObject(){
        SEXP charSym = Rf_install(symbol.c_str());      // cannot be gc()'ed  once in symbol table
        setSEXP( charSym );
    }
        
    Symbol::Symbol( const Symbol& other) : RObject() {
        setSEXP( other.asSexp() );
    }
        
    Symbol& Symbol::operator=(const Symbol& other){
        setSEXP( other.asSexp() );
        return *this;
    }
        
    Symbol::~Symbol(){}
        
} // namespace Rcpp

