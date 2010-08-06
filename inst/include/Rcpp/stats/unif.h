
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// unif.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 Douglas Bates, Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__stats__unif_h
#define Rcpp__stats__unif_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DUnif : public Rcpp::VectorBase< REALSXP, NA, DUnif<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DUnif( const VEC_TYPE& vec_, double min_ = 0.0, double max_ = 1.0 , bool log_ = false ) : 
			vec(vec_), min(min_), max(max_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dunif( vec[i], min, max , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double min; double max; 
		int log;
	
	};

	template <bool NA, typename T>
	class PUnif : public Rcpp::VectorBase< REALSXP, NA, PUnif<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PUnif( const VEC_TYPE& vec_, double min_ = 0.0, double max_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), min(min_), max(max_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::punif( vec[i], min, max, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double min; double max; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QUnif : public Rcpp::VectorBase< REALSXP, NA, QUnif<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QUnif( const VEC_TYPE& vec_, double min_ = 0.0, double max_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), min(min_), max(max_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qunif( vec[i], min, max, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double min; double max; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DUnif<NA,T> dunif( const Rcpp::VectorBase<REALSXP,NA,T>& x, double min_ = 0.0, double max_ = 1.0, bool log = false ) {
	return impl::DUnif<NA,T>( x, min_, max_, log ); 
}

template <bool NA, typename T>
inline impl::PUnif<NA,T> punif( const Rcpp::VectorBase<REALSXP,NA,T>& x, double min_ = 0.0, double max_ = 1.0, bool lower = true, bool log = false ) {
	return impl::PUnif<NA,T>( x, min_, max_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QUnif<NA,T> qunif( const Rcpp::VectorBase<REALSXP,NA,T>& x, double min_ = 0.0, double max_ = 1.0, bool lower = true, bool log = false ) {
	return impl::QUnif<NA,T>( x, min_, max_, lower, log ); 
}
	
}
}

#endif

