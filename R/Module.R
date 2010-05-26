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

setGeneric( "new" )

setClass( "Module", representation( pointer = "externalptr" ) )
setClass( "C++Class", representation( module = "externalptr", name = "character" ) )
setClass( "C++Object", representation( module = "externalptr", cppclass = "externalptr", pointer = "externalptr" ) )

Module <- function( module, PACKAGE ){
	name <- sprintf( "_rcpp_module_boot_%s", module )
	symbol <- getNativeSymbolInfo( name, PACKAGE )
	xp  <- .Call( symbol )
	new( "Module", pointer = xp ) 
}

setMethod( "$", "Module", function(x, name){
	if( .Call( "Module__has_function", x@pointer, name, PACKAGE = "Rcpp" ) ){
		function( ... ) {
			res <- .External(  "Module__invoke" , x@pointer, name, ..., PACKAGE = "Rcpp"  )
			if( isTRUE( res$void ) ) invisible(NULL) else res$result	
		}
	} else if( .Call("Module__has_class", x@pointer, name, PACKAGE = "Rcpp" ) ){
		.Call( "Module__get_class", x@pointer, name, PACKAGE = "Rcpp" )  
	} else{
		stop( "no such method or class in module" )
	}
} )

setMethod( "show", "Module", function( object ){
	info <- .Call( "Module__funtions_arity", object@pointer, PACKAGE = "Rcpp" )
	name <- .Call( "Module__name", object@pointer )
	txt <- sprintf( "Rcpp module '%s' \n\t%d functions: ", name, length(info) )
	writeLines( txt )           
	txt <- sprintf( "%15s : %d arguments", names(info), info )
	writeLines( txt )
	                                                     
	info <- .Call( "Module__classes_info", object@pointer, PACKAGE = "Rcpp" )
	txt <- sprintf( "\n\t%d classes : ", length(info) )
	writeLines( txt )
	txt <- sprintf( "%15s ", names(info) )
	writeLines( txt )
} )

#TODO: maybe attach( Module ), with( Module )

setMethod( "new", "C++Class", function(Class, ...){
	.External( "Module__class__newInstance", Class@module, Class@name, ..., PACKAGE = "Rcpp" )
} )

setMethod( "$", "C++Object", function(x, name){
	if( .Call( "Class__has_method", x@cppclass, name, PACKAGE = "Rcpp" ) ){
		function(...){
			res <- .External( "Class__invoke_method", x@module, x@cppclass, name, x@pointer, ..., PACKAGE = "Rcpp" )
			if( isTRUE( res$void ) ) invisible(NULL) else res$result
		}
	} else{
		stop( "no such method" )
	}
} )

