// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Conj.h: Rcpp R/C++ interface class library -- Conj
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

#ifndef Rcpp__sugar__Conj_h
#define Rcpp__sugar__Conj_h

namespace Rcpp{
namespace sugar{

template <bool NA, typename T>
class Conj : public Rcpp::VectorBase< CPLXSXP,NA, Conj<NA,T> > {
public:
	typedef typename Rcpp::VectorBase<CPLXSXP,NA,T> VEC_TYPE ;
	
	Conj( const VEC_TYPE& object_ ) : object(object_){}
	
	inline Rcomplex operator[]( int i ) const {
		Rcomplex x = object[i] ;
		x.i = - x.i ;
		return x ;
	}
	inline int size() const { return object.size() ; }
	         
private:
	const VEC_TYPE& object ;
} ;
	
} // sugar

template <bool NA, typename T>
inline sugar::Conj<NA,T> Conj( const VectorBase<CPLXSXP,NA,T>& t){
	return sugar::Conj<NA,T>( t ) ;
}

} // Rcpp
#endif

