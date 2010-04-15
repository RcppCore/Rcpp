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

test.IntegerVector.create <- function(){
	fx <- cppfunction(signature(), '
	List output(2); 
	output[0] = IntegerVector::create( 10, 20 ) ;
	output[1] = IntegerVector::create( 
		_["foo"] = 20, 
		_["bar"] = 30 ) ;
	return output ;
	' )
	
	checkEquals( fx(), list( c( 10L, 20L) , c(foo = 20L, bar = 30L) ), 
		msg = "IntegerVector::create" )
}

test.List.create <- function(){
	fx <- cppfunction(signature(), '
	List output(2); 
	output[0] = List::create( 10, "foo" ) ;
	output[1] = List::create( 
		_["foo"] = 10, 
		_["bar"] = true ) ;
	return output ;
	' )
	
	checkEquals( fx(), list( list( 10L, "foo" ), list(foo = 10L, bar =  TRUE ) ), 
		msg = "List::create" )
}

test.CharacterVector.create <- function(){
	fx <- cppfunction(signature(), '
	List output(2); 
	output[0] = CharacterVector::create( "foo", "bar" ) ;
	output[1] = CharacterVector::create( 
		_["foo"] = "bar", 
		_["bar"] = "foo"
		) ;
	return output ;
	')
	
	checkEquals( fx(), list( c( "foo", "bar" ), c(foo = "bar", bar = "foo" ) ), 
	 	msg = "CharacterVector::create" )
	
}

