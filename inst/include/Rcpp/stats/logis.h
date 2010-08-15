
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// logis.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__logis_h
#define Rcpp__stats__logis_h

namespace Rcpp {
namespace stats {


	template <bool NA, typename T>
	class DLogis : public Rcpp::VectorBase< REALSXP, NA, DLogis<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DLogis( const VEC_TYPE& vec_, double location_ = 0.0, double scale_ = 1.0 , bool log_ = false ) : 
			vec(vec_), location(location_), scale(scale_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::Rf_dlogis( vec[i], location, scale , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double location; double scale; 
		int log;
	
	};

	template <bool NA, typename T>
	class PLogis : public Rcpp::VectorBase< REALSXP, NA, PLogis<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PLogis( const VEC_TYPE& vec_, double location_ = 0.0, double scale_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), location(location_), scale(scale_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::Rf_plogis( vec[i], location, scale, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double location; double scale; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QLogis : public Rcpp::VectorBase< REALSXP, NA, QLogis<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QLogis( const VEC_TYPE& vec_, double location_ = 0.0, double scale_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), location(location_), scale(scale_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::Rf_qlogis( vec[i], location, scale, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double location; double scale; 
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DLogis<NA,T> dlogis( const Rcpp::VectorBase<REALSXP,NA,T>& x, double location_ = 0.0, double scale_ = 1.0, bool log = false ) {
	return stats::DLogis<NA,T>( x, location_, scale_, log ); 
}

template <bool NA, typename T>
inline stats::PLogis<NA,T> plogis( const Rcpp::VectorBase<REALSXP,NA,T>& x, double location_ = 0.0, double scale_ = 1.0, bool lower = true, bool log = false ) {
	return stats::PLogis<NA,T>( x, location_, scale_, lower, log ); 
}

template <bool NA, typename T>
inline stats::QLogis<NA,T> qlogis( const Rcpp::VectorBase<REALSXP,NA,T>& x, double location_ = 0.0, double scale_ = 1.0, bool lower = true, bool log = false ) {
	return stats::QLogis<NA,T>( x, location_, scale_, lower, log ); 
}
	
}

#endif

