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

test.NumericMatrix <- function(){
	funx <- cfunction(signature(x = "matrix" ), '
		NumericMatrix m(x) ;
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

}

test.CharacterMatrix <- function(){
	funx <- cfunction(signature(x = "matrix" ), '
		CharacterMatrix m(x) ;
		std::string trace ;
		for( size_t i=0 ; i<4; i++){
			trace += m(i,i) ;
		}
		return wrap( trace ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- matrix( letters[1:16], ncol = 4 )
	checkEquals( funx(x), paste( diag(x), collapse = "" ) )
}

test.GenericMatrix <- function( ){
	funx <- cfunction(signature(x = "matrix" ), '
		GenericMatrix m(x) ;
		List output( m.ncol() ) ;
		for( size_t i=0 ; i<4; i++){
			output[i] = m(i,i) ;
		}
		return output ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	g <- function(y){
		sapply( y, function(x) seq(from=x, to = 16) )
	}
	x <- matrix( g(1:16), ncol = 4 )
	checkEquals( funx(x), g(diag(matrix(1:16,ncol=4))), msg = "GenericMatrix" )
}

test.IntegerMatrix.diag <- function(){
	fx <- cfunction( signature(), '
		return IntegerMatrix::diag( 5, 1 ) ;
	',
	Rcpp  = TRUE, includes = "using namespace Rcpp;" )
	expected <- matrix( 0L, nrow = 5, ncol = 5 )
	diag( expected ) <- 1L
	checkEquals( fx(), expected, msg = "IntegerMatrix::diag" )
}

test.CharacterMatrix.diag <- function(){
	fx <- cfunction( signature(), '
		return CharacterMatrix::diag( 5, "foo" ) ;
	',
	Rcpp  = TRUE, includes = "using namespace Rcpp;" )
	expected <- matrix( "", nrow = 5, ncol = 5 )
	diag( expected ) <- "foo"
	checkEquals( fx(), expected, msg = "CharacterMatrix::diag" )
}

test.NumericMatrix.Ctors <- function(){
	funx <- cfunction(signature(), '
		NumericMatrix m(3);
		return m;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- matrix(0, 3, 3)
	checkEquals( funx(), x, msg = "matrix from single int" )

	funx <- cfunction(signature(), '
		NumericMatrix m(3,3);
		return m;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- matrix(0, 3, 3)
	checkEquals( funx(), x, msg = "matrix from two int" )
}

