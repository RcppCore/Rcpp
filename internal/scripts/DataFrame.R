#!/usr/bin/r
##
## use this script to generate the file DataFrame_generated.h
##

DataFrame_generator <- function( i ) {
    src <-
    sprintf('
template <%s>
static DataFrame create( %s ) {
    return DataFrame::from_list( List::create( %s ) ) ;
} ',
            paste( sprintf( "typename T%d", 1:i ), collapse = ", "),
            paste( sprintf( "const T%d& t%d", 1:i, 1:i ), collapse = ", "),
            paste( sprintf( "t%d", 1:i ), collapse = ", ")
            )
}


content <- sprintf( '// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DataFrame_generated.h: Rcpp R/C++ interface class library -- data frames
//
// Copyright (C) 2010 - 2013  Dirk Eddelbuettel and Romain Francois
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


#ifndef Rcpp__DataFrame_generated_h
#define Rcpp__DataFrame_generated_h

%s

#endif
' ,
paste( sapply( 1:20, DataFrame_generator ), collapse = "\n\n" )
)
writeLines( content, "Rcpp/inst/include/Rcpp/generated/DataFrame_generated.h" )

