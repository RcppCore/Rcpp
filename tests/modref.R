    require( Rcpp )
    if(!require( inline ))
     q("no")

	inc  <- '

	class World {
	public:
	    World() : foo(1), msg("hello") {}
	    void set(std::string msg_) { this->msg = msg_; }
	    std::string greet() { return msg; }

	    int foo ;
	    double bar ;

	private:
	    std::string msg;
	};

	void clearWorld( World* w ){
		w->set( "" );
	}

	RCPP_MODULE(yada){
		using namespace Rcpp ;

		class_<World>( "World" )
			.method( "greet", &World::greet )
			.method( "set", &World::set )
			.method( "clear", &clearWorld )

			.field( "foo", &World::foo )
			.field_readonly( "bar", &World::bar )
		;

	}

	'
	fx <- inline::cxxfunction( signature(), "" , include = inc, plugin = "Rcpp" )

	mod <- Module( "yada", getDynLib(fx) )
    World <- mod$World

ww = new(World)
wg = World$new()

stopifnot(all.equal(ww$greet(), wg$greet()))
wgg <- wg$greet()

ww$set("Other")

## test independence of ww, wg
stopifnot(all.equal(ww$greet(), "Other"),
          all.equal(wg$greet(), wgg))

World$methods(
     twice = function() paste(greet(), greet()))

stopifnot(all.equal(ww$twice(), paste(ww$greet(), ww$greet())))
