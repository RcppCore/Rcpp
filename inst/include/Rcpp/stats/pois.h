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

template <bool NA, typename T>
class PPois : public Rcpp::VectorBase< REALSXP, NA, PPois<NA,T> >{
public:
    typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE ;
	
    PPois( const VEC_TYPE& vec_, double lambda_, bool lower_tail = true, bool log_ = false ) : 
	vec(vec_), lambda(lambda_), lower(lower_tail), log(log_) {}
	
    inline double operator[]( int i) const {
	return ::ppois( vec[i], lambda, lower, log ) ;
    }
	
    inline int size() const { return vec.size(); }
	
private:
    const VEC_TYPE& vec ;
    double lambda ;
    int lower, log ;
	
} ;

template <bool NA, typename T>
class QPois : public Rcpp::VectorBase< REALSXP, NA, QPois<NA,T> >{
public:
    typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE ;
	
    QPois( const VEC_TYPE& vec_, double lambda_, bool lower_tail = true, bool log_ = false ) : 
	vec(vec_), lambda(lambda_), lower(lower_tail), log(log_) {}
	
    inline double operator[]( int i) const {
	return ::qpois( vec[i], lambda, lower, log ) ;
    }
	
    inline int size() const { return vec.size(); }
	
private:
    const VEC_TYPE& vec ;
    double lambda ;
    int lower, log ;
	
} ;

} // stats

template <bool NA, typename T>
inline stats::DPois<NA,T> dpois( const Rcpp::VectorBase<INTSXP,NA,T>& x, double lambda, bool log = false ){
	return stats::DPois<NA,T>( x, lambda, log ); 
}
	
template <bool NA, typename T>
inline stats::PPois<NA,T> ppois( const Rcpp::VectorBase<REALSXP,NA,T>& x,
				double lambda, bool lower = true, bool log = false ){
    return stats::PPois<NA,T>( x, lambda, lower, log ); 
}

template <bool NA, typename T>
inline stats::QPois<NA,T> qpois( const Rcpp::VectorBase<REALSXP,NA,T>& x,
				double lambda, bool lower = true, bool log = false ){
    return stats::QPois<NA,T>( x, lambda, lower, log ); 
}
	
}

#endif
