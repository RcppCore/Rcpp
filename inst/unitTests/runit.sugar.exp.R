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

test.sugar.exp <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( exp(xx), exp(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( exp(x), exp(y) ) )
}

test.sugar.floor <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( floor(xx), floor(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( floor(x), floor(y) ) )
}

test.sugar.ceil <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( ceil(xx), ceil(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( ceiling(x), ceiling(y) ) )
}

test.sugar.pow <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( pow(xx, 3), pow(yy, 2.3) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( x^3L , y^2.3 ) )
}

