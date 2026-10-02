# Copyright (C) 2010 - 2016  John Chambers, Dirk Eddelbuettel and Romain Francois
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

# anticipating a change in R 2.16.0
setClass( "refClassGeneratorFunction" ) 	# #nocov start
setClassUnion("refGenerator", c("refObjectGenerator", "refClassGeneratorFunction")) 

## "Module" class as an environment with "pointer", "moduleName",
##  "packageName" and "refClassGenerators"
## Stands in for a reference class with those fields.
setClass( "Module",  contains = "environment" )

## Plain S4 classes describing the fields, methods and constructors that a
## C++ class exposes. These used to be reference classes; creating one
## reference-class object per exposed method (via new()) dominated the
## time spent loading a module. A "$" method is provided below so that
## existing code using field-style access (x$pointer, x$info()) keeps working.
setClass( "C++Field",
    representation(
        pointer       = "externalptr",
        cpp_class     = "character",
        read_only     = "logical",
        class_pointer = "externalptr",
        docstring     = "character"
    )
)

setClass( "C++OverloadedMethods",
    representation(
        pointer       = "externalptr",
        class_pointer = "externalptr",
        size          = "integer",
        void          = "logical",
        const         = "logical",
        docstrings    = "character",
        signatures    = "character",
        nargs         = "integer"
    )
)

setClass( "C++Constructor",
    representation(
        pointer       = "externalptr",
        class_pointer = "externalptr",
        nargs         = "integer",
        signature     = "character",
        docstring     = "character"
    )
)

## formerly the 'info' reference method of C++OverloadedMethods
.cpp_methods_info <- function( x, prefix = "    " ){
    paste(
        paste( prefix, x@signatures, ifelse(x@const, " const", "" ), "\n", prefix, prefix,
            ifelse( nchar(x@docstrings), paste( "docstring :", x@docstrings) , "" )
        ) , collapse = "\n" )
}

## backwards compatible field-style access
setMethod( "$", "C++OverloadedMethods", function(x, name){
    if( identical( name, "info" ) )
        function( prefix = "    " ) .cpp_methods_info( x, prefix )
    else
        methods::slot( x, name )
} )
setMethod( "$", "C++Field",       function(x, name) methods::slot( x, name ) )
setMethod( "$", "C++Constructor", function(x, name) methods::slot( x, name ) )

## packages compiled against earlier versions of the Rcpp headers populate
## these objects with `$<-` (FieldProxy); keep those binaries loadable
.slot_dollar_assign <- function(x, name, value) {
    methods::slot( x, name ) <- value
    x
}
setReplaceMethod( "$", "C++OverloadedMethods", .slot_dollar_assign )
setReplaceMethod( "$", "C++Field",             .slot_dollar_assign )
setReplaceMethod( "$", "C++Constructor",       .slot_dollar_assign )

setClass( "C++Class", 
	representation( 
	    pointer      = "externalptr", 
	    module       = "externalptr", 
	    fields       = "list",
	    methods      = "list",
	    constructors = "list",
	    generator    = "refGenerator", 
	    docstring    = "character", 
	    typeid       = "character", 
	    enums        = "list", 
	    parents      = "character"
	), 
	contains = "character"
	)
	
setClass( "C++Object")

setClass( "C++Function", 
	representation( 
	    pointer   = "externalptr", 
	    docstring = "character", 
	    signature = "character"
	), 
	contains = "function"
)

.cppfunction_formals_gets <- function (fun, envir = environment(fun), value) {
    bd <- body(fun)
    b2 <- bd[[2L]]
    for( i in seq_along(value) ){
        b2[[3L+i]] <- as.name( names(value)[i] )
    }
    bd[[2]] <- b2
    f <- fun@.Data
    formals(f) <- value
    body(f) <- bd
    fun@.Data <- f
    fun
}
setGeneric( "formals<-" )
setMethod( "formals<-", "C++Function", .cppfunction_formals_gets ) # #nocov end
