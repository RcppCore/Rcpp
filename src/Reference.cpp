// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
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

#include <Rcpp/Reference.h>
#include <Rcpp/exceptions.h>
#include <Rcpp/Vector.h>

namespace Rcpp {

	Reference::Reference() : S4(){}
	
	Reference::Reference(SEXP x) throw(not_reference) : S4(){
		set( x) ;
	}
	
	Reference::Reference( const Reference& other) : S4(){
		setSEXP( other.asSexp() ) ;	
	}
	
	Reference::Reference( const RObject::SlotProxy& proxy ) throw(not_reference) : S4() {
		set( proxy ) ;
	}
	Reference::Reference( const RObject::AttributeProxy& proxy ) throw(not_reference) : S4() {
		set( proxy ) ;
	}
	
	Reference& Reference::operator=( const Reference& other){
		setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	Reference& Reference::operator=( SEXP other ) throw(not_reference) {
		set( other ) ;
		return *this ;
	}
	
	Reference::Reference( const std::string& klass ) throw(S4_creation_error,reference_creation_error) : S4(klass){
		// TODO: check that klass is indeed a reference class
	}
	
	void Reference::set( SEXP x) throw(not_reference) {
		// TODO: check that x is of a reference class
	    if( ! ::Rf_isS4(x) ){
			throw not_reference() ;
		} else{
			setSEXP( x) ;
		}
	}
	
	Reference::FieldProxy::FieldProxy( const Reference& v, const std::string& name) throw(no_such_field) : 
	    parent(v), field_name(name) {}

    Reference::FieldProxy& Reference::FieldProxy::operator=(const FieldProxy& rhs){
    	set( rhs.get() ) ;
    	return *this ;
    }
    
    
    SEXP Reference::FieldProxy::get() const {
    	// TODO: get the field  
    	
    	SEXP call = ::Rf_lcons( 
    	    R_DollarSymbol, 
    	    Rf_cons( const_cast<Reference&>(parent).asSexp() , 
    	        Rf_cons( 
    	            Rf_mkString( field_name.c_str() ),
    	            R_NilValue 
    	            ) ) ) ;
    	
    	return Rcpp::internal::try_catch( call ) ;
    }
    
    void Reference::FieldProxy::set( SEXP x) const {
    	// TODO: set the field
        SEXP call = ::Rf_lcons( 
    	    Rf_install( "$<-") , 
    	    Rf_cons( const_cast<Reference&>(parent).asSexp() , 
    	        Rf_cons( 
    	            Rf_mkString( field_name.c_str() ),
    	            Rf_cons( 
    	               x,
    	               R_NilValue 
    	            ) ) ) ) ;
    	const_cast<Reference&>(parent).setSEXP( Rf_eval( call, R_GlobalEnv ) );	            
    }

    Reference::FieldProxy Reference::field( const std::string& name) const {
        return FieldProxy( *this, name );
    }
	
} // namespace Rcpp
