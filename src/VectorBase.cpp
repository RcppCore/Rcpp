// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// VectorBase.h: Rcpp R/C++ interface class library -- base vector class
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

#include <RcppCommon.h>
#include <Rcpp/VectorBase.h>

namespace Rcpp{
	
	VectorBase::VectorBase() : RObject() {} ;
	VectorBase::~VectorBase(){}
	
	size_t VectorBase::offset( const size_t& i, const size_t& j) const throw(not_a_matrix,RObject::index_out_of_bounds) {
		if( !Rf_isMatrix(m_sexp) ) throw VectorBase::not_a_matrix() ;
		/* we need to extract the dimensions */
		int *dim = INTEGER( Rf_getAttrib( m_sexp, R_DimSymbol ) ) ;
		size_t nrow = static_cast<size_t>(dim[0]) ;
		size_t ncol = static_cast<size_t>(dim[1]) ;
		if( i >= nrow || j >= ncol ) throw RObject::index_out_of_bounds() ;
		return i + nrow*j ;
	}

	size_t VectorBase::offset(const size_t& i) const throw(RObject::index_out_of_bounds){
    	    if( static_cast<R_len_t>(i) >= Rf_length(m_sexp) ) throw RObject::index_out_of_bounds() ;
    	    return i ;
    	}
    	
    	R_len_t VectorBase::offset(const std::string& name) const throw(RObject::index_out_of_bounds){
    		SEXP names = RCPP_GET_NAMES( m_sexp ) ;
    		if( names == R_NilValue ) throw RObject::index_out_of_bounds(); 
    		R_len_t n=size() ;
    		for( R_len_t i=0; i<n; ++i){
    			if( ! name.compare( CHAR(STRING_ELT(names, i)) ) ){
    				return i ;
    			}
    		}
    		throw RObject::index_out_of_bounds() ;
    		return -1 ; /* -Wall */
    	}
    	

    	VectorBase::NamesProxy::NamesProxy( const VectorBase& v) : parent(v){} ;
    	VectorBase::NamesProxy& VectorBase::NamesProxy::operator=( const NamesProxy& rhs){
    		set( rhs.get() ) ;
    		return *this ;
    	}
    	
    	SEXP VectorBase::NamesProxy::get() const {
    		return RCPP_GET_NAMES(parent) ;
    	}
    	void VectorBase::NamesProxy::set(SEXP x) const {
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
    	
    	VectorBase::NamesProxy VectorBase::names() const{
    		return NamesProxy(*this) ;
    	}
    	
} // namespace )
