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

test.make.list.no.names <- function(){
	
	fx <- cfunction(signature(),'
		return make_list( 1, 2, "foobar", 4.0 ) ;	
	', 
	Rcpp = TRUE, includes = "using namespace Rcpp; " )
	res <- fx()
	checkEquals( res, list( 1L, 2L, "foobar", 4.0 ), msg = "unnamed make.list" )
	checkTrue( is.null(names(res)), msg = "unnamed make.list, no names" )
}

test.make.list.with.names <- function(){
	
	fx <- cfunction(signature(),'
		return make_list( 
			Named("a") = 1 , 
			Named("b") = 2 , 
			Named("c") = "foobar", 
			Named("d") = 4.0 ) ;	
	', 
	Rcpp = TRUE, includes = "using namespace Rcpp; " )
	res <- fx()
	checkEquals( res, 
		list( a = 1L, b = 2L, c = "foobar", d = 4.0 ), msg = "named make.list" )
}

test.make.list.some.names <- function(){
	
	fx <- cfunction(signature(),'
		return make_list( 
			Named("a") = 1 , 
			2 , 
			"foobar", 
			Named("d") = 4.0 ) ;	
	', 
	Rcpp = TRUE, includes = "using namespace Rcpp; " )
	res <- fx()
	checkEquals( res, 
		list( a = 1L, 2L, "foobar", d = 4.0 ), msg = "named make.list" )
}

