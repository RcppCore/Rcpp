// mask.h: Rcpp R/C++ interface class library -- masking macros
//
// Copyright (C) 2025        Iñaki Ucar
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

#ifndef Rcpp_macros_mask_h
#define Rcpp_macros_mask_h

#ifndef RCPP_NO_MASK_RF_ERROR
#ifdef RCPP_MASK_RF_ERROR
#define Rf_error(...) \
    _Pragma("GCC warning \"Use of Rf_error() instead of Rcpp::stop(). Calls \
to Rf_error() in C++ contexts are unsafe: consider using Rcpp::stop() instead, \
or define RCPP_NO_MASK_RF_ERROR if this is a false positive. More info:\n\
 - https://github.com/RcppCore/Rcpp/issues/1247\n\
 - https://github.com/RcppCore/Rcpp/pull/1402\"") \
    Rf_error(__VA_ARGS__)
#endif
#endif

#endif
