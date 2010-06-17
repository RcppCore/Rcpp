// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// VectorBase.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__vector__VectorBase_h
#define Rcpp__vector__VectorBase_h

namespace Rcpp{
	
/** a base class for vectors, modelled after the CRTP */
template <int RTYPE, bool na, typename VECTOR>
class VectorBase {
public:
	struct r_type : traits::integral_constant<int,RTYPE>{} ;
	struct can_have_na : traits::integral_constant<bool,na>{} ;
	typedef typename traits::storage_type<RTYPE>::type stored_type ;
	
	VECTOR& get_ref(){
		return static_cast<VECTOR&>(*this) ;
	}
	
	// FIXME (or not): cannot get the iterator stuff to work
	//                 we can probaly live without
	// typedef typename traits::get_iterator<VECTOR>::type iterator ;
	// inline iterator begin(){ return static_cast<VECTOR*>(this)->begin() ; }
	// inline iterator end(){ return static_cast<VECTOR*>(this)->end() ; }

	inline stored_type operator[]( int i) const { return static_cast<VECTOR*>(this)->operator[](i) ; }
	
	inline int size() const { return static_cast<VECTOR*>(this)->size() ; }
} ;

} // namespace Rcpp
#endif
