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

test.ComplexVector <- function(){
	funx <- cppfunction(signature(), '
	ComplexVector x(10) ;
	Rcomplex rc ;
	for( int i=0; i<10; i++) {
		rc.r = rc.i = i + 0.0 ;
		x[i] = rc ;
	}
	return x ;'  )
	checkEquals( funx(), 0:9*(1+1i), msg = "ComplexVector" )
}

test.ComplexVector.INTSXP <- function(){
	funx <- cppfunction(signature(vec = "complex" ), '
	ComplexVector x(vec) ;
	for( int i=0; i<x.size(); i++) { 
		x[i].r = x[i].r*2 ;
		x[i].i = x[i].i*2 ;
	}
	return x ;'  )
	checkEquals( funx(0:9*(1+1i)), 2*0:9*(1+1i), msg = "ComplexVector( CPLXSXP) " )
}

test.ComplexVector.initializer.list <- function(){
	if( Rcpp:::capabilities()[["initializer lists"]] ){
		funx <- cppfunction(signature(), '
		Rcomplex c1 ; c1.r = c1.i = 0.0 ;
		Rcomplex c2 ; c2.r = c2.i = 1.0 ;
		ComplexVector x = { c1, c2 } ;
		return x ;', cxxargs = "-std=c++0x" )
		checkEquals( funx(), c( 0:1*(1+1i)), msg = "ComplexVector( initializer list) " )
	}
}


