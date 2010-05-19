# Copyright (C)        2010 Dirk Eddelbuettel and Romain Francois
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

# TODO: this probably should be in inline rather than in Rcpp

setGeneric("getDLL", function(x, ...) standardGeneric("getDLL") )

setMethod( "getDLL", signature( x = "character" ), 
function( x ){
	dlls <- getLoadedDLLs()
	if( x %in% names( dlls ) ){
		dlls[[ x ]]
	} else {
		stop( sprintf( "dll %s not loaded" ) )	
	}
} )

setMethod( "getDLL", signature( x = "CFunc" ), 
function( x ){
	env <- environment( x@.Data )
	f <- get( "f", env )
	dlls <- getLoadedDLLs()
	dll <- if( ! f %in% names(dlls) ){
		dyn.load( get( "libLFile", env ) )
	} else{
		dlls[[ f ]]
	}
	dll
} )

