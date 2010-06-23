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

test.sugar.Range <- function( ){

	fx <- cxxfunction( signature(  ), '
	
		NumericVector xx(8) ;
		xx[ Range(0,3) ] = exp( seq_len(4) ) ;
		xx[ Range(4,7) ] = exp( - seq_len(4) ) ;
		return xx ;
	', plugin = "Rcpp" )
	
	checkEquals( fx() , c( exp(seq_len(4)), exp(-seq_len(4))  ) )
}
