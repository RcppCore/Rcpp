# Copyright (C) 2010 - 2011 John Chambers, Dirk Eddelbuettel and Romain Francois
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

setGeneric( "functions", function(object, ...) standardGeneric( "functions" ) )
setMethod( "functions", "Module", function(object, ...){
    pointer <- .getModulePointer(object)
    if(identical(pointer, .badModulePointer))
        stop(gettextf("Module \"%s\" has not been intialized:  try Module(object)",
                      get("moduleName", envir = as.environment(object))), domain = NA)
    else
	.Call( Module__functions_arity, pointer )
} )

setGeneric( "prompt" )
setMethod( "prompt", "Module", function(object, filename = NULL, name = NULL, ...){
	lines <- readLines( system.file( "prompt", "module.Rd", package = "Rcpp" ) )
        pointer <- .getModulePointer(object)
	if( is.null(name) )
            name <- .Call( Module__name, pointer )
	if( is.null(filename) ) filename <- sprintf( "%s-module.Rd", name )
	lines <- gsub( "NAME", name, lines )
	
	info <- functions( object )
	f.txt <- if( length( info ) ){
		sprintf( "functions: \\\\describe{
%s
		}", paste( sprintf( "        \\\\item{%s}{ ~~ description of function %s ~~ }", names(info), names(info) ), collapse = "\n" ) )
	} else {
		"" 
	}
	lines <- sub( "FUNCTIONS", f.txt, lines )

        ## at this point functions() would have failed if the
        ## pointer in object was not valid
	
	classes <- .Call( Module__classes_info, pointer )
	c.txt <- if( length( classes ) ){
		sprintf( "classes: \\\\describe{
%s
		}", paste( sprintf( "        \\\\item{%s}{ ~~ description of class %s ~~ }", names(classes), names(classes) ), collapse = "\n" ) )
	} else {
		"" 
	}
	lines <- sub( "CLASSES", c.txt, lines )
	
	writeLines( lines, filename )
	invisible(NULL)
} )

