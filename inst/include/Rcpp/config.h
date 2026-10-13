
// config.h: Rcpp R/C++ interface class library -- Rcpp configuration
//
// Copyright (C) 2010-2026  Dirk Eddelbuettel, Romain François and Iñaki Ucar
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

#ifndef RCPP__CONFIG_H
#define RCPP__CONFIG_H

#define Rcpp_Version(v,p,s) (((v) * 65536) + ((p) * 256) + (s))

#define RcppDevVersion(maj, min, rev, dev)  (((maj)*1000000) + ((min)*10000) + ((rev)*100) + (dev))

// the currently released version
#define RCPP_VERSION            Rcpp_Version(1,1,2)
#define RCPP_VERSION_STRING     "1.1.2"

// the current source snapshot (using four components, if a fifth is used in DESCRIPTION we ignore it)
#define RCPP_DEV_VERSION        RcppDevVersion(1,1,2,4)
#define RCPP_DEV_VERSION_STRING "1.1.2.4"

// Whether sugar checks that the operands of an expression, and a vector
// assigned into a range, row or column, have matching lengths. On by default
// in development versions (a non-zero fourth version component), so that
// reverse-dependency checks catch mismatches; off in releases, so that
// packages on CRAN are not affected. Define RCPP_SUGAR_LENGTH_CHECKS as 1 or
// 0 before including Rcpp.h to override.
#ifndef RCPP_SUGAR_LENGTH_CHECKS
# if (RCPP_DEV_VERSION % 100) != 0
#  define RCPP_SUGAR_LENGTH_CHECKS 1
# else
#  define RCPP_SUGAR_LENGTH_CHECKS 0
# endif
#endif

#endif
