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


is.valid.for.dot.call <- function( symbol ){
	cl <- oldClass( symbol )
	identical( cl, "NativeSymbolInfo" ) || identical( cl, c("CallRoutine", "NativeSymbolInfo") )
}

.Cpp <- function(name, ..., PACKAGE){
	symbol <- if( inherits( name , "NativeSymbolInfo" ) ){
		name
	} else{
		if( missing(PACKAGE) ){
			getNativeSymbolInfo( name )
		} else{
			getNativeSymbolInfo( name, PACKAGE )
		}
	}
	if( ! is.valid.for.dot.call(symbol ) ){
		stop( ".Cpp only supports .Call compatible routines" )
	}
	.External( "do_dot_cpp", 
		symbol$address,         # external pointer tp the C routine
		symbol$numParameters,   # number of parameters it expects (or NULL)
		...,                    # actual parameters 
		PACKAGE = "Rcpp" )
}
