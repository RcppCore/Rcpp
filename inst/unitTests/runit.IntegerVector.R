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

test.IntegerVector <- function(){
	funx <- cfunction(signature(), '
	IntegerVector x(10) ;
	for( int i=0; i<10; i++) x[i] = i ;
	return x ;', 
		Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkEquals( funx(), 0:9, msg = "IntegerVector" )
}

test.IntegerVector.INTSXP <- function(){
	funx <- cfunction(signature(vec = "integer" ), '
	IntegerVector x(vec) ;
	for( int i=0; i<x.size(); i++) { 
		x[i] = x[i]*2 ;
	}
	return x ;', 
		Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkEquals( funx(0:9), 2*0:9, msg = "IntegerVector( INTSXP) " )
}

test.IntegerVector.initializer.list <- function(){
	if( Rcpp:::capabilities()[["initializer lists"]] ){
		funx <- cfunction(signature(), '
		IntegerVector x = {0,1,2,3} ;
		for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
		return x ;', 
			Rcpp=TRUE, verbose=FALSE, 
			includes = "using namespace Rcpp;",
			cxxargs = "-std=c++0x" )
		checkEquals( funx(), 2*0:3, msg = "IntegerVector( initializer list) " )
	}
}

test.IntegerVector.matrix.indexing <- function(){
	funx <- cfunction(signature(x = "integer" ), '
		IntegerVector m(x) ;
		int trace = 0.0 ;
		for( size_t i=0 ; i<4; i++){
			trace += m(i,i) ;
		}
		return wrap( trace ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- matrix( 1:16, ncol = 4 )
	checkEquals( funx(x), sum(diag(x)), msg = "matrix indexing" )
	
	funx <- cfunction(signature(x = "integer" ), '
		IntegerVector m(x) ;
		for( size_t i=0 ; i<4; i++){
			m(i,i) = 2 * i ;
		}
		return m ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( diag(funx(x)), 2*0:3, msg = "matrix indexing lhs" )
	
	
	y <- as.vector( x )
	checkException( funx(y) , msg = "not a matrix" )
}

test.IntegerVector.Dimension.constructor <- function(){

	funx <- cfunction(signature(), '
		return IntegerVector( Dimension( 5 ) ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( funx(), 
		integer(5) , 
		msg = "IntegerVector( Dimension(5))" )
	
	funx <- cfunction(signature(), '
		return IntegerVector( Dimension( 5, 5 ) ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( funx(), 
		matrix( 0L, ncol = 5, nrow = 5) , 
		msg = "IntegerVector( Dimension(5,5))" )
	
	funx <- cfunction(signature(), '
		return IntegerVector( Dimension( 2, 3, 4) ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( funx(), 
		array( 0L, dim = c(2,3,4) ) , 
		msg = "IntegerVector( Dimension(2,3,4))" )
}

test.IntegerVector.range.constructors <- function(){

	funx <- cfunction(signature(), '
		int x[] = { 0, 1, 2, 3 } ;
		IntegerVector y( x, x+4 ) ;
		return y;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( funx(), 0:3, msg = "assign(int*, int*)" )
	
	funx <- cfunction(signature(), '
		std::vector<int> vec(4) ;
		for( size_t i = 0; i<4; i++) vec[i] = i;
		IntegerVector y( vec.begin(), vec.end() ) ;
		return y;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( funx(), 0:3, msg = "assign(int*, int*)" )
}

test.IntegerVector.names.set <- function(){
	funx <- cfunction(signature(), '
		IntegerVector y(2) ;
		std::vector<std::string> names(2)  ;
		names[0] = "foo" ;
		names[1] = "bar" ; 
		y.names() = names ;
		return y ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( names(funx()), c("foo", "bar"), 
		msg = "Vector::names" )
}

test.IntegerVector.names.get <- function(){
	funx <- cfunction(signature(x = "integer"), '
		IntegerVector y(x) ;
		return y.names() ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	checkEquals( funx( c("foo" = 1L, "bar" = 2L) ), c("foo", "bar"), 
		msg = "Vector::names get" )
}

test.IntegerVector.names.indexing <- function(){
	funx <- cfunction(signature(x = "integer"), '
		IntegerVector y(x) ;
		return wrap( y["foo"]) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- c( "foo" = 1L, "bar" = 2L )
	checkEquals( funx( x ), 1L, msg = "IntegerVector names based indexing" )
	
}

