// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// diff.h: Rcpp R/C++ interface class library -- diff
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

#ifndef Rcpp__sugar__diff_h
#define Rcpp__sugar__diff_h

namespace Rcpp{
namespace sugar{
	
	// NOTE: caching the previous value so that we only have to fetch the 
	//       value once only works because we process the object from left to 
	//       right
template <int RTYPE, bool LHS_NA, typename LHS_T>
class Diff : public Rcpp::VectorBase< RTYPE, LHS_NA , Diff<RTYPE,LHS_NA,LHS_T> > {
public:
	typedef typename Rcpp::VectorBase<RTYPE,LHS_NA,LHS_T> LHS_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	Diff( const LHS_TYPE& lhs_ ) : lhs(lhs_), previous(lhs_[0]), was_na(false) {
		was_na = traits::is_na<RTYPE>(previous) ;
	}
	
	inline STORAGE operator[]( int i ) const {
		STORAGE y = lhs[i+1] ;
		if( was_na ){
			previous = y ;
			was_na = traits::is_na<RTYPE>(y) ;
			return previous ; // NA
		}
		if( traits::is_na<RTYPE>(y) ) {
			was_na = true ;
			previous = y ;
			return previous ; // NA
		}
		STORAGE res = y - previous ;
		previous = y ;
		was_na = false ;
		return res ;
	}
	inline int size() const { return lhs.size() - 1 ; }
	         
private:
	const LHS_TYPE& lhs ;
	mutable STORAGE previous ;
	mutable bool was_na ;
} ;

template <int RTYPE, typename LHS_T>
class Diff<RTYPE,false,LHS_T> : public Rcpp::VectorBase< RTYPE, false , Diff<RTYPE,false,LHS_T> > {
public:
	typedef typename Rcpp::VectorBase<RTYPE,false,LHS_T> LHS_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	Diff( const LHS_TYPE& lhs_ ) : lhs(lhs_) {}
	
	inline STORAGE operator[]( int i ) const {
		STORAGE y = lhs[i+1] ;
		STORAGE diff = y - previous ;
		previous = y ;
		return y - previous ;
	}
	inline int size() const { return lhs.size() - 1 ; }
	         
private:
	const LHS_TYPE& lhs ;
	mutable STORAGE previous ;
} ;

} // sugar

template <bool LHS_NA, typename LHS_T>
inline sugar::Diff<INTSXP,LHS_NA,LHS_T> diff( 
	const VectorBase<INTSXP,LHS_NA,LHS_T>& lhs
	){
	return sugar::Diff<INTSXP,LHS_NA,LHS_T>( lhs ) ;
}

template <bool LHS_NA, typename LHS_T>
inline sugar::Diff<REALSXP,LHS_NA,LHS_T> diff( 
	const VectorBase<REALSXP,LHS_NA,LHS_T>& lhs
	){
	return sugar::Diff<REALSXP,LHS_NA,LHS_T>( lhs ) ;
}

} // Rcpp
#endif

