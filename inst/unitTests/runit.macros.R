#!/usr/bin/r -t
#
# Copyright (C) 2010 - 2012  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"

if( .runThisTest  ) {

.getDll <- function( fx ){
	env <- environment( fx@.Data )
	f <- get( "f", env )
	dlls <- getLoadedDLLs()
	dll <- if( ! f %in% names(dlls) ){
		dyn.load( get( "libLFile", env ) )
	} else{
		dlls[[ match( f, names(dlls) ) ]]
	}
	dll
}

.getInfo <- function( symbol, fx ){
	env <- environment( fx@.Data )
	f <- get( "f", env )
	dlls <- getLoadedDLLs()
	dll <- .getDll( fx )
	info_symbol <- paste( symbol, "__rcpp_info__", sep = "" )
	routine <- getNativeSymbolInfo( info_symbol, dll )
	info <- .Call( routine )
	info
}

test.RCPPFUNCTION <- function(){

	fx <- cxxfunction( signature(), '
		return foo() ;
	', includes = '
	RCPP_FUNCTION_0(int, foo){
		return 10 ;
	}
	', plugin = "Rcpp" )
	checkEquals( fx(), 10L, msg = "RCPP_FUNCTION_0" )

	checkEquals( .getInfo( "foo", fx ) ,
		structure( list(
		n = 0L,
		output = "int",
		input = character(0) ), class = "rcppfunctioninfo" ) )

	fx <- cxxfunction( signature(x = "numeric", y = "numeric" ), '
		return foo(x, y) ;
	', includes = '
	RCPP_FUNCTION_2(double, foo, double x, double y){
		return x * y ;
	}
	', plugin = "Rcpp" )
	checkEquals( fx( 10, 10), 100, msg = "RCPP_FUNCTION_2" )

	checkEquals( .getInfo( "foo", fx ) ,
		structure( list(
		n = 2L,
		output = "double",
		input = c("double x","double y") ), class = "rcppfunctioninfo" ) )

}

test.RCPPFUNCTION.VOID <- function(){
	fx <- cxxfunction( signature(), '
		return foo() ;
	', includes = '
	RCPP_FUNCTION_VOID_0(foo){
		Rprintf("hello\\n") ;
	}
	', plugin = "Rcpp" )
	checkEquals( capture.output( x <- fx() ) , "hello", 10L, msg = "RCPP_FUNCTION_VOID_0" )

	info <- .getInfo( "foo", fx )
	checkEquals( info[["n"]], 0L )
	checkEquals( info[["input"]], character(0) )
	checkEquals( info[["output"]], NULL)
	checkEquals( class(info), "rcppfunctionvoidinfo" )

	fx <- cxxfunction( signature(x = "character", y = "integer" ), '
		return foo(x, y) ;
	', includes = '
	RCPP_FUNCTION_VOID_2(foo, std::string x, int y){
		Rprintf("hello %s (%d)\\n", x.c_str(), y) ;
	}
	', plugin = "Rcpp" )
	checkEquals( capture.output( x <- fx("world", 3L) ) , "hello world (3)", 10L, msg = "RCPP_FUNCTION_VOID_0" )

	info <- .getInfo( "foo", fx )
	checkEquals( info[["n"]], 2L )
	checkEquals( info[["input"]], c("std::string x","int y") )
	checkEquals( info[["output"]], NULL)
	checkEquals( class(info), "rcppfunctionvoidinfo" )

}

test.RCPPXPMETHOD <- function(){

	fx <- cxxfunction( signature(), '
		std::vector<int>* v = new std::vector<int>(5) ;
		v->push_back( 5 ) ;
		return XPtr< std::vector<int> >(v,true) ;
	' , plugin = "Rcpp" )
	xp <- fx()

	f_back <- cxxfunction( signature( xp = "externalptr" ), '
		return get_back( xp ) ;
	', includes = '
		RCPP_XP_METHOD_0( get_back, std::vector<int>, back )
	', plugin = "Rcpp" )
	checkEquals( f_back(xp), 5L, msg = "RCPP_XP_METHOD_0" )

	info <- .getInfo( "get_back", f_back )
	checkEquals( info[["n"]], 0L )
	checkEquals( info[["class"]], "std::vector<int>" )
	checkEquals( info[["method"]], "back")
	checkEquals( class(info), "rcppxpmethodinfo" )

	f_push_back <- cxxfunction( signature( xp = "externalptr", x = "integer" ), '
		vec_push_back( xp, x );
		return R_NilValue ;
	', includes = '
		RCPP_XP_METHOD_VOID_1( vec_push_back, std::vector<int>, push_back )
	' , plugin = "Rcpp" )
	f_push_back( xp, 10L )
	checkEquals( f_back(xp), 10L, msg = "RCPP_XP_METHOD_0" )
	f_push_back( xp, 20L )
	checkEquals( f_back(xp), 20L, msg = "RCPP_XP_METHOD_0" )

	info <- .getInfo( "vec_push_back", f_push_back )
	checkEquals( info[["n"]], 1L )
	checkEquals( info[["class"]], "std::vector<int>" )
	checkEquals( info[["method"]], "push_back")
	checkEquals( class(info), "rcppxpmethodvoidinfo" )


	f_front_cast <- cxxfunction( signature( xp = "externalptr" ), '
		return front( xp ) ;
	', includes = '
		RCPP_XP_METHOD_CAST_0( front, std::vector<int>, front, double )
	' , plugin = "Rcpp" )
	checkEquals( f_front_cast(xp), 0, msg = "RCPP_XP_METHOD_CAST value" )
	checkEquals( typeof( f_front_cast(xp) ), "double", msg = "RCPP_XP_METHOD_CAST type" )

	info <- .getInfo( "front", f_front_cast )
	checkEquals( info[["n"]], 0L )
	checkEquals( info[["class"]], "std::vector<int>" )
	checkEquals( info[["method"]], "front")
	checkEquals( info[["cast"]], "double")

	checkEquals( class(info), "rcppxpmethodcastinfo" )

}

test.RCPPXPFIELD <- function(){

	cl <- '
	class Foo {
		public:
			int x ;
			Foo( int x_) : x(x_){}
	} ;
	RCPP_XP_FIELD( Foo_x, Foo, x )
	RCPP_FUNCTION_0(SEXP, newFoo){
		return Rcpp::XPtr<Foo>( new Foo(2), true ) ;
	}
	'

	fx <- cxxfunction( signature(xp = "externalptr"), '', include = cl, plugin = "Rcpp" )

	get_info <- .getInfo( "Foo_x_get", fx )
	set_info <- .getInfo( "Foo_x_set", fx )
	checkEquals( get_info[["class"]], "Foo" )
	checkEquals( set_info[["class"]], "Foo" )
	checkEquals( get_info[["field"]], "x" )
	checkEquals( set_info[["field"]], "x" )
	checkEquals( class( get_info ), "rcppxpfieldgetinfo" )
	checkEquals( class( set_info ), "rcppxpfieldsetinfo" )

	dll <- .getDll( fx )
	xp <- .Call( dll$newFoo )

	checkEquals( .Call( dll$Foo_x_get, xp ), 2L )
	.Call( dll$Foo_x_set, xp, 10L )
	checkEquals( .Call( dll$Foo_x_get, xp ), 10L )

}

#### regression test for long long support
#test.long.long <- function(){
#
#	fx <- cxxfunction( signature(), '
#		return foo() ;
#	', includes = '
#	RCPP_FUNCTION_0(size_t, foo){
#		std::vector<int> v(10) ;
#		return v.size() ;
#	}
#	', plugin = "Rcpp" )
#	checkEquals( as.integer(fx()), 10L, msg = "long long support" )
#
#}

}
