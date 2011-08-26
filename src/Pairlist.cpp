// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Pairlist.cpp: Rcpp R/C++ interface class library -- Pairlist objects
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

#include <Rcpp/Pairlist.h>

namespace Rcpp {
        
    Pairlist::Pairlist() : DottedPair() {}
    Pairlist::Pairlist( SEXP x ) : DottedPair(){
        setSEXP( r_cast<LISTSXP>(x) );
    }
    Pairlist::~Pairlist(){}
    Pairlist::Pairlist( const Pairlist& other): DottedPair(){
        setSEXP( other.asSexp() ) ;
    }
    Pairlist& Pairlist::operator=(const Pairlist& other){
        setSEXP( other.asSexp() ) ;
        return *this ;
    }
        
} // namespace Rcpp
