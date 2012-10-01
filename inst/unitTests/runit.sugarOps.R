#!/usr/bin/r -t
#                     -*- mode: R; ess-indent-level: 4; indent-tabs-mode: nil; -*-
#
# Copyright (C) 2012         Dirk Eddelbuettel and Romain Francois
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

definitions <- function() {
    list(
    	"vector_scalar_ops" = list(signature(x = "numeric"),
    			'
			NumericVector xx(x);
			NumericVector y1 = xx + 2.0;  // NB does not work with ints as eg "+ 2L"
			NumericVector y2 = 2 - xx;
			NumericVector y3 = xx * 2.0;
			NumericVector y4 = 2.0 / xx;
			return List::create(y1, y2, y3, y4);
			'
			)

        ,
    	"vector_scalar_logical" = list(signature(x = "numeric"),
    			'
			NumericVector xx(x);
			LogicalVector y1 = xx < 2;
			LogicalVector y2 = 2  > xx;
			LogicalVector y3 = xx <= 2;
			LogicalVector y4 = 2 != xx;
			return List::create(y1, y2, y3, y4);
			'
        		)

        ,
    	"vector_vector_ops" = list(signature(x = "numeric", y="numeric"),
    			'
			NumericVector xx(x);
			NumericVector yy(y);
			NumericVector y1 = xx + yy;
			NumericVector y2 = yy - xx;
			NumericVector y3 = xx * yy;
			NumericVector y4 = yy / xx;
			return List::create(y1, y2, y3, y4);
			'
        		)

        ,
    	"vector_vector_logical" = list(signature(x = "numeric", y="numeric"),
    			'
			NumericVector xx(x);
			NumericVector yy(y);
			LogicalVector y1 = xx < yy;
			LogicalVector y2 = xx > yy;
			LogicalVector y3 = xx <= yy;
			LogicalVector y4 = xx >= yy;
			LogicalVector y5 = xx == yy;
			LogicalVector y6 = xx != yy;
			return List::create(y1, y2, y3, y4, y5, y6);
			'
        		)

        ## ,
    	## "matrix_plus" = list(signature(x = "numeric"),
	## 		'
	## 		NumericMatrix xx(x);
	## 		// -- fails to compile
        ##                 NumericMatrix yy = xx + 2;
	## 		return yy;
	## 		'
	## 		)
    )
}

.setUp <- function(){
    if ( ! exists( ".rcpp.sugarOps", globalenv() ) ) {
        fun <- Rcpp:::compile_unit_tests(definitions())
        assign( ".rcpp.sugarOps", fun, globalenv() )
    }
}

test.vector.scalar.ops <- function( ){
    fx <- .rcpp.sugarOps$vector_scalar_ops
    x <- rnorm(10)
    checkEquals(fx(x), list(x + 2, 2 - x, x * 2, 2 / x), "sugar vector scalar operations")
}

test.vector.scalar.logical <- function( ){
    fx <- .rcpp.sugarOps$vector_scalar_logical
    x <- rnorm(10) + 2
    checkEquals(fx(x), list(x < 2, 2 > x, x <= 2, 2 != x), "sugar vector scalar logical operations")
}

test.vector.vector.ops <- function( ){
    fx <- .rcpp.sugarOps$vector_vector_ops
    x <- rnorm(10)
    y <- runif(10)
    checkEquals(fx(x,y), list(x + y, y - x, x * y, y / x), "sugar vector vector operations")
}

test.vector.vector.logical <- function( ){
    fx <- .rcpp.sugarOps$vector_vector_logical
    x <- rnorm(10)
    y <- runif(10)
    checkEquals(fx(x,y), list(x < y, x > y, x <= y, x >= y, x == y, x != y), "sugar vector vector operations")
}

## test.matrix.plus <- function( ){
##     fx <- .rcpp.sugarOps$matrix_plus
##     x <- matrix(rnorm(10), 5, 2)
##     checkEquals(fx(x) , x + 2)
##     #checkEquals(fx(x) , x )             # DUMMY
## }
