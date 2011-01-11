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

setGeneric( ".DollarNames" )
.DollarNames.Module <- function(x, pattern){    
    pointer <- .getModulePointer( x )
    if(identical(pointer, .badModulePointer)) {
        stop( "unitialized module" )
    }
    grep( pattern , .Call( Module__complete, pointer), value = TRUE )	
}
setMethod( ".DollarNames", "Module", .DollarNames.Module )

# completion for C++ objects
# do we actually need this or do we get it for free via setRefClass, etc ...
setGeneric( "complete", function(x) standardGeneric("complete") )
setMethod( "complete", "C++Object", function(x){
    xp <- get(".cppclass", envir = as.environment(x))
    # FIXME: implement another test  
    #    if(identical(xp, .emptyPointer))
    #        stop("C++ object with unset pointer to C++ class")
    .Call( CppClass__complete , xp )
} )

".DollarNames.C++Object" <- function( x, pattern ){
	grep( pattern, complete(x), value = TRUE )
}
setMethod( ".DollarNames", "C++Object", `.DollarNames.C++Object` )

