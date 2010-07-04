
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

# does not yet work because of some compiler ambiguities

# .setUp <- function(){
# 	if( ! exists( ".rcpp.sugar.matrix", globalenv() ) ){
# 		# definition of all the functions at once
# 		
# 		sugar.functions <- list( 
# 			"runit_outer" = list( 
# 				signature( x = "numeric", y = "numeric" ), 
# '
# NumericVector xx(x) ;
# NumericVector yy(y);
# NumericMatrix m = outer( xx, yy, std::plus<double>() ) ;
# return m ;
# '		), 
# 			"runit_row" = list( 
# 				signature( x = "numeric" ), 
# '
# NumericMatrix xx(x) ;
# return wrap( row( xx ) ) ;
# '
# 			) 
# 		)
# 		
# 		signatures <- lapply( sugar.functions, "[[", 1L )
# 		bodies <- lapply( sugar.functions, "[[", 2L )
# 		fx <- cxxfunction( signatures, bodies, plugin = "Rcpp")
# 		getDynLib( fx ) # just forcing loading the dll now
# 		assign( ".rcpp.sugar", fx, globalenv() )			
# 	}
# }
# 			
# test.sugar.outer <- function( ){
# 	fx <- .rcpp.sugar.matrix$runit_outer
# 	x <- 1:2
# 	y <- 1:5
# 	checkEquals( fx(x,y) , outer(x,y,"+") )
# }
# 
# test.sugar.row <- function( ){
# 	fx <- .rcpp.sugar.matrix$runit_row
# 	m <- matrix( 1:16, nc = 4 )
# 	checkEquals( fx(m), row(m) ) 
# }
# 
