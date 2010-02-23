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
	
	class Row {
	public:
		class RowIterator {
		public:
			typedef typename traits::storage_type<RTYPE>::type value_type ;
			typedef value_type& reference ;
			typedef value_type* pointer ;
			typedef int difference_type ;
			typedef std::random_access_iterator_tag iterator_category ;
			
			RowIterator( Row& row_, int index_ ) : row(row_), index(index_){}
			
			RowIterator& operator++(){ index++; }
			RowIterator& operator++(int) { index++; }
		
			RowIterator& operator--(){ index-- ; } 
			RowIterator& operator--(int){ index-- ;}
			                    
			RowIterator operator+(difference_type n) const { return iterator( row, index + n ) ; }
			RowIterator operator-(difference_type n) const { return iterator( row, index - n ) ; }
			
			RowIterator& operator+=(difference_type n) { index += n ;} 
			RowIterator& operator-=(difference_type n) { index -= n ;} 
                	
			reference operator*() {
				return row[index] ;
			}
			pointer operator->(){
				return &row[index] ;
			}
			
			bool operator==( const RowIterator& other) { return index == other.index ; } 
			bool operator!=( const RowIterator& other) { return index != other.index ; }
			bool operator<( const RowIterator& other ) { return index < other.index ;}
			bool operator>( const RowIterator& other ) { return index > other.index ;}
			bool operator<=( const RowIterator& other ) { return index <= other.index ; }
			bool operator>=( const RowIterator& other ) { return index >= other.index ; }
			
			difference_type operator-(const RowIterator& other) {
				return index - other.index ;
			}
			
		private:
			Row& row ;
			int index ;
		} ;
		
		typedef typename traits::storage_type<RTYPE>::type value_type ;
		
		Row( SimpleVector& object, int i ) : parent(object), index(i){
			if( ! ::Rf_isMatrix(parent) ) throw VectorBase::not_a_matrix() ;
		}
		
		value_type& operator[]( const int& i ){
			return parent[ index + i * parent.nrow() ] ;
		}
		
		inline RowIterator begin(){
			return RowIterator( *this, 0 ) ;
		}
		
		inline RowIterator end(){
			return RowIterator( *this, size() ) ;
		}
		
		inline int size(){
			return parent.ncol() ;
		}
		
	private:
		SimpleVector& parent; 
		int index ;
	} ;
	
	
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
	
	internal::ListInitialization<iterator,value_type> operator=( value_type x){
		*start = x ;
		return internal::ListInitialization<iterator,value_type>( start + 1 ) ; ;
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

	inline int ncol(){
		if( !::Rf_isMatrix(m_sexp) ) throw VectorBase::not_a_matrix() ;
		return dims()[1]; 
	}
	
	inline int nrow(){
		if( !::Rf_isMatrix(m_sexp) ) throw VectorBase::not_a_matrix() ;
		return dims()[0]; 
	}
	
protected:
	void init(){
		internal::r_init_vector<RTYPE>(m_sexp) ;
	}
	
	void update_vector(){
		start = internal::r_vector_start<RTYPE,value_type>(m_sexp) ;
	}
	
private:
	value_type* start ;
	
	virtual void update(){ 
		update_vector() ;
	}
	
	inline int* dims(){
		return INTEGER( ::Rf_getAttrib( m_sexp, ::Rf_install( "dim") ) ) ;
	}
	
} ;

template <int RTYPE> 
class SimpleMatrix : public SimpleVector<RTYPE> {
public:
	SimpleMatrix() : SimpleVector<RTYPE>() {}
	
	SimpleMatrix(SEXP x) throw(RObject::not_compatible) : SimpleVector<RTYPE>(){
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		SEXP y = r_cast<RTYPE>( x ) ;
		SimpleVector<RTYPE>::setSEXP( y );
	}
	
	SimpleMatrix( const Dimension& dims) : SimpleVector<RTYPE>() {
		if( dims.size() != 2 ) throw RObject::not_compatible("not a matrix") ;
		SimpleVector<RTYPE>::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		SimpleVector<RTYPE>::init() ;
		SimpleVector<RTYPE>::attr( "dim" ) = dims ;
	}
	
	SimpleMatrix( const int& nrows, const int& ncols) : SimpleVector<RTYPE>() {
		SimpleVector<RTYPE>::setSEXP( Rf_allocVector( RTYPE, nrows*ncols ) ) ;
		SimpleVector<RTYPE>::init() ;
		SimpleVector<RTYPE>::attr( "dim" ) = Dimension( nrows, ncols ) ;
	}
	
	
	SimpleMatrix( const SimpleMatrix& other) : SimpleVector<RTYPE>() {
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		SimpleVector<RTYPE>::setSEXP( x ) ;
	}
	
	SimpleMatrix& operator=(const SimpleMatrix& other) {
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		SimpleVector<RTYPE>::setSEXP( x ) ;
		return *this ;
	}
	
private:
	virtual void update(){
		SimpleVector<RTYPE>::update_vector() ;
	}
	
} ;


typedef SimpleVector<CPLXSXP> ComplexVector ;
typedef SimpleVector<INTSXP> IntegerVector ;
typedef SimpleVector<LGLSXP> LogicalVector ;
typedef SimpleVector<REALSXP> NumericVector ;
typedef SimpleVector<RAWSXP> RawVector ;

typedef SimpleMatrix<CPLXSXP> ComplexMatrix ;
typedef SimpleMatrix<INTSXP> IntegerMatrix ;
typedef SimpleMatrix<LGLSXP> LogicalMatrix ;
typedef SimpleMatrix<REALSXP> NumericMatrix ;
typedef SimpleMatrix<RAWSXP> RawMatrix ;

}// namespace Rcpp

#endif
