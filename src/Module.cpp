// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Module.cpp: Rcpp R/C++ interface class library -- Rcpp modules
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>

#define MAX_ARGS 65

extern "C" SEXP Module__invoke( SEXP args){
	SEXP p = CDR(args) ;
	Rcpp::XPtr<Rcpp::Module> module( CAR(p) ) ; p = CDR(p) ;
	std::string fun = Rcpp::as<std::string>( CAR(p) ) ; p = CDR(p) ;
	
	SEXP cargs[MAX_ARGS] ;
    int nargs = 0 ;
   	for(; nargs<MAX_ARGS; nargs++){
   		if( p == R_NilValue ) break ;
   		cargs[nargs] = CAR(p) ;
   		p = CDR(p) ;
   	}
   	return module->invoke( fun, cargs, nargs ) ;
}

extern "C" SEXP Module__funtions_arity( SEXP mod_xp ){
	Rcpp::XPtr<Rcpp::Module> module(mod_xp) ;
	return module->	functions_arity() ;
}

extern "C" SEXP Module__name( SEXP mod_xp ){
	Rcpp::XPtr<Rcpp::Module> module(mod_xp) ;
	return Rcpp::wrap( module->name );
}

namespace Rcpp{
	Rcpp::Module* current_scope = 0 ;
	                                   
	Rcpp::IntegerVector Module::functions_arity(){
		int n = functions.size() ;
		Rcpp::IntegerVector x( n ) ;
		Rcpp::CharacterVector names( n );
		MAP::iterator it = functions.begin() ;
		for( int i=0; i<n; i++, ++it){
			x[i] = (it->second)->nargs() ;
			names[i] = it->first ;
		}
		x.names() = names ;
		return x ;
	}
	
	
	CppFunction0<void>::CppFunction0( void (*fun)(void) ) : 
		CppFunction(), ptr_fun(fun){}
	
	SEXP CppFunction0<void>::operator()(SEXP* args) throw(std::exception) {
		ptr_fun() ;
		return R_NilValue ;
	}
		
	
	
}

