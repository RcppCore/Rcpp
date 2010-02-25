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

.setUp <- function(){
	require( inline )
}

test.clone <- function(){
	
	x <- 1:10
	funx <- cfunction(signature(x="integer"), '
	IntegerVector vec(x) ;
	IntegerVector dolly = clone( vec ) ;
	for( size_t i=0; i<10; i++){
		dolly[i] = 10 - i ;
	}
	return dolly ;
	', Rcpp = TRUE, includes = "using namespace Rcpp;" )
	y <- funx(x)
	checkEquals( x, 1:10, msg = "clone" )
	checkEquals( y, 10:1, msg = "clone" )
	
	# TODO: add more
	
}

