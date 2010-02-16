// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Language.cpp: Rcpp R/C++ interface class library -- Language objects ( calls )
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

#include <Rcpp/Language.h>

namespace Rcpp {
	
	Language::Language() : DottedPair() {};
	
	Language::Language( SEXP x ) throw(not_compatible) : DottedPair(){
		setSEXP( r_cast<LANGSXP>(x) ) ;
	};
	
	Language::Language( const Language& other): DottedPair(){
		setSEXP( other.asSexp() ) ;
	}
	
	Language& Language::operator=(const Language& other){
		setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	Language::Language( const std::string& symbol ): DottedPair() {
		setSEXP( Rf_lcons( Symbol(symbol), R_NilValue ) );
	}
	
	Language::Language( const Symbol& symbol ): DottedPair() {
		setSEXP( Rf_lcons( symbol, R_NilValue ) ) ;
	}
	
	Language::Language( const Function& function): DottedPair() {
		setSEXP( Rf_lcons( function, R_NilValue ) ) ;		
	}
	
	Language::~Language(){}

	void Language::setSymbol( const std::string& symbol){
		setSymbol( Symbol( symbol ) ) ;
	}
	
	void Language::setSymbol( const Symbol& symbol){
		SETCAR( m_sexp, symbol ) ;
		SET_TAG(m_sexp, R_NilValue);/* probably not necessary */
	}
	
	void Language::setFunction( const Function& function){
		SETCAR( m_sexp, function );
		SET_TAG(m_sexp, R_NilValue); /* probably not necessary */
	}
	
	void Language::update(){ 
		SET_TYPEOF( m_sexp, LANGSXP ) ;
		SET_TAG( m_sexp, R_NilValue ) ;
	}
	
	SEXP Language::eval(){
		return eval( R_GlobalEnv ) ;
	}
	
	SEXP Language::eval( SEXP env ){
		return internal::try_catch( m_sexp, env );
	}
	
} // namespace Rcpp
