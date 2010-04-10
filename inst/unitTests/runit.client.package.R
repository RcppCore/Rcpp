#!/usr/bin/r -t
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

.setUp <- function(){
	suppressMessages( require( inline ) )
}

test.client.package <- function(){
	td <- tempfile()
	cwd <- getwd()
	dir.create( td )
	file.copy( system.file( "unitTests", "RcppTestA_1.0.tar.gz", package = "Rcpp" ) , td ) 
	setwd( td )
	on.exit( { setwd( cwd) ; unlink( td, recursive = TRUE ) } )
	dir.create( "templib" )
	install.packages( "RcppTestA_1.0.tar.gz", "templib", repos = NULL, type = "source" )
	require( "RcppTestA", "templib" )
	res <- RcppTestA:::rcpp_hello_world( )
	checkEquals( res, list( c("foo", "bar"), c(0.0, 1.0) ), msg = "code from client package" )
}

