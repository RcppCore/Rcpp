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

# not used, but this keeps packages that import the class happy
# e.g. highlight 
setClass( "C++ObjectS3" ) 

## "Module" class as an environment with "pointer", "moduleName",
##  "packageName" and "refClassGenerators"
## Stands in for a reference class with those fields.
setClass( "Module",  contains = "environment" )

setRefClass( "C++Field", 
    fields = list( 
        pointer       = "externalptr", 
        cpp_class     = "character", 
        read_only     = "logical", 
        class_pointer = "externalptr"
    )
)

setRefClass( "C++OverloadedMethods", 
    fields = list( 
        pointer       = "externalptr", 
        class_pointer = "externalptr", 
        size          = "integer", 
        void          = "logical"
    )
)

setRefClass( "C++Constructor", 
    fields = list( 
        pointer       = "externalptr", 
        class_pointer = "externalptr", 
        nargs         = "integer"
    )
)

setClass( "C++Class", 
	representation( 
	    pointer      = "externalptr", 
	    module       = "externalptr", 
	    fields       = "list",
	    methods      = "list",
	    constructors = "list", 
	    generator    = "refObjectGenerator"
	), 
	contains = "character"
	)
setClass( "C++ClassRepresentation", 
    representation( 
        pointer         = "externalptr", 
        generator       = "refObjectGenerator", 
        cpp_fields      = "list", 
        cpp_methods     = "list", 
        cpp_constructor = "list"
    ), 
    contains = "classRepresentation" )

setClass( "C++Object")

setClass( "C++Function", 
	representation( pointer = "externalptr" ), 
	contains = "function"
)


