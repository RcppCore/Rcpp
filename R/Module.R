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

internal_function <- function(pointer){
	f <- function(xp){
		force(xp)
		function(...){
			.External( InternalFunction_invoke, xp, ... )
		}
	}
	o <- new( "C++Function", f(pointer) )
	o@pointer <- pointer
	o
}

setMethod("$", "C++Class", function(x, name) {
    x <- x@generator
    eval.parent(substitute(x$name))
})

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
	if( .Call( Module__has_function, pointer, name ) ){
		function( ... ) {
			res <- .External( Module__invoke , pointer, name, ... )
			if( isTRUE( res$void ) ) invisible(NULL) else res$result
		}
	} else if( .Call( Module__has_class, pointer, name ) ){
		value <- .Call( Module__get_class, pointer, name )
                value@generator <-  get("refClassGenerators",envir=x)[[as.character(value)]]
                value
	} else{
		stop( "no such method or class in module" )
	}
} )

new_CppObject_xp <- function(module, pointer, ...) {
	.External( class__newInstance, module, pointer, ... )
}


# class method for $initialize
cpp_object_initializer <- function(.self, .refClassDef, ...){
    selfEnv <- as.environment(.self)
    ## generate the C++-side object and store its pointer, etc.
    ## access the private fields in the fieldPrototypes env.
    fields <- .refClassDef@fieldPrototypes
    pointer <- new_CppObject_xp(fields$.module, fields$.pointer, ...)
    assign(".module", fields$.module, envir = selfEnv)
    assign(".pointer", pointer, envir = selfEnv)
    assign(".cppclass", fields$.pointer, envir = selfEnv)
    .self
}

Module <- function( module, PACKAGE = getPackageName(where), where = topenv(parent.frame()), mustStart = FALSE ) {
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
        ## [John]  One technique is to initialize the pointer to a known value
        ## and just check whether it's been reset from that (bad) value
        xp <- module
        moduleName <- .Call( Module__name, xp )
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
    classes <- .Call( Module__classes_info, xp )

    ## We need a general strategy for assigning class defintions
    ## since delaying the initialization of the module causes
    ## where to be the Rcpp namespace:
    if(environmentIsLocked(where))
        where <- .GlobalEnv # or???
    generators <- list()
    for( i in seq_along(classes) ){
        CLASS <- classes[[i]]
        clname <- as.character(CLASS)

        fields <- cpp_fields( CLASS, where )
        methods <- cpp_refMethods(CLASS, where)
        generator <- setRefClass( clname,
                                 fields = fields,
                                 contains = "C++Object",
                                 methods = methods,
                                 where = where
                                 )
        # just to make codetools happy
        .self <- .refClassDef <- NULL
        generator$methods(initialize = function(...) Rcpp:::cpp_object_initializer(.self,.refClassDef, ...))
        rm( .self, .refClassDef )
        
        classDef <- getClass(clname)
        ## non-public (static) fields in class representation
        ## <fixme>  Should these become real fields? </fixme>
        fields <- classDef@fieldPrototypes
        assign(".pointer", CLASS@pointer, envir = fields)
        assign(".module", xp, envir = fields)
        assign(".CppClassName", clname, envir = fields)
        generators[[clname]] <- generator
        
        # [romain] : should this be promoted to reference classes
        #            perhaps with better handling of j and ... arguments
        if( any( grepl( "^[[]", names(CLASS@methods) ) ) ){
            if( "[[" %in% names( CLASS@methods ) ){
                setMethod( "[[", clname, function(x, i, j, ..., exact = TRUE){
                    x$`[[`( i )
                }, where = where )
            }
            
            if( "[[<-" %in% names( CLASS@methods ) ){
                setReplaceMethod( "[[", clname, function(x, i, j, ..., exact = TRUE, value){
                    x$`[[<-`( i, value )
                    x
                } , where = where )
            }
            
        }
    }
    module$refClassGenerators <- generators
    module
}

method_wrapper <- function( METHOD, where ){
            f <- function(...) NULL
	    extCall <- substitute(
	    {
           res <- .External(CppMethod__invoke, class_pointer, pointer, .pointer, ...)
           if(res[[1]]) invisible(NULL) else res[[2]]
        }
           ,
            list(
                class_pointer = METHOD$class_pointer,
                pointer = METHOD$pointer,
                CppMethod__invoke = CppMethod__invoke
                 )
            )
            body(f, where) <- extCall
            f
	}
## create a named list of the R methods to invoke C++ methods
## from the C++ class with pointer xp
cpp_refMethods <- function(CLASS, where) {
    finalizer <- eval( substitute( 
	    function(){
	        .Call( CppObject__finalize, class_pointer , .pointer )
	    }, 
	    list( 
	        CLASS = CLASS@pointer, 
	        CppObject__finalize = CppObject__finalize, 
	        class_pointer = CLASS@pointer
	    )
	) )
	mets <- c( 
	    sapply( CLASS@methods, method_wrapper, where = where ),
	    "finalize" = finalizer
	)
    mets
}

binding_maker <- function( FIELD, where ){
    f <- function( x ) NULL
    body(f) <- substitute({
        if( missing( x ) )
            .Call( CppField__get, class_pointer, pointer, .pointer)
        else
            .Call( CppField__set, class_pointer, pointer, .pointer, x)
    }, list(class_pointer = FIELD$class_pointer,
            pointer = FIELD$pointer, 
            CppField__get = CppField__get, 
            CppField__set = CppField__set ))
    environment(f) <- where
    f
}
    
cpp_fields <- function( CLASS, where){
     sapply( CLASS@fields, binding_maker, where = where )
}

