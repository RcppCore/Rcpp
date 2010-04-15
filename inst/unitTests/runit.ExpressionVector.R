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

test.ExpressionVector <- function(){
	funx <- cppfunction(signature(), '
	ExpressionVector x(2) ;
	x[0] = Symbol( "rnorm" ) ;
	x[1] = Rf_lcons( Symbol("rnorm"), Rf_cons( Rf_ScalarReal(10.0), R_NilValue) ) ;
	return x ;'  )
	ex <- parse( text = "rnorm; rnorm(10)" )
	# get rid of the srcref stuff so that we can compare
	# more easily
	attributes(ex) <- NULL 
	checkEquals( funx(),  ex , msg = "ExpressionVector" )
}

if( Rcpp:::capabilities()[["variadic templates"]] ){
	test.ExpressionVector.variadic <- function(){
		funx <- cppfunction(signature(), '
		ExpressionVector x(2) ;
		x[0] = Symbol( "rnorm" ) ;
		x[1] = Language( "rnorm", 10.0 ) ;
		return x ;', cxxargs = "-std=c++0x" )
		ex <- parse( text = "rnorm; rnorm(10)" )
		attributes(ex) <- NULL
		checkEquals( funx(),  ex , msg = "ExpressionVector (using variadic templates) " )
	}
}

test.ExpressionVector.parse <- function( ){
	funx <- cppfunction(signature(), '
	ExpressionVector code( "local( { y <- sample(1:10); sort(y) })" ) ;
	return code ;'  )
	code <- funx()
	results <- eval( code )
	checkEquals( results, 1:10, msg = "ExpressionVector parsing" )
}

test.ExpressionVector.parse.error <- function(){
	funx <- cppfunction(signature(), '
	ExpressionVector code( "rnorm(" ) ;
	return code ;'  )
	checkException( funx(), msg = "parse error" )
}

test.ExpressionVector.eval <- function(){
	funx <- cppfunction(signature(), '
	ExpressionVector code( "local( { y <- sample(1:10); sort(y) })" ) ;
	return code.eval() ;'  )
	checkEquals( funx(), 1:10, msg = "ExpressionVector::eval" )
}

test.ExpressionVector.eval.env <- function(){
	funx <- cppfunction(signature(env = "environment"), '
	ExpressionVector code( "sort(x)" ) ;
	return code.eval(env) ;'  )
	
	e <- new.env()
	e[["x"]] <- sample(1:10)
	checkEquals( funx(e), 1:10, msg = "ExpressionVector::eval" )
}

