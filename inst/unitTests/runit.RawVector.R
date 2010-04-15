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

test.RawVector <- function(){
	funx <- cppfunction(signature(), '
	RawVector x(10) ;
	for( int i=0; i<10; i++) x[i] = (Rbyte)i ;
	return x ;' )
	checkEquals( funx(), as.raw(0:9), msg = "RawVector(int)" )
}

test.RawVector.REALSXP <- function(){
	funx <- cppfunction(signature(vec = "raw" ), '
	RawVector x(vec) ;
	for( int i=0; i<x.size(); i++) { 
		x[i] = x[i]*2 ;
	}
	return x ;'  )
	checkEquals( funx(as.raw(0:9)), as.raw(2*0:9), msg = "RawVector( RAWSXP) " )
}

test.RawVector.initializer.list <- function(){
	if( Rcpp:::capabilities()[["initializer lists"]] ){
		funx <- cppfunction(signature(), '
		RawVector x = {0,1,2,3} ;
		for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
		return x ;', cxxargs = "-std=c++0x" )
		checkEquals( funx(), as.raw(2*0:3), msg = "RawVector( initializer list) " )
	}
}


