#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/module/Module_generated_get_signature.h
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois

fun <- function(i) {

    index <- 0:i
    collapse <- function(x) paste(x, collapse = ", ")
	
    typenames <- collapse(sprintf("typename U%d", index))
    demangles <- paste(sprintf('    s += ", "; s+= get_return_type<U%d>();', 1:i), collapse = "\n")
    
    txt <- sprintf('

template <typename RESULT_TYPE,%s>
inline void signature(std::string& s, const char* name) {
    s.clear();
    s += get_return_type<RESULT_TYPE>();
    s += " ";
    s += name;
    s += "(";
    s += get_return_type<U0>();
%s
    s += ")";
}

',
                   typenames,   # typename U0, ...
                   demangles)   
    txt
}

file <- sprintf( 
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_generated_get_signature.h: -- generated helper code for Modules
//                                      see rcpp-scripts repo for generator script
//
// Copyright (C) 2010 - 2014  Doug Bates, Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Module_generated_get_signature_h
#define Rcpp_Module_generated_get_signature_h

namespace Rcpp {

template <typename RESULT_TYPE>
inline void signature(std::string& s, const char* name) {
    s.clear();
    s += get_return_type<RESULT_TYPE>();
    s += " ";
    s += name;
    s += "()";
}

template <typename RESULT_TYPE,typename U0>
inline void signature(std::string& s, const char* name) {
    s.clear();
    s += get_return_type<RESULT_TYPE>();
    s += " ";
    s += name;
    s += "(";
    s += get_return_type<U0>();
    s += ")";
}

%s

}

#endif', paste(sapply(1:65, fun), collapse = "\n") 
)

stopifnot(file.exists("inst/include/Rcpp/module/"))
writeLines(file, "inst/include/Rcpp/module/Module_generated_get_signature.h")
