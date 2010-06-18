// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// ifelse.h: Rcpp R/C++ interface class library -- ifelse
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

#ifndef Rcpp__sugar__ifelse_h
#define Rcpp__sugar__ifelse_h

namespace Rcpp{
namespace sugar{

template <
	int RTYPE, 
	bool COND_NA, typename COND_T, 
	bool LHS_NA , typename LHS_T, 
	bool RHS_NA , typename RHS_T
	>
class IfElse : public VectorBase< 
	RTYPE, 
	( COND_NA && LHS_NA && RHS_NA ) ,
	IfElse<RTYPE,COND_NA,COND_T,LHS_NA,LHS_T,RHS_NA,RHS_T>
> {
public:         
	typedef Rcpp::VectorBase<LGLSXP,COND_NA,COND_T> COND_TYPE ;
	typedef Rcpp::VectorBase<RTYPE ,LHS_NA ,LHS_T>  LHS_TYPE ;
	typedef Rcpp::VectorBase<RTYPE ,RHS_NA ,RHS_T>  RHS_TYPE ;
	typedef typename traits::storage_type<RTYPE>::type STORAGE ;
	
	IfElse( const COND_TYPE& cond_, const LHS_TYPE& lhs_, const RHS_TYPE& rhs_ ) : 
		cond(cond_), lhs(lhs_), rhs(rhs_) {
			/* FIXME : cond, lhs and rhs must all have the sale size */	
	}
	
	inline STORAGE operator[]( int i ) const {
		return get__impl( i, typename Rcpp::traits::integral_constant<bool,COND_NA>() ); 
	}
	
	inline int size() const { return cond.size() ; }
	         
private:
	
	inline STORAGE get__impl( int i, Rcpp::traits::true_type ) const {	
		int x = cond[i] ;
		return Rcpp::traits::is_na<LGLSXP>(x) ? Rcpp::traits::get_na<RTYPE>() : ( x ? lhs[i] : rhs[i] ) ;
	}
	
	inline STORAGE get__impl( int i, Rcpp::traits::false_type ) const {	
		return cond[i] ? lhs[i] : rhs[i] ;
	}
	
	const COND_TYPE& cond ;
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	
} ;
	
} // sugar

template <
	int RTYPE, 
	bool COND_NA, typename COND_T, 
	bool LHS_NA , typename LHS_T, 
	bool RHS_NA , typename RHS_T
	>
inline sugar::IfElse< RTYPE,COND_NA,COND_T,LHS_NA,LHS_T,RHS_NA,RHS_T > 
ifelse( 
	const Rcpp::VectorBase<LGLSXP,COND_NA,COND_T>& cond,
	const Rcpp::VectorBase<RTYPE ,LHS_NA ,LHS_T>& lhs,
	const Rcpp::VectorBase<RTYPE ,RHS_NA ,RHS_T>& rhs
	){
	return sugar::IfElse<RTYPE,COND_NA,COND_T,LHS_NA,LHS_T,RHS_NA,RHS_T>( cond, lhs, rhs ) ;
}

} // Rcpp

#endif
