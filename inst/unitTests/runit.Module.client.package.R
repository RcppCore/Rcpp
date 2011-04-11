#!/usr/bin/r -t
#       hey emacs, please make this use  -*- tab-width: 4 -*-
#
# Copyright (C) 2010 - 2011	 John Chambers, Dirk Eddelbuettel and Romain Francois
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

.tearDown <- function(){
	gc()
}

## The unit test in this file fails on OS X 10.5.* but pass on 10.6.*
## Sys.info release comes back with 10.* for the latter but 9.* for the former
## Thanks to Simon Urbanek and Baptiste Auguie for suggesting and testing this
.badOSX <- (Sys.info()['sysname'] == "Darwin" &&
            isTRUE(as.integer(gsub("\\..*","",Sys.info()['release'])) < 10L) )

if( Rcpp:::capabilities()[["Rcpp modules"]] && ! .badOSX ) {

test.Module.package <- function( ){

    td <- tempfile()
    cwd <- getwd()
    dir.create( td )
    file.copy( system.file( "unitTests", "testRcppModule", package = "Rcpp" ) , td, recursive = TRUE)
    setwd( td )
    on.exit( { setwd( cwd) ; unlink( td, recursive = TRUE ) } )
    R <- shQuote( file.path( R.home( component = "bin" ), "R" ))
    cmd <- paste( R , "CMD build testRcppModule" )
    system( cmd )
    dir.create( "templib" )
    install.packages( "testRcppModule_0.1.tar.gz", "templib", repos = NULL, type = "source" )
    require( "testRcppModule", "templib", character.only = TRUE )

	v <- new(vec)

	data <- 1:10
	v$assign(data)
	v[[3]] <- v[[3]] + 1

	data[[4]] <- data[[4]] +1

	checkEquals( v$as.vector(), data )

	## a few function calls
	checkEquals( bar(2), 4)
	checkEquals( foo(2,3), 6)

}

}
