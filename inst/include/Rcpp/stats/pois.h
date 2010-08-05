// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// pois.h: Rcpp R/C++ interface class library --
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

#ifndef Rcpp__stats__pois_h
#define Rcpp__stats__pois_h

namespace Rcpp{
namespace stats{
namespace impl{

template <bool NA, typename T>
class DPois : public Rcpp::VectorBase< REALSXP, NA, DPois<NA,T> >{
public:
	typedef typename Rcpp::VectorBase<INTSXP,NA,T> VEC_TYPE ;
	
	DPois( const VEC_TYPE& vec_, double lambda_, bool log_ = false ) : 
		vec(vec_), lambda(lambda_), log(log_) {}
	
	inline double operator[]( int i) const {
		return ::dpois( vec[i], lambda, log ) ;
	}
	
	inline int size() const { return vec.size(); }
	
private:
	const VEC_TYPE& vec ;
	double lambda ;
	int log ;
	
} ;

} // impl

template <bool NA, typename T>
inline impl::DPois<NA,T> dpois( const Rcpp::VectorBase<INTSXP,NA,T>& x, double lambda, bool log = false ){
	return impl::DPois<NA,T>( x, lambda, log ); 
}
	
}
}

#endif
