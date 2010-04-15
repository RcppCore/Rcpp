#!/usr/bin/r -t
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

.setUp <- function(){
	suppressMessages( require( inline ) )
}

generate.dot.cpp.code <- function(i, suffix = "" ){
	code <- sprintf( '.Cpp( "testfun_%s%d" %s, PACKAGE = "Rcpp" )', suffix, i, 
		if( i == 0L ) "" else paste( ", ", paste( 0:(i-1), collapse = ", "), sep = "" )
	)
	parse( text = code )
}

test.dot.cpp <- function(){
	for( i in 0:65 ){
		expr <- generate.dot.cpp.code(i)
		checkEquals( eval(expr), i, msg = sprintf( ".Cpp (%d arguments)", i ) )
	}
}

test.dot.cpp.exceptions <- function(){
	for( i in 0:65 ){
		expr <- generate.dot.cpp.code(i, "ex_")
		error <- tryCatch( {
			eval(expr)
			FALSE	
		}, "std::range_error" = function(e){
			TRUE
		} )
		checkTrue( error, msg = sprintf( ".Cpp (%d arguments) throwing exception", i ) )
	}
}

