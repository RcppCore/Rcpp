// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// barrier.cpp: Rcpp R/C++ interface class library -- write barrier
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

#define USE_RINTERNALS
#include <Rinternals.h>
#include <Rcpp/barrier.h>

SEXP get_string_elt(SEXP x, int i){
    return STRING_ELT(x, i ) ;
}    
const char* char_get_string_elt(SEXP x, int i){
    return CHAR(STRING_ELT(x, i )) ;
}    
void set_string_elt(SEXP x, int i, SEXP value){
    STRING_ELT(x, i) = value ;
}
void char_set_string_elt(SEXP x, int i, const char* value){
    STRING_ELT(x, i) = Rf_mkChar(value) ; 
}
SEXP* get_string_ptr(SEXP x){ return STRING_PTR(x) ; }

SEXP get_vector_elt(SEXP x, int i){
    return VECTOR_ELT(x, i ) ;
}
void set_vector_elt(SEXP x, int i, SEXP value){
    SET_VECTOR_ELT(x, i, value ) ;
}
SEXP* get_vector_ptr(SEXP x){ return VECTOR_PTR(x) ; }

