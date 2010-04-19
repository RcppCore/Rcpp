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

NAMESPACE <- environment()
HAVEINLINE <- FALSE
cfunction <- function(...) stop( "inline not available" )
compileCode <- function(...) stop( "inline not available" )

init.inline <- function(){
	hack_compileCode()

	unlockBinding( "HAVEINLINE", NAMESPACE )
	unlockBinding( "cfunction", NAMESPACE )
	assignInNamespace( "HAVEINLINE", TRUE, NAMESPACE )
	assignInNamespace( "cfunction" , get( "cfunction", asNamespace( "inline" )), NAMESPACE )
	lockBinding( "HAVEINLINE", NAMESPACE )
	lockBinding( "cfunction", NAMESPACE )
}

hack_compileCode <- function(){
	inline <- asNamespace( "inline" )
	
	unlockBinding( "compileCode", inline )
	compileCode <- get("compileCode", 	inline )
	exprs <- append( 
		list( as.name("{"), parse(text="code <- Rcpp:::compileCode_hook(f, code)")[[1]] ) , 
		as.list( body( compileCode )[-1] )
		)
	body( compileCode ) <- as.call( exprs )
	assignInNamespace( "compileCode", compileCode, inline )
	unlockBinding( "compileCode", inline )
}

compileCode_hook <- function( f, code){
	# we only do something if we are called from cppfunction
	calls <- sys.calls()
	functions <- sapply( calls, function(.){ if( is.name(.[[1]]) ) as.character( .[[1]]) else "" } )
	if( "cppfunction" %in% functions ){
sprintf( 
'%s
#if defined(WIN32)
extern "C" void R_init_%s( DllInfo* info ){
	std::set_terminate( forward_uncaught_exceptions_to_r ) ;
}
#endif
', code, f )
	} else {
		code
	}
}

cppfunction <- function (sig = character(), body = character(), includes = character(), 
    otherdefs = character(), verbose = FALSE, 
    cppargs = character(), cxxargs = character(), libargs = character(), 
    namespace = TRUE, forward.exceptions = TRUE ){
	
    ok <- HAVEINLINE                                                                                
	if( !ok){
		if( "package:inline" %in% search() ){
			ok <- TRUE
		} else{
			ok <- tryCatch( {
				require( "inline", character.only = TRUE, quietly = TRUE )
				TRUE 
			} , error = function(e) FALSE )
		}
		if( ! ok ){
			stop( "package inline is not available" )	
		}
		init.inline()
	}
	if( isTRUE( namespace ) ){
		includes <- c( includes, "using namespace Rcpp;" )
	}
	if( isTRUE( forward.exceptions ) ){
		body <- sprintf( "try{ %s } catch( std::exception& __ex__){ forward_exception_to_r( __ex__ ) ; } ", body )
	}
	fx <- cfunction( sig = sig, body = body, includes = includes, 
		otherdefs = otherdefs, language = "C++", convention = ".Call", 
		Rcpp = TRUE, cppargs = cppargs, cxxargs = cxxargs, libargs = libargs, 
		verbose = verbose )
	fx
}
