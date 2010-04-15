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

HAVEINLINE <- FALSE
cfunction <- function(...) stop( "inline not available" ) 

cppfunction <- function (sig = character(), body = character(), includes = character(), 
    otherdefs = character(), verbose = FALSE, 
    cppargs = character(), cxxargs = character(), libargs = character(), 
    .Cpp = TRUE){
	
    ok <- HAVEINLINE
	if( !ok){
		if( "package:inline" %in% search() ){
			ok <- TRUE
		} else{
			ok <- tryCatch( {
				require( "inline" )
				TRUE 
			} , error = function(e) FALSE )
		}
		if( ! ok ){
			stop( "package inline is not available" )	
		}
		HAVEINLINE <<- TRUE
		cfunction <<- get( "cfunction", asNamespace( "inline" ) )
	}
	fx <- cfunction( sig = sig, body = body, includes = includes, 
		otherdefs = otherdefs, language = "C++", convention = ".Call", 
		Rcpp = TRUE, cppargs = cppargs, cxxargs = cxxargs, libargs = libargs, 
		verbose = verbose )
	if( isTRUE( .Cpp ) ){
		# replace .Call by Rcpp::.Cpp
		# this is somewhat heuristic, maybe we should search for .Call as opposed
		# to assume it is in this position
		body( fx@.Data )[[4]][[1]] <- call( "::", as.name("Rcpp"), as.name(".Cpp") )
	}
	fx
}
