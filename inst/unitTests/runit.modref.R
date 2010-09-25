#!/usr/bin/r -t
#
# Copyright (C) 2010	John Chambers, Dirk Eddelbuettel and Romain Francois
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


test.modRef <- function() {
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

    checkEquals(ww$greet(), wg$greet())
    wgg <- wg$greet()

    ww$set("Other")

    ## test independence of ww, wg
    checkEquals(ww$greet(), "Other")
    checkEquals(wg$greet(), wgg)

    World$methods(
                  twice = function() paste(greet(), greet()))

    checkEquals(ww$twice(), paste(ww$greet(), ww$greet()))

}
