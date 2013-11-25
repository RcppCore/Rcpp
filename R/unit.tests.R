# Copyright (C) 2010 - 2013 Dirk Eddelbuettel and Romain Francois
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

run_unit_tests <- function( output = if( file.exists( "/tmp" ) ) "/tmp" else getwd(), package = "Rcpp" ){
    if( !file.exists( output ) ){ 
      stop( "output directory does not exist" ) 
    }

    Rscript <- file.path( R.home( component = "bin" ), "Rscript" )
    if( .Platform$OS.type == "windows" ){
        Rscript <- sprintf( "%s.exe", Rscript )
    }
    test.script <- system.file( "unitTests", "runTests.R", package = package )
    cmd <- sprintf( '"%s" "%s" --output=%s', Rscript, test.script, output )
    system( cmd )
}

test <- function( output = if( file.exists( "/tmp" ) ) "/tmp" else getwd() ){
  message( "test is deprecated, use `run_unit_test` instead" )
  run_unit_tests( output, "Rcpp" )  
}

unit_test_setup <- function(file, packages = NULL) {
    function(){
        if( !is.null(packages) ){
            for( p in packages ){
                suppressMessages( require( p, character.only = TRUE ) )
            }
        }
        if (!exists("pathRcppTests")) pathRcppTests <- getwd()
        sourceCpp(file.path(pathRcppTests, "cpp", file ))
    }
}

