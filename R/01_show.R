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

setMethod( "show", "C++Object", function(object){
    env <- as.environment(object)
    pointer <- get(".pointer", envir = env)
    cppclass <- get(".cppclass", envir = env)
    txt <- sprintf( "C++ object <%s> of class '%s' <%s>", 
		externalptr_address(pointer), 
		.Call( Class__name, cppclass ), 
		externalptr_address(cppclass)
	)
	writeLines( txt )
} )

setMethod( "show", "C++Class", function(object){
	doc <- object@docstring
    txt <- sprintf( "C++ class '%s' <%s>%s", 
		.Call( Class__name, object@pointer ), 
		externalptr_address(object@pointer), 
		if( length(doc) && nchar(doc) ) sprintf( "\n    docstring : %s", doc ) else ""
	)
	writeLines( txt )
	
	ctors <- object@constructors
	nctors <- length( ctors )
	txt <- character( nctors )
	for( i in seq_len(nctors) ){
	    ctor <- ctors[[i]]
	    doc  <- ctor$docstring
	    txt[i] <- sprintf( "    %s%s", ctor$signature, if( nchar(doc) ) sprintf( "\n        docstring : %s", doc) else "" )
	}
	writeLines( "Constructors:" )
	writeLines( paste( txt, collapse = "\n" ) )
	
	fields <- object@fields
	nfields <- length(fields)
	if( nfields ){
	    names <- names(fields)
	    txt <- character(nfields)
	    writeLines( "\nFields: " )
	    for( i in seq_len(nfields) ){
	        f <- fields[[i]]
	        doc <- f$docstring
	        txt[i] <- sprintf( "    %s %s%s%s",
	            f$cpp_class, 
	            names[i], 
	            if( f$read_only ) " [readonly]" else "", 
	            if( nchar(doc) ) sprintf( "\n        docstring : %s", doc ) else ""
	        )    
	    }
	    writeLines( paste( txt, collapse = "\n" ) )
	} else {
	    writeLines( "\nFields: No public fields exposed by this class" )
	}
	
	mets <- object@methods
	nmethods <- length(mets)
	if( nmethods ){
	    writeLines( "\nMethods: " )
	    txt <- character( nmethods )
	    for( i in seq_len(nmethods) ){
	        txt[i] <- mets[[i]]$info("    ")
	    }
	    writeLines( paste( txt, collapse = "\n" ) ) 
	} else {
	    writeLines( "\nMethods: no methods exposed by this class" )
	}
} )

setMethod( "show", "C++Function", function(object){
	txt <- sprintf( "internal C++ function <%s>", externalptr_address(object@pointer) )
    writeLines( txt )
    
    doc <- object@docstring
    if( length(doc) && nchar( doc ) ){
        writeLines( sprintf( "    docstring : %s", doc ) )
    }
    
    sign <- object@signature
    if( length(sign) && nchar( sign ) ){
        writeLines( sprintf( "    signature : %s", sign ) )
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

