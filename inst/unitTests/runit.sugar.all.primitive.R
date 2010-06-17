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

test.sugar.all.one.less <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return all( xx < 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( is.na( fx( NA ) ) )
	checkTrue( is.na( fx( c( NA, 1)  ) ) )
	checkTrue( ! fx( c( 6, NA)  ) )
	
}

test.sugar.all.one.greater <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	    NumericVector xx(x) ;
		return all( xx > 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
}


test.sugar.all.one.less.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return all( xx <= 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( is.na( fx( NA ) ) )
	checkTrue( is.na( fx( c( NA, 1)  ) ) )
	checkTrue( ! fx( c( 6, NA)  ) )
	checkTrue( fx( 5 ) )
	
}

test.sugar.all.one.greater.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	    NumericVector xx(x) ;
		return all( xx >= 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( fx( 5 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
}
 

test.sugar.all.one.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	   	NumericVector xx(x) ;
		return all( xx == 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:2 ) )
	checkTrue( fx( rep(5,4) ) )
	checkTrue( is.na( fx( c(5,NA) ) ) )
	checkTrue(! fx( c(NA, 1) ) )
	
}

test.sugar.all.one.not.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return all( xx != 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1 ) )
	checkTrue( fx( 1:2 ) )
	checkTrue( ! fx( 5 ) )
	checkTrue( is.na( fx( c(NA, 1) ) ) )
	checkTrue( ! fx( c(NA, 5) ) )
	
}

