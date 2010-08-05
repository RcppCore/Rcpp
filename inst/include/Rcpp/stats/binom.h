// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// binom.h: Rcpp R/C++ interface class library --
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

#ifndef Rcpp__stats__binom_h
#define Rcpp__stats__binom_h

namespace Rcpp{
namespace stats{
namespace impl{

template <bool NA, typename T>
class DBinom : public Rcpp::VectorBase< REALSXP, NA, DBinom<NA,T> >{
public:
	typedef typename Rcpp::VectorBase<INTSXP,NA,T> VEC_TYPE ;
	
	DBinom( const VEC_TYPE& vec_, int n_, double prob_, bool log_ = false ) : 
		vec(vec_), n(n_), prob(prob_), log(log_) {}
	
	inline double operator[]( int i) const {
	    return ::dbinom( vec[i], (double) n, prob, log ) ;
	}
	
	inline int size() const { return vec.size(); }
	
private:
	const VEC_TYPE& vec ;
	int n ;
	double prob ;
	int log ;
	
} ;

template <bool NA, typename T>
class PBinom : public Rcpp::VectorBase< REALSXP, NA, PBinom<NA,T> >{
public:
    typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE ;
	
    PBinom( const VEC_TYPE& vec_, int n_, double prob_, bool lower_tail = true, bool log_ = false ) : 
	vec(vec_), n(n_), prob(prob_), lower(lower_tail), log(log_) {}
	
    inline double operator[]( int i) const {
	return ::pbinom( vec[i], (double) n, prob, lower, log ) ;
    }
	
    inline int size() const { return vec.size(); }
	
private:
    const VEC_TYPE& vec ;
    int n ;
    double prob ;
    int lower, log ;
	
} ;

template <bool NA, typename T>
class QBinom : public Rcpp::VectorBase< REALSXP, NA, QBinom<NA,T> >{
public:
    typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE ;
	
    QBinom( const VEC_TYPE& vec_, int n_, double prob_, bool lower_tail = true, bool log_ = false ) : 
	vec(vec_), n(n_), prob(prob_), lower(lower_tail), log(log_) {}
	
	inline double operator[]( int i) const {
	    return ::qbinom( vec[i], (double) n, prob, lower, log ) ;
	}
	
	inline int size() const { return vec.size(); }
	
private:
    const VEC_TYPE& vec ;
    int n ;
    double prob ;
    int lower, log ;
	
} ;

} // impl

template <bool NA, typename T>
inline impl::DBinom<NA,T> dbinom( const Rcpp::VectorBase<INTSXP,NA,T>& x, int size, double prob, bool log = false ){
	return impl::DBinom<NA,T>( x, size, prob, log ); 
}

template <bool NA, typename T>
inline impl::PBinom<NA,T> pbinom( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size, double prob, bool lower = false, bool log = false ){
    return impl::PBinom<NA,T>( x, size, prob, lower, log ); 
}

template <bool NA, typename T>
inline impl::QBinom<NA,T> qbinom( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size, double prob, bool lower = false, bool log = false ){
    return impl::QBinom<NA,T>( x, size, prob, lower, log ); 
}
	
}
}

#endif
