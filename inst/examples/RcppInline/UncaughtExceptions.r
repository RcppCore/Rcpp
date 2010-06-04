#!/usr/bin/r -t
#
# Copyright (C) 2009 - 2010  Romain Francois and Dirk Eddelbuettel
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

require(Rcpp)
require(inline)
funx <- cxxfunction(	
	signature(), 
	'throw std::range_error("boom"); return R_NilValue ; ', 
	plugin = "Rcpp" )
tryCatch(  funx(), "C++Error" = function(e){
	cat( sprintf( "C++ exception of class '%s' : %s\n", class(e)[1L], e$message  ) )
} )
# or using a direct handler
tryCatch(  funx(), "std::range_error" = function(e){
        cat( sprintf( "C++ exception of class '%s' : %s\n", class(e)[1L], e$message  ) )
} )
# just to check things carry on
print( rnorm(10) )

