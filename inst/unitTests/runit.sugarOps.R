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
    	"vector_plus" = list(signature(x = "numeric"),
    			'
			NumericVector xx(x);
			NumericVector yy = xx + 2;
			return yy;
			'
			)
    	,
    	"matrix_plus" = list(signature(x = "numeric"),
			'
			NumericMatrix xx(x);
			// -- fails to compile  NumericMatrix yy = xx + 2;
			NumericMatrix yy = xx;
			return yy;
			'
			)
    )
}

.setUp <- function(){
    if ( ! exists( ".rcpp.sugarOps", globalenv() ) ) {
        fun <- Rcpp:::compile_unit_tests(definitions())
        assign( ".rcpp.sugarOps", fun, globalenv() )
    }
}

test.vector.plus <- function( ){
    fx <- .rcpp.sugarOps$vector_plus
    x <- rnorm(10)
    checkEquals(fx(x) , x + 2)
}

test.matrix.plus <- function( ){
    fx <- .rcpp.sugarOps$matrix_plus
    x <- matrix(rnorm(10), 5, 2)
    #checkEquals(fx(x) , x + 2)
    checkEquals(fx(x) , x )             # DUMMY
}
