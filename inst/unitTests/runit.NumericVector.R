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

test.NumericVector <- function(){
	funx <- cfunction(signature(), '
	NumericVector x(10) ;
	for( int i=0; i<10; i++) x[i] = i ;
	return x ;', 
		Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkEquals( funx(), as.numeric(0:9), msg = "NumericVector(int)" )
}

test.NumericVector.REALSXP <- function(){
	funx <- cfunction(signature(vec = "numeric" ), '
	NumericVector x(vec) ;
	for( int i=0; i<x.size(); i++) { 
		x[i] = x[i]*2.0 ;
	}
	return x ;', 
		Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkEquals( funx(as.numeric(0:9)), 2*0:9, msg = "NumericVector( REALSXP) " )
}

test.NumericVector.initializer.list <- function(){
	if( Rcpp:::capabilities()[["initializer lists"]] ){
		funx <- cfunction(signature(), '
		NumericVector x = {0.0,1.0,2.0,3.0} ;
		for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
		return x ;', 
			Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;",
			cxxargs = "-std=c++0x" )
		checkEquals( funx(), as.numeric(2*0:3), msg = "NumericVector( initializer list) " )
	}
}

test.NumericVector.matrix.indexing <- function(){
	funx <- cfunction(signature(x = "numeric" ), '
		NumericVector m(x) ;
		double trace = 0.0 ;
		for( size_t i=0 ; i<4; i++){
			trace += m(i,i) ;
		}
		return wrap( trace ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx(x), sum(diag(x)), msg = "matrix indexing" )
	
	y <- as.vector( x )
	checkException( funx(y) , msg = "not a matrix" )
	
	funx <- cfunction(signature(x = "numeric" ), '
		NumericVector m(x) ;
		for( size_t i=0 ; i<4; i++){
			m(i,i) = 2.0 * i ;
		}
		return m ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( diag(funx(x)), 2.0*0:3, msg = "matrix indexing lhs" )
	
}

