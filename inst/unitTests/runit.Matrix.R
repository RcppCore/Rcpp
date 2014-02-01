#!/usr/bin/r -t
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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

    .setUp <- Rcpp:::unitTestSetup("Matrix.cpp")

    test.List.column <- function(){
	x <- matrix( 1:16+.5, nc = 4 )
	res <- runit_Row_Column_sugar( x )
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
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( matrix_numeric(x), sum(diag(x)), msg = "matrix indexing" )

	y <- as.vector( x )
	checkException( matrix_numeric(y) , msg = "not a matrix" )

    }

    test.CharacterMatrix <- function(){
	x <- matrix( letters[1:16], ncol = 4 )
	checkEquals( matrix_character(x), paste( diag(x), collapse = "" ) )
    }

    test.GenericMatrix <- function( ){
	g <- function(y){
            sapply( y, function(x) seq(from=x, to = 16) )
	}
	x <- matrix( g(1:16), ncol = 4 )
	checkEquals( matrix_generic(x), g(diag(matrix(1:16,ncol=4))), msg = "GenericMatrix" )
    }

    test.IntegerMatrix.diag <- function(){
	expected <- matrix( 0L, nrow = 5, ncol = 5 )
	diag( expected ) <- 1L
	checkEquals( matrix_integer_diag(), expected, msg = "IntegerMatrix::diag" )
    }

    test.CharacterMatrix.diag <- function(){
	expected <- matrix( "", nrow = 5, ncol = 5 )
	diag( expected ) <- "foo"
	checkEquals( matrix_character_diag(), expected, msg = "CharacterMatrix::diag" )
    }

    test.NumericMatrix.Ctors <- function(){
	x <- matrix(0, 3, 3)
	checkEquals( matrix_numeric_ctor1(), x, msg = "matrix from single int" )

	x <- matrix(0, 3, 3)
	checkEquals( matrix_numeric_ctor2(), x, msg = "matrix from two int" )
    }

    test.IntegerVector.matrix.indexing <- function(){
        x <- matrix( 1:16, ncol = 4 )
        checkEquals( integer_matrix_indexing(x), sum(diag(x)), msg = "matrix indexing" )

        checkEquals( diag(integer_matrix_indexing_lhs(x)), 2*0:3, msg = "matrix indexing lhs" )

        y <- as.vector( x )
        checkException( integer_matrix_indexing_lhs(y) , msg = "not a matrix" )
    }

    test.NumericMatrix.row <- function(){
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( runit_NumericMatrix_row( x ), sum( x[1,] ), msg = "iterating over a row" )
    }

    test.CharacterMatrix.row <- function(){
	m <- matrix( letters, ncol = 2 )
	checkEquals( runit_CharacterMatrix_row(m), paste( m[1,], collapse = "" ), msg = "CharacterVector::Row" )
    }

    test.List.row <- function(){
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( runit_GenericMatrix_row( m ), 1 + 0:3*4, msg = "List::Row" )
    }

    test.NumericMatrix.column <- function(){
	x <- matrix( 1:16 + .5, ncol = 4 )
	checkEquals( runit_NumericMatrix_column( x ), sum( x[,1] ) , msg = "iterating over a column" )
    }

    test.NumericMatrix.cumsum <- function(){
	x <- matrix( 1:8 + .5, ncol = 2 )
	checkEquals( runit_NumericMatrix_cumsum( x ), t(apply(x, 1, cumsum)) , msg = "cumsum" )
    }

    test.CharacterMatrix.column <- function(){
	m <- matrix( letters, ncol = 2 )
	checkEquals( runit_CharacterMatrix_column(m), paste( m[,1], collapse = "" ), msg = "CharacterVector::Column" )
    }

    test.List.column <- function(){
	m <- lapply( 1:16, function(i) seq(from=1, to = i ) )
	dim( m ) <- c( 4, 4 )
	checkEquals( runit_GenericMatrix_column( m ), 1:4, msg = "List::Column" )
    }

    test.NumericMatrix.colsum <- function( ){
        probs <- matrix(1:12,nrow=3)
        checkEquals( runit_NumericMatrix_colsum( probs ), t(apply(probs,1,cumsum)) )
    }

    test.NumericMatrix.rowsum <- function( ){
        probs <- matrix(1:12,nrow=3)
        checkEquals( runit_NumericMatrix_rowsum( probs ), apply(probs,2,cumsum) )
    }

    test.NumericMatrix.SubMatrix <- function( ){
        target <- rbind( c(3,4,5,5), c(3,4,5,5), 0 )
        checkEquals( runit_SubMatrix(), target, msg = "SubMatrix" )
    }

    test.NumericMatrix.opequals <- function() {
        m <- matrix(1:4, nrow=2)
        checkEquals(m, matrix_opequals(m))
    }


}
