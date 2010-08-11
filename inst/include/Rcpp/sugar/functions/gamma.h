// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// gamma.h: Rcpp R/C++ interface class library -- gamma
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

#ifndef Rcpp__sugar__gamma_h
#define Rcpp__sugar__gamma_h

SUGAR_BLOCK_1(gamma      , ::Rf_gammafn     )
SUGAR_BLOCK_1(lgamma     , ::Rf_lgammafn    )
SUGAR_BLOCK_1(digamma    , ::Rf_digamma     )
SUGAR_BLOCK_1(trigamma   , ::Rf_trigamma    )
SUGAR_BLOCK_1(tetragamma , ::Rf_tetragamma  )
SUGAR_BLOCK_1(pentagamma , ::Rf_pentagamma  )
SUGAR_BLOCK_1(expm1      , ::expm1          )
SUGAR_BLOCK_1(log1p      , ::log1p          )

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
SUGAR_BLOCK_1(factorial  , ::Rcpp::internal::factorial   )
SUGAR_BLOCK_1(lfactorial , ::Rcpp::internal::lfactorial  )

SUGAR_BLOCK_2(choose      , ::Rf_choose     )
SUGAR_BLOCK_2(lchoose     , ::Rf_lchoose    )

SUGAR_BLOCK_2(beta      , ::Rf_beta     )
SUGAR_BLOCK_2(lbeta     , ::Rf_lbeta    )

SUGAR_BLOCK_2(psigamma     , ::Rf_psigamma    )

#endif

