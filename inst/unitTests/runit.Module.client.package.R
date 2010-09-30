#!/usr/bin/r -t
#       hey emacs, please make this use  -*- tab-width: 4 -*-
#
# Copyright (C) 2010	John Chambers, Dirk Eddelbuettel and Romain Francois
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

if( Rcpp:::capabilities()[["Rcpp modules"]] ) {

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

	vClass <- stdVector$vec
	vec <- new(vClass)

	data <- 1:10
	vec$assign(data)
	vec[[3]] <- vec[[3]] + 1

	data[[4]] <- data[[4]] +1

	checkEquals( vec$as.vector(), data )

	## a few function calls

	checkEquals( yada$bar(2), 4)

	# this upsets the windows/gcc 4.5 combo
	# e <- tryCatch(yada$hello(), error = function(x)x)
	# checkTrue(is(e, "error"))
	# checkEquals( e$message, "boom")
    
	checkEquals( yada$foo(2,3), 6)

	## properties (at one stage this seqfaulted, so beware)
	nc = NumEx$Num
	nn <- new(nc)
	nn$x <- pi
	checkEquals( nn$x, pi )

}

}
