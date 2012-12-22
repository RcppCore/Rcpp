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

# anticipating a change in R 2.16.0
setClass( "refClassGeneratorFunction" )
setClassUnion("refGenerator", c("refObjectGenerator", "refClassGeneratorFunction")) 

## "Module" class as an environment with "pointer", "moduleName",
##  "packageName" and "refClassGenerators"
## Stands in for a reference class with those fields.
setClass( "Module",  contains = "environment" )

setRefClass( "C++Field", 
    fields = list( 
        pointer       = "externalptr", 
        cpp_class     = "character", 
        read_only     = "logical", 
        class_pointer = "externalptr", 
        docstring     = "character"
    )
)

setRefClass( "C++OverloadedMethods", 
    fields = list( 
        pointer       = "externalptr", 
        class_pointer = "externalptr", 
        size          = "integer", 
        void          = "logical",
        const         = "logical", 
        docstrings    = "character", 
        signatures    = "character", 
        nargs         = "integer"
    ), 
    methods = list( 
        info = function(prefix = "    " ){
             paste( 
                paste( prefix, signatures, ifelse(const, " const", "" ), "\n", prefix, prefix, 
                    ifelse( nchar(docstrings), paste( "docstring :", docstrings) , "" ) 
                ) , collapse = "\n" )   
        }
    )
)

setRefClass( "C++Constructor", 
    fields = list( 
        pointer       = "externalptr", 
        class_pointer = "externalptr", 
        nargs         = "integer", 
        signature     = "character", 
        docstring     = "character"
    )
)

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
setMethod( "formals<-", "C++Function", .cppfunction_formals_gets )
