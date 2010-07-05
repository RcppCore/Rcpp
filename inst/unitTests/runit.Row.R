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
	if( ! exists( ".rcpp.row", globalenv() ) ){
		# definition of all the functions at once
		
		sugar.functions <- list( 
			"runit_NumericMatrix_row" = list( 
				signature(x = "matrix" ), 
				'
					NumericMatrix m(x) ;
					NumericMatrix::Row first_row = m.row(0) ;
					return wrap( std::accumulate( first_row.begin(), first_row.end(), 0.0 ) ) ;
				'), 
			"runit_CharacterMatrix_row" = list( 
				signature(x = "matrix" ), 
				'
					CharacterMatrix m(x) ;
					CharacterMatrix::Row first_row = m.row(0) ;
					std::string res( 
						std::accumulate( 
							first_row.begin(), first_row.end(), std::string() ) ) ;
					return wrap(res) ;
				'				
			),           
			"runit_GenericMatrix_row" = list( 
				signature(x = "matrix" ), 
				'
					GenericMatrix m(x) ;
					GenericMatrix::Row first_row = m.row(0) ;
					IntegerVector out( first_row.size() ) ;
					std::transform( 
						first_row.begin(), first_row.end(),
						out.begin(), 
						unary_call<SEXP,int>( Function("length" ) ) ) ;
					return wrap(out) ;
				'
			),
			"runit_NumericMatrix_column" = list( 
				signature(x = "matrix" ), 
				'
					NumericMatrix m(x) ;
					NumericMatrix::Column col = m.column(0) ;
					return wrap( std::accumulate( col.begin(), col.end(), 0.0 ) ) ;
				'	
			), 
			"runit_CharacterMatrix_column" = list( 
				signature(x = "matrix" ),
					'
						CharacterMatrix m(x) ;
						CharacterMatrix::Column col = m.column(0) ;
						std::string res( 
							std::accumulate( 
								col.begin(), col.end(), std::string() ) ) ;
						return wrap(res) ;
					'			
			), 
			"runit_GenericMatrix_column" = list( 
				signature(x = "matrix" ), 
				'
					GenericMatrix m(x) ;
					GenericMatrix::Column col = m.column(0) ;
					IntegerVector out( col.size() ) ;
					std::transform( 
						col.begin(), col.end(),
						out.begin(), 
						unary_call<SEXP,int>( Function("length" ) ) ) ;
					return wrap(out) ;
				' 			
			)
		)
		signatures <- lapply( sugar.functions, "[[", 1L )
		bodies <- lapply( sugar.functions, "[[", 2L )
		fx <- cxxfunction( signatures, bodies, plugin = "Rcpp" )
		getDynLib( fx ) # just forcing loading the dll now
		assign( ".rcpp.row", fx, globalenv() )
	}
}
	
			
			
test.NumericMatrix.row <- function(){
	funx <- .rcpp.row$runit_NumericMatrix_row
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx( x ), sum( x[1,] ), msg = "iterating over a row" )
}

test.CharacterMatrix.row <- function(){
	funx <- .rcpp.row$runit_CharacterMatrix_row
	m <- matrix( letters, ncol = 2 )
	checkEquals( funx(m), paste( m[1,], collapse = "" ), msg = "CharacterVector::Row" )
}

test.List.row <- function(){
	funx <- .rcpp.row$runit_GenericMatrix_row
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( funx( m ), 1 + 0:3*4, msg = "List::Row" )
	
}

test.NumericMatrix.column <- function(){
	funx <- .rcpp.row$runit_NumericMatrix_column
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx( x ), sum( x[,1] ) , msg = "iterating over a column" )
}

test.CharacterMatrix.column <- function(){
	funx <- .rcpp.row$runit_CharacterMatrix_column
	m <- matrix( letters, ncol = 2 )
	checkEquals( funx(m), paste( m[,1], collapse = "" ), msg = "CharacterVector::Column" )
}

test.List.column <- function(){
	funx <- .rcpp.row$runit_GenericMatrix_column
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( funx( m ), 1:4, msg = "List::Column" )
	
}

