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


## "Module" class as an environment with "pointer", "moduleName", and "packageName"
## Stands in for a reference class with those fields.
setClass( "Module",  contains = "environment" )

setRefClass( "C++Field", 
    fieldClasses = list( 
        pointer       = "externalptr", 
        cpp_class     = "character", 
        read_only     = "logical", 
        class_pointer = "externalptr"
    ),
    refMethods = list( 
        get = function(obj_xp){
            .Call( "CppField__get", class_pointer, pointer, obj_xp, PACKAGE = "Rcpp" ) 
        }, 
        set = function(obj_xp, value){
            .Call( "CppField__set", class_pointer, pointer, obj_xp, value, PACKAGE = "Rcpp" )
            invisible( NULL )
        }
    )
)

setClass( "C++Class", 
	representation( 
	    pointer = "externalptr", 
	    module  = "externalptr", 
	    fields  = "list" 
	), 
	contains = "character"
	)
setClass( "C++ClassRepresentation", 
    representation( pointer = "externalptr", generator = "refObjectGenerator" ), 
    contains = "classRepresentation" )

# might not actually use this
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


