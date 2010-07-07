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

.setUp <- function() {
    tests <- ".rcpp.Vector"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list(
        	"raw_" = list( 
        		signature(), 
        		'
				RawVector x(10) ;
				for( int i=0; i<10; i++) x[i] = (Rbyte)i ;
				return x ;
				'
        	), 
        	"raw_REALSXP" = list( 
        		signature(vec = "raw" ),
        		'
				RawVector x(vec) ;
				for( int i=0; i<x.size(); i++) { 
					x[i] = x[i]*2 ;
				}
				return x ;
				'
        	), 
        	"expression_" = list( 
        		signature(), 
        		'
				ExpressionVector x(2) ;
				x[0] = Symbol( "rnorm" ) ;
				x[1] = Rf_lcons( Symbol("rnorm"), Rf_cons( Rf_ScalarReal(10.0), R_NilValue) ) ;
				return x ;
				'
        	), 
        	"expression_variadic" = list( 
        		signature(), 
        		'
				ExpressionVector x(2) ;
				x[0] = Symbol( "rnorm" ) ;
				x[1] = Language( "rnorm", 10.0 ) ;
				return x ;
				'
        	), 
        	"expression_parse" = list( 
        		signature(), 
        		'
					ExpressionVector code( "local( { y <- sample(1:10); sort(y) })" ) ;
					return code ;
				'
        	), 
        	"expression_parseerror" = list( 
        		signature(), 
        		'
					ExpressionVector code( "rnorm(" ) ;
					return code ;
				'
        	), 
        	"expression_eval" = list( 
        		signature(), 
        		'
				ExpressionVector code( "local( { y <- sample(1:10); sort(y) })" ) ;
				return code.eval() ;
				'
        	), 
        	"expression_evalenv" = list( 
        		signature(env = "environment"), 
        		'
				ExpressionVector code( "sort(x)" ) ;
				return code.eval(env) ;
				' 
        	)
        	
        )

        if (Rcpp:::capabilities()[["initializer lists"]]) {
        	g <- list(
        		"raw_initializer_list"=list(
        			signature(), 
        			'
					RawVector x = {0,1,2,3} ;
					for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
					return x ;
					'
        		)
        	)
        	f <- c(f,g)
        }

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp", includes = "using namespace std;",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.RawVector <- function(){
	funx <- .rcpp.Vector$raw_
	checkEquals( funx(), as.raw(0:9), msg = "RawVector(int)" )
}

test.RawVector.REALSXP <- function(){
	funx <- .rcpp.Vector$raw_REALSXP
	checkEquals( funx(as.raw(0:9)), as.raw(2*0:9), msg = "RawVector( RAWSXP) " )
}

if( Rcpp:::capabilities()[["initializer lists"]] ){
	test.RawVector.initializer.list <- function(){
		funx <- .rcpp.Vector$raw_initializer_list
		checkEquals( funx(), as.raw(2*0:3), msg = "RawVector( initializer list) " )
	}
}

test.ExpressionVector <- function(){
	funx <- .rcpp.Vector$expression_
	ex <- parse( text = "rnorm; rnorm(10)" )
	# get rid of the srcref stuff so that we can compare
	# more easily
	attributes(ex) <- NULL 
	checkEquals( funx(),  ex , msg = "ExpressionVector" )
}

test.ExpressionVector.variadic <- function(){
	funx <- .rcpp.Vector$expression_variadic
	ex <- parse( text = "rnorm; rnorm(10)" )
	attributes(ex) <- NULL
	checkEquals( funx(),  ex , msg = "ExpressionVector (using variadic templates) " )
}

test.ExpressionVector.parse <- function( ){
	funx <- .rcpp.Vector$expression_parse
	code <- funx()
	results <- eval( code )
	checkEquals( results, 1:10, msg = "ExpressionVector parsing" )
}

test.ExpressionVector.parse.error <- function(){
	funx <- .rcpp.Vector$expression_parseerror
	checkException( funx(), msg = "parse error" )
}

test.ExpressionVector.eval <- function(){
	funx <- .rcpp.Vector$expression_eval
	checkEquals( funx(), 1:10, msg = "ExpressionVector::eval" )
}

test.ExpressionVector.eval.env <- function(){
	funx <- .rcpp.Vector$expression_evalenv
	e <- new.env()
	e[["x"]] <- sample(1:10)
	checkEquals( funx(e), 1:10, msg = "ExpressionVector::eval in specific environment" )
}

