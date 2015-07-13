#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/module/Module_generated_function.h
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois

fun <- function(i) {
	
    typename <- if (i == 0) "" else paste0(",", paste(sprintf( "typename U%d", (1:i)-1), collapse = ", "))
    Uu <- if( i == 0 ) "void" else paste(sprintf("U%d u%d", (1:i)-1, (1:i)-1), collapse = ", ")
    U <- if( i == 0 ) "" else paste0(",", paste(sprintf( "U%d", (1:i)-1), collapse = ", "))
    
    txt <- sprintf('
template <typename RESULT_TYPE%s>
void function(const char* name_,  RESULT_TYPE (*fun)(%s), const char* docstring = 0) {
    Rcpp::Module* scope = ::getCurrentScope();
    if (scope) {
        scope->Add(name_, new CppFunction%d<RESULT_TYPE%s>(fun, docstring));
    }
}

template <typename RESULT_TYPE%s>
void function(const char* name_,  RESULT_TYPE (*fun)(%s), Rcpp::List formals, const char* docstring = 0) {
    Rcpp::Module* scope = ::getCurrentScope();
    if (scope) {
       scope->Add(name_, new CppFunction_WithFormals%d<RESULT_TYPE%s>(fun, formals, docstring));
    }
}', 
                   typename, 
                   Uu, 
                   i, 
                   U, 

                   typename, 
                   Uu, 
                   i, 
                   U
                   )
	
}

file <- sprintf( 
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_generated_function.h: -- generated helper code for Modules
//                                 see rcpp-scripts repo for generator script
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

#ifndef Rcpp_Module_generated_function_h
#define Rcpp_Module_generated_function_h

namespace Rcpp {

%s

}

#endif ',
    paste(sapply( 0:65, fun), collapse = "\n") 
)

stopifnot(file.exists("inst/include/Rcpp/module/"))
writeLines(file, "inst/include/Rcpp/module/Module_generated_function.h")
