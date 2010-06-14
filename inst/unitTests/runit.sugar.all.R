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

test.sugar.all.less <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx < yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.greater <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx > yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 0:9, c(0:8,10) ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.less.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx <= yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.greater.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx >= yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}


test.sugar.all.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx == yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.not.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx != yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

