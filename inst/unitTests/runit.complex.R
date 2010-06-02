#!/usr/bin/r -t
#
# Copyright (C) 2009 - 2010	Romain Francois
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

test.vector.complex <- function(){
	
	fx <- cxxfunction( signature() , '

	std::vector< std::complex<double> > v_double(10) ;
    std::vector< std::complex<float> > v_float(10) ;
    
	return List::create( _["float"] = v_float, _["double"] = v_double ) ;
    
	', plugin = "Rcpp" )
	checkEquals( 
		fx(), 
		list( float = rep(0+0i), double = rep(0+0i) ), 
		msg = "range wrap over std::complex" )
}

