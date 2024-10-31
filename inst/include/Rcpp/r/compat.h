
//
// compat.h: Rcpp R/C++ interface class library -- compatibility defines
//
// Copyright (C) 2024         Dirk Eddelbuettel, Kevin Ushey
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

#ifndef RCPP_R_COMPAT_H
#define RCPP_R_COMPAT_H

#include <Rversion.h>

#if R_VERSION >= R_Version(4, 5, 0)
# define RCPP_STRING_PTR STRING_PTR_RO
#else
# define RCPP_STRING_PTR STRING_PTR
#endif

#if R_VERSION >= R_Version(4, 5, 0)
# define RCPP_VECTOR_PTR VECTOR_PTR_RO
#else
# define RCPP_VECTOR_PTR VECTOR_PTR
#endif

#endif /* RCPP_R_COMPAT_H */
