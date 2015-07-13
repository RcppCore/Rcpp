#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/generated/InternalFunction__ctors.h
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois

fun <- function(i) {
        
    txt <- sprintf( '

    template <typename RESULT_TYPE%s>
    InternalFunction_Impl(RESULT_TYPE (*fun)(%s)) {
        set(XPtr<CppFunction%d<RESULT_TYPE%s> >(new CppFunction%d<RESULT_TYPE%s>(fun), false));
    }
', 
                   if (i == 0) ""     else paste0(",", paste(sprintf("typename U%d", (1:i)-1), collapse = ", ")), 
                   if (i == 0) "void" else paste(sprintf("U%d u%d", (1:i)-1, (1:i)-1 ), collapse = ", "), 
                   i, 
                   if (i == 0) ""     else paste0(",", paste(sprintf("U%d", (1:i)-1), collapse = ", ")), 
                   i, 
                   if (i == 0) ""     else paste0(",", paste(sprintf("U%d", (1:i)-1), collapse = ", "))
                   )
}

file <- sprintf( 
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// InternalFunction_Impl_ctors.h -- generated helper code for InternalFunction__ctors.h
//                                  see rcpp-scripts repo for generator script
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

#ifndef Rcpp__generated__InternalFunction_Impl_ctors_h
#define Rcpp__generated__InternalFunction_Impl_ctors_h

%s

#endif
', paste(sapply(0:65, fun), collapse = "\n") 
)

stopifnot(file.exists("inst/include/Rcpp/generated/"))
writeLines(file, "inst/include/Rcpp/generated/InternalFunction__ctors.h")
