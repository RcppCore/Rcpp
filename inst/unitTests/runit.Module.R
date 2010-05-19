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

test.Argument <- function(){

	inc  <- '
	
	std::string hello(){
		return "hello" ;
	}
	
	int bar( int x){
		return x*2 ;
	}
	        
	double foo( int x, double y){
		return x * y ;
	}
	
	void bla( ){
		Rprintf( "hello\\n" ) ;
	}
	
	void bla1( int x){
		Rprintf( "hello (x = %d)\\n", x ) ;
	}
	
	void bla2( int x, double y){
		Rprintf( "hello (x = %d, y = %5.2f)\\n", x, y ) ;
	}
	
	
	RCPP_MODULE(yada){
		using namespace Rcpp ;
		
		function( "hello" , &hello ) ;
		function( "bar"   , &bar   ) ;
		function( "foo"   , &foo   ) ;
		function( "bla"   , &bla   ) ;
		function( "bla1"  , &bla1   ) ;
		function( "bla2"  , &bla2   ) ;
		
	}                     
	
	'
	fx <- cppfunction( signature(), "" , include = inc )
	
	mod <- Module( "yada", getDLL(fx) )
	checkEquals( mod$bar( 2L ), 4L )
	checkEquals( mod$foo( 2L, 10.0 ), 20.0 )
	checkEquals( mod$hello(), "hello" )
	checkEquals( capture.output( mod$bla() ), "hello" )
	checkEquals( capture.output( mod$bla1(2L) ), "hello (x = 2)" )
    checkEquals( capture.output( mod$bla2(2L, 5.0) ), "hello (x = 2, y =  5.00)" )
   
}
