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

definitions <- function() {
    list(
    "plus_REALSXP"=list(
         signature(),
         '
         return List::create( 
           NA_REAL + NA_REAL, 
           NA_REAL + 1.0,
           1.0 + NA_REAL 
           ); 
         '), 
    "times_REALSXP" = list( 
       signature(), 
       '
        return List::create( 
           NA_REAL * NA_REAL, 
           NA_REAL * 1.0,
           1.0 * NA_REAL 
           ); 
       '), 
     "divides_REALSXP" = list( 
        signature(), 
        '
        return List::create( 
           NA_REAL / NA_REAL, 
           NA_REAL / 1.0,
           1.0 / NA_REAL 
           ); 
        '
     ), 
     "minus_REALSXP" = list( 
        signature(), 
        '
        return List::create( 
           NA_REAL - NA_REAL, 
           NA_REAL - 1.0,
           1.0 - NA_REAL 
           ); 
        '
     )
    )
}
.setUp <- function() {
    tests <- ".rcpp.support"
    if( ! exists( tests, globalenv() )) {
        fun <- Rcpp:::compile_unit_tests(definitions())
        assign( tests, fun, globalenv() )
    }
}

test.plus.REALSXP <- function(){
    fun <- .rcpp.support$plus_REALSXP
    checkEquals( 
        fun(), 
        list(NA_real_,NA_real_,NA_real_) , 
        msg = " REALSXP + REALSXP" )
}

test.times.REALSXP <- function(){
    fun <- .rcpp.support$times_REALSXP
    checkEquals( 
        fun(), 
        list(NA_real_,NA_real_,NA_real_) , 
        msg = " REALSXP * REALSXP" )
}

test.divides.REALSXP <- function(){
    fun <- .rcpp.support$divides_REALSXP
    checkEquals( 
        fun(), 
        list(NA_real_,NA_real_,NA_real_) , 
        msg = " REALSXP / REALSXP" )
}

test.minus.REALSXP <- function(){
    fun <- .rcpp.support$minus_REALSXP
    checkEquals( 
        fun(), 
        list(NA_real_,NA_real_,NA_real_) , 
        msg = " REALSXP - REALSXP" )
}

