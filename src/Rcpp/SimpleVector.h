// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// SimpleVector.h: Rcpp R/C++ interface class library -- simple vectors (INTSXP,REALSXP,RAWSXP,LGLSXP,CPLXSXP)
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

#ifndef Rcpp_SimpleVector_h
#define Rcpp_SimpleVector_h

#include <RcppCommon.h>

#include <Rcpp/VectorBase.h>
#include <Rcpp/r_cast.h>
#include <Rcpp/Dimension.h>

namespace Rcpp{

template <int RTYPE>
class SimpleVector : public VectorBase {
public:
	
	typedef typename traits::storage_type<RTYPE>::type value_type ;
	typedef value_type* iterator ;
	typedef value_type& reference ;
	
	SimpleVector() : VectorBase(), start(0){}
	
	SimpleVector(SEXP x) throw(RObject::not_compatible) : VectorBase(), start(0){
		SEXP y = r_cast<RTYPE>( x ) ;
		setSEXP( y );
	}
	
	SimpleVector( const size_t& size){
		setSEXP( Rf_allocVector( RTYPE, size) ) ;
		init() ;
	}
	
	SimpleVector( const Dimension& dims){
		setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		init() ;
		if( dims.size() > 1 ){
			attr( "dim" ) = dims ;
		}
	}
	
	SimpleVector( const SimpleVector& other) : VectorBase() {
		setSEXP( other.asSexp() ) ;
	}
	
	SimpleVector& operator=(const SimpleVector& other){
		setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	template <typename InputIterator>
	SimpleVector( InputIterator first, InputIterator last) : VectorBase(), start(){
		assign( first, last ) ;
	}
	
#ifdef HAS_INIT_LISTS
	SimpleVector( std::initializer_list<value_type> list ) : VectorBase(), start(0){
		assign( list.begin() , list.end() ) ;
	}
#endif

	inline reference operator[]( const int& i ){ return start[i] ; }
	inline reference operator[]( const std::string& name) {
		return start[ offset(name) ];
	}
	inline iterator begin() const{ return start ; }
	inline iterator end() const{ return start+Rf_length(m_sexp); }
	
	inline reference operator()( const size_t& i) throw(RObject::index_out_of_bounds){
		return start[ offset(i) ] ;
	}
	inline reference operator()( const std::string& name) {
		return start[ offset(name) ];
	}
	inline reference operator()( const size_t& i, const size_t& j) throw(VectorBase::not_a_matrix,RObject::index_out_of_bounds){
		return start[ offset(i,j) ] ;
	}
	
	template <typename InputIterator>
	void assign( InputIterator first, InputIterator last){
		/* FIXME: we can do better than this r_cast to avoid 
		          allocating an unnecessary temporary object
		 */
		SEXP x = PROTECT( r_cast<RTYPE>( wrap( first, last ) ) );
		setSEXP( x) ;
		UNPROTECT(1) ;
	}

private:
	value_type* start ;
	
	virtual void update(){ 
		start = internal::r_vector_start<RTYPE,value_type>(m_sexp) ;
	}
	
	void init(){
		internal::r_init_vector<RTYPE>(m_sexp) ;
	}
	
} ;

typedef SimpleVector<CPLXSXP> ComplexVector ;
typedef SimpleVector<INTSXP> IntegerVector ;
typedef SimpleVector<LGLSXP> LogicalVector ;
typedef SimpleVector<REALSXP> NumericVector ;
typedef SimpleVector<RAWSXP> RawVector ;

}// namespace Rcpp

#endif
