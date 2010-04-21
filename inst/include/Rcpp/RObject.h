// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RObject.h: Rcpp R/C++ interface class library -- general R object wrapper
//
// Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_RObject_h
#define Rcpp_RObject_h

#include <RcppCommon.h>

namespace Rcpp{ 

class RObject {
public:

	
	/**
   	 * Exception thrown when attempting to convert a SEXP
   	 */
   	class not_s4: public std::exception{
   		public:
   			not_s4() throw(){};
   			virtual ~not_s4() throw(){} ;
   			virtual const char* what() const throw() ; 
   	} ;
   	
   	/**
   	 * Exception thrown when attempting to convert a SEXP
   	 */
   	class no_such_slot : public std::exception{
   		public:
   			no_such_slot() throw(){};
   			virtual ~no_such_slot() throw(){} ;
   			virtual const char* what() const throw() ;
   	} ;
   	
    /**
     * default constructor. uses R_NilValue
     */ 
    RObject() : m_sexp(R_NilValue) {} ;	

    /**
     * wraps a SEXP. The SEXP is automatically protected from garbage 
     * collection by this object and the protection vanishes when this 
     * object is destroyed
     */
    RObject(SEXP x) : m_sexp(R_NilValue) { setSEXP(x) ; };

    /**
     * Copy constructor. set this SEXP to the SEXP of the copied object
     */
    RObject( const RObject& other ) ;

    /**
     * Assignment operator. set this SEXP to the SEXP of the copied object
     */
    RObject& operator=( const RObject& other ) ;

    /** 
     * Assignement operator. Set this SEXP to the given SEXP
     */ 
    RObject& operator=( SEXP other ) ;

    /**
     * Removes the protection. The enclosed SEXP becomes subject
     * to garbage collection, if not otherwise protected
     */
    virtual ~RObject() ;

    /**
     * implicit conversion to SEXP.
     */
    inline operator SEXP() const { return m_sexp ; }

    /* attributes */

    /**
     * extracts the names of the attributes of the wrapped SEXP
     */
    std::vector<std::string> attributeNames() const ;

    /**
     * Identifies if the SEXP has the given attribute
     */
    bool hasAttribute( const std::string& attr) const ; 

    /**
     * Proxy for an object's attribute. Instances of this class
     * are created by the attr member function of RObject.
     *
     * When the proxy is used on the lhs of an assignment it 
     * forwards the object it is assigned to to the attribute, 
     * outsourcing to wrap the job of creating the SEXP from the 
     * input type
     *
     * When the proxy is used on the rhs of the assignment, it retrieves
     * the current value of the attribute and outsources to as the job
     * of making an object of the appropriate type
     */
    class AttributeProxy {
	public:
		
		/** 
		 * @param v object of which we manipulate the attributes
		 * @param attr_name name of the attribute the proxy manipulates
		 */
		AttributeProxy( const RObject& v, const std::string& attr_name) ;

		/**
		 * lhs use. This assigns the target attribute by using the 
		 * current attribute referred by another proxy
		 */
		AttributeProxy& operator=(const AttributeProxy& rhs) ;
		
		/**
		 * lhs use. assigns the target attribute by wrapping 
		 * the rhs object
		 *
		 * @param rhs wrappable object
		 */
		template <typename T> AttributeProxy& operator=(const T& rhs){
			set( wrap(rhs) ) ;
			return *this ;
		}
		
		/**
		 * rhs use. Retrieves the current value for the target
		 * attribute and structure it as a T object using as
		 */
		template <typename T> operator T() const {
			return as<T>(get()) ;
		}
		
	private:
		const RObject& parent; 
		std::string attr_name ;
		
		SEXP get() const ;
		void set(SEXP x) const ;
	} ;
	
	/**
	 * Proxy for objects slots. 
	 */
	class SlotProxy {
	public:
		/**
		 * Creates a slot proxy. This throws an exception 
		 * if the parent object is not an S4 object or if the 
		 * class of parent object does not have the requested 
		 * slot
		 *
		 * @param v parent object of which we get/set a slot
		 * @param name slot name
		 */
		SlotProxy( const RObject& v, const std::string& name) ;

		/**
		 * lhs use. Assigns the target slot using the current 
		 * value of another slot proxy.
		 *
		 * @param rhs another slot proxy
		 */
		SlotProxy& operator=(const SlotProxy& rhs) ;
		
		/**
		 * lhs use. Assigns the slot by wrapping the rhs object
		 *
		 * @param rhs wrappable object
		 */
		template <typename T> SlotProxy& operator=(const T& rhs){
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
		const RObject& parent; 
		std::string slot_name ;
		
		SEXP get() const ;
		void set(SEXP x ) const;
	} ;
    	
	
    /**
     * extract or set the given attribute
     *
     * @param name name of the attribute to get/set
     *
     * @return this returns a proxy to the given attribute. Depending
     * on whether the proxy is used as a lhs or a rhs the attribute is
     * either set (if the proxy is used on the lhs) or extracted 
     * (if the proxy is used on the rhs). 
     *
     * RObject y = x.attr("foo") ; // rhs : get the attribute
     * x.attr( "bar" ) = 10 ;      // lhs : set the attribute. 
     *
     * wrap is called on the right side of the assignment it can be anything
     * wrap can handle. 
     */
    AttributeProxy attr( const std::string& name) const  ;
    
    /**
     * is this object NULL
     */
    inline bool isNULL() const{ return Rf_isNull(m_sexp) ; }

    /**
     * The SEXP typeof, calls TYPEOF on the underlying SEXP
     */
    inline int sexp_type() const { return TYPEOF(m_sexp) ; }

    /** 
     * explicit conversion to SEXP
     */
    inline SEXP asSexp() const { return m_sexp ; }

    /**
     * Tests if the SEXP has the object bit set
     */
    inline bool isObject() const { return ::Rf_isObject(m_sexp) ;}

    /**
     * Tests if the SEXP is an S4 object
     */
    inline bool isS4() const { return ::Rf_isS4(m_sexp) ; }

    /**
     * Indicates if this S4 object has the given slot
     *
     * @throw not_s4 if the object is not an S4 object
     */
    bool hasSlot(const std::string& name) const throw(not_s4) ;

    /**
     * Retrieves the given slot
     *
     * @throw not_s4 if this is not an S4 object
     */
    SlotProxy slot(const std::string& name) const throw(not_s4) ;
    
protected:

    /**
     * sets the SEXP wrapped by this object
     *
     * @param x new SEXP to attach to this object
     */
    void setSEXP(SEXP x) ;

    /**
     * The SEXP this is wrapping. This has to be considered read only.
     * to change it, use setSEXP
     */
    SEXP m_sexp ;
    
private:

    void preserve(){ if( m_sexp != R_NilValue ) R_PreserveObject(m_sexp) ; } 
    void release() { if( m_sexp != R_NilValue ) R_ReleaseObject(m_sexp) ; } 
    virtual void update() {} ;
    
};

class exception : public std::exception {
	public:
		exception(const char* message_, const char* file, int line ) ;
		virtual ~exception() throw() ;
		virtual const char* what() const throw() { return message.c_str() ; };
	private:
		std::string message ;
} ;

} // namespace Rcpp

#endif
