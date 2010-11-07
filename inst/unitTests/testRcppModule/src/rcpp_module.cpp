#include <Rcpp.h>

/* removed as it upsets windows */
// std::string hello() {
// 	throw std::range_error( "boom" ) ;
// }

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
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }

private:
    std::string msg;
};



RCPP_MODULE(yada){
	using namespace Rcpp ;
	                  
	// function( "hello" , &hello ) ;
	function( "bar"   , &bar   ) ;
	function( "foo"   , &foo   ) ;
	function( "bla"   , &bla   ) ;
	function( "bla1"  , &bla1   ) ;
	function( "bla2"  , &bla2   ) ;
	
	class_<World>( "World" )
	
	    .default_constructor()
	    
		.method( "greet", &World::greet )
		.method( "set", &World::set )
	;
}                     


