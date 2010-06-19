// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// pmin.h: Rcpp R/C++ interface class library -- pmin
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

#ifndef Rcpp__sugar__pmin_h
#define Rcpp__sugar__pmin_h

namespace Rcpp{
namespace sugar{

template <
	int RTYPE, 
	bool LHS_NA, typename LHS_T, 
	bool RHS_NA, typename RHS_T
	>
class Pmin_Vector_Vector : public VectorBase< 
	RTYPE , 
	( LHS_NA || RHS_NA ) ,
	Pmin_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T>
> {
public:
	typedef typename Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T> LHS_TYPE ;
	typedef typename Rcpp::VectorBase<RTYPE,RHS_NA,RHS_T> RHS_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	Pmin_Vector_Vector( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_ ) : lhs(lhs_), rhs(rhs_) {}
	
	inline STORAGE operator[]( int i ) const {
		STORAGE left = lhs[i] ;
		STORAGE right = rhs[i] ;
		return left < right ? left : right ;
	}
	inline int size() const { return lhs.size() ; }
	         
private:
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
} ;
	
} // sugar

template <
	int RTYPE, 
	bool LHS_NA, typename LHS_T,
	bool RHS_NA, typename RHS_T
>
inline sugar::Pmin_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T> 
pmin( 
	const Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T>& lhs, 
	const Rcpp::VectorBase<RTYPE,RHS_NA,RHS_T>& rhs 
	){
	return sugar::Pmin_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T>( lhs, rhs ) ;
}

} // Rcpp

#endif
