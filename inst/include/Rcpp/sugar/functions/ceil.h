// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// ceil.h: Rcpp R/C++ interface class library -- ceil
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

#ifndef Rcpp__sugar__ceil_h
#define Rcpp__sugar__ceil_h

namespace Rcpp{
namespace sugar{

template <bool NA, int RTYPE>
class ceil__impl{
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	static inline double get( STORAGE x){
		return Rcpp::traits::is_na<RTYPE>(x) ? NA_INTEGER : ceil(x) ;
	}
} ;

template <int RTYPE>
class ceil__impl<false,RTYPE>{
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	static inline double get( STORAGE x){
		return ceil(x) ;
	}
} ;

	
template <int RTYPE, bool NA, typename T>
class Ceil : public Rcpp::VectorBase< REALSXP ,NA, Ceil<RTYPE,NA,T> > {
public:
	typedef typename Rcpp::VectorBase<RTYPE,NA,T> VEC_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	Ceil( const VEC_TYPE& object_ ) : object(object_){}
	
	inline double operator[]( int i ) const {
		return ceil__impl<NA,RTYPE>::get( object[i] );
	}
	inline int size() const { return object.size() ; }
	         
private:
	const VEC_TYPE& object ;
} ;
	
} // sugar

template <bool NA, typename T>
inline sugar::Ceil<INTSXP,NA,T> ceil( const VectorBase<INTSXP,NA,T>& t){
	return sugar::Ceil<INTSXP,NA,T>( t ) ;
}

template <bool NA, typename T>
inline sugar::Ceil<REALSXP,NA,T> ceil( const VectorBase<REALSXP,NA,T>& t){
	return sugar::Ceil<REALSXP,NA,T>( t ) ;
}

template <bool NA, typename T>
inline sugar::Ceil<INTSXP,NA,T> ceiling( const VectorBase<INTSXP,NA,T>& t){
	return sugar::Ceil<INTSXP,NA,T>( t ) ;
}

template <bool NA, typename T>
inline sugar::Ceil<REALSXP,NA,T> ceiling( const VectorBase<REALSXP,NA,T>& t){
	return sugar::Ceil<REALSXP,NA,T>( t ) ;
}

} // Rcpp
#endif

