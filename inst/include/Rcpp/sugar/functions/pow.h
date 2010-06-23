// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// pow.h: Rcpp R/C++ interface class library -- pow
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

#ifndef Rcpp__sugar__pow_h
#define Rcpp__sugar__pow_h

namespace Rcpp{
namespace sugar{

template <bool NA, int RTYPE, typename EXPONENT_TYPE>
class pow__impl{
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	pow__impl( EXPONENT_TYPE exponent_) : exponent(exponent_){}
	
	inline double get( STORAGE x) const {
		return Rcpp::traits::is_na<RTYPE>(x) ? NA_INTEGER : pow(x, exponent) ;
	}
private:
	EXPONENT_TYPE exponent ;
} ;

template <int RTYPE, typename EXPONENT_TYPE>
class pow__impl<false,RTYPE,EXPONENT_TYPE>{
public:
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	pow__impl( EXPONENT_TYPE exponent_) : exponent(exponent_){}
	
	inline double get( STORAGE x) const {
		return pow(x, exponent) ;
	}
private:
	EXPONENT_TYPE exponent ;
} ;

	
template <int RTYPE, bool NA, typename T, typename EXPONENT_TYPE>
class Pow : public Rcpp::VectorBase< REALSXP ,NA, Pow<RTYPE,NA,T,EXPONENT_TYPE> > {
public:
	typedef typename Rcpp::VectorBase<RTYPE,NA,T> VEC_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	typedef pow__impl<NA,RTYPE,EXPONENT_TYPE> OPERATOR ;
	
	Pow( const VEC_TYPE& object_, EXPONENT_TYPE exponent ) : 
		object(object_), op(exponent) {}
	
	inline double operator[]( int i ) const {
		return op.get( object[i] );
	}
	inline int size() const { return object.size() ; }
	         
private:
	const VEC_TYPE& object ;
	OPERATOR op ;
} ;
	
} // sugar

template <bool NA, typename T, typename EXPONENT_TYPE >
inline sugar::Pow<INTSXP,NA,T,EXPONENT_TYPE> pow( 
	const VectorBase<INTSXP,NA,T>& t, 
	EXPONENT_TYPE exponent 
){
	return sugar::Pow<INTSXP,NA,T,EXPONENT_TYPE>( t , exponent ) ;
}

template <bool NA, typename T, typename EXPONENT_TYPE>
inline sugar::Pow<REALSXP,NA,T,EXPONENT_TYPE> pow( 
	const VectorBase<REALSXP,NA,T>& t, 
	EXPONENT_TYPE exponent
){
	return sugar::Pow<REALSXP,NA,T,EXPONENT_TYPE>( t, exponent ) ;
}


} // Rcpp
#endif

