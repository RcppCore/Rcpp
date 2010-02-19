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
#include <Rcpp/RObject.h>
#include <Rcpp/r_cast.h>

namespace Rcpp{ 

class VectorBase : public RObject {     
public:
	class not_a_matrix : public std::exception{
	public:
		not_a_matrix(){} ;
		virtual ~not_a_matrix() throw() {} ;
		virtual const char* what() const throw() { return "not a matrix" ; };
	} ;
  
    VectorBase() ;
    virtual ~VectorBase() ;

    /**
     * the length of the vector, uses Rf_length
     */
    inline R_len_t length() const { return ::Rf_length( m_sexp ) ; }

    /**
     * alias of length
     */
    inline R_len_t size() const { return ::Rf_length( m_sexp ) ; }

    /**
     * offset based on the dimensions of this vector
     */
    size_t offset(const size_t& i, const size_t& j) const throw(not_a_matrix,RObject::index_out_of_bounds) ;
    
    /**
     * one dimensional offset doing bounds checking to ensure
     * it is valid
     */
    size_t offset(const size_t& i) const throw(RObject::index_out_of_bounds);
    
    R_len_t offset(const std::string& name) const throw(RObject::index_out_of_bounds) ;
    
    /* TODO: 3 dimensions, ... n dimensions through variadic templates */
    
    class NamesProxy {
	public:
		NamesProxy( const VectorBase& v) ;
	
		/* lvalue uses */
		NamesProxy& operator=(const NamesProxy& rhs) ;
	
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
		
		SEXP get() const ;
		void set(SEXP x) const;
	} ;
    	
    NamesProxy names() const ;
} ;

} // namespace

#endif
