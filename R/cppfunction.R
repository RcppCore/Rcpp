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

NAMESPACE <- environment()
HAVEINLINE <- FALSE
cfunction <- function(...) stop( "inline not available" )

init.inline <- function(){
	unlockBinding( "HAVEINLINE", NAMESPACE )
	unlockBinding( "cfunction", NAMESPACE )
	assignInNamespace( "HAVEINLINE", TRUE, NAMESPACE )
	assignInNamespace( "cfunction" , get( "cfunction", asNamespace( "inline" )), NAMESPACE )
	lockBinding( "HAVEINLINE", NAMESPACE )
	lockBinding( "cfunction", NAMESPACE )
}

cppfunction <- function (sig = character(), body = character(), includes = character(), 
    otherdefs = character(), verbose = FALSE, 
    cppargs = character(), cxxargs = character(), libargs = character(), 
    namespace = TRUE, forward.exceptions = TRUE ){
	
    ok <- HAVEINLINE                                                                                
	if( !ok){
		if( "package:inline" %in% search() ){
			ok <- TRUE
		} else{
			ok <- tryCatch( {
				require( "inline", character.only = TRUE, quietly = TRUE )
				TRUE 
			} , error = function(e) FALSE )
		}
		if( ! ok ){
			stop( "package inline is not available" )	
		}
		init.inline()
	}
	if( isTRUE( namespace ) ){
		includes <- c( includes, "using namespace Rcpp;" )
	}
	if( isTRUE( forward.exceptions ) ){
		body <- sprintf( 
"BEGIN_RCPP
%s
END_RCPP
", body )
	}
	fx <- cfunction( sig = sig, body = body, includes = includes, 
		otherdefs = otherdefs, language = "C++", convention = ".Call", 
		Rcpp = TRUE, cppargs = cppargs, cxxargs = cxxargs, libargs = libargs, 
		verbose = verbose )
	fx
}
