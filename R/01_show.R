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
    env <- as.environment(object)
    pointer <- get(".pointer", envir = env)
    # FIXME: .emptyPointer is gone
    # if(identical(pointer, .emptyPointer))
    #     stop("Uninitialized C++ object")
    cppclass <- get(".cppclass", envir = env)
    # FIXME: .emptyPointer is gone
    # if(identical(cppclass, .emptyPointer))
    #     stop("C++ object with unset C++ class pointer")
	txt <- sprintf( "C++ object <%s> of class '%s' <%s>", 
		externalptr_address(pointer), 
		.Call( Class__name, cppclass ), 
		externalptr_address(cppclass)
	)
	writeLines( txt )
} )

setMethod( "show", "C++Class", function(object){
	txt <- sprintf( "C++ class '%s' <%s>", 
		.Call( Class__name, object@pointer ), 
		externalptr_address(object@pointer) )
	writeLines( txt )
	
	ctors <- object@constructors
	nctors <- length( ctors )
	txt <- character( nctors )
	for( i in seq_len(nctors) ){
	    txt[i] <- sprintf( "    %s", ctors[[i]]$signature )
	}
	writeLines( "Constructors:" )
	writeLines( paste( txt, collapse = "\n" ) )
	
	writeLines( "\nFields: " )
	fields <- object@fields
	nfields <- length(fields)
	names <- names(fields)
	txt <- character(nfields)
	for( i in seq_len(nfields) ){
	    f <- fields[[i]]
	    txt[i] <- sprintf( "    %s %s%s",
	        f$cpp_class, 
	        names[i], 
	        if( f$read_only ) " [readonly]" else "" 
	    )    
	}
	writeLines( paste( txt, collapse = "\n" ) )
	
	writeLines( "\nMethods: " )
	mets <- object@methods
	nmethods <- length(mets)
	txt <- character( nmethods )
	for( i in seq_len(nmethods) ){
	    txt[i] <- mets[[i]]$info("    ")
	}
	writeLines( paste( txt, collapse = "\n" ) )
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
	info <- .Call( Module__functions_arity, pointer )
	name <- .Call( Module__name, pointer )
	txt <- sprintf( "Rcpp module '%s' \n\t%d functions: ", name, length(info) )
	writeLines( txt )                       
	txt <- sprintf( "%15s : %d arguments", names(info), info )
	writeLines( txt )
	                                                     
	info <- .Call( Module__classes_info, pointer )
	txt <- sprintf( "\n\t%d classes : ", length(info) )
	writeLines( txt )
	txt <- sprintf( "%15s ", names(info) )
	writeLines( txt )
    }
} )

