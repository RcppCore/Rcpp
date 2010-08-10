
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// geom.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__geom_h
#define Rcpp__stats__geom_h

namespace Rcpp {
namespace stats {


	template <bool NA, typename T>
	class DGeom : public Rcpp::VectorBase< REALSXP, NA, DGeom<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DGeom( const VEC_TYPE& vec_, double prob_ , bool log_ = false ) : 
			vec(vec_), prob(prob_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dgeom( vec[i], prob , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double prob; 
		int log;
	
	};

	template <bool NA, typename T>
	class PGeom : public Rcpp::VectorBase< REALSXP, NA, PGeom<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PGeom( const VEC_TYPE& vec_, double prob_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), prob(prob_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pgeom( vec[i], prob, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double prob; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QGeom : public Rcpp::VectorBase< REALSXP, NA, QGeom<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QGeom( const VEC_TYPE& vec_, double prob_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), prob(prob_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qgeom( vec[i], prob, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double prob; 
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DGeom<NA,T> dgeom( const Rcpp::VectorBase<REALSXP,NA,T>& x, double prob_, bool log = false ) {
	return stats::DGeom<NA,T>( x, prob_, log ); 
}

template <bool NA, typename T>
inline stats::PGeom<NA,T> pgeom( const Rcpp::VectorBase<REALSXP,NA,T>& x, double prob_, bool lower = true, bool log = false ) {
	return stats::PGeom<NA,T>( x, prob_, lower, log ); 
}

template <bool NA, typename T>
inline stats::QGeom<NA,T> qgeom( const Rcpp::VectorBase<REALSXP,NA,T>& x, double prob_, bool lower = true, bool log = false ) {
	return stats::QGeom<NA,T>( x, prob_, lower, log ); 
}
	
}

#endif

