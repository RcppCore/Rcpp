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

internal.classes <- environment()

setClass( "Module", representation( pointer = "externalptr" ) )
setClass( "C++Class", representation( pointer = "externalptr", module = "externalptr" ) )
setClass( "C++Object", representation( module = "externalptr", cppclass = "externalptr", pointer = "externalptr" ) )

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

new_CppObject_xp <- function(Class, ...){
	xp <- .External( "class__newInstance", Class@module, Class@pointer, ..., PACKAGE = "Rcpp" )
	cl <- .Call( "Class__name", Class@pointer, PACKAGE = "Rcpp" )
	
	cpp <- getClass( "C++Object" )
	known_cpp_classes <- cpp@subclasses
	if( ! cl %in% names( known_cpp_classes ) ){
		cl <- "C++Object"
	}
	list( cl = cl, xp = xp )
}

setMethod( "new", "C++Class", function(Class,...){
	out <- new_CppObject_xp( Class, ... )
	new( out$cl, pointer = out$xp, cppclass = Class@pointer, module = Class@module )
} )

dollar_cppobject <- function(x, name){
	if( .Call( "Class__has_method", x@cppclass, name, PACKAGE = "Rcpp" ) ){
		function(...){
			res <- .External( "Class__invoke_method", x@cppclass, name, x@pointer, ..., PACKAGE = "Rcpp" )
			if( isTRUE( res$void ) ) invisible(NULL) else res$result
		}
	} else{
		stop( "no such method" )
	}
}

setMethod( "$", "C++Object", dollar_cppobject )

Module <- function( module, PACKAGE = getPackageName(where), where = topenv(parent.frame()) ){
	name <- sprintf( "_rcpp_module_boot_%s", module )
	symbol <- getNativeSymbolInfo( name, PACKAGE )
	xp  <- .Call( symbol )
	classes <- .Call( "Module__classes_info", xp, PACKAGE = "Rcpp" )
	if( length( classes ) ){
		clnames <- names( classes )
		for( i in seq_along(classes) ){
			setClass( clnames[i], contains = "C++Object", where = where )
			init <- function(.Object, ...){
				if( .Call( "CppObject__needs_init", .Object@pointer, PACKAGE = "Rcpp" ) ){
					CLASS <- classes[[i]]
					out <- new_CppObject_xp( CLASS, ... )
					.Object@pointer <- out$xp
					.Object@cppclass <- CLASS@pointer
					.Object@module <- CLASS@module
				}
				.Object
			}
			setMethod( "initialize", clnames[i], init , where = where )
		}
	}
	new( "Module", pointer = xp ) 
}

