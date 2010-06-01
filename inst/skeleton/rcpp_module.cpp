#include <Rcpp.h>

class World {
public:
    World() : msg("hello"){}
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }

private:
    std::string msg;
};

void clearWorld( World* w){
	w->set( "" ) ;
}

RCPP_MODULE(yada){
	using namespace Rcpp ;
	
	class_<World>( "World" )
		.method( "greet", &World::greet )
		.method( "set", &World::set )
		.method( "clear", &clearWorld )
	;

}            

