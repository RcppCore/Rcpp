#!/usr/bin/r -t
#
# Copyright (C) 2009 - 2010	Romain Francois
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

test.exceptions <- function(){
	funx <- cfunction(signature(), '
	throw std::range_error("boom") ;
	return R_NilValue ;
	', Rcpp=TRUE, verbose=FALSE)
	e <- tryCatch(  funx(), "C++Error" = function(e) e )
	checkTrue( "C++Error" %in% class(e), msg = "exception class C++Error" )
	checkTrue( "std::range_error" %in% class(e), msg = "exception class std::range_error" )
	checkEquals( e$message, "boom", msg = "exception message" )
	
	# same with direct handler
	e <- tryCatch(  funx(), "std::range_error" = function(e) e )
	checkTrue( "C++Error" %in% class(e), msg = "(direct handler) exception class C++Error" )
	checkTrue( "std::range_error" %in% class(e), msg = "(direct handler) exception class std::range_error" )
	checkEquals( e$message, "boom", msg = "(direct handler) exception message" )
	
	f <- function(){
		try( funx(), silent = TRUE)
		"hello world" 
	}
	checkEquals( f(), "hello world", msg = "life continues after an exception" )
	
}




