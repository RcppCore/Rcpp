
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// nbeta.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__nbeta_h
#define Rcpp__stats__nbeta_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DNbeta : public Rcpp::VectorBase< REALSXP, NA, DNbeta<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNbeta( const VEC_TYPE& vec_, double shape1_, double shape2_, double ncp_ , bool log_ = false ) : 
			vec(vec_), shape1(shape1_), shape2(shape2_), ncp(ncp_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dnbeta( vec[i], shape1, shape2, ncp , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double shape1; double shape2; double ncp; 
		int log;
	
	};

	template <bool NA, typename T>
	class PNbeta : public Rcpp::VectorBase< REALSXP, NA, PNbeta<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PNbeta( const VEC_TYPE& vec_, double shape1_, double shape2_, double ncp_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), shape1(shape1_), shape2(shape2_), ncp(ncp_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pnbeta( vec[i], shape1, shape2, ncp, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double shape1; double shape2; double ncp; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QNbeta : public Rcpp::VectorBase< REALSXP, NA, QNbeta<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QNbeta( const VEC_TYPE& vec_, double shape1_, double shape2_, double ncp_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), shape1(shape1_), shape2(shape2_), ncp(ncp_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qnbeta( vec[i], shape1, shape2, ncp, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double shape1; double shape2; double ncp; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DNbeta<NA,T> dnbeta( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape1_, double shape2_, double ncp_, bool log = false ) {
	return impl::DNbeta<NA,T>( x, shape1_, shape2_, ncp_, log ); 
}

template <bool NA, typename T>
inline impl::PNbeta<NA,T> pnbeta( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape1_, double shape2_, double ncp_, bool lower = true, bool log = false ) {
	return impl::PNbeta<NA,T>( x, shape1_, shape2_, ncp_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QNbeta<NA,T> qnbeta( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape1_, double shape2_, double ncp_, bool lower = true, bool log = false ) {
	return impl::QNbeta<NA,T>( x, shape1_, shape2_, ncp_, lower, log ); 
}
	
}
}

#endif

