// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// S4.h: Rcpp R/C++ interface class library -- S4 objects
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

#ifndef Rcpp_Reference_h
#define Rcpp_Reference_h                     

#include <Rcpp/S4.h>
#include <Rcpp/exceptions.h>

namespace Rcpp{ 

/**
 * S4 object (of a reference class)
 */
class Reference : public S4 {
public:
	Reference() ;
	
	/**
	 * checks that x is an S4 object of a reference class and wrap it.
	 *
	 * @param x must be an S4 object of some reference class
	 */
	Reference(SEXP x) throw(not_reference) ; 
	
	/**
	 * copy constructor
	 *
	 * @param other other S4 object
	 */
	Reference(const Reference& other) ;
	Reference(const RObject::SlotProxy& proxy ) throw(not_reference) ;
	Reference(const RObject::AttributeProxy& proxy ) throw(not_reference);
	
	Reference& operator=( const Reference& other);
	Reference& operator=( SEXP other ) throw(not_reference) ; 
	
	/**
	 * Creates an reference object of the requested class. 
	 *
	 * @param klass name of the target reference class
	 * @throw reference_creation_error if klass does not map to a known S4 class
	 */
	Reference( const std::string& klass ) throw(S4_creation_error,reference_creation_error) ;

	
	// TODO: perhaps I should move this to RObject (do the same as SlotProxy, etc ...)
	/**
	 * Proxy for objects slots. 
	 */
	class FieldProxy {
	public:
		/**
		 * Creates a field proxy. 
		 *
		 * @param v parent object of which we get/set a field
		 * @param name field name
		 */
		FieldProxy( const Reference& v, const std::string& name) throw(no_such_field) ;

		/**
		 * lhs use. Assigns the target slot using the current 
		 * value of another slot proxy.
		 *
		 * @param rhs another slot proxy
		 */
		FieldProxy& operator=(const FieldProxy& rhs) ;
		
		/**
		 * lhs use. Assigns the slot by wrapping the rhs object
		 *
		 * @param rhs wrappable object
		 */
		template <typename T> FieldProxy& operator=(const T& rhs){
			set( wrap(rhs) ) ;
			return *this ;
		}
		
		/**
		 * rhs use. Retrieves the current value of the slot
		 * and structures it as a T object. This only works 
		 * when as<T> makes sense
		 */ 
		template <typename T> operator T() const {
			return as<T>(get()) ;
		}
		
	private:
		const Reference& parent; 
		std::string field_name ;
		
		SEXP get() const ;
		void set(SEXP x ) const;
	} ;
    friend class FieldProxy ;	
		
	FieldProxy field( const std::string& name) const  ;
    
    
private:
	void set( SEXP x) throw(not_reference) ;	
} ;

} // namespace Rcpp

#endif
