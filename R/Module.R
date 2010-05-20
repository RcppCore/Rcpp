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

# not yet
# setClass( "Module", representation( pointer = "externalptr" ) )
# 
# Module <- function( module, PACKAGE ){
# 	name <- sprintf( "_rcpp_module_boot_%s", module )
# 	symbol <- getNativeSymbolInfo( name, PACKAGE )
# 	xp  <- .Call( symbol )
# 	new( "Module", pointer = xp ) 
# }
# 
# setMethod( "$", "Module", function(x, name){
# 	function( ... ) {
# 		res <- .External(  "Module__invoke" , x@pointer, name, ..., PACKAGE = "Rcpp"  )
# 		if( isTRUE( res$void ) ) invisible(NULL) else res$result	
# 	}
# } )
# 
# setMethod( "show", "Module", function( object ){
# 	info <- .Call( "Module__funtions_arity", object@pointer, PACKAGE = "Rcpp" )
# 	name <- .Call( "Module__name", object@pointer )
# 	txt <- sprintf( "Rcpp module '%s' \n\t%d functions: ", name, length(info) )
# 	writeLines( txt )
# 	txt <- sprintf( "%15s : %d arguments", names(info), info )
# 	writeLines( txt )
# } )

#TODO: maybe attach( Module ), with( Module )

