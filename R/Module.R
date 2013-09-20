# Copyright (C) 2010 - 2012 John Chambers, Dirk Eddelbuettel and Romain Francois
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

.get_Module_function <- function(x, name, pointer = .getModulePointer(x) ){
    pointer <- .getModulePointer(x)
	info <- .Call( Module__get_function, pointer, name )
	fun_ptr <- info[[1L]]
	is_void <- info[[2L]]
	doc     <- info[[3L]]
	sign    <- info[[4L]]
	formal_args <- info[[5L]]
	nargs <- info[[6L]]
	f <- function(...) NULL
	if( nargs == 0L ) formals(f) <- NULL
	stuff <- list( fun_pointer = fun_ptr, InternalFunction_invoke = InternalFunction_invoke )
	body(f) <- if( nargs == 0L ){
	    if( is_void ) {
	        substitute( {
	            .External( InternalFunction_invoke, fun_pointer)
	            invisible(NULL)
	        }, stuff )
	    } else {
	        substitute( {
	            .External( InternalFunction_invoke, fun_pointer)
	        }, stuff )
	    }
	} else {
	    if( is_void ) {
	        substitute( {
	            .External( InternalFunction_invoke, fun_pointer, ... )
	            invisible(NULL)
	        }, stuff )
	    } else {
	        substitute( {
	            .External( InternalFunction_invoke, fun_pointer, ... )
	        }, stuff )
	    }
	}
	out <- new( "C++Function", f, pointer = fun_ptr, docstring = doc, signature = sign )
	if( ! is.null( formal_args ) ){
	    formals( out ) <- formal_args
	}
	out
}

.get_Module_Class <- function( x, name, pointer =  .getModulePointer(x) ){
    value <- .Call( Module__get_class, pointer, name )
    value@generator <-  get("refClassGenerators",envir=x)[[as.character(value)]]
    value
}

setMethod( "$", "Module", function(x, name){
    pointer <- .getModulePointer(x)
    storage <- get( "storage", envir = as.environment(x) )
    storage[[ name ]]
} )

new_CppObject_xp <- function(module, pointer, ...) {
	.External( class__newInstance, module, pointer, ... )
}

new_dummyObject <- function(...)
    .External( "class__dummyInstance", ...)


# class method for $initialize
cpp_object_initializer <- function(.self, .refClassDef, ..., .object_pointer){
    selfEnv <- as.environment(.self)
    ## generate the C++-side object and store its pointer, etc.
    ## access the private fields in the fieldPrototypes env.
    fields <- .refClassDef@fieldPrototypes
    pointer <- if(missing(.object_pointer)) new_CppObject_xp(fields$.module, fields$.pointer, ...) else .object_pointer
    assign(".module", fields$.module, envir = selfEnv)
    assign(".pointer", pointer, envir = selfEnv)
    assign(".cppclass", fields$.pointer, envir = selfEnv)
    .self
}

cpp_object_dummy <- function(.self, .refClassDef) {
    selfEnv <- as.environment(.self)
    ## like initializer but a dummy for the case of no default
    ## constructor.  Will throw an error if the object is used.
    fields <- .refClassDef@fieldPrototypes
    pointer <- new_dummyObject()
    assign(".module", fields$.module, envir = selfEnv)
    assign(".pointer", pointer, envir = selfEnv)
    assign(".cppclass", fields$.pointer, envir = selfEnv)
    .self
}

cpp_object_maker <- function(typeid, pointer){
    Class <- .classes_map[[ typeid ]]
    new( Class, .object_pointer = pointer )
}

Module <- function( module, PACKAGE = methods::getPackageName(where), where = topenv(parent.frame()), mustStart = FALSE ) {
    if(inherits(module, "DLLInfo") && missing(mustStart)) mustStart <- TRUE
    if(inherits(module, "Module")) {
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
        module <- methods::new("Module", pointer = xp, packageName = PACKAGE,
                      moduleName = moduleName)
    } else if(is.character(module)) {
        moduleName <- module
        xp <- .badModulePointer
        module <- methods::new("Module", pointer = xp, packageName = PACKAGE,
                      moduleName = moduleName)
    }
    if(identical(xp, .badModulePointer)) {
        if(mustStart) {
            name <- sprintf( "_rcpp_module_boot_%s", moduleName )
            symbol <- tryCatch(getNativeSymbolInfo( name, PACKAGE ),
                               error = function(e)e)
            if(inherits(symbol, "error"))
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

    storage <- new.env()

    for( i in seq_along(classes) ){
        CLASS <- classes[[i]]

        clname <- as.character(CLASS)

        fields <- cpp_fields( CLASS, where )
        methods <- cpp_refMethods(CLASS, where)
        generator <- methods::setRefClass( clname,
                                 fields = fields,
                                 contains = "C++Object",
                                 methods = methods,
                                 where = where
                                 )
        # just to make codetools happy
        .self <- .refClassDef <- NULL
        generator$methods(initialize =
              if(cpp_hasDefaultConstructor(CLASS))
                 function(...) cpp_object_initializer(.self,.refClassDef, ...)
              else
                 function(...) {
                     if(nargs()) cpp_object_initializer(.self,.refClassDef, ...)
                     else cpp_object_dummy(.self, .refClassDef)
                 }
                          )
        rm( .self, .refClassDef )

        classDef <- methods::getClass(clname)
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
                methods::setMethod( "[[", clname, function(x, i, j, ..., exact = TRUE){
                    x$`[[`( i )
                }, where = where )
            }

            if( "[[<-" %in% names( CLASS@methods ) ){
                methods::setReplaceMethod( "[[", clname, function(x, i, j, ..., exact = TRUE, value){
                    x$`[[<-`( i, value )
                    x
                } , where = where )
            }
        }

        # promoting show to S4
        if( any( grepl( "show", names(CLASS@methods) ) ) ){
            setMethod( "show", clname, function(object) object$show(), where = where )
        }

    }
    if(length(classes)) {
        module$refClassGenerators <- generators
    }

    for( i in seq_along(classes) ){
        CLASS <- classes[[i]]
        clname <- as.character(CLASS)
        demangled_name <- sub( "^Rcpp_", "", clname )
        .classes_map[[ CLASS@typeid ]] <- storage[[ demangled_name ]] <- .get_Module_Class( module, demangled_name, xp )

        # exposing enums values as CLASS.VALUE
        # (should really be CLASS$value but I don't know how to do it)
        if( length( CLASS@enums ) ){
            for( enum in CLASS@enums ){
                for( i in 1:length(enum) ){
                    storage[[ paste( demangled_name, ".", names(enum)[i], sep = "" ) ]] <- enum[i]
                }
            }
        }

    }

    # functions
    functions <- .Call( Module__functions_names, xp )
    for( fun in functions ){
        storage[[ fun ]] <- .get_Module_function( module, fun, xp )

        # register as(FROM, TO) methods
        converter_rx <- "^[.]___converter___(.*)___(.*)$"
        if( length( matches <- grep( converter_rx, functions ) ) ){
            for( i in matches ){
                fun <- functions[i]
                from <- sub( converter_rx, "\\1", fun )
                to   <- sub( converter_rx, "\\2", fun )
                converter <- function( from ){}
                body( converter ) <- substitute( { CONVERT(from) },
                    list( CONVERT = storage[[fun]] )
                )
                setAs( from, to, converter, where = where )
            }
        }

    }

    assign( "storage", storage, envir = as.environment(module) )
    module
}

dealWith <- function( x ) if(isTRUE(x[[1]])) invisible(NULL) else x[[2]]

method_wrapper <- function( METHOD, where ){
        noargs <- all( METHOD$nargs == 0 )
        stuff <- list(
            class_pointer = METHOD$class_pointer,
            pointer = METHOD$pointer,
            CppMethod__invoke = CppMethod__invoke,
            CppMethod__invoke_void = CppMethod__invoke_void,
            CppMethod__invoke_notvoid = CppMethod__invoke_notvoid,
            dealWith = dealWith,
            docstring = METHOD$info("")
        )
        f <- function(...) NULL
        if( noargs ){
            formals(f) <- NULL
        }

        extCall <- if( noargs ) {
            if( all( METHOD$void ) ){
                # all methods are void, so we know we want to return invisible(NULL)
                substitute(
                {
                    docstring
                    .External(CppMethod__invoke_void, class_pointer, pointer, .pointer )
                    invisible(NULL)
                } , stuff )
            } else if( all( ! METHOD$void ) ){
                # none of the methods are void so we always return the result of
                # .External
                substitute(
                {
                    docstring
                   .External(CppMethod__invoke_notvoid, class_pointer, pointer, .pointer )
                } , stuff )
            } else {
                # some are void, some are not, so the voidness is part of the result
                # we get from internally and we need to deal with it
                substitute(
	            {
	                docstring
	                dealWith( .External(CppMethod__invoke, class_pointer, pointer, .pointer ) )
                } , stuff )
            }
        } else {
            if( all( METHOD$void ) ){
                # all methods are void, so we know we want to return invisible(NULL)
                substitute(
                {
                    docstring
                    .External(CppMethod__invoke_void, class_pointer, pointer, .pointer, ...)
                    invisible(NULL)
                } , stuff )
            } else if( all( ! METHOD$void ) ){
                # none of the methods are void so we always return the result of
                # .External
                substitute(
                {
                    docstring
                   .External(CppMethod__invoke_notvoid, class_pointer, pointer, .pointer, ...)
                } , stuff )
            } else {
                # some are void, some are not, so the voidness is part of the result
                # we get from internally and we need to deal with it
                substitute(
	            {
	                docstring
	                dealWith( .External(CppMethod__invoke, class_pointer, pointer, .pointer, ...) )
                } , stuff )
            }
        }
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

cpp_hasDefaultConstructor <- function(CLASS) {
    .Call( Class__has_default_constructor, CLASS@pointer )
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

.CppClassName <- function(name)
    paste0("Rcpp_",name)
