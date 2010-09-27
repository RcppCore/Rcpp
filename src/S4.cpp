// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// S4.cpp: Rcpp R/C++ interface class library -- S4 objects
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

#include <Rcpp/S4.h>
#include <Rcpp/exceptions.h>
#include <Rcpp/Vector.h>

namespace Rcpp {

	S4::S4() : RObject(){}
	
	S4::S4(SEXP x) throw(not_s4) : RObject(){
		set( x) ;
	}
	
	S4::S4( const S4& other) : RObject(){
		setSEXP( other.asSexp() ) ;	
	}
	
	S4::S4( const RObject::SlotProxy& proxy ) throw(not_s4) : RObject() {
		set( proxy ) ;
	}
	S4::S4( const RObject::AttributeProxy& proxy ) throw(not_s4) : RObject() {
		set( proxy ) ;
	}
	
	S4& S4::operator=( const S4& other){
		setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	S4& S4::operator=( SEXP other ) throw(not_s4) {
		set( other ) ;
		return *this ;
	}
	
	S4::S4( const std::string& klass ) throw(S4_creation_error) {
		SEXP oo = PROTECT( R_do_new_object(R_do_MAKE_CLASS(klass.c_str())) ) ;
  		if (!Rf_inherits(oo, klass.c_str())) {
  			UNPROTECT( 1) ;
  			throw S4_creation_error( klass ) ;
  		}
  		setSEXP( oo ) ;
  		UNPROTECT( 1) ; /* oo */
	}
	
	bool S4::is( const std::string& clazz ) {
		CharacterVector cl = attr("class");
		
		// simple test for exact match
		if( ! clazz.compare( cl[0] ) ) return true ;
		
		try{
			// 
			// mimic the R call: 
			// names( slot( getClassDef( cl ), "contains" ) )
			// 
			CharacterVector res = internal::try_catch( 
				Rf_lang2(
					R_NamesSymbol,
					Rf_lang3( 
						Rf_install( "slot" ),
						Rf_lang2( Rf_install( "getClassDef"), cl ), 
						Rf_mkString( "contains" )
					) 
				)
			) ;
			return any( res.begin(), res.end(), clazz.c_str() ) ;
		} catch( ... ){
			// we catch eval_error and also not_compatible when 
			// contains is NULL
		}
		return false ;
		
	}
	
	void S4::set( SEXP x) throw(not_s4) {
		if( ! ::Rf_isS4(x) ){
			throw not_s4() ;
		} else{
			setSEXP( x) ;
		}
	}
	
} // namespace Rcpp
