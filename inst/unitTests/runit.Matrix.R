#!/usr/bin/r -t
#
# Copyright (C) 2010 - 2013  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"

if (.runThisTest) {

.setUp <- Rcpp:::unit_test_setup("Matrix.cpp")


test.List.column <- function(){
	funx <- .rcpp.Matrix$runit_Row_Column_sugar
	x <- matrix( 1:16+.5, nc = 4 )
	res <- funx( x )
	target <- list(
	    x[1,],
	    x[,1],
	    x[2,],
	    x[,2],
	    x[2,] + x[,2]
	    )
	checkEquals( res, target, msg = "column and row as sugar" )

}

test.NumericMatrix <- function(){
	funx <- .rcpp.Matrix$matrix_numeric
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx(x), sum(diag(x)), msg = "matrix indexing" )

	y <- as.vector( x )
	checkException( funx(y) , msg = "not a matrix" )

}

test.CharacterMatrix <- function(){
	funx <- .rcpp.Matrix$matrix_character
	x <- matrix( letters[1:16], ncol = 4 )
	checkEquals( funx(x), paste( diag(x), collapse = "" ) )
}

test.GenericMatrix <- function( ){
	funx <- .rcpp.Matrix$matrix_generic
	g <- function(y){
		sapply( y, function(x) seq(from=x, to = 16) )
	}
	x <- matrix( g(1:16), ncol = 4 )
	checkEquals( funx(x), g(diag(matrix(1:16,ncol=4))), msg = "GenericMatrix" )
}

test.IntegerMatrix.diag <- function(){
	funx <- .rcpp.Matrix$matrix_integer_diag
	expected <- matrix( 0L, nrow = 5, ncol = 5 )
	diag( expected ) <- 1L
	checkEquals( funx(), expected, msg = "IntegerMatrix::diag" )
}

test.CharacterMatrix.diag <- function(){
	funx <- .rcpp.Matrix$matrix_character_diag
	expected <- matrix( "", nrow = 5, ncol = 5 )
	diag( expected ) <- "foo"
	checkEquals( funx(), expected, msg = "CharacterMatrix::diag" )
}

test.NumericMatrix.Ctors <- function(){
	funx <- .rcpp.Matrix$matrix_numeric_ctor1
	x <- matrix(0, 3, 3)
	checkEquals( funx(), x, msg = "matrix from single int" )

	funx <- .rcpp.Matrix$matrix_numeric_ctor2
	x <- matrix(0, 3, 3)
	checkEquals( funx(), x, msg = "matrix from two int" )
}

test.IntegerVector.matrix.indexing <- function(){
    fun <- .rcpp.Matrix$integer_matrix_indexing
    x <- matrix( 1:16, ncol = 4 )
    checkEquals( fun(x), sum(diag(x)), msg = "matrix indexing" )

    fun <- .rcpp.Matrix$integer_matrix_indexing_lhs
    checkEquals( diag(fun(x)), 2*0:3, msg = "matrix indexing lhs" )

    y <- as.vector( x )
    checkException( fun(y) , msg = "not a matrix" )
}



test.NumericMatrix.row <- function(){
	funx <- .rcpp.Matrix$runit_NumericMatrix_row
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx( x ), sum( x[1,] ), msg = "iterating over a row" )
}

test.CharacterMatrix.row <- function(){
	funx <- .rcpp.Matrix$runit_CharacterMatrix_row
	m <- matrix( letters, ncol = 2 )
	checkEquals( funx(m), paste( m[1,], collapse = "" ), msg = "CharacterVector::Row" )
}

test.List.row <- function(){
	funx <- .rcpp.Matrix$runit_GenericMatrix_row
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( funx( m ), 1 + 0:3*4, msg = "List::Row" )

}

test.NumericMatrix.column <- function(){
	funx <- .rcpp.Matrix$runit_NumericMatrix_column
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( funx( x ), sum( x[,1] ) , msg = "iterating over a column" )
}

test.NumericMatrix.cumsum <- function(){
	funx <- .rcpp.Matrix$runit_NumericMatrix_cumsum
	x <- matrix( 1:8 + .5, ncol = 2 )
	checkEquals( funx( x ), t(apply(x, 1, cumsum)) , msg = "cumsum" )
}

test.CharacterMatrix.column <- function(){
	funx <- .rcpp.Matrix$runit_CharacterMatrix_column
	m <- matrix( letters, ncol = 2 )
	checkEquals( funx(m), paste( m[,1], collapse = "" ), msg = "CharacterVector::Column" )
}

test.List.column <- function(){
	funx <- .rcpp.Matrix$runit_GenericMatrix_column
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( funx( m ), 1:4, msg = "List::Column" )
}

test.NumericMatrix.colsum <- function( ){
    funx <- .rcpp.Matrix$runit_NumericMatrix_colsum
    probs <- matrix(1:12,nrow=3)
    checkEquals( funx( probs ), t(apply(probs,1,cumsum)) )
}

test.NumericMatrix.rowsum <- function( ){
    funx <- .rcpp.Matrix$runit_NumericMatrix_rowsum
    probs <- matrix(1:12,nrow=3)
    checkEquals( funx( probs ), apply(probs,2,cumsum) )
}

test.NumericMatrix.SubMatrix <- function( ){
    funx <- .rcpp.Matrix$runit_SubMatrix
    target <- rbind( c(3,4,5,5), c(3,4,5,5), 0 )
    checkEquals( funx(), target, msg = "SubMatrix" )
}


}
