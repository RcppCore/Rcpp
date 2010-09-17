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

setMethod( "show", "C++Function", function(object){
	writeLines( sprintf( "internal C++ function <%s>", externalptr_address(object@pointer) ) )
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

