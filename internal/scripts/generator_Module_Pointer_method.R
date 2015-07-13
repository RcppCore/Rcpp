#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/module/Module_generated_Pointer_method.h
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois

fun <- function(i) {

    index <- (1:i)-1
    collapse <- function(x) paste(x, collapse = ", ")
	
    typenames <- collapse(sprintf("typename U%d", index))
    u <- collapse(sprintf("U%d u%d", index, index))
    as <- collapse(sprintf("Rcpp::as< typename Rcpp::traits::remove_const_and_reference<U%d>::type>(args[%d])",
                           index, index))  
    U <- collapse(sprintf("U%d", index))
    
    txt <- sprintf('

template <typename RESULT_TYPE, %s>
self& method(const char* name_, RESULT_TYPE (*fun)(Class*, %s),
             const char* docstring = 0, ValidMethod valid = &yes_arity<%d>) {
    AddMethod(name_, new Pointer_CppMethod%d<Class,RESULT_TYPE,%s>(fun), valid, docstring);
    return *this;
}

template <typename RESULT_TYPE, %s>
self& const_method(const char* name_, RESULT_TYPE (*fun)(const Class*, %s),
                   const char* docstring = 0, ValidMethod valid = &yes_arity<%d>) {
    AddMethod(name_, new Const_Pointer_CppMethod%d<Class,RESULT_TYPE,%s>(fun), valid, docstring);
    return *this ;
}',
                   typenames,   # typename U0, ...
                   u,           # U0 u0, ...
                   i,
                   i,
                   U,           # U0, ...
                   
                   typenames,   # typename U0, ...
                   u,           # U0 u0, ...
                   i,
                   i,
                   U            # U0, ...
                   )   
}

file <- sprintf( 
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_generated_Pointer_method.h: -- generated helper code for Modules
//                                       see rcpp-scripts repo for generator script
//
// Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Module_generated_Pointer_method_h
#define Rcpp_Module_generated_Pointer_method_h

template <typename RESULT_TYPE>
self& method(const char* name_, RESULT_TYPE (*fun)(Class*),
             const char* docstring = 0, ValidMethod valid = &yes) {
    AddMethod(name_, new Pointer_CppMethod0<Class,RESULT_TYPE>(fun), valid, docstring);
    return *this;
}

template <typename RESULT_TYPE>
self& const_method(const char* name_, RESULT_TYPE (*fun)(const Class*),
                   const char* docstring = 0, ValidMethod valid = &yes ){
    AddMethod(name_, new Const_Pointer_CppMethod0<Class,RESULT_TYPE>( fun ), valid, docstring);
    return *this;
}

%s

#endif
', paste(sapply(1:65, fun), collapse = "\n") 
)

stopifnot(file.exists("inst/include/Rcpp/module/"))
writeLines( file, "inst/include/Rcpp/module/Module_generated_Pointer_method.h")
