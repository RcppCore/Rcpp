#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/generated/InternalFunctionWithStdFunction_call.h
#
# Copyright (C) 2014 Christian Authmann

fun <- function(i) {
        
    txt <- sprintf( '
    template <typename RESULT_TYPE%s>
    RESULT_TYPE call(const std::function<RESULT_TYPE(%s)> &fun, SEXP* args) {%s
        return fun(%s);
    }
', 
                   if (i == 0) ""     else paste0(",", paste(sprintf("typename U%d", (1:i)-1), collapse = ", ")),
                   if (i == 0) ""     else paste(sprintf("U%d", (1:i)-1), collapse = ","),  
                   if (i == 0) ""     else paste0("\n", paste(sprintf("        typename traits::input_parameter<U%d>::type x%d(args[%d]);", (1:i)-1, (1:i)-1, (1:i)-1 ), collapse = "\n")),
                   if (i == 0) ""     else paste(sprintf("x%d", (1:i)-1), collapse = ",")
              )
}

file <- sprintf( 
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// InternalFunctionWithStdFunction_call.h -- generated helper code for
//                                  InternalFunctionWithStdFunction.h
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

#ifndef Rcpp__generated__InternalFunctionWithStdFunction_calls_h
#define Rcpp__generated__InternalFunctionWithStdFunction_calls_h

%s

#endif
', paste(sapply(0:65, fun), collapse = "\n") 
)

stopifnot(file.exists("inst/include/Rcpp/generated/"))
writeLines(file, "inst/include/Rcpp/generated/InternalFunctionWithStdFunction_call.h")
