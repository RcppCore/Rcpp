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

.setUp <- function() {
	suppressMessages( require( stats ) )
    tests <- ".rcpp.Function"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list( 
        	"function_" = list( 
        		signature(x="ANY"), 'return Function(x) ;'
        	), 
        	"function_variadic" = list( 
        		signature(x="function", y = "ANY"), 
        		'
				Function sort(x) ;
				return sort( y, Named("decreasing", true) ) ;
				' 
        	), 
        	"function_env" = list( 
        		signature(x="function"), 
        		'
					Function fun(x) ;
					return fun.environment() ;
				'
        	), 
        	"function_unarycall" = list( 
        		signature(y = "list" ), 
        		'
				Function len( "length" ) ;
				List x(y) ;
				IntegerVector output( x.size() ) ;
				std::transform( 
					x.begin(), x.end(), 
					output.begin(),
					unary_call<IntegerVector,int>(len)
					) ;
				return output ;
				'
        	), 
        	"function_binarycall" = list( 
        		signature(x1 = "list", x2 = "integer" ), 
        		'
					Function pmin( "pmin" ) ;
					List list(x1) ;
					IntegerVector vec(x2) ;
					List output( list.size() ) ;
					std::transform( 
						list.begin(), list.end(),
						vec.begin(), 
						output.begin(),
						binary_call<IntegerVector,int,IntegerVector>(pmin)
						) ;
					return output ;
				'
        	)
        )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp", includes = "using namespace std;",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}


test.Function <- function(){
	funx <- .rcpp.Function$function_
    checkEquals( funx( rnorm ), rnorm, msg = "Function( CLOSXP )" )
	checkEquals( funx( is.function ), is.function, msg = "Pairlist( BUILTINSXP )" )
	
	checkException( funx(1:10), msg = "Function( INTSXP) " )
	checkException( funx(TRUE), msg = "Function( LGLSXP )" )
	checkException( funx(1.3), msg = "Function( REALSXP) " )
	checkException( funx(as.raw(1) ), msg = "Function( RAWSXP)" )
	checkException( funx(new.env()), msg = "Function not compatible with environment" )
	
}

test.Function.variadic <- function(){
	funx <- .rcpp.Function$function_variadic
    checkEquals( funx( sort, sample(1:20) ), 
		20:1, msg = "calling function" )
	checkException( funx(sort, sort), msg = "Function, R error -> exception" )
}

test.Function.env <- function(){
	funx <- .rcpp.Function$function_env
    checkEquals( funx(rnorm), asNamespace("stats" ), msg = "Function::environment" )
	checkException( funx(is.function), 
		msg = "Function::environment( builtin) : exception" )
	checkException( funx(`~`), 
		msg = "Function::environment( special) : exception" )
}

test.Function.unary.call <- function(){
	funx <- .rcpp.Function$function_unarycall
	checkEquals( 
		funx( lapply( 1:10, function(n) seq(from=n, to = 0 ) ) ), 
		2:11 , 
		msg = "unary_call(Fcuntion)" )
}

test.Function.binary.call <- function(){
	funx <- .rcpp.Function$function_binarycall
	data <- lapply( 1:10, function(n) seq(from=n, to = 0 ) )
	res <- funx( data , rep(5L,10) )
	expected <- lapply( data, pmin, 5 )
	checkEquals( res, expected, 
		msg = "binary_call(Function)" )
}

