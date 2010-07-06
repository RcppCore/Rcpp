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

.setUp <- function(){
	if( ! exists( ".rcpp.environments", globalenv() ) ){
		# definition of all the functions at once
		
		sugar.functions <- list( 
			"runit_ls" = list( 
				signature(x="environment"), 
				'
					Rcpp::Environment env(x) ; 
					return env.ls(true) ;
				' ), 
			"runit_ls2" = list( 
				signature(x="environment"),
				'
					Rcpp::Environment env(x) ; 
					return env.ls(false) ;
				' 	
			), 
			"runit_get" = list( 
				signature(x="environment", name = "character" ),
				'
					Environment env(x) ;
					return env.get( as<std::string>(name) ) ;
				'
			), 
			"runit_exists" = list( 
				signature(x="environment", name = "character" ), 
				'
					Environment env(x) ;
					std::string st = as< std::string >(name) ;
					return wrap( env.exists( st ) ) ;
				'
			), 
			"runit_assign"  =list( 
				signature(x="environment", name = "character", object = "ANY" ), 
				'
					Environment env(x) ;
					std::string st = as< std::string>(name) ;
					return wrap( env.assign(st, object) ) ;
				' 				
			), 
			"runit_islocked" = list( 
				signature(x="environment" ), 
				'
					Environment env(x) ;
					env.assign( "x1", 1 ) ;
					env.assign( "x2", 10.0 ) ;
					env.assign( "x3", std::string( "foobar" ) ) ;
					env.assign( "x4", "foobar" ) ;
					std::vector< std::string > aa(2) ; aa[0] = "foo" ; aa[1] = "bar" ;
					env.assign( "x5", aa ) ;
					return R_NilValue ;
				'			
			), 
			"runit_bindingIsActive" = list( 
				signature(x="environment", name = "character" ), 
				'
					Environment env(x) ;
					std::string st = as<std::string>(name);
					return wrap( env.bindingIsActive(st) ) ;
				' 
			), 
			"runit_bindingIsLocked" = list( 
				signature(x="environment", name = "character" ), 
				'
					Environment env(x) ;
					std::string st = as<std::string>(name) ;
					return wrap( env.bindingIsLocked(st) ) ;
				'				
			), 
			"runit_notanenv" = list( 
				signature(x="ANY"), 
				'Rcpp::Environment env(x) ;'
			), 
			"runit_lockbinding" = list( 
				signature(x="environment", name = "character" ), 
				'
					Environment env(x) ;
					std::string st = as<std::string>(name) ;
					env.lockBinding( st ) ;
					return R_NilValue ;
				'			
			), 
			"runit_unlockbinding" = list( 
				signature(x="environment", name = "character" ), 
				'
					Environment env(x) ;
					std::string st = as<std::string>(name) ;
					env.unlockBinding( st ) ;
					return R_NilValue ;
				'	
			), 
			"runit_globenv" = list( 
				signature(), 
				'return Rcpp::Environment::global_env(); '
			), 
			"runit_emptyenv" = list( 
				 signature(), 
				 'return Rcpp::Environment::empty_env(); '
			), 
			"runit_baseenv" = list( 
				 signature(), 
				 'return Rcpp::Environment::base_env(); '
			), 
			"runit_namespace" = list( 
				signature(env = "character" ),  
				'
				std::string st = as<std::string>(env) ;
				return Environment::namespace_env(st); 
				'	
			), 
			"runit_env_SEXP" = list( 
				signature( env = "ANY" ), 
				'return Environment( env ) ;'
			), 
			"runit_env_string" = list( 
				 signature( env = "character" ), 
				 '
				 	std::string st = as<std::string>( env ) ;
				 	return Environment( st ) ;
				 '
			), 
			"runit_env_int" = list( 
				signature( env = "integer" ), 
				'
					int pos = as<int>(env) ;
					return Environment( pos ) ;
				'
			), 
			"runit_parent" = list( 
				 signature( env = "environment" ), 
				 '
				 	return Environment(env).parent() ;
				 '   
			), 
			"runit_remove" = list( 
				signature( env = "environment", name = "character" ),
				'
					bool res = Environment(env).remove( as<std::string>(name) ) ;
					return wrap( res ) ;
				'
			), 
			"runit_square" = list( 
				  signature( env = "environment" ), 
				  '
					Environment e(env) ;
					List out(3) ;
					out[0] = e["x"] ;
					e["y"] = 2 ;
					out[1] = e["y"] ;
					e["x"] = "foo"; 
					out[2] = e["x"] ;
					return out ;
					' 
			), 
			"runit_Rcpp" = list( 
				 signature(), 
				 'return Environment::Rcpp_namespace() ; '
			), 
			"runit_child" = list( 
				signature(), 
				'
				Environment global_env = Environment::global_env() ;
				return global_env.new_child(false) ;
				'
			)
		)
		signatures <- lapply( sugar.functions, "[[", 1L )
		bodies <- lapply( sugar.functions, "[[", 2L )
		fx <- cxxfunction( signatures, bodies, plugin = "Rcpp" )
		getDynLib( fx ) # just forcing loading the dll now
		assign( ".rcpp.environments", fx, globalenv() )
	}
}
			
test.environment.ls <- function(){
	funx <- .rcpp.environments$runit_ls
	e <- new.env( )
	e$a <- 1:10
	e$b <- "foo"
	e$.c <- "hidden"
	checkEquals( sort(funx(e)), sort(c("a","b", ".c")), msg = "Environment::ls(true)" )
	checkEquals( funx(asNamespace("Rcpp")), ls(envir=asNamespace("Rcpp"), all = TRUE), 
		msg = "Environment(namespace)::ls()" )
	
	funx <- .rcpp.environments$runit_ls2
	checkEquals( funx(e), c("a","b"), msg = "Environment::ls(false)" )
	checkEquals( funx(asNamespace("Rcpp")), ls(envir=asNamespace("Rcpp"), all = FALSE), 
		msg = "Environment(namespace)::ls()" )
	
}

test.environment.get <- function(){
	funx <- .rcpp.environments$runit_get
	
	e <- new.env( )
	e$a <- 1:10
	e$b <- "foo"
	
	checkEquals( funx( e, "a" ), e$a, msg = "Environment::get()" )
	checkEquals( funx( e, "foobar" ), NULL, msg = "Environment::get()" )
	checkEquals( funx( asNamespace("Rcpp"), "CxxFlags"), Rcpp:::CxxFlags, 
		msg = "Environment(namespace)::get() " )
	
}

test.environment.exists <- function(){
	funx <- .rcpp.environments$runit_exists
	e <- new.env( )
	e$a <- 1:10
	e$b <- "foo"
	
	checkTrue( funx( e, "a" ), msg = "Environment::get()" )
	checkTrue( !funx( e, "foobar" ), msg = "Environment::get()" )
	checkTrue( funx( asNamespace("Rcpp"), "CxxFlags"), 
		msg = "Environment(namespace)::get() " )
}

test.environment.assign <- function(){
	funx <- .rcpp.environments$runit_assign
	e <- new.env( )
	checkTrue( funx(e, "a", 1:10 ), msg = "Environment::assign" )
	checkTrue( funx(e, "b", Rcpp:::CxxFlags ), msg = "Environment::assign" )
	checkEquals( ls(e), c("a", "b"), msg = "Environment::assign, checking names" )
	checkEquals( e$a, 1:10, msg = "Environment::assign, checking value 1" )
	checkEquals( e$b, Rcpp:::CxxFlags, msg = "Environment::assign, checking value 2" )
	
	lockBinding( "a", e )
	can.demangle <- Rcpp:::capabilities()[["demangling"]]
	if( can.demangle ){
		checkTrue( 
			tryCatch( { funx(e, "a", letters ) ; FALSE}, "Rcpp::binding_is_locked" = function(e) TRUE ), 
			msg = "cannot assign to locked binding (catch exception)" )
	} else {
		checkTrue( 
			tryCatch( { funx(e, "a", letters ) ; FALSE}, "error" = function(e) TRUE ), 
			msg = "cannot assign to locked binding (catch exception)" )
	}
}

test.environment.isLocked <- function(){
	funx <- .rcpp.environments$runit_islocked
	e <- new.env()
	funx(e)
	checkEquals( e[["x1"]], 1L  , msg = "Environment::assign( int ) " )
	checkEquals( e[["x2"]], 10.0, msg = "Environment::assign( double ) " )
	checkEquals( e[["x3"]], "foobar", msg = "Environment::assign( char* ) " )
	checkEquals( e[["x4"]], "foobar", msg = "Environment::assign( std::string ) " )
	checkEquals( e[["x5"]], c("foo", "bar" ), msg = "Environment::assign( vector<string> ) " )
}

test.environment.bindingIsActive <- function(){
	funx <- .rcpp.environments$runit_bindingIsActive
	e <- new.env()
	e$a <- 1:10
	makeActiveBinding( "b", function(x) 10, e ) 

	checkTrue( !funx(e, "a" ), msg = "Environment::bindingIsActive( non active ) -> false" )
	checkTrue( funx(e, "b" ), msg = "Environment::bindingIsActive( active ) -> true" )

	can.demangle <- Rcpp:::capabilities()[["demangling"]]
	if( can.demangle ){
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
			msg = "Environment::bindingIsActive(no binding) -> exception)" )
	} else {
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, error = function(e) TRUE ), 
			msg = "Environment::bindingIsActive(no binding) -> exception)" )
	}
}

test.environment.bindingIsLocked <- function(){
	funx <- .rcpp.environments$runit_bindingIsLocked
	e <- new.env()
	e$a <- 1:10
	e$b <- letters
	lockBinding( "b", e )
	
	checkTrue( !funx(e, "a" ), msg = "Environment::bindingIsActive( non active ) -> false" )
	checkTrue( funx(e, "b" ), msg = "Environment::bindingIsActive( active ) -> true" )

	can.demangle <- Rcpp:::capabilities()[["demangling"]]
	if( can.demangle ){
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
			msg = "Environment::bindingIsLocked(no binding) -> exception)" )
	} else {
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, error = function(e) TRUE ), 
			msg = "Environment::bindingIsLocked(no binding) -> exception)" )
	}
}

test.environment.NotAnEnvironment <- function(){
	funx <- .rcpp.environments$runit_notanenv
	checkException( funx( funx ), msg = "not an environment" )
	checkException( funx( letters ), msg = "not an environment" )
	checkException( funx( NULL ), msg = "not an environment" )
}


test.environment.lockBinding <- function(){
	funx <- .rcpp.environments$runit_lockbinding
	e <- new.env()
	e$a <- 1:10
	e$b <- letters
	funx(e, "b")
	checkTrue( bindingIsLocked("b", e ), msg = "Environment::lockBinding()" )

	can.demangle <- Rcpp:::capabilities()[["demangling"]]
	if( can.demangle ){
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
			msg = "Environment::lockBinding(no binding) -> exception)" )
	} else {
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, error = function(e) TRUE ), 
			msg = "Environment::lockBinding(no binding) -> exception)" )
	}
}

test.environment.unlockBinding <- function(){
	funx <- .rcpp.environments$runit_unlockbinding
	e <- new.env()
	e$a <- 1:10
	e$b <- letters
	lockBinding( "b", e )
	funx(e, "b")
	checkTrue( !bindingIsLocked("b", e ), msg = "Environment::lockBinding()" )

	can.demangle <- Rcpp:::capabilities()[["demangling"]]
	if( can.demangle ){
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, "Rcpp::no_such_binding" = function(e) TRUE ), 
			msg = "Environment::unlockBinding(no binding) -> exception)" )
	} else {
		checkTrue( 
			tryCatch( { funx(e, "xx" ) ; FALSE}, error = function(e) TRUE ), 
			msg = "Environment::unlockBinding(no binding) -> exception)" )
	}
}

test.environment.global.env <- function(){
	funx <- .rcpp.environments$runit_globenv
	checkEquals( funx(), globalenv(), msg = "REnvironment::global_env" )
}

test.environment.empty.env <- function(){
	funx <- .rcpp.environments$runit_emptyenv
	checkEquals( funx(), emptyenv(), msg = "REnvironment::empty_env" )
}

test.environment.base.env <- function(){
	funx <- .rcpp.environments$runit_baseenv
	checkEquals( funx(), baseenv(), msg = "REnvironment::base_env" )
}

test.environment.empty.env <- function(){
	funx <- .rcpp.environments$runit_emptyenv
	checkEquals( funx(), .BaseNamespaceEnv, msg = "REnvironment::base_namespace" )
}

test.environment.namespace.env <- function(){
	funx <- .rcpp.environments$runit_namespace
	checkEquals( funx("Rcpp"), asNamespace("Rcpp"), msg = "REnvironment::base_namespace" )

	can.demangle <- Rcpp:::capabilities()[["demangling"]]
	if( can.demangle ){
		checkTrue( 
			tryCatch( { funx("----" ) ; FALSE}, "Rcpp::no_such_namespace" = function(e) TRUE ), 
			msg = "Environment::namespace_env(no namespace) -> exception)" )
	} else {
		checkTrue( 
			tryCatch( { funx("----" ) ; FALSE}, error = function(e) TRUE ), 
			msg = "Environment::namespace_env(no namespace) -> exception)" )
	}
}

test.environment.constructor.SEXP <- function(){
	funx <- .rcpp.environments$runit_env_SEXP
	checkEquals( funx( globalenv() ), globalenv(), msg = "Environment( environment ) - 1" )
	checkEquals( funx( baseenv() ), baseenv(), msg = "Environment( environment ) - 2" )
	checkEquals( funx( asNamespace("Rcpp") ), asNamespace("Rcpp"), msg = "Environment( environment ) - 3" )
	
	checkEquals( funx( ".GlobalEnv" ), globalenv(), msg = "Environment( character ) - 1" )
	checkEquals( funx( "package:base" ), baseenv(), msg = "Environment( character ) - 2" )
	checkEquals( funx( "package:Rcpp" ), as.environment("package:Rcpp") , msg = 'Environment( "package:Rcpp") ' )
	
	checkEquals( funx(1L), globalenv(), msg = "Environment( SEXP{integer} )" )
}

test.environment.constructor.stdstring <- function(){
	funx <- .rcpp.environments$runit_env_string
	checkEquals( funx( ".GlobalEnv" ), globalenv(), msg = "Environment( std::string ) - 1" )
	checkEquals( funx( "package:base" ), baseenv(), msg = "Environment( std::string ) - 2" )
	checkEquals( funx( "package:Rcpp" ), as.environment("package:Rcpp") , 
		msg = 'Environment( std::string ) - 3' )
	
}

test.environment.constructor.int <- function(){
	funx <- .rcpp.environments$runit_env_int
	for( i in 1:length(search())){
		checkEquals( funx(i), as.environment(i), msg = sprintf("Environment(int) - %d", i) ) 
	}
}

test.environment.remove <- function(){
	funx <- .rcpp.environments$runit_remove
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
	funx <- .rcpp.environments$runit_parent
	
	e <- new.env( parent = emptyenv() )
	f <- new.env( parent = e )
	checkEquals( funx(f), e, msg = "Environment::parent" )
	checkEquals( funx(e), emptyenv() , msg = "Environment::parent" )
	
}

test.environment.square <- function(){
	funx <- .rcpp.environments$runit_square
	env <- new.env( )
	env[["x"]] <- 10L
	checkEquals( funx(env), list( 10L, 2L, "foo") )
	
}

test.environment.Rcpp <- function(){
	funx <- .rcpp.environments$runit_Rcpp
	checkEquals( funx(), asNamespace("Rcpp") , msg = "cached Rcpp namespace" )
}

test.environment.child <- function(){
	funx <- .rcpp.environments$runit_child
	checkEquals( parent.env(funx()), globalenv(), 
		msg = "" )
}


