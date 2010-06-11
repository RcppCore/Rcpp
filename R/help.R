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

.help <- function( what ){
	print( sprintf( "Rcpp help for '%s'", what ) )
	invisible(TRUE)
}

install_help_workaround <- function(){
	utils <- asNamespace( "utils" )
	unlockBinding( ".tryHelp", utils )
	th <- get( ".tryHelp", utils )
	b <- body( th )
	b <- as.call( c( 
			as.name( "{" ), 
			quote( 
				if( grepl( "[-]Rcpp$", topic ) ){
					result <- Rcpp:::.help( sub( "[-]Rcpp$", "", topic ) )
					if( result )
						return( invisible(NULL) )
				}
			), 
			as.list( b[-1] )
		) )
	body( th ) <- b
	assign( ".tryHelp", th, utils )
	lockBinding( ".tryHelp", utils )
}

