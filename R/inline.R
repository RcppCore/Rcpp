# Copyright (C) 2009- 2010	Dirk Eddelbuettel and Romain Francois
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

Makevars.Rcpp <- '
## Use the R_HOME indirection to support installations of multiple R version
PKG_LIBS = $(shell $(R_HOME)/bin/Rscript -e "Rcpp:::LdFlags()" )
'

Makevars.win.Rcpp <- '
## Use the R_HOME indirection to support installations of multiple R version
PKG_LIBS = $(shell "${R_HOME}/bin${R_ARCH_BIN}/Rscript.exe" -e "Rcpp:::LdFlags()")
'

Rcpp.plugin.maker <- function( include.before = "", include.after = "", 
	LinkingTo = "Rcpp", Depends = "Rcpp", libs = "", 
	Makevars = Makevars.Rcpp, 
	Makevars.win = Makevars.win.Rcpp
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

	list( 
		env = list( PKG_LIBS = paste( Rcpp:::RcppLdFlags(), libs ) ), 
		includes = includes, 
		LinkingTo = LinkingTo , 
		body = function( x ){
			sprintf( "BEGIN_RCPP\n%s\nEND_RCPP", x )	
		}, 
		Depends = Depends, 
		Makevars = Makevars, 
		Makevars.win = Makevars.win
	)
}
}

inline_cxx_plugin <- Rcpp.plugin.maker() 

