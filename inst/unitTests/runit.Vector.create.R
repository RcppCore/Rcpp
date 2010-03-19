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

test.IntegerVector.create <- function(){
	fx <- cfunction(signature(), '
	List output(2); 
	output[0] = IntegerVector::create( 10 ) ;
	output[1] = IntegerVector::create( _["foo"] = 20 ) ;
	return output ;
	', 
	Rcpp = TRUE, includes = "using namespace Rcpp;" )
	
	checkEquals( fx(), list( 10L, c(foo = 20L ) ), 
		msg = "IntegerVector::create" )
}

test.List.create <- function(){
	fx <- cfunction(signature(), '
	List output(2); 
	output[0] = List::create( 10 ) ;
	output[1] = List::create( _["foo"] = "bar" ) ;
	return output ;
	', 
	Rcpp = TRUE, includes = "using namespace Rcpp;" )
	
	checkEquals( fx(), list( list( 10L ), list(foo = "bar" ) ), 
		msg = "List::create" )
}

test.CharacterVector.create <- function(){
	fx <- cfunction(signature(), '
	List output(2); 
	output[0] = CharacterVector::create( "foo" ) ;
	output[1] = CharacterVector::create( _["foo"] = "bar" ) ;
	return output ;
	', 
	Rcpp = TRUE, includes = "using namespace Rcpp;" )
	                          
	checkEquals( fx(), list( "foo", c(foo = "bar" ) ), 
		msg = "CharacterVector::create" )
	
}

