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

setOldClass( "C++ObjectS3" )
setClass( "Module", representation( pointer = "externalptr" ) )
setClass( "C++Class", 
	representation( pointer = "externalptr", module = "externalptr" ), 
	contains = "character"
	)
setClass( "C++Object", 
	representation( 
		module = "externalptr", 
		cppclass = "externalptr", 
		pointer = "externalptr"
		), 
	contains = "C++ObjectS3" )
setClass( "C++Function", 
	representation( pointer = "externalptr" ), 
	contains = "function"
)
     
internal_function <- function(pointer){
	f <- function(xp){
		force(xp)
		function(...){
			.External( "InternalFunction_invoke" , PACKAGE = "Rcpp", xp, ... )
		}
	}
	o <- new( "C++Function", f(pointer) )
	o@pointer <- pointer
	o
}
setMethod( "show", "C++Function", function(object){
	writeLines( sprintf( "internal C++ function <%s>", externalptr_address(object@pointer) ) )
} )

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

.DollarNames.Module <- function(x, pattern){
	grep( pattern , .Call( "Module__complete", x@pointer, PACKAGE = "Rcpp"), value = TRUE )	
}

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

MethodInvoker <- function( x, name ){
	function(...){
		res <- .External( "Class__invoke_method", x@cppclass, name, x@pointer, ... , PACKAGE = "Rcpp" )
		if( isTRUE( res$void ) ) invisible(NULL) else res$result
	}
	
}

dollar_cppobject <- function(x, name){
	if( .Call( "Class__has_method", x@cppclass, name, PACKAGE = "Rcpp" ) ){
		MethodInvoker( x, name )
	} else if( .Call("Class__has_property", x@cppclass, name, PACKAGE = "Rcpp" ) ) {
		.Call( "CppClass__get", x@cppclass, x@pointer, name, PACKAGE = "Rcpp" )
	} else {
		stop( "no such method or property" )
	}
}

setMethod( "$", "C++Object", dollar_cppobject )

dollargets_cppobject <- function(x, name, value){
	if( .Call("Class__has_property", x@cppclass, name, PACKAGE = "Rcpp" ) ){
		.Call( "CppClass__set", x@cppclass, x@pointer, name, value, PACKAGE = "Rcpp" )
	}
	x
}

setReplaceMethod( "$", "C++Object", dollargets_cppobject )

Module <- function( module, PACKAGE = getPackageName(where), where = topenv(parent.frame()) ){
	if( identical( typeof( module ), "externalptr" ) ){
		xp <- module
	} else {
		name <- sprintf( "_rcpp_module_boot_%s", module )
		symbol <- getNativeSymbolInfo( name, PACKAGE )
		xp  <- .Call( symbol )
	}
	classes <- .Call( "Module__classes_info", xp, PACKAGE = "Rcpp" )
	if( length( classes ) ){
		for( i in seq_along(classes) ){
			CLASS <- classes[[i]]
			clname <- as.character(CLASS)
			setClass( clname, contains = "C++Object", where = where )
			setMethod( "initialize",clname, function(.Object, ...){
				.Object <- callNextMethod()
				if( .Call( "CppObject__needs_init", .Object@pointer, PACKAGE = "Rcpp" ) ){
					out <- new_CppObject_xp( CLASS, ... )
					.Object@pointer <- out$xp
					.Object@cppclass <- CLASS@pointer
					.Object@module <- CLASS@module
				}
				.Object
			} , where = where )
			
			METHODS <- .Call( "CppClass__methods" , CLASS@pointer , PACKAGE = "Rcpp" )
			if( "[[" %in% METHODS ){
				setMethod( "[[", clname, function(x, i, j, ...){
					MethodInvoker( x, "[[" )( i )
				}, where = where )
			}
			
			if( "[[<-" %in% METHODS ){
				setReplaceMethod( "[[", clname, function(x, i, j, ..., exact = TRUE, value ){
					MethodInvoker( x, "[[<-" )( i, value )
					x
				}, where = where )
			}
			
		}
	}
	new( "Module", pointer = xp ) 
}

setGeneric( "complete", function(x) standardGeneric("complete") )
setMethod( "complete", "C++Object", function(x){
	xp <- x@cppclass
	.Call( "CppClass__complete" , xp , PACKAGE = "Rcpp" )
} )

".DollarNames.C++ObjectS3" <- function( x, pattern ){
	grep( pattern, complete(x), value = TRUE )
}

setGeneric( "functions", function(object, ...) standardGeneric( "functions" ) )
setMethod( "functions", "Module", function(object, ...){
	.Call( "Module__funtions_arity", object@pointer, PACKAGE = "Rcpp" )
} )

setGeneric( "prompt" )
setMethod( "prompt", "Module", function(object, filename = NULL, name = NULL, ...){
	lines <- readLines( system.file( "prompt", "module.Rd", package = "Rcpp" ) )
	if( is.null(name) ) name <- .Call( "Module__name", object@pointer, PACKAGE = "Rcpp" )
	if( is.null(filename) ) filename <- sprintf( "%s-module.Rd", name )
	lines <- gsub( "NAME", name, lines )
	
	info <- functions( object )
	f.txt <- if( length( info ) ){
		sprintf( "functions: \\\\describe{
%s
		}", paste( sprintf( "        \\\\item{%s}{ ~~ description of function %s ~~ }", names(info), names(info) ), collapse = "\n" ) )
	} else {
		"" 
	}
	lines <- sub( "FUNCTIONS", f.txt, lines )
	
	classes <- .Call( "Module__classes_info", object@pointer, PACKAGE = "Rcpp" )
	c.txt <- if( length( classes ) ){
		sprintf( "classes: \\\\describe{
%s
		}", paste( sprintf( "        \\\\item{%s}{ ~~ description of class %s ~~ }", names(classes), names(classes) ), collapse = "\n" ) )
	} else {
		"" 
	}
	lines <- sub( "CLASSES", c.txt, lines )
	
	writeLines( lines, filename )
	invisible(NULL)
} )

setMethod( "show", "C++Object", function(object){
	txt <- sprintf( "C++ object <%s> of class '%s' <%s>", 
		externalptr_address(object@pointer), 
		.Call( "Class__name", object@cppclass, PACKAGE = "Rcpp" ), 
		externalptr_address(object@cppclass)
	)
	writeLines( txt )
} )

setMethod( "show", "C++Class", function(object){
	txt <- sprintf( "C++ class '%s' <%s>", 
		.Call( "Class__name", object@pointer, PACKAGE = "Rcpp" ), 
		externalptr_address(object@pointer) )
	writeLines( txt )
	
	met <- .Call( "CppClass__methods", object@pointer, PACKAGE = "Rcpp" )
	if( length( met ) ){
		txt <- sprintf( "\n%d methods : \n%s", length(met), paste( sprintf("    %s", met), collapse = "\n") )
		writeLines( txt )
	}
} )

