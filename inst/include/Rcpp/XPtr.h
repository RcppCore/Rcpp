// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// XPtr.h: Rcpp R/C++ interface class library -- smart external pointers
//
// Copyright (C) 2009 - 2013	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_XPtr_h
#define Rcpp_XPtr_h

#include <RcppCommon.h>

namespace Rcpp{
    
template <typename T>
void standard_delete_finalizer(T* obj){
    delete obj ;   
}

template <typename T, void Finalizer(T*) >
void finalizer_wrapper(SEXP p){
    if( TYPEOF(p) == EXTPTRSXP ){
	T* ptr = (T*) R_ExternalPtrAddr(p) ;
	RCPP_DEBUG_3( "finalizer_wrapper<%s>(SEXP p = <%p>). ptr = %p", DEMANGLE(T), p, ptr  )
	Finalizer(ptr) ;
    }
}

template <typename T, void Finalizer(T*) = standard_delete_finalizer<T> >
class XPtr : public RObject {
public:
		
    /** 
     * constructs a XPtr wrapping the external pointer (EXTPTRSXP SEXP)
     *
     * @param xp external pointer to wrap
     */
    explicit XPtr(SEXP m_sexp, SEXP tag = R_NilValue, SEXP prot = R_NilValue) : RObject(m_sexp){
        if( TYPEOF(m_sexp) != EXTPTRSXP )
            throw ::Rcpp::not_compatible( "expecting an external pointer" ) ;
        R_SetExternalPtrTag( m_sexp, tag ) ;
        R_SetExternalPtrProtected( m_sexp, prot ) ;
    } ;
		
    /**
     * creates a new external pointer wrapping the dumb pointer p. 
     * 
     * @param p dumb pointer to some object
     * @param set_delete_finalizer if set to true, a finalizer will 
     *        be registered for the external pointer. The finalizer
     *        is called when the xp is garbage collected. The finalizer 
     *        is merely a call to the delete operator or the pointer
     *        so you need to make sure the pointer can be "delete" d
     *        this way (has to be a C++ object)
     */
    explicit XPtr(T* p, bool set_delete_finalizer = true, SEXP tag = R_NilValue, SEXP prot = R_NilValue){
        RCPP_DEBUG_2( "XPtr(T* p = <%p>, bool set_delete_finalizer = %s, SEXP tag = R_NilValue, SEXP prot = R_NilValue)", p, ( set_delete_finalizer ? "true" : "false" ) )
        SEXP x = PROTECT( R_MakeExternalPtr( (void*)p , tag, prot) ) ; 
        #if RCPP_DEBUG_LEVEL > 0
        Rf_PrintValue( x ) ;
        #endif
        setSEXP( x ) ;
        UNPROTECT(1); 
        if( set_delete_finalizer ){
            setDeleteFinalizer() ;
        }
    }

    XPtr( const XPtr& other ) : RObject( other.asSexp() ) {}
    
    XPtr& operator=(const XPtr& other){
    	    setSEXP( other.asSexp() ) ;
    	    return *this ;
    }
    
    /**
     * Returns a reference to the object wrapped. This allows this
     * object to look and feel like a dumb pointer to T
     */
     T& operator*() const {
         return *((T*)R_ExternalPtrAddr( m_sexp )) ;    
     }
  		
    /**
     * Returns the dumb pointer. This allows to call the -> operator 
     * on this as if it was the dumb pointer
     */
     T* operator->() const {
          return (T*)(R_ExternalPtrAddr(m_sexp));
     }
  		  		        
    void setDeleteFinalizer() {
        R_RegisterCFinalizerEx( m_sexp, finalizer_wrapper<T,Finalizer> , FALSE) ;     
    }
  	
    inline operator T*(){ return (T*)( R_ExternalPtrAddr(m_sexp)) ; }

    class TagProxy{
    public:
    	TagProxy( XPtr& xp_ ): xp(xp_){}
    	
    	template <typename U>
    	TagProxy& operator=( const U& u){
    		set( Rcpp::wrap(u) );
    		return *this ;
    	}
    	
    	template <typename U>
    	operator U(){
    		return Rcpp::as<U>( get() ) ;
    	}
    	
    	operator SEXP(){ return get(); }
    	
    	inline SEXP get(){
    		return R_ExternalPtrTag(xp.asSexp()) ;
    	}
    	
    	inline void set( SEXP x){
    		R_SetExternalPtrTag( xp.asSexp(), x ) ;
    	}
    	
    private:
    	XPtr& xp ;
    } ;

	TagProxy tag(){
		return TagProxy( *this ) ;
	}
    
    class ProtectedProxy{
    public:
    	ProtectedProxy( XPtr& xp_ ): xp(xp_){}
    	
    	template <typename U>
    	ProtectedProxy& operator=( const U& u){
    		set( Rcpp::wrap(u) );
    		return *this ;
    	}
    	
    	template <typename U>
    	operator U(){
    		return Rcpp::as<U>( get() ) ;
    	}

    	operator SEXP(){ return get() ; }
    	
    	inline SEXP get(){
    		return R_ExternalPtrProtected(xp.asSexp()) ;
    	}
    	
    	inline void set( SEXP x){
    		R_SetExternalPtrProtected( xp.asSexp(), x ) ;
    	}
    	
    private:
    	XPtr& xp ;
    } ;

	ProtectedProxy prot(){
		return ProtectedProxy( *this ) ;
	}
	
    
};

} // namespace Rcpp 

#endif
