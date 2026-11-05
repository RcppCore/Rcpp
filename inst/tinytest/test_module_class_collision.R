
##  Copyright (C) 2026  Kevin Ushey
##
##  This file is part of Rcpp.
##
##  Rcpp is free software: you can redistribute it and/or modify it
##  under the terms of the GNU General Public License as published by
##  the Free Software Foundation, either version 2 of the License, or
##  (at your option) any later version.
##
##  Rcpp is distributed in the hope that it will be useful, but
##  WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

## as in test_module_client_package.R
.onWindows <- .Platform$OS.type == "windows"
if (.onWindows) exit_file("Skipping on Windows.")

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes" && Sys.getenv("RunVerboseRcppTests") == "yes"
if (! .runThisTest) exit_file("Set 'RunVerboseRcppTests' and 'RunAllRcppTests' to 'yes' to run.")

## testRcppCollisionA and testRcppCollisionB expose unrelated C++ classes
## that are both named Collision, and so have the same typeid name; objects
## returned from C++ must be wrapped as the class of the package that
## returned them (#1531)

td <- tempfile()
cwd <- getwd()
dir.create( td )
pkgs <- c( "testRcppCollisionA", "testRcppCollisionB" )
for( pkg in pkgs )
    file.copy( system.file( "tinytest", pkg, package = "Rcpp" ), td, recursive = TRUE )
setwd( td )
dir.create( "templib" )
install.packages( pkgs, "templib", repos = NULL, type = "source" )
suppressMessages( for( pkg in pkgs ) require( pkg, "templib", character.only = TRUE ) )

expect_equal( testRcppCollisionA::make_collision( 42 )$get(), 42 )
expect_equal( testRcppCollisionB::make_collision()$get(), c( 1, 1, 1 ) )

on.exit( { setwd( cwd ) ; unlink( td, recursive = TRUE ) } )
