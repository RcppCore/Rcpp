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

.setUp <- function(){
	if( ! exists( ".rcpp.language", globalenv() ) ){
		# definition of all the functions at once
		
		sugar.functions <- list( 
			"runit_language" = list( 
				signature(x="ANY"), 'return Language(x) ;'
			), 
			"runit_lang_variadic_1" = list( 
				signature(), 'return Language( "rnorm", 10, 0.0, 2.0 ) ; '
			), 
			"runit_lang_variadic_2" = list( 
				signature(), 'return Language( "rnorm", 10, Named("mean",0.0), 2.0 ) ; '
			), 
			"runit_lang_push_back" = list( 
				signature(), 
				'
					Language call("rnorm") ;
					call.push_back( 10 ) ;
					call.push_back( Named("mean", 0.0) ) ;
					call.push_back( 2.0 ) ;
					return call ;
				'
			), 
			"runit_lang_square_rv" = list( 
				signature(), 
				'
					Language p("rnorm") ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					return p[2] ;
				'	
			),
			"runit_lang_square_lv" = list( 
				signature(), 
				'
					Language p("rnorm") ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					p[1] = "foobar" ;
					p[2] = p[3] ;
					return p ;
				'
			), 
			"runit_lang_fun" = list( 
				signature(g = "function", x = "numeric"), 
				'
					Function fun(g) ;
					Language call( fun );
					call.push_back(x) ;
					return Rf_eval( call, R_GlobalEnv ) ;
				'
			),  
			"runit_lang_inputop" = list( 
				signature(), 
				'
					Language call( "rnorm" );
					call << 10 << Named( "sd", 10 ) ;
					return call ;
				'
			), 
			"runit_lang_unarycall" = list( 
				signature(y = "integer" ), 
				'
	            	Language call( "seq", Named("from", 10 ), Named("to", 0 ) ) ;
					IntegerVector x(y) ;
					List output( x.size() ) ;
					std::transform( 
						x.begin(), x.end(), 
						output.begin(),
						unary_call<int>(call)
						) ;
					return output ;
				'	
			), 
			"runit_lang_unarycallindex" = list( 
				signature(y = "integer" ), 
				'
					Language call( "seq", 10, 0 ) ;
					IntegerVector x(y) ;
					List output( x.size() ) ;
					std::transform( 
						x.begin(), x.end(), 
						output.begin(),
						unary_call<int>(call,2)
						) ;
					return output ;
				'
			), 
			"runit_lang_binarycall" = list( 
				signature(y1 = "integer", y2 = "integer" ), 
				'
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
				'	
			), 
			"runit_lang_fixedcall" = list( 
				signature(), 
				'
					Language call( Function("rnorm"), 10 ) ;
					std::vector< std::vector<double> > result(10) ;
					std::generate( 
						result.begin(), result.end(), 
						fixed_call< std::vector<double> >(call)
						) ;
					return wrap( result );
				'
			), 
			"runit_lang_inenv" = list( 
				 signature(x = "environment" ), 
				 '
					Environment env(x) ;
					Language call( "sum", Symbol("y") ) ;
					return call.eval( env ) ;
				'
			), 
			"runit_pairlist" = list( 
				 signature(x="ANY"),
				 'return Pairlist(x) ;'
			), 
			"runit_pl_variadic_1" = list( 
				 signature(), 
				 'return Pairlist( "rnorm", 10, 0.0, 2.0 ) ;'
			), 
			"runit_pl_variadic_2" = list( 
				signature(), 
				'return Pairlist( "rnorm", 10, Named("mean",0.0), 2.0 ) ;'
			), 
			"runit_pl_push_front" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_front( 1 ) ;
					p.push_front( 10.0 ) ;
					p.push_front( "foo" ) ;
					p.push_front( Named( "foobar", 10) ) ;
					return p ;
				'
			), 
			"runit_pl_push_back" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( "foo" ) ;
					p.push_back( Named( "foobar", 10) ) ;
					return p ;
				'
			), 
			"runit_pl_insert" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					
					/* insert in 2nd position */
					p.insert( 1, Named( "bla", "bla" ) ) ;
					
					/* insert in front */
					p.insert( 0, 30.0 ) ;
					
					/* insert in back */
					p.insert( 5, "foobar" ) ;
					
					return p ;
				'
			), 
			"runit_pl_replace" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					p.replace( 0, Named( "first", 1 ) ) ;
					p.replace( 1, 20.0 ) ;
					p.replace( 2, false ) ;
					return p ;
				'
			), 
			"runit_pl_size" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					return wrap( p.size() ) ;
				'
			), 
			"runit_pl_remove_1" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					p.remove( 0 ) ;
					return p ;
				'
			), 
			"runit_pl_remove_2" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					p.remove( 2 ) ;
					return p ;
				'
			), 
			"runit_pl_remove_3" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					p.remove( 1 ) ;
					return p ;
				'
			), 
			"runit_pl_square_1" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					return p[1] ;
				'
			), 
			"runit_pl_square_2" = list( 
				signature(), 
				'
					Pairlist p ;
					p.push_back( 1 ) ;
					p.push_back( 10.0 ) ;
					p.push_back( 20.0 ) ;
					p[1] = "foobar" ;
					p[2] = p[0] ;
					return p ;
				'
			)
			
		)
		
		signatures <- lapply( sugar.functions, "[[", 1L )
		bodies <- lapply( sugar.functions, "[[", 2L )
		fx <- cxxfunction( signatures, bodies, plugin = "Rcpp" )
		getDynLib( fx ) # just forcing loading the dll now
		assign( ".rcpp.language", fx, globalenv() )
	}
}

	
test.Language <- function(){
	funx <- .rcpp.language$runit_language
	checkEquals( funx( call("rnorm") ), call("rnorm" ), msg = "Language( LANGSXP )" )
	checkException( funx(funx), msg = "Language not compatible with function" )
	checkException( funx(new.env()), msg = "Language not compatible with environment" )
	checkException( funx(1:10), msg = "Language not compatible with integer" )
	checkException( funx(TRUE), msg = "Language not compatible with logical" )
	checkException( funx(1.3), msg = "Language not compatible with numeric" )
	checkException( funx(as.raw(1) ), msg = "Language not compatible with raw" )
}

test.Language.variadic <- function(){
	funx <- .rcpp.language$runit_lang_variadic_1
	checkEquals( funx(), call("rnorm", 10L, 0.0, 2.0 ), 
		msg = "variadic templates" )
		
	funx <- .rcpp.language$runit_lang_variadic_2
	checkEquals( funx(), call("rnorm", 10L, mean = 0.0, 2.0 ), 
		msg = "variadic templates (with names)" )
}

# same as about but without variadic templates
test.Language.push.back <- function(){
	funx <- .rcpp.language$runit_lang_push_back
	checkEquals( funx(), 
		call("rnorm", 10L, mean = 0.0, 2.0 ), 
		msg = "Language::push_back" )
}

test.Language.square <- function(){
	funx <- .rcpp.language$runit_lang_square_rv
	checkEquals( funx(), 10.0, msg = "Language::operator[] used as rvalue" )

	funx <- .rcpp.language$runit_lang_square_lv
	checkEquals( funx(), call("rnorm", "foobar", 20.0, 20.0) , msg = "Pairlist::operator[] used as lvalue" )
}

test.Language.function <- function(){
	funx <- .rcpp.language$runit_lang_fun
	checkEquals( funx(sort, sample(1:10)), 1:10, msg = "Language( Function ) " )
}

test.Language.inputoperator <- function(){
	funx <- .rcpp.language$runit_lang_inputop
	checkEquals( funx(), call("rnorm", 10L, sd = 10L ) , msg = "Language<<" )
}

test.Language.unary.call <- function(){
	funx <- .rcpp.language$runit_lang_unarycall
	checkEquals( 
		funx( 1:10 ), 
		lapply( 1:10, function(n) seq(from=n, to = 0 ) ), 
		msg = "c++ lapply using calls" )
	
}

test.Language.unary.call.index <- function(){
	funx <- .rcpp.language$runit_lang_unarycallindex
	checkEquals( 
		funx( 1:10 ), 
		lapply( 1:10, function(n) seq(from=10, to = n ) ), 
		msg = "c++ lapply using calls" )
	
}

test.Language.binary.call <- function(){
	funx <- .rcpp.language$runit_lang_binarycall
	checkEquals( 
		funx( 1:10, 11:20 ), 
		lapply( 1:10, function(n) seq(n, n+10) ), 
		msg = "c++ lapply using calls" )
	
}

test.Language.fixed.call <- function(){
	funx <- .rcpp.language$runit_lang_fixedcall
	set.seed(123)
	res <- funx()
	set.seed(123)
	exp <- lapply( 1:10, function(n) rnorm(10) )
	checkEquals( res, exp, msg = "std::generate" )
}

test.Language.in.env <- function(){
	funx <- .rcpp.language$runit_lang_inenv
	e <- new.env()
	e[["y"]] <- 1:10
	checkEquals( funx(e), sum(1:10), msg = "Language::eval( SEXP )" )
}

test.Pairlist <- function(){
	funx <- .rcpp.language$runit_pairlist
	checkEquals( funx( pairlist("rnorm") ), pairlist("rnorm" ), msg = "Pairlist( LISTSXP )" )
	checkEquals( funx( call("rnorm") ), pairlist(as.name("rnorm")), msg = "Pairlist( LANGSXP )" )
	checkEquals( funx(1:10), as.pairlist(1:10) , msg = "Pairlist( INTSXP) " )
	checkEquals( funx(TRUE), as.pairlist( TRUE) , msg = "Pairlist( LGLSXP )" )
	checkEquals( funx(1.3), as.pairlist(1.3), msg = "Pairlist( REALSXP) " )
	checkEquals( funx(as.raw(1) ), as.pairlist(as.raw(1)), msg = "Pairlist( RAWSXP)" )
	
	checkException( funx(funx), msg = "Pairlist not compatible with function" )
	checkException( funx(new.env()), msg = "Pairlist not compatible with environment" )
	
}

test.Pairlist.variadic <- function(){
	funx <- .rcpp.language$runit_pl_variadic_1
	checkEquals( funx(), pairlist("rnorm", 10L, 0.0, 2.0 ), 
		msg = "variadic templates" )
		
	funx <- .rcpp.language$runit_pl_variadic_2
	checkEquals( funx(), pairlist("rnorm", 10L, mean = 0.0, 2.0 ), 
		msg = "variadic templates (with names)" )
}

test.Pairlist.push.front <- function(){
	funx <- .rcpp.language$runit_pl_push_front
	checkEquals( funx(), 
		pairlist( foobar = 10, "foo", 10.0, 1L), 
		msg = "Pairlist::push_front" )
}

test.Pairlist.push.back <- function(){
	funx <- .rcpp.language$runit_pl_push_back
	checkEquals( funx(), 
		pairlist( 1L, 10.0, "foo", foobar = 10), 
		msg = "Pairlist::push_back" )
}

test.Pairlist.insert <- function(){
	funx <- .rcpp.language$runit_pl_insert
	checkEquals( funx(), 
		pairlist( 30.0, 1L, bla = "bla", 10.0, 20.0, "foobar" ), 
		msg = "Pairlist::replace" )
}

test.Pairlist.replace <- function(){
	funx <- .rcpp.language$runit_pl_replace
	checkEquals( funx(),
		pairlist( first = 1, 20.0 , FALSE), msg = "Pairlist::replace" )	
}

test.Pairlist.size <- function(){
	funx <- .rcpp.language$runit_pl_size
	checkEquals( funx(), 3L, msg = "Pairlist::size()" )
}

test.Pairlist.remove <- function(){
	funx <- .rcpp.language$runit_pl_remove_1
	checkEquals( funx(), pairlist(10.0, 20.0), msg = "Pairlist::remove(0)" )
	
	funx <- .rcpp.language$runit_pl_remove_2
	checkEquals( funx(), pairlist(1L, 10.0), msg = "Pairlist::remove(0)" )
	
	funx <- .rcpp.language$runit_pl_remove_3
	checkEquals( funx(), pairlist(1L, 20.0), msg = "Pairlist::remove(0)" )
	
}

test.Pairlist.square <- function(){
	funx <- .rcpp.language$runit_pl_square_1
	checkEquals( funx(), 10.0, msg = "Pairlist::operator[] used as rvalue" )

	funx <- .rcpp.language$runit_pl_square_2
	checkEquals( funx(), pairlist(1L, "foobar", 1L) , msg = "Pairlist::operator[] used as lvalue" )
}

