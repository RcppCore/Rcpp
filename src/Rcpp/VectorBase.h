// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// VectorBase.h: Rcpp R/C++ interface class library -- base class for all vectors
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

#ifndef Rcpp_VectorBase_h
#define Rcpp_VectorBase_h

#include <RcppCommon.h>
#include <Rcpp/exceptions.h>
#include <Rcpp/RObject.h>
#include <Rcpp/r_cast.h>
#include <Rcpp/Dimension.h>
#include <Rcpp/MatrixRow.h>
#include <Rcpp/MatrixColumn.h>

namespace Rcpp{ 

namespace traits{
	template <int RTYPE>
	struct r_vector_iterator {
		typedef typename storage_type<RTYPE>::type* iterator ;
	} ;
	template<> struct r_vector_iterator<VECSXP> ;
	template<> struct r_vector_iterator<EXPRSXP> ;
	template<> struct r_vector_iterator<STRSXP> ;
} // traits 

template <typename VECTOR>
class VectorBase : public RObject {     
public:

	const static int r_type = VECTOR::r_type ;
	typedef MatrixRow<VECTOR> Row ;
	typedef MatrixColumn<VECTOR> Column ;
	
    VectorBase() : RObject(){} ;
    virtual ~VectorBase(){};
    
    VectorBase( SEXP x ) : RObject(){
    	setSEXP( r_cast<r_type>( x ) ) ;
    }
    
    VectorBase( const size_t& size ) : RObject(){
    	setSEXP( Rf_allocVector( r_type, size) ) ;
		init() ;
    }
    
    VectorBase( const Dimension& dims) : RObject(){
    	setSEXP( Rf_allocVector( r_type, dims.prod() ) ) ;
		init() ;
		if( dims.size() > 1 ){
			attr( "dim" ) = dims;
		}
    }
    
    /**
     * the length of the vector, uses Rf_length
     */
    inline R_len_t length() const { return ::Rf_length( m_sexp ) ; }
    
    /**
     * alias of length
     */
    inline R_len_t size() const { return ::Rf_length( m_sexp ) ; }
    
    inline int ncol(){
    	return dims()[1]; 
    }
    
    inline int nrow(){
    	return dims()[0]; 
    }
	
    /**
     * offset based on the dimensions of this vector
     */
    size_t offset(const size_t& i, const size_t& j) const throw(not_a_matrix,index_out_of_bounds){
    	if( !Rf_isMatrix(m_sexp) ) throw not_a_matrix() ;
	/* we need to extract the dimensions */
	int *dim = INTEGER( Rf_getAttrib( m_sexp, R_DimSymbol ) ) ;
	size_t nrow = static_cast<size_t>(dim[0]) ;
	size_t ncol = static_cast<size_t>(dim[1]) ;
	if( i >= nrow || j >= ncol ) throw index_out_of_bounds() ;
	return i + nrow*j ;
    }
    
    /**
     * one dimensional offset doing bounds checking to ensure
     * it is valid
     */
    size_t offset(const size_t& i) const throw(index_out_of_bounds){
	if( static_cast<R_len_t>(i) >= Rf_length(m_sexp) ) throw index_out_of_bounds() ;
	return i ;
    }
    
    R_len_t offset(const std::string& name) const throw(index_out_of_bounds){
    	SEXP names = RCPP_GET_NAMES( m_sexp ) ;
    	if( names == R_NilValue ) throw index_out_of_bounds(); 
    	R_len_t n=size() ;
    	for( R_len_t i=0; i<n; ++i){
    		if( ! name.compare( CHAR(STRING_ELT(names, i)) ) ){
    			return i ;
    		}
    	}
    	throw index_out_of_bounds() ;
    	return -1 ; /* -Wall */
    }
    
    /* TODO: 3 dimensions, ... n dimensions through variadic templates */
    
    class NamesProxy {
	public:
		NamesProxy( const VectorBase& v) : parent(v){} ;
	
		/* lvalue uses */
		NamesProxy& operator=(const NamesProxy& rhs) {
			set( rhs.get() ) ;
			return *this ;
    		}
	
		template <typename T>
		NamesProxy& operator=(const T& rhs){
			set( wrap(rhs) ) ;
			return *this ;
		}
	
		template <typename T> operator T() const {
			return Rcpp::as<T>(get()) ;
		} ;
		
	private:
		const VectorBase& parent; 
		
		SEXP get() const {
			return RCPP_GET_NAMES(parent) ;
		}
		
		void set(SEXP x) const {
			SEXP new_vec = PROTECT( internal::try_catch( 
			Rf_lcons( Rf_install("names<-"), 
					Rf_cons( parent, Rf_cons( x , R_NilValue) )))) ;
			/* names<- makes a new vector, so we have to change 
			   the SEXP of the parent of this proxy, it might be 
			   worth to work directly with the names attribute instead
			   of using the names<- R function, but then we need to 
			   take care of coercion, recycling, etc ... we cannot just 
			   brutally assign the names attribute */
			const_cast<VectorBase&>(parent).setSEXP( new_vec ) ;
			UNPROTECT(1) ; /* new_vec */
    		}
    		
	} ;
    	
	NamesProxy names() const {
		return NamesProxy(*this) ;
	}
    
	inline Row row( int i ){ return Row( static_cast<VECTOR&>(*this), i ) ; }
	inline Column column( int i ){ return Column( static_cast<VECTOR&>(*this), i ) ; }
	
private:
		
	inline int* dims(){
		if( !::Rf_isMatrix(m_sexp) ) throw not_a_matrix() ;
		return INTEGER( ::Rf_getAttrib( m_sexp, ::Rf_install( "dim") ) ) ;
	}
	
	void init(){
		internal::r_init_vector<r_type>(m_sexp) ;
	}
	
} ;

} // namespace

#endif
