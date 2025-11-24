// check_r_headers.h: Rcpp R/C++ interface class library -- R header check
//
// Copyright (C) 2025 - current Dirk Eddelbuettel
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

#ifndef RCPP__CHECK__R__HEADERS__H
#define RCPP__CHECK__R__HEADERS__H

// Allow an escape hatch
#if !defined(RCPP_NO_R_HEADERS_CHECK)

  #if defined(R_R_H) && defined(USING_R)
    #pragma message "R.h has been included before any Rcpp headers. This can lead to hard-to-debug errors, and is not necessary. See https://github.com/RcppCore/Rcpp/issues/1410"
  #endif

  #if defined(RINTERFACE_H_)
    #pragma message "Rinterface.h has been included before any Rcpp headers. This can lead to hard-to-debug errors, and is not necessary. See https://github.com/RcppCore/Rcpp/issues/1410"
  #endif

  #if defined(R_INTERNALS_H_)
    #pragma message "Rinternals.h has been included before any Rcpp headers. This can lead to hard-to-debug errors, and is not necessary. See https://github.com/RcppCore/Rcpp/issues/1410"
  #endif

  #if defined(R_DEFINES_H_)
    #pragma message "Rdefines.h has been included before any Rcpp headers. This can lead to hard-to-debug errors, and is not necessary. See https://github.com/RcppCore/Rcpp/issues/1410"
  #endif

#endif  // escape hatch '!defined(RCPP_NO_R_HEADERS_CHECK)'

#endif  // header guard
