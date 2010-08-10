
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// hyper.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__hyper_h
#define Rcpp__stats__hyper_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DHyper : public Rcpp::VectorBase< REALSXP, NA, DHyper<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DHyper( const VEC_TYPE& vec_, double mm_, double nn_, double kk_ , bool log_ = false ) : 
			vec(vec_), mm(mm_), nn(nn_), kk(kk_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dhyper( vec[i], mm, nn, kk , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mm; double nn; double kk; 
		int log;
	
	};

	template <bool NA, typename T>
	class PHyper : public Rcpp::VectorBase< REALSXP, NA, PHyper<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PHyper( const VEC_TYPE& vec_, double mm_, double nn_, double kk_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), mm(mm_), nn(nn_), kk(kk_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::phyper( vec[i], mm, nn, kk, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mm; double nn; double kk; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QHyper : public Rcpp::VectorBase< REALSXP, NA, QHyper<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QHyper( const VEC_TYPE& vec_, double mm_, double nn_, double kk_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), mm(mm_), nn(nn_), kk(kk_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qhyper( vec[i], mm, nn, kk, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mm; double nn; double kk; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DHyper<NA,T> dhyper( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mm_, double nn_, double kk_, bool log = false ) {
	return impl::DHyper<NA,T>( x, mm_, nn_, kk_, log ); 
}

template <bool NA, typename T>
inline impl::PHyper<NA,T> phyper( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mm_, double nn_, double kk_, bool lower = true, bool log = false ) {
	return impl::PHyper<NA,T>( x, mm_, nn_, kk_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QHyper<NA,T> qhyper( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mm_, double nn_, double kk_, bool lower = true, bool log = false ) {
	return impl::QHyper<NA,T>( x, mm_, nn_, kk_, lower, log ); 
}
	
}
}

#endif

