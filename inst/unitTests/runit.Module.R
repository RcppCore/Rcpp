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

.tearDown <- function(){
	gc()
}

if( Rcpp:::capabilities()[["Rcpp modules"]] ) {

test.Module <- function(){

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
	
	class World {
	public:
	    World() : msg("hello"){}
	    void set(std::string msg_) { this->msg = msg_; }
	    std::string greet() { return msg; }
	
	private:
	    std::string msg;
	};

	void clearWorld( World* w ){ 
		w->set( "" );
	}
	
	RCPP_MODULE(yada){
		using namespace Rcpp ;
		
		function( "hello" , &hello ) ;
		function( "bar"   , &bar   ) ;
		function( "foo"   , &foo   ) ;
		function( "bla"   , &bla   ) ;
		function( "bla1"  , &bla1   ) ;
		function( "bla2"  , &bla2   ) ;
		
		class_<World>( "World" )
			.method( "greet", &World::greet )
			.method( "set", &World::set )
			.method( "clear", &clearWorld )
		;

	}                     
	
	'
	fx <- cxxfunction( signature(), "" , include = inc, plugin = "Rcpp" )
	
	mod <- Module( "yada", getDynLib(fx) )
	checkEquals( mod$bar( 2L ), 4L )
	checkEquals( mod$foo( 2L, 10.0 ), 20.0 )
	checkEquals( mod$hello(), "hello" )
	checkEquals( capture.output( mod$bla() ), "hello" )
	checkEquals( capture.output( mod$bla1(2L) ), "hello (x = 2)" )
    checkEquals( capture.output( mod$bla2(2L, 5.0) ), "hello (x = 2, y =  5.00)" )
    
    World <- mod$World
    w <- new( World )
    checkEquals( w$greet(), "hello" )
    w$set( "hello world" ) 
    checkEquals( w$greet(), "hello world" )
    w$clear( )
    checkEquals( w$greet(), "" )
    
    
}

# hide this one for now (suncc not happy about overloads)
if(FALSE){
test.Module.stdvec <- function(){

code <- ''

inc  <- '
typedef std::vector<double> vec ;

void vec_assign( vec* obj, Rcpp::NumericVector data ){
	obj->assign( data.begin(), data.end() ) ;
}

void vec_insert( vec* obj, int position, Rcpp::NumericVector data){
	vec::iterator it = obj->begin() + position ;
	obj->insert( it, data.begin(), data.end() ) ;
}

Rcpp::NumericVector vec_asR( vec* obj){
	return Rcpp::wrap( *obj ) ;
}

RCPP_MODULE(yada){
	using namespace Rcpp ;
	
	class_<vec>( "vec")
	 	.method( "size", &vec::size)
 		.method( "max_size", &vec::max_size) 
 		.method( "resize", &vec::resize) 
 		.method( "capacity", &vec::capacity) 
 		.method( "empty", &vec::empty) 
 		.method( "reserve", &vec::reserve) 
 		.method( "push_back", &vec::push_back )
 		.method( "pop_back", &vec::pop_back )
 		.method( "clear", &vec::clear )
 		
 		.const_method( "back", &vec::back )
		.const_method( "front", &vec::front )
		.const_method( "at", &vec::at )
		
		.method( "assign", &vec_assign )
		.method( "insert", &vec_insert )
		.method( "as.vector", &vec_asR ) 
			
		
	;
}                     

'
	fx <- cxxfunction( signature(), "", include = inc, plugin = "Rcpp" )
	
	yada <- Rcpp:::Module( "yada", getDynLib( fx ) )
	v <- new( yada$vec )
	v$assign( 1:10 )
	
	checkEquals( v$back(), 10 )
	v$push_back( 10 )
	checkEquals( as.integer(v$size()), 11L )
	checkEquals( v$at( 0 ), 1 )
	checkEquals( v$as.vector(), c(1:10, 10 ) )
	
}
}

test.Module.property <- function(){

	inc  <- '
	class Num{
	public:
	    Num() : x(0.0), y(0){} ;
	    
	    double getX() const { return x ; }
	    void setX(double value){ x = value ; }
	    
	    int getY() { return y ; }
	    
	private:
	    double x ;
	    int y ;
	};
	
	RCPP_MODULE(yada){
		using namespace Rcpp ;
	
		class_<Num>( "Num" )
		
			// read and write property
			.property( "x", &Num::getX, &Num::setX )
			
			// read-only property
			.property( "y", &Num::getY )
		;
	}
	'
	fx <- cxxfunction( signature(), "" , include = inc, plugin = "Rcpp" )
	
	mod <- Module( "yada", getDynLib(fx) )
	Num <- mod$Num
    w <- new( Num )
    checkEquals( w$x, 0.0 )  
    checkEquals( w$y, 0L )  
    
    w$x <- 2.0
    checkEquals( w$x, 2.0 )  
    
    checkException( { w$y <- 3 } )
}

          
test.Module.member <- function(){

	inc  <- '
	class Number{
	public:
	    Number() : x(0.0), y(0){} ;
	    	    
	    double x ;
	    int y ;
	};
	
	RCPP_MODULE(yada){
		using namespace Rcpp ;
	
		class_<Number>( "Number" )
		
			// read and write data member
			.field( "x", &Number::x )
			
			// read only data member
			.field_readonly( "y", &Number::y )
		;
	}
	'
	fx <- cxxfunction( signature(), "" , include = inc, plugin = "Rcpp" )
	
	mod <- Module( "yada", getDynLib(fx) )
	Number <- mod$Number
    w <- new( Number )
    checkEquals( w$x, 0.0 )  
    checkEquals( w$y, 0L )  
    
    w$x <- 2.0
    checkEquals( w$x, 2.0 )  
    
    checkException( { w$y <- 3 } )
}
  
}
