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
			.External( "InternalFunction_invoke" , PACKAGE = "Rcpp", xp, ... )
		}
	}
	o <- new( "C++Function", f(pointer) )
	o@pointer <- pointer
	o
}

setMethod("$", "C++Class", function(x, name) {
    x <- .getCppGenerator(x)
    eval.parent(substitute(x$name))
})

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

new_CppObject_xp <- function(module, pointer, ...) {
	.External( "class__newInstance", module, pointer, ..., PACKAGE = "Rcpp" )
}

## [John] making new() a generic is bad:  a commonly used pardigm assumes that all relevant methods come from initialize()
## Breaks the reference class new() method, & plausibly could fail if a C++ object was a slot of another class
## changes to initializer below should achieve the desired effect.  At some point, we should clean up the 3(!) different class objects
## associated with each C++ class object.  But no rush.

.emptyPointer <- new("externalptr") # used in initializer method for C++ objects

# [romain] this uses scoping to get access to the fields, but it might not be
#          necessary, we can get them from the C++ClassRepresentation $ cpp_fields 
#          field
cpp_object_initializer <- function(CLASS){
    function(.Object, ...){
        .Object <- callNextMethod(.Object)
    	selfEnv <- as.environment(.Object)
        ## generate the C++-side object and store its pointer, etc.
        pointer <- selfEnv$.pointer
        if(is.null(pointer) || identical(pointer, .emptyPointer)) {
            fields <- getClass(class(.Object))@fieldPrototypes
            pointer <- new_CppObject_xp(fields$.module, fields$.pointer, ...)
            assign(".module", fields$.module, envir = selfEnv)
            assign(".pointer", pointer, envir = selfEnv)
            assign(".cppclass", fields$.pointer, envir = selfEnv)
            ## </note> these should not be needed and are being
            ## dropped from the object class
            ## .Object@module <- fields$.module
            ## .Object@cppclass <- fields$.pointer
            ## .Object@pointer <- pointer
            ##</note>
        }
        ## for the C++ fields (only), create active bindings
    	fields <- CLASS@fields
    	fields_names <- names( fields )
    	binding_maker <- function( FIELD ){
    	    f <- function( x ) NULL
            body(f) <- substitute({
                fieldPtr <- FIELD
    	        if( missing( x ) ){
    	            fieldPtr$get( .pointer )
    	        } else {
    	            fieldPtr$set( .pointer, x )
    	        }
    	    }, list(FIELD = FIELD))
            environment(f) <- selfEnv
            f
    	}
    	for( i in seq_along(fields) ){
    	    makeActiveBinding( fields_names[i], binding_maker( fields[[i]] ) , selfEnv )
    	}
    	.Object
    }
}

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
            ## [John]  One technique is to initialize the pointer to a known value
            ## and just check whether it's been reset from that (bad) value
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
	
    for( i in seq_along(classes) ){
        ## We need a general strategy for assigning class defintions
        ## since delaying the initialization of the module causes
        ## where to be the Rcpp namespace:
        if(environmentIsLocked(where))
            where <- .GlobalEnv # or???
        CLASS <- classes[[i]]
        clname <- as.character(CLASS)
        
        interface <- cppInterfaceClass( clname )
        setClass( interface, where = where )
        cdef <- getClassDef( interface, where = where )
        classRep <- new( "C++ClassRepresentation", 
                                        # grab the data from the generated classRepresentation
                        className = cdef@className, 
                        virtual = TRUE, 
                        versionKey = cdef@versionKey, 
                        package = cdef@package, 
                        sealed  = cdef@sealed, 
                        
                                        # Rcpp specific information
                        pointer = CLASS@pointer, 
                        cpp_fields = CLASS@fields, 
                        cpp_methods = CLASS@methods
                                        # anything else ?
                        )
        
        ## [romain] perhaps we should have something like "C++Property" 
        ##          instead of "ANY" with appropriate setAs/setIs methods
        ##          or maybe change setRefClass so that it takes a "refFields"
        ##          argument instead of the trio fieldClasses, fieldPrototypes, fieldReadOnly
        fc <- .Call( "CppClass__property_classes", CLASS@pointer, PACKAGE = "Rcpp" )
        class_names <- names( fc )
        
        fieldClasses <- rep( list( "ANY" ), length( class_names ) )
        names( fieldClasses ) <- class_names
        
        fieldPrototypes <- rep( list( NA ), length( class_names ) )
        names( fieldPrototypes ) <- class_names
        
        generator <- setRefClass( clname, 
                                 fieldClasses = fieldClasses,
                                 fieldPrototypes = fieldPrototypes , 
                                 contains = "C++Object", 
                                 interfaceClasses = classRep, 
                                 where = where
                                 )
        classRep@generator <- generator
        classDef <- getClass(clname)
        ## non-public (static) fields in class representation
        fields <- classDef@fieldPrototypes
        assign(".pointer", CLASS@pointer, envir = fields)
        assign(".module", xp, envir = fields)
        assign(".CppClassName", clname, envir = fields)
        assignClassDef( interface, classRep, where)
        
        setMethod( "initialize", clname, cpp_object_initializer(CLASS) , where = where )
        
    }
    module
}

.referenceMethods__cppclass <- function( classDef, where ){
    xp <- classDef@pointer
    cpp_methods <- classDef@cpp_methods

	method_wrapper <- function( METHOD ){
	    here <- environment()
	    eval( substitute(
            function(...) {
                res <- MET$invoke( .pointer, ... )
                RES
            }, 
            list( 
                MET = METHOD, 
                RES = if( METHOD$void ) quote(invisible(NULL)) else as.name("res")
            )
	    ), here )
	}
	mets <- sapply( cpp_methods, method_wrapper )
		     
	# [romain] commenting out fields get/set 
	#          because they are not used anyway, they lose over the default 
	#          getters and setters installed by setRefClass
	#          The cpp_object_initializer takes care of setting the field as an 
	#          active binding that hooks back internally
	#         
	# props <- .Call( "CppClass__properties", xp, PACKAGE = "Rcpp" )
	# accesors <- lapply( props, function(p){
	#     
	#     getter <- function(){
	#         .Call( "CppClass__get", .self@cppclass, .self@pointer, p, PACKAGE = "Rcpp" )
	#     }
	#     body( getter )[[2]][[5]] <- p
	#     
	#     setter <- function(value){
	#         .Call( "CppClass__set", .self@cppclass, .self@pointer, p, value, PACKAGE = "Rcpp" )
	#         invisible( NULL )
	#     }
	#     body( setter )[[2]][[5]] <- p
	#     
	#     res <- list( get = getter, set = setter )
	#     names( res ) <- methods:::firstCap( p )
	#     res
	# } )
	# 
	# c( mets, accesors, recursive = TRUE )
    mets
}
setMethod( "referenceMethods", "C++ClassRepresentation", .referenceMethods__cppclass )


#### alternative generator
setRCppClass <- function(cppClass, className, ...,
                         where = topenv(parent.frame())) {
    pointer <- cppClass@pointer
    setRefClass(className,
                fieldClasses = list(pointer = "externalptr",
                      cppClass = "C++Class"),
                fieldPrototypes = list(pointer = pointer,
                    cppClass = cppClass),
                fieldReadOnly = c("pointer", "cppClass"),
                interfaceClasses = cppClass,
                where = where
                )
}

cppInterfaceClass <- function(cppClass)
    paste("interface", as.character(cppClass), sep = "_")

.getCppGenerator <- function(cppClass) {
    ## Requires the interface class to exist
    ## We should guarantee that constructing the C++Class object
    ## creates the interface class as well.
    cc = getClass(cppInterfaceClass(cppClass))
    cc@generator
}
