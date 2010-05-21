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

test.Language <- function(){
	funx <- cppfunction(signature(x="ANY"), 'return Language(x) ;' )
	checkEquals( funx( call("rnorm") ), call("rnorm" ), msg = "Language( LANGSXP )" )
	checkException( funx(funx), msg = "Language not compatible with function" )
	checkException( funx(new.env()), msg = "Language not compatible with environment" )
	checkException( funx(1:10), msg = "Language not compatible with integer" )
	checkException( funx(TRUE), msg = "Language not compatible with logical" )
	checkException( funx(1.3), msg = "Language not compatible with numeric" )
	checkException( funx(as.raw(1) ), msg = "Language not compatible with raw" )
}

test.Language.variadic <- function(){
	if( Rcpp:::capabilities()[["variadic templates"]] ){
		funx <- cppfunction(signature(), '
		return Language( "rnorm", 10, 0.0, 2.0 ) ;
		',
			cxxargs = "-std=c++0x" )
		checkEquals( funx(), call("rnorm", 10L, 0.0, 2.0 ), 
			msg = "variadic templates" )
			
		funx <- cppfunction(signature(), '
		return Language( "rnorm", 10, Named("mean",0.0), 2.0 ) ;
		',
			cxxargs = "-std=c++0x" )
		checkEquals( funx(), call("rnorm", 10L, mean = 0.0, 2.0 ), 
			msg = "variadic templates (with names)" )
	}
}

# same as about but without variadic templates
test.Language.push.back <- function(){
	funx <- cppfunction(signature(), '
	Language call("rnorm") ;
	call.push_back( 10 ) ;
	call.push_back( Named("mean", 0.0) ) ;
	call.push_back( 2.0 ) ;
	return call ;
	' )
	checkEquals( funx(), 
		call("rnorm", 10L, mean = 0.0, 2.0 ), 
		msg = "Language::push_back" )
}

test.Language.square <- function(){
	funx <- cppfunction(signature(), '
	Language p("rnorm") ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	return p[2] ;
	' )
	checkEquals( funx(), 10.0, msg = "Language::operator[] used as rvalue" )

	funx <- cppfunction(signature(), '
	Language p("rnorm") ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	p[1] = "foobar" ;
	p[2] = p[3] ;
	return p ;
	' )
	checkEquals( funx(), call("rnorm", "foobar", 20.0, 20.0) , msg = "Pairlist::operator[] used as lvalue" )
}

test.Language.function <- function(){
	funx <- cppfunction(signature(g = "function", x = "numeric"), 
	'
	Function fun(g) ;
	Language call( fun );
	call.push_back(x) ;
	return Rf_eval( call, R_GlobalEnv ) ;
	' )
	checkEquals( funx(sort, sample(1:10)), 1:10, msg = "Language( Function ) " )
}

test.Language.inputoperator <- function(){
	funx <- cppfunction(signature(), 
	'
	Language call( "rnorm" );
	call << 10 << Named( "sd", 10 ) ;
	return call ;
	' )
	checkEquals( funx(), call("rnorm", 10L, sd = 10L ) , msg = "Language<<" )
}

test.Language.unary.call <- function(){
	
	funx <- cppfunction(signature(y = "integer" ), '
	
	Language call( "seq", Named("from", 10 ), Named("to", 0 ) ) ;
	IntegerVector x(y) ;
	List output( x.size() ) ;
	std::transform( 
		x.begin(), x.end(), 
		output.begin(),
		unary_call<int>(call)
		) ;
	return output ;
	' )
	
	checkEquals( 
		funx( 1:10 ), 
		lapply( 1:10, function(n) seq(from=n, to = 0 ) ), 
		msg = "c++ lapply using calls" )
	
}

test.Language.unary.call.index <- function(){
	
	funx <- cppfunction(signature(y = "integer" ), '
	Language call( "seq", 10, 0 ) ;
	IntegerVector x(y) ;
	List output( x.size() ) ;
	std::transform( 
		x.begin(), x.end(), 
		output.begin(),
		unary_call<int>(call,2)
		) ;
	return output ;
	' )
	
	checkEquals( 
		funx( 1:10 ), 
		lapply( 1:10, function(n) seq(from=10, to = n ) ), 
		msg = "c++ lapply using calls" )
	
}

test.Language.binary.call <- function(){
	
	funx <- cppfunction(signature(y1 = "integer", y2 = "integer" ), '
	
	Language call( "seq", Named("from", 10 ), Named("to", 0 ) ) ;
	IntegerVector x1(y1) ;
	IntegerVector x2(y2) ;
	List output( x1.size() ) ;
	std::transform( 
		x1.begin(), x1.end(), x2.begin(),
		output.begin(),
		binary_call<int,int>(call)
		) ;
	return output ;
	' )
	
	checkEquals( 
		funx( 1:10, 11:20 ), 
		lapply( 1:10, function(n) seq(n, n+10) ), 
		msg = "c++ lapply using calls" )
	
}

test.Language.fixed.call <- function(){
	
	funx <- cppfunction(signature(), '
	
	Language call( Function("rnorm"), 10 ) ;
	std::vector< std::vector<double> > result(10) ;
	std::generate( 
		result.begin(), result.end(), 
		fixed_call< std::vector<double> >(call)
		) ;
	return wrap( result );
	' )
	
	set.seed(123)
	res <- funx()
	set.seed(123)
	exp <- lapply( 1:10, function(n) rnorm(10) )
	checkEquals( res, exp, msg = "std::generate" )
}

test.Language.in.env <- function(){

	fx <- cppfunction( signature(x = "environment" ), '
		Environment env(x) ;
		Language call( "sum", Symbol("y") ) ;
		return call.eval( env ) ;
	' )
	
	e <- new.env()
	e[["y"]] <- 1:10
	checkEquals( fx(e), sum(1:10), msg = "Language::eval( SEXP )" )
}
