# Copyright (C)        2010 Dirk Eddelbuettel and Romain Francois
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

test <- function( output = if( file.exists( "/tmp" ) ) "/tmp" else getwd() ){
	if( !file.exists( output ) ){ stop( "output directory does not exist" ) }
	
	Rscript <- file.path( R.home( component = "bin" ), "Rscript" )
	if( .Platform$OS.type == "windows" ){
		Rscript <- sprintf( "%s.exe", Rscript )
	}
	test.script <- system.file( "unitTests", "runTests.R", package = "Rcpp" )
	cmd <- sprintf( '"%s" "%s" --output=%s', Rscript, test.script, output )
	system( cmd )
}

