#!/usr/bin/r -t
#
# Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

test.environment.ls <- function(){
	funx <- cppfunction(signature(x="environment"), '
	Rcpp::Environment env(x) ; 
	return env.ls(true) ;
	' )
	
	e <- new.env( )
	e$a <- 1:10
	e$b <- "foo"
	e$.c <- "hidden"
	checkEquals( sort(funx(e)), sort(c("a","b", ".c")), msg = "Environment::ls(true)" )
	checkEquals( funx(asNamespace("Rcpp")), ls(envir=asNamespace("Rcpp"), all = TRUE), 
		msg = "Environment(namespace)::ls()" )
	
	funx <- cppfunction(signature(x="environment"), '
	Rcpp::Environment env(x) ; 
	return env.ls(false) ;
	' )
	checkEquals( funx(e), c("a","b"), msg = "Environment::ls(false)" )
	checkEquals( funx(asNamespace("Rcpp")), ls(envir=asNamespace("Rcpp"), all = FALSE), 
		msg = "Environment(namespace)::ls()" )
	
}

test.environment.get <- function(){
	funx <- cppfunction(signature(x="environment", name = "character" ), '
	Environment env(x) ;
	return env.get( as<std::string>(name) ) ;
	' )
	
	e <- new.env( )
	e$a <- 1:10
	e$b <- "foo"
	
	checkEquals( funx( e, "a" ), e$a, msg = "Environment::get()" )
	checkEquals( funx( e, "foobar" ), NULL, msg = "Environment::get()" )
	checkEquals( funx( asNamespace("Rcpp"), "CxxFlags"), Rcpp:::CxxFlags, 
		msg = "Environment(namespace)::get() " )
	
}

test.environment.exists <- function(){
	funx <- cppfunction(signature(x="environment", name = "character" ), '
	Environment env(x) ;
	std::string st = as< std::string >(name) ;
	return wrap( env.exists( st ) ) ;
	'  )
	
	e <- new.env( )
	e$a <- 1:10
	e$b <- "foo"
	
	checkTrue( funx( e, "a" ), msg = "Environment::get()" )
	checkTrue( !funx( e, "foobar" ), msg = "Environment::get()" )
	checkTrue( funx( asNamespace("Rcpp"), "CxxFlags"), 
		msg = "Environment(namespace)::get() " )
}

test.environment.assign <- function(){
	
	funx <- cppfunction(signature(x="environment", name = "character", object = "ANY" ), '
	Environment env(x) ;
	std::string st = as< std::string>(name) ;
	return wrap( env.assign(st, object) ) ;
	' )
	
	e <- new.env( )
	checkTrue( funx(e, "a", 1:10 ), msg = "Environment::assign" )
	checkTrue( funx(e, "b", Rcpp:::CxxFlags ), msg = "Environment::assign" )
	checkEquals( ls(e), c("a", "b"), msg = "Environment::assign, checking names" )
	checkEquals( e$a, 1:10, msg = "Environment::assign, checking value 1" )
	checkEquals( e$b, Rcpp:::CxxFlags, msg = "Environment::assign, checking value 2" )
	
	lockBinding( "a", e )
	checkTrue( 
		tryCatch( { funx(e, "a", letters ) ; FALSE}, "Rcpp::binding_is_locked" = function(e) TRUE ), 
		msg = "cannot assign to locked binding (catch exception)" )

}

test.environment.isLocked <- function(){
	funx <- cppfunction(signature(x="environment" ), '
	Environment env(x) ;
	env.assign( "x1", 1 ) ;
	env.assign( "x2", 10.0 ) ;
	env.assign( "x3", std::string( "foobar" ) ) ;
	env.assign( "x4", "foobar" ) ;
	std::vector< std::string > aa(2) ; aa[0] = "foo" ; aa[1] = "bar" ;
	env.assign( "x5", aa ) ;
	return R_NilValue ;
	' )
	
	e <- new.env()
	funx(e)
	checkEquals( e[["x1"]], 1L  , msg = "Environment::assign( int ) " )
	checkEquals( e[["x2"]], 10.0, msg = "Environment::assign( double ) " )
	checkEquals( e[["x3"]], "foobar", msg = "Environment::assign( char* ) " )
	checkEquals( e[["x4"]], "foobar", msg = "Environment::assign( std::string ) " )
	checkEquals( e[["x5"]], c("foo", "bar" ), msg = "Environment::assign( vector<string> ) " )
}

test.environment.bindingIsActive <- function(){
	
	funx <- cppfunction(signature(x="environment", name = "character" ), '
	Environment env(x) ;
	std::string st = as<std::string>(name);
	return wrap( env.bindingIsActive(st) ) ;
	' )
	
	e <- new.env()
	e$a <- 1:10
	makeActiveBinding( "b", function(x) 10, e ) 

	checkTrue( !funx(e, "a" ), msg = "Environment::bindingIsActive( non active ) -> false" )
	checkTrue( funx(e, "b" ), msg = "Environment::bindingIsActive( active ) -> true" )
	checkTrue( 
		tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
		msg = "Environment::bindingIsActive(no binding) -> exception)" )
	
}

test.environment.bindingIsLocked <- function(){
	
	funx <- cppfunction(signature(x="environment", name = "character" ), '
	Environment env(x) ;
	std::string st = as<std::string>(name) ;
	return wrap( env.bindingIsLocked(st) ) ;
	'  )
	
	e <- new.env()
	e$a <- 1:10
	e$b <- letters
	lockBinding( "b", e )
	
	checkTrue( !funx(e, "a" ), msg = "Environment::bindingIsActive( non active ) -> false" )
	checkTrue( funx(e, "b" ), msg = "Environment::bindingIsActive( active ) -> true" )
	checkTrue( 
		tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
		msg = "Environment::bindingIsLocked(no binding) -> exception)" )
	
}

test.environment.NotAnEnvironment <- function(){
	funx <- cppfunction(signature(x="ANY"), 'Rcpp::Environment env(x) ;' )
	checkException( funx( funx ), msg = "not an environment" )
	checkException( funx( letters ), msg = "not an environment" )
	checkException( funx( NULL ), msg = "not an environment" )
}


test.environment.lockBinding <- function(){
	funx <- cppfunction(signature(x="environment", name = "character" ), '
	Environment env(x) ;
	std::string st = as<std::string>(name) ;
	env.lockBinding( st ) ;
	return R_NilValue ;
	' )
	
	e <- new.env()
	e$a <- 1:10
	e$b <- letters
	funx(e, "b")
	checkTrue( bindingIsLocked("b", e ), msg = "Environment::lockBinding()" )
	checkTrue( 
		tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
		msg = "Environment::lockBinding(no binding) -> exception)" )
	
}

test.environment.unlockBinding <- function(){
	funx <- cppfunction(signature(x="environment", name = "character" ), '
	Environment env(x) ;
	std::string st = as<std::string>(name) ;
	env.unlockBinding( st ) ;
	return R_NilValue ;
	' )
	
	e <- new.env()
	e$a <- 1:10
	e$b <- letters
	lockBinding( "b", e )
	funx(e, "b")
	checkTrue( !bindingIsLocked("b", e ), msg = "Environment::lockBinding()" )
	checkTrue( 
		tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
		msg = "Environment::unlockBinding(no binding) -> exception)" )
	
}

test.environment.global.env <- function(){
	funx <- cppfunction(signature(), 
	'return Rcpp::Environment::global_env(); ')
	checkEquals( funx(), globalenv(), msg = "REnvironment::global_env" )
}

test.environment.empty.env <- function(){
	funx <- cppfunction(signature(), 
	'return Rcpp::Environment::empty_env(); ' )
	checkEquals( funx(), emptyenv(), msg = "REnvironment::empty_env" )
}

test.environment.base.env <- function(){
	funx <- cppfunction(signature(), 
	'return Rcpp::Environment::base_env(); ' )
	checkEquals( funx(), baseenv(), msg = "REnvironment::base_env" )
}

test.environment.empty.env <- function(){
	funx <- cppfunction(signature(), 
	'return Rcpp::Environment::base_namespace(); ' )
	checkEquals( funx(), .BaseNamespaceEnv, msg = "REnvironment::base_namespace" )
}

test.environment.namespace.env <- function(){
	funx <- cppfunction(signature(env = "character" ),  '
	std::string st = as<std::string>(env) ;
	return Environment::namespace_env(st); ' )
	checkEquals( funx("Rcpp"), asNamespace("Rcpp"), msg = "REnvironment::base_namespace" )
	checkTrue( 
		tryCatch( { funx("----" ) ; FALSE}, "Rcpp::no_such_namespace" = function(e) TRUE ), 
		msg = "Environment::namespace_env(no namespace) -> exception)" )
	
}

test.environment.constructor.SEXP <- function(){
	funx <- cppfunction(signature( env = "ANY" ), 'return Environment( env ) ;'  )
	checkEquals( funx( globalenv() ), globalenv(), msg = "Environment( environment ) - 1" )
	checkEquals( funx( baseenv() ), baseenv(), msg = "Environment( environment ) - 2" )
	checkEquals( funx( asNamespace("Rcpp") ), asNamespace("Rcpp"), msg = "Environment( environment ) - 3" )
	
	checkEquals( funx( ".GlobalEnv" ), globalenv(), msg = "Environment( character ) - 1" )
	checkEquals( funx( "package:base" ), baseenv(), msg = "Environment( character ) - 2" )
	checkEquals( funx( "package:Rcpp" ), as.environment("package:Rcpp") , msg = 'Environment( "package:Rcpp") ' )
	
	checkEquals( funx(1L), globalenv(), msg = "Environment( SEXP{integer} )" )
}

test.environment.constructor.stdstring <- function(){
	funx <- cppfunction(signature( env = "character" ), '
	std::string st = as<std::string>( env ) ;
	return Environment( st ) ; '  )
	
	checkEquals( funx( ".GlobalEnv" ), globalenv(), msg = "Environment( std::string ) - 1" )
	checkEquals( funx( "package:base" ), baseenv(), msg = "Environment( std::string ) - 2" )
	checkEquals( funx( "package:Rcpp" ), as.environment("package:Rcpp") , 
		msg = 'Environment( std::string ) - 3' )
	
}

test.environment.constructor.int <- function(){
	funx <- cppfunction(signature( env = "integer" ), '
	int pos = as<int>(env) ;
	return Environment( pos ) ;'  )
	for( i in 1:length(search())){
		checkEquals( funx(i), as.environment(i), msg = sprintf("Environment(int) - %d", i) ) 
	}
}

test.environment.remove <- function(){
	funx <- cppfunction(signature( env = "environment", name = "character" ), '
	bool res = Environment(env).remove( as<std::string>(name) ) ;
	return wrap( res ) ;
	'  )
	
	e <- new.env( )
	e$a <- 1
	e$b <- 2
	checkTrue( funx( e, "a" ), msg = "Environment::remove" )
	checkEquals( ls(envir=e), "b", msg = "check that the element was removed" )
	checkException( funx(e, "xx"), msg = "Environment::remove no such binding" )
	lockBinding( "b", e )
	checkException( funx(e, "b"), msg = "Environment::remove binding is locked" )
	checkEquals( ls(envir=e), "b", msg = "check that the element was not removed" )
	
}

test.environment.parent <- function(){
	funx <- cppfunction(signature( env = "environment" ), '
	return Environment(env).parent() ;
	' )
	
	e <- new.env( parent = emptyenv() )
	f <- new.env( parent = e )
	checkEquals( funx(f), e, msg = "Environment::parent" )
	checkEquals( funx(e), emptyenv() , msg = "Environment::parent" )
	
}

test.environment.square <- function(){
	
	funx <- cppfunction(signature( env = "environment" ), '
	Environment e(env) ;
	List out(3) ;
	out[0] = e["x"] ;
	e["y"] = 2 ;
	out[1] = e["y"] ;
	e["x"] = "foo"; 
	out[2] = e["x"] ;
	return out ;
	'  )
	
	env <- new.env( )
	env[["x"]] <- 10L
	checkEquals( funx(env), list( 10L, 2L, "foo") )
	
}

test.environment.Rcpp <- function(){
	funx <- cppfunction(signature(), '
	return Environment::Rcpp_namespace() ;
	'  )
	checkEquals( funx(), asNamespace("Rcpp") , msg = "cached Rcpp namespace" )
}

test.environment.child <- function(){
	funx <- cppfunction(signature(), '
	Environment global_env = Environment::global_env() ;
	return global_env.new_child(false) ;
	' )
	checkEquals( parent.env(funx()), globalenv(), 
		msg = "" )
}


