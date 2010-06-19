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

test.sugar.sapply <- function( ){

	inc <- '
	template <typename T>
	class square : public std::unary_function<T,T> {
	public:
		T operator()( T t) const { return t*t ; }
	} ;
	'
	
	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector res = sapply( xx, square<double>() );
		
		return res ;
	
	', include = inc, plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , (1:10)^2 )
}

test.sugar.sapply.rawfun <- function( ){

	inc <- '
	double square( double x){ return x*x; }
	'
	
	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector res = sapply( xx, square );
		
		return res ;
	
	', include = inc, plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , (1:10)^2 )
}

test.sugar.sapply.square <- function( ){

	inc <- '
	template <typename T>
	class square : public std::unary_function<T,T> {
	public:
		T operator()( T t) const { return t*t ; }
	} ;
	'
	
	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		return all( sapply( xx * xx , square<double>() ) < 10 );
	
	', include = inc, plugin = "Rcpp" )
	
	checkTrue( fx(1:10)  )
}

