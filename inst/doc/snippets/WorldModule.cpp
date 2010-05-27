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
	
	class_<World>( "World" )
		.method( "greet", &World::greet )
		.method( "set", &World::set )
	;

}                     

