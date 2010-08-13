// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Mod.h: Rcpp R/C++ interface class library -- Mod
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

#ifndef Rcpp__sugar__complex_h
#define Rcpp__sugar__complex_h

#ifdef HAVE_HYPOT
# define RCPP_HYPOT ::hypot
#else
# define RCPP_HYPOT ::Rf_pythag
#endif

namespace Rcpp{
namespace sugar{

	
template <bool NA, typename OUT, typename T, typename FunPtr>
class SugarComplex : public Rcpp::VectorBase< 
	Rcpp::traits::r_sexptype_traits<OUT>::rtype , 
	NA, 
	SugarComplex<NA,OUT,T,FunPtr>
	> {
public:
	
	typedef Rcpp::VectorBase<CPLXSXP,NA,T> VEC_TYPE ;
	
	SugarComplex( FunPtr ptr_, const VEC_TYPE & vec_) : ptr(ptr_), vec(vec_){}
	
	inline OUT operator[]( int i) const { 
		Rcomplex x = vec[i] ;
		if( Rcpp::traits::is_na<CPLXSXP>( x ) ) 
			return Rcpp::traits::get_na< Rcpp::traits::r_sexptype_traits<OUT>::rtype >() ;
		return ptr( x ); 
	}
	inline int size() const { return vec.size() ; }
	
private:
	FunPtr ptr ;
	const VEC_TYPE& vec ;
};
} // sugar

namespace internal{
inline double complex__Re( Rcomplex x){ return x.r ; }
	inline double complex__Im( Rcomplex x){ return x.i ; }
	inline double complex__Mod( Rcomplex x){ return ::sqrt( x.i * x.i + x.r * x.r) ; }
	inline Rcomplex complex__Conj( Rcomplex x){
		Rcomplex y ;
		y.r = x.r; 
		y.i = -x.i ;
		return y ;
	}
	// TODO: this does not use HAVE_C99_COMPLEX as in R, perhaps it should
	inline Rcomplex complex__exp( Rcomplex x){
		Rcomplex y ;
		double expx = ::exp(x.r);
    	y.r = expx * ::cos(x.i);
    	y.i = expx * ::sin(x.i);
		return y ;
	}
	inline Rcomplex complex__log( Rcomplex x){
		Rcomplex y ;
		y.i = ::atan2(x.i, x.r);
		y.r = ::log( RCPP_HYPOT( x.r, x.i ) );
	    return y ;
	}
} // internal

#define RCPP_SUGAR_COMPLEX(__NAME__,__OUT__)                                \
	template <bool NA, typename T>                                          \
	inline sugar::SugarComplex<NA,__OUT__,T, __OUT__ (*)(Rcomplex) >        \
	__NAME__(                                                               \
		const VectorBase<CPLXSXP,NA,T>& t                                   \
		){                                                                  \
		return sugar::SugarComplex<NA,__OUT__,T, __OUT__ (*)(Rcomplex) >(   \
			internal::complex__##__NAME__, t                                \
		) ;                                                                 \
	}

RCPP_SUGAR_COMPLEX( Re, double )
RCPP_SUGAR_COMPLEX( Im, double )
RCPP_SUGAR_COMPLEX( Mod, double )
RCPP_SUGAR_COMPLEX( Conj, Rcomplex )
RCPP_SUGAR_COMPLEX( exp, Rcomplex )
RCPP_SUGAR_COMPLEX( log, Rcomplex )

#undef RCPP_SUGAR_COMPLEX	 
	
} // Rcpp
#endif

