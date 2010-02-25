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

test.NumericMatrix.row <- function(){
	funx <- cfunction(signature(x = "matrix" ), '
		NumericMatrix m(x) ;
		NumericMatrix::Row first_row = m.row(0) ;
		return wrap( std::accumulate( first_row.begin(), first_row.end(), 0.0 ) ) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx( x ), sum( x[1,] ), msg = "iterating over a row" )
}

test.CharacterMatrix.row <- function(){
	funx <- cfunction(signature(x = "matrix" ), '
		CharacterVector m(x) ;
		CharacterVector::Row first_row = m.row(0) ;
		std::string res( 
			std::accumulate( 
				first_row.begin(), first_row.end(), std::string() ) ) ;
		return wrap(res) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	
	m <- matrix( letters, ncol = 2 )
	checkEquals( funx(m), paste( m[1,], collapse = "" ), msg = "CharacterVector::Row" )
}

test.List.row <- function(){
	
	funx <- cfunction(signature(x = "matrix" ), '
		List m(x) ;
		List::Row first_row = m.row(0) ;
		IntegerVector out( first_row.size() ) ;
		std::transform( 
			first_row.begin(), first_row.end(),
			out.begin(), 
			unary_call<SEXP,int>( Function("length" ) ) ) ;
		return wrap(out) ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;"  )
	
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( funx( m ), 1 + 0:3*4, msg = "List::Row" )
	
}

