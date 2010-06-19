// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// pmax.h: Rcpp R/C++ interface class library -- pmax
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__pmax_h
#define Rcpp__sugar__pmax_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool LHS_NA, bool RHS_NA> class pmax_op {
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	inline STORAGE operator()( STORAGE left, STORAGE right ) const {
		if( Rcpp::traits::is_na<RTYPE>(left) ) return left ;
		if( Rcpp::traits::is_na<RTYPE>(right) ) return right ;
		return left > right ? left : right ;
	}
	
} ;
template <int RTYPE, bool LHS_NA> class pmax_op<RTYPE,LHS_NA,false> {
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	inline STORAGE operator()( STORAGE left, STORAGE right ) const {
		if( Rcpp::traits::is_na<RTYPE>(left) ) return left ;
		return left > right ? left : right ;
	}
} ;
template <int RTYPE, bool RHS_NA> class pmax_op<RTYPE,false,RHS_NA> {
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	inline STORAGE operator()( STORAGE left, STORAGE right ) const {
		if( Rcpp::traits::is_na<RTYPE>(right) ) return right ;
		return left > right ? left : right ;
	}
} ;
template <int RTYPE> class pmax_op<RTYPE,false,false> {
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	inline STORAGE operator()( STORAGE left, STORAGE right ) const {
		return left > right ? left : right ;
	}
} ;

template <int RTYPE,bool NA> class pmax_op_Vector_Primitive {
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;

	pmax_op_Vector_Primitive( STORAGE right_ ) : 
		right(right_) {}
	
	inline STORAGE operator()( STORAGE left ) const {
		if( Rcpp::traits::is_na<RTYPE>(left) ) return left ;
		return left > right ? left : right ;
	}	
		
private:
	STORAGE right ;
} ;

template <int RTYPE> class pmax_op_Vector_Primitive<RTYPE,false> {
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;

	pmax_op_Vector_Primitive( STORAGE right_ ) : 
		right(right_){}
	
	inline STORAGE operator()( STORAGE left ) const {
		return left > right ? left : right ;
	}	
		
private:
	STORAGE right ;
} ;



template <
	int RTYPE, 
	bool LHS_NA, typename LHS_T, 
	bool RHS_NA, typename RHS_T
	>
class Pmax_Vector_Vector : public VectorBase< 
	RTYPE , 
	( LHS_NA || RHS_NA ) ,
	Pmax_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T>
> {
public:
	typedef typename Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T> LHS_TYPE ;
	typedef typename Rcpp::VectorBase<RTYPE,RHS_NA,RHS_T> RHS_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	typedef pmax_op<RTYPE,LHS_NA,RHS_NA> OPERATOR ;
	
	Pmax_Vector_Vector( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_ ) : 
		lhs(lhs_), rhs(rhs_), op() {}
	
	inline STORAGE operator[]( int i ) const {
		return op( lhs[i], rhs[i] ) ;
	}
	inline int size() const { return lhs.size() ; }
	         
private:
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	OPERATOR op ;
} ;



template <
	int RTYPE, 
	bool LHS_NA, typename LHS_T
	>
class Pmax_Vector_Primitive : public VectorBase< 
	RTYPE , 
	true ,
	Pmax_Vector_Primitive<RTYPE,LHS_NA,LHS_T>
> {
public:
	typedef typename Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T> LHS_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	typedef pmax_op_Vector_Primitive<RTYPE,LHS_NA> OPERATOR ;
	
	Pmax_Vector_Primitive( const LHS_TYPE& lhs_, STORAGE rhs_ ) : 
		lhs(lhs_), op(rhs_), rhs(rhs_), isna( Rcpp::traits::is_na<RTYPE>(rhs_) ) {}
	
	inline STORAGE operator[]( int i ) const {
		return isna ? rhs : op( lhs[i] ) ;
	}
	inline int size() const { return lhs.size() ; }
	         
private:
	const LHS_TYPE& lhs ;
	OPERATOR op ;
	STORAGE rhs ;
	bool isna ;
} ;



} // sugar

template <
	int RTYPE, 
	bool LHS_NA, typename LHS_T,
	bool RHS_NA, typename RHS_T
>
inline sugar::Pmax_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T> 
pmax( 
	const Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T>& lhs, 
	const Rcpp::VectorBase<RTYPE,RHS_NA,RHS_T>& rhs 
	){
	return sugar::Pmax_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T>( lhs, rhs ) ;
}

template <
	int RTYPE, 
	bool LHS_NA, typename LHS_T
>
inline sugar::Pmax_Vector_Primitive<RTYPE,LHS_NA,LHS_T> 
pmax( 
	const Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T>& lhs, 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs 
	){
	return sugar::Pmax_Vector_Primitive<RTYPE,LHS_NA,LHS_T>( lhs, rhs ) ;
}


template <
	int RTYPE, 
	bool RHS_NA, typename RHS_T
>
inline sugar::Pmax_Vector_Primitive<RTYPE,RHS_NA,RHS_T> 
pmax( 
	typename Rcpp::traits::storage_type<RTYPE>::type lhs,  
	const Rcpp::VectorBase<RTYPE,RHS_NA,RHS_T>& rhs 
	){
	return sugar::Pmax_Vector_Primitive<RTYPE,RHS_NA,RHS_T>( rhs, lhs ) ;
}


} // Rcpp

#endif
