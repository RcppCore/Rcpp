# Copyright (C) 2009 - 2013 Dirk Eddelbuettel and Romain Francois
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

Rcpp.plugin.maker <- function(
	include.before = "",
	include.after = "",
	LinkingTo     = unique( c( package, "Rcpp" ) ),
	Depends       = unique( c( package, "Rcpp" ) ),
	libs          = "",
	Makevars      = NULL ,
	Makevars.win  = NULL,
	package       = "Rcpp"
){
	function( ... ){
includes <- sprintf( "%s
#include <Rcpp.h>
%s

#ifndef BEGIN_RCPP
#define BEGIN_RCPP
#endif

#ifndef END_RCPP
#define END_RCPP
#endif

using namespace Rcpp;
", include.before, include.after )

  out <- list(
		env = list( PKG_LIBS = libs ),
		includes = includes,
		LinkingTo = LinkingTo ,
		body = function( x ){
			sprintf( "BEGIN_RCPP\n%s\nEND_RCPP", x )
		},
		Depends = Depends
	)
	if( !is.null(Makevars ) ) out$Makevars <- Makevars
  	if( !is.null(Makevars.win ) ) out$Makevars.win <- Makevars.win
  	out
}
}

inlineCxxPlugin <- Rcpp.plugin.maker()

