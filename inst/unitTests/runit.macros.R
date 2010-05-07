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

.getInfo <- function( symbol, fx ){
	env <- environment( fx@.Data )
	f <- get( "f", env )
	dlls <- getLoadedDLLs()
	dll <- if( ! f %in% names(dlls) ){
		dyn.load( get( "libLFile", env ) )
	} else{
		dlls[[ match( f, names(dlls) ) ]]
	}
	info_symbol <- paste( symbol, "__rcpp_info__", sep = "" )
	routine <- getNativeSymbolInfo( info_symbol, dll )
	info <- .Call( routine )
	info
}

test.macro.switch <- function(){
	rcpp_typeof <- function(x){
		.Call( "rcpp_call_test", x, PACKAGE = "Rcpp" )
	}
	sexp_types <- c( integer = 13L, double = 14L, raw = 24L, 
		complex = 15L, logical = 10L, list = 19L, 
		"expression" = 20L, character = 16 )
	checkEquals( rcpp_typeof(1L ), sexp_types[[ "integer" ]], msg = "RCPP_RETURN_VECTOR <INTSXP> " )
	checkEquals( rcpp_typeof(1.0), sexp_types[["double"]], msg = "RCPP_RETURN_VECTOR <REALSXP> " )
	checkEquals( rcpp_typeof(as.raw(0)), sexp_types[["raw"]] , msg = "RCPP_RETURN_VECTOR <RAWSXP> " )
	checkEquals( rcpp_typeof(1i), sexp_types[["complex"]], msg = "RCPP_RETURN_VECTOR <CPLXSXP> " )
	checkEquals( rcpp_typeof(TRUE), sexp_types[["logical"]], msg = "RCPP_RETURN_VECTOR <LGLSXP> " )
	checkEquals( rcpp_typeof(list(1)), sexp_types[["list"]] , msg = "RCPP_RETURN_VECTOR <VECSXP> " )
	checkEquals( rcpp_typeof(expression(x)), sexp_types[["expression"]], msg = "RCPP_RETURN_VECTOR <EXPRSXP> " )
	checkEquals( rcpp_typeof(""), sexp_types[["character"]], msg = "RCPP_RETURN_VECTOR <STRSXP> " )
}

test.RCPPFUNCTION <- function(){
	
	fx <- cppfunction( signature(), '
		return foo() ;
	', includes = '
	RCPP_FUNCTION_0(int, foo){
		return 10 ;
	}
	')
	checkEquals( fx(), 10L, msg = "RCPP_FUNCTION_0" )
	
	checkEquals( .getInfo( "foo", fx ) , 
		structure( list( 
		n = 0L, 
		output = "int", 
		input = character(0) ), class = "rcppfunctioninfo" ) )
	
	fx <- cppfunction( signature(x = "numeric", y = "numeric" ), '
		return foo(x, y) ;
	', includes = '
	RCPP_FUNCTION_2(double, foo, double x, double y){
		return x * y ;
	}
	')
	checkEquals( fx( 10, 10), 100, msg = "RCPP_FUNCTION_2" )
	
	checkEquals( .getInfo( "foo", fx ) , 
		structure( list( 
		n = 2L, 
		output = "double", 
		input = c("double x","double y") ), class = "rcppfunctioninfo" ) )
	
}

test.RCPPFUNCTION.VOID <- function(){
	fx <- cppfunction( signature(), '
		return foo() ;
	', includes = '
	RCPP_FUNCTION_VOID_0(foo){
		Rprintf("hello\\n") ;
	}
	')
	checkEquals( capture.output( x <- fx() ) , "hello", 10L, msg = "RCPP_FUNCTION_VOID_0" )
	
	info <- .getInfo( "foo", fx )
	checkEquals( info[["n"]], 0L )
	checkEquals( info[["input"]], character(0) )
	checkEquals( info[["output"]], NULL) 
	checkEquals( class(info), "rcppfunctionvoidinfo" )
	
	fx <- cppfunction( signature(x = "character", y = "integer" ), '
		return foo(x, y) ;
	', includes = '
	RCPP_FUNCTION_VOID_2(foo, std::string x, int y){
		Rprintf("hello %s (%d)\\n", x.c_str(), y) ;
	}
	')
	checkEquals( capture.output( x <- fx("world", 3L) ) , "hello world (3)", 10L, msg = "RCPP_FUNCTION_VOID_0" )
	
	info <- .getInfo( "foo", fx )
	checkEquals( info[["n"]], 2L )
	checkEquals( info[["input"]], c("std::string x","int y") )
	checkEquals( info[["output"]], NULL) 
	checkEquals( class(info), "rcppfunctionvoidinfo" )
		
}

test.RCPPXPMETHOD <- function(){
	
	fx <- cppfunction( signature(), '
		std::vector<int>* v = new std::vector<int>(5) ;
		return XPtr< std::vector<int> >(v,true) ;
	' )
	xp <- fx()
	
	f_size <- cppfunction( signature( xp = "externalptr" ), '
		return get_size( xp ) ;
	', includes = '
		RCPP_XP_METHOD_0( get_size, std::vector<int>, size )
	' )
	checkEquals( f_size(xp), 5L, msg = "RCPP_XP_METHOD_0" )
	
	info <- .getInfo( "get_size", f_size )
	checkEquals( info[["n"]], 0L )
	checkEquals( info[["class"]], "std::vector<int>" )
	checkEquals( info[["method"]], "size") 
	checkEquals( class(info), "rcppxpmethodinfo" )
	
	
	f_push_back <- cppfunction( signature( xp = "externalptr", x = "integer" ), '
		vec_push_back( xp, x );
		return R_NilValue ;
	', includes = '
		RCPP_XP_METHOD_VOID_1( vec_push_back, std::vector<int>, push_back )
	' )
	f_push_back( xp, 10L )
	f_push_back( xp, 20L )
	checkEquals( f_size(xp), 7L, msg = "RCPP_XP_METHOD_0" )
	
	info <- .getInfo( "vec_push_back", f_push_back )
	checkEquals( info[["n"]], 1L )
	checkEquals( info[["class"]], "std::vector<int>" )
	checkEquals( info[["method"]], "push_back") 
	checkEquals( class(info), "rcppxpmethodvoidinfo" )
	
	
	f_front_cast <- cppfunction( signature( xp = "externalptr" ), '
		return front( xp ) ;
	', includes = '
		RCPP_XP_METHOD_CAST_0( front, std::vector<int>, front, double )
	' )
	checkEquals( f_front_cast(xp), 0, msg = "RCPP_XP_METHOD_CAST value" )
	checkEquals( typeof( f_front_cast(xp) ), "double", msg = "RCPP_XP_METHOD_CAST type" )
	
	info <- .getInfo( "front", f_front_cast )
	checkEquals( info[["n"]], 0L )
	checkEquals( info[["class"]], "std::vector<int>" )
	checkEquals( info[["method"]], "front") 
	checkEquals( info[["cast"]], "double") 
	
	checkEquals( class(info), "rcppxpmethodcastinfo" )
	
}


