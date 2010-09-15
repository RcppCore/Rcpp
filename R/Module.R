# Copyright (C)        2010 John Chambers, Dirk Eddelbuettel and Romain Francois
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

## "Module" class as an environment with "pointer", "moduleName", and "packageName"
## Stands in for a reference class with those fields.
setClass( "Module",  contains = "environment" )
setClass( "C++Class", 
	representation( pointer = "externalptr", module = "externalptr" ), 
	contains = "character"
	)
setClass( "C++ClassRepresentation", 
    representation( pointer = "externalptr" ), 
    contains = "classRepresentation" )
setClass( "C++Property" )	
setClass( "C++Object", 
	representation( 
		module = "externalptr", 
		cppclass = "externalptr", 
		pointer = "externalptr"
		)
	)
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

## FIXME:  should be set to something that will not segfault if accidentally
## called as a module pointer (but one hopes to intercept any such call)
## AND:: curently a bug in identical() fails to return TRUE on externalptr's
## so for now we initialize the "pointer" to a NULL (!)
.badModulePointer <- NULL

.setModulePointer <- function(module, value) {
    assign("pointer", value, envir = as.environment(module))
    value
}

.getModulePointer <- function(module, mustStart = TRUE) {
    pointer <- get("pointer", envir = as.environment(module))
    if(is.null(pointer) && mustStart) {
## should be (except for bug noted in identical())        
##    if(identical(pointer, .badModulePointer) && mustStart) {
        Module(module, mustStart = TRUE) # will either initialize pointer or throw error
        pointer <- get("pointer", envir = as.environment(module))
    }
    pointer
}
    

setMethod("initialize", "Module",
          function(.Object,
                   moduleName = "UNKNOWN",
                   packageName = "",
                   pointer = .badModulePointer, ...) {
              env <- new.env(TRUE, emptyenv())
              as(.Object, "environment") <- env
              assign("pointer", pointer, envir = env)
              assign("packageName", packageName, envir = env)
              assign("moduleName", moduleName, envir = env)
              if(length(list(...)) > 0) {
                  .Object <- callNextMethod(.Object, ...)
              }
              .Object
          })
                  

setMethod( "$", "Module", function(x, name){
    pointer <- .getModulePointer(x)
	if( .Call( "Module__has_function", pointer, name, PACKAGE = "Rcpp" ) ){
		function( ... ) {
			res <- .External(  "Module__invoke" , pointer, name, ..., PACKAGE = "Rcpp"  )
			if( isTRUE( res$void ) ) invisible(NULL) else res$result	
		}
	} else if( .Call("Module__has_class", pointer, name, PACKAGE = "Rcpp" ) ){
		.Call( "Module__get_class", pointer, name, PACKAGE = "Rcpp" )  
	} else{
		stop( "no such method or class in module" )
	}
} )

setMethod( "show", "Module", function( object ){
    pointer <- .getModulePointer(object, FALSE)
    if(identical(pointer, .badModulePointer)) {
        object <- as.environment(object) ## not needed when 2.12.0 arrives
        txt <- sprintf("Uninitialized module named \"%s\" from package \"%s\"",
                       get("moduleName", envir = object),
                       get("packageName", envir = object))
        writeLines(txt)
    }
    else {
	info <- .Call( "Module__funtions_arity", pointer, PACKAGE = "Rcpp" )
	name <- .Call( "Module__name", pointer )
	txt <- sprintf( "Rcpp module '%s' \n\t%d functions: ", name, length(info) )
	writeLines( txt )                       
	txt <- sprintf( "%15s : %d arguments", names(info), info )
	writeLines( txt )
	                                                     
	info <- .Call( "Module__classes_info", pointer, PACKAGE = "Rcpp" )
	txt <- sprintf( "\n\t%d classes : ", length(info) )
	writeLines( txt )
	txt <- sprintf( "%15s ", names(info) )
	writeLines( txt )
    }
} )

setGeneric( ".DollarNames" )
.DollarNames.Module <- function(x, pattern){
	grep( pattern , .Call( "Module__complete", x@pointer, PACKAGE = "Rcpp"), value = TRUE )	
}
setMethod( ".DollarNames", "Module", .DollarNames.Module )

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
	new( as.character(Class), pointer = out$xp, cppclass = Class@pointer, module = Class@module )
} )

MethodInvoker <- function( x, name ){
	function(...){
		res <- .External( "Class__invoke_method", x@cppclass, name, x@pointer, ... , PACKAGE = "Rcpp" )
		if( isTRUE( res$void ) ) invisible(NULL) else res$result
	}
}

# dollar_cppobject <- function(x, name){
# 	if( .Call( "Class__has_method", x@cppclass, name, PACKAGE = "Rcpp" ) ){
# 		MethodInvoker( x, name )
# 	} else if( .Call("Class__has_property", x@cppclass, name, PACKAGE = "Rcpp" ) ) {
# 		.Call( "CppClass__get", x@cppclass, x@pointer, name, PACKAGE = "Rcpp" )
# 	} else {
# 		stop( "no such method or property" )
# 	}
# }
# 
# setMethod( "$", "C++Object", dollar_cppobject )
# 
# dollargets_cppobject <- function(x, name, value){
# 	if( .Call("Class__has_property", x@cppclass, name, PACKAGE = "Rcpp" ) ){
# 		.Call( "CppClass__set", x@cppclass, x@pointer, name, value, PACKAGE = "Rcpp" )
# 	}
# 	x
# }
# 
# setReplaceMethod( "$", "C++Object", dollargets_cppobject )

Module <- function( module, PACKAGE = getPackageName(where), where = topenv(parent.frame()), mustStart = FALSE ){
    if(is(module, "Module")) {
        xp <- .getModulePointer(module, FALSE)
        if(!missing(PACKAGE))
            warning("ignoring PACKAGE argument in favor of internal package from Module object")
        env <- as.environment(module) # not needed from R 2.12.0
        PACKAGE <- get("packageName", envir = env)
        moduleName <- get("moduleName", envir = env)
    }
	else if( identical( typeof( module ), "externalptr" ) ){
            ## [john] Should Module() ever be called with a pointer as argument?
            ## If so, we need a safe check of the pointer's validity
            
            ## [romain] I don't think we actually can, external pointers 
            ## are stored as void*, they don't know what they are. Or we could 
            ## perhaps keep a vector of all known module pointers
		xp <- module
                moduleName <- .Call( "Module__name", xp )
                module <- new("Module", pointer = xp, packageName = PACKAGE,
                              moduleName = moduleName)
	} else if(is(module, "character")) {
            moduleName <- module
            xp <- .badModulePointer
            module <- new("Module", pointer = xp, packageName = PACKAGE,
                              moduleName = moduleName)
        }
        if(identical(xp, .badModulePointer)) {
            if(mustStart) {
		name <- sprintf( "_rcpp_module_boot_%s", moduleName )
		symbol <- tryCatch(getNativeSymbolInfo( name, PACKAGE ),
                                   error = function(e)e)
                if(is(symbol, "error"))
                    stop(gettextf("Failed to initialize module pointer: %s",
                                  symbol), domain = NA)
		xp  <- .Call( symbol )
                .setModulePointer(module, xp)
            }
            else
                return(module)
        }
	classes <- .Call( "Module__classes_info", xp, PACKAGE = "Rcpp" )
	if( length( classes ) ){
		for( i in seq_along(classes) ){
                    ## We need a general strategy for assigning class defintions
                    ## since delaying the initialization of the module causes
                    ## where to be the Rcpp namespace:
                        if(environmentIsLocked(where))
                            where <- .GlobalEnv # or???
			CLASS <- classes[[i]]
			clname <- as.character(CLASS)
			
			interface <- sprintf( "interface_%s", clname )
			setClass( interface, where = where )
			cdef <- getClassDef( interface, where = where )
			classRep <- new( "C++ClassRepresentation", 
			    pointer = CLASS@pointer, className = cdef@className, 
			    virtual = TRUE, versionKey = cdef@versionKey, 
			    package = cdef@package, 
			    sealed  = cdef@sealed 
			    # anything else
			)
			assignClassDef( interface, classRep, where)
    
			fc <- .Call( "CppClass__property_classes", CLASS@pointer, PACKAGE = "Rcpp" )
			class_names <- names( fc )
			fieldClasses <- fieldPrototypes <- fc
			for( f in class_names ){
			    fieldClasses[[ f ]] <- sprintf( "C++Property__%s__%s", clname, fc[[f]] )
			    if( is.null( getClassDef( fieldClasses[[ f ]] ) ) ){
			        setClass( fieldClasses[[ f ]], contains = "C++Property", where = where )
			    }
			    fieldPrototypes[[ f ]] <- new( fieldClasses[[ f ]] )
			}
			dummy <- list() ; names(dummy) <- character(0)
			setRefClass( clname, 
			    # fieldClasses = fieldClasses,
			    fieldPrototypes = dummy , 
			    contains = "C++Object", 
			    interfaceClasses = classRep, 
			    where = where
			)
			
			imethods <- referenceMethods( classRep )
				  
			initializer <- function(.Object, ...){
				.Object <- callNextMethod()
				
				# why is this not already done ?
				selfEnv <- .Object@.xData
				assign( ".self", .Object, envir = selfEnv )
				
				# <hack>
				try( rm( list = names(fieldClasses), envir = selfEnv ), silent = TRUE )
				for( prop in names(fieldClasses) ){
				    caps <- methods:::firstCap( prop )
				    binding_fun <- function(x){
				        if( missing(x) ){
				            GET( )
				        } else {
				            SET( x )
				        }
				    }
				    e <- new.env()
				    e[[ "GET" ]] <- imethods[[ caps$get ]]
				    e[[ "SET" ]] <- imethods[[ caps$set ]]
				    environment( e[["GET"]] ) <- selfEnv
				    environment( e[["SET"]] ) <- selfEnv
				    environment( binding_fun ) <- e
				    
				    makeActiveBinding( prop, binding_fun , selfEnv )
				}
				# </hack>
				if( .Call( "CppObject__needs_init", .Object@pointer, PACKAGE = "Rcpp" ) ){
					out <- new_CppObject_xp( CLASS, ... )
					.Object@pointer   <- out$xp
					.Object@cppclass  <- CLASS@pointer
					.Object@module    <- CLASS@module
				}
				.Object
			}
			setMethod( "initialize",clname, initializer, where = where )
			
			# METHODS <- .Call( "CppClass__methods" , CLASS@pointer , PACKAGE = "Rcpp" )
			# if( "[[" %in% METHODS ){
			# 	setMethod( "[[", clname, function(x, i, j, ...){
			# 		MethodInvoker( x, "[[" )( i )
			# 	}, where = where )
			# }
			#            
			# if( "[[<-" %in% METHODS ){
			# 	setReplaceMethod( "[[", clname, function(x, i, j, ..., exact = TRUE, value ){
			# 		MethodInvoker( x, "[[<-" )( i, value )
			# 		x
			# 	}, where = where )
			# }
			
		}
	}
	module
}

setGeneric( "complete", function(x) standardGeneric("complete") )
setMethod( "complete", "C++Object", function(x){
	xp <- x@cppclass
	.Call( "CppClass__complete" , xp , PACKAGE = "Rcpp" )
} )

".DollarNames.C++Object" <- function( x, pattern ){
	grep( pattern, complete(x), value = TRUE )
}
setMethod( ".DollarNames", "C++Object", `.DollarNames.C++Object` )

setGeneric( "functions", function(object, ...) standardGeneric( "functions" ) )
setMethod( "functions", "Module", function(object, ...){
    pointer <- .getModulePointer(object)
    if(identical(pointer, .badModulePointer))
        stop(gettextf("Module \"%s\" has not been intialized:  try Module(object)",
                      get("moduleName", envir = as.environment(object))), domain = NA)
    else
	.Call( "Module__funtions_arity", pointer, PACKAGE = "Rcpp" )
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

        ## at this point functions() would have failed if the
        ## pointer in object was not valid
        pointer <- .getModulePointer(object)
	
	classes <- .Call( "Module__classes_info", pointer, PACKAGE = "Rcpp" )
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

.referenceMethods__cppclass <- function( classDef, where ){
    xp <- classDef@pointer
    
    met <- .Call( "CppClass__methods", xp, PACKAGE = "Rcpp" )
    arity <- .Call( "CppClass__methods_arity", xp, PACKAGE = "Rcpp" )
	voidness <- .Call( "CppClass__methods_voidness", xp, PACKAGE = "Rcpp" )
	
	mets <- sapply( met, function( m ){
	    # skeleton
	    f <- function( ){
	        res <- .External( "Class__invoke_method", .self@cppclass , m, .self@pointer, PACKAGE = "Rcpp" )
	        # TODO: update Class__invoke_method so that it does not create a list
	        #       list( void, result ) since we already know that information
	        res$result
	    }
	    body( f )[[2]][[3]][[4]] <- m 
	    
	    
	    if( ar <- arity[[ m ]] ){
	        # change the formal arguments
	        formals( f ) <- structure( rep( alist( . = ), ar ), names = sprintf( "x%d", seq_len(ar) ) )
	    
	        # change the body
	        b <- body( f )
	        ext.call <- quote( .External( "Class__invoke_method", PACKAGE="Rcpp", .self@cppclass, m, .self@pointer, ARG) )[ c(1:6, rep(7L, ar )) ]
	        ext.call[[5]] <- m
	        for( i in seq_len(ar) ){
	            ext.call[[ 6 + i ]] <- as.name( paste( "x", i, sep = "" ) )
	        }
	        b[[2]][[3]] <- ext.call
	        body( f ) <- b
	    }
	    
	    if( voidness[[m]] ){
	        b <- body( f )
	        b[[3]] <- quote( invisible( NULL ) )
	        body( f ) <- b
	    }
	    
	    f
	} )
	
	props <- .Call( "CppClass__properties", xp, PACKAGE = "Rcpp" )
	accesors <- lapply( props, function(p){
	    
	    getter <- function(){
	        .Call( "CppClass__get", .self@cppclass, .self@pointer, p, PACKAGE = "Rcpp" )
	    }
	    body( getter )[[2]][[5]] <- p
	    
	    setter <- function(value){
	        .Call( "CppClass__set", .self@cppclass, .self@pointer, p, value, PACKAGE = "Rcpp" )
	        invisible( NULL )
	    }
	    body( setter )[[2]][[5]] <- p
	    
	    res <- list( get = getter, set = setter )
	    names( res ) <- methods:::firstCap( p )
	    res
	} )
	
	c( mets, accesors, recursive = TRUE )
    
}
setMethod( "referenceMethods", "C++ClassRepresentation", .referenceMethods__cppclass )

