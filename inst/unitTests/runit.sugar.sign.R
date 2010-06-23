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

test.sugar.sign <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create(
			sign( xx ), 
			sign( yy )
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( 
		fx( seq(-10, 10, length.out = 51), -25:25 ), 
		list( 
			c( rep(-1L, 25), 0L, rep(1L, 25) ), 
			c( rep(-1L, 25), 0L, rep(1L, 25) )
		)
	)
}

