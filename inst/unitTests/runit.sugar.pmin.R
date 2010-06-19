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

test.sugar.pmin <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		NumericVector res = pmin( xx, yy );
		return res ;
	
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10, 10:1) , c(1:5,5:1) )
}

test.sugar.pmin.one <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return List::create( 
			pmin( xx, 5), 
			pmin( 5, xx)
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , 
		list( 
			c(1:5,rep(5,5)), 
			c(1:5,rep(5,5))
		)
	)
}



test.sugar.pmax <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		NumericVector res = pmax( xx, yy );
		return res ;
	
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10, 10:1) , c(10:6,6:10) )
}

test.sugar.pmax.one <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return List::create( 
			pmax( xx, 5), 
			pmax( 5, xx)
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , 
		list( 
			c(rep(5,5), 6:10), 
			c(rep(5,5), 6:10) 
		)
	) 
}

