// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// SugarBlock.h: Rcpp R/C++ interface class library -- sugar functions
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

#ifndef RCPP_SUGAR_MATH_H
#define RCPP_SUGAR_MATH_H

SUGAR_MATH_1(acos,::acos)
SUGAR_MATH_1(asin,::asin)
SUGAR_MATH_1(atan,::atan)
SUGAR_MATH_1(ceil,::ceil)
SUGAR_MATH_1(ceiling,::ceil)
SUGAR_MATH_1(cos,::cos)
SUGAR_MATH_1(cosh,::cosh)
SUGAR_MATH_1(exp,::exp)
SUGAR_MATH_1(floor,::floor)
SUGAR_MATH_1(log,::log)
SUGAR_MATH_1(log10,::log10)
SUGAR_MATH_1(sqrt,::sqrt)
SUGAR_MATH_1(sin,::sin)
SUGAR_MATH_1(sinh,::sinh)
SUGAR_MATH_1(tan,::tan)
SUGAR_MATH_1(tanh,::tanh)

SUGAR_MATH_1(abs,::fabs)

SUGAR_MATH_1(gamma      , ::Rf_gammafn     )
SUGAR_MATH_1(lgamma     , ::Rf_lgammafn    )
SUGAR_MATH_1(digamma    , ::Rf_digamma     )
SUGAR_MATH_1(trigamma   , ::Rf_trigamma    )
SUGAR_MATH_1(tetragamma , ::Rf_tetragamma  )
SUGAR_MATH_1(pentagamma , ::Rf_pentagamma  )
SUGAR_MATH_1(expm1      , ::expm1          )
SUGAR_MATH_1(log1p      , ::log1p          )

namespace Rcpp{
namespace internal{

inline double factorial( double x ){
	return ::Rf_gammafn( x + 1.0 ) ;
}
inline double lfactorial( double x ){
	return ::Rf_lgammafn( x + 1.0 ) ;
}

}
}
SUGAR_MATH_1(factorial  , ::Rcpp::internal::factorial   )
SUGAR_MATH_1(lfactorial , ::Rcpp::internal::lfactorial  )


SUGAR_BLOCK_2(choose    , ::Rf_choose   )
SUGAR_BLOCK_2(lchoose   , ::Rf_lchoose  )
SUGAR_BLOCK_2(beta      , ::Rf_beta     )
SUGAR_BLOCK_2(lbeta     , ::Rf_lbeta    )
SUGAR_BLOCK_2(psigamma  , ::Rf_psigamma )

#endif
