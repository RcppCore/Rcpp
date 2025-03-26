// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// longlong.h: Rcpp R/C++ interface class library -- long long support
//
// Copyright (C) 2013 - 2017 Dirk Eddelbuettel and Romain Francois
// Copyright (C) 2018 - 2025 Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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

#ifndef RCPP_LONG_LONG_H
#define RCPP_LONG_LONG_H

typedef long long int rcpp_long_long_type;
typedef unsigned long long int rcpp_ulong_long_type;
# define RCPP_HAS_LONG_LONG_TYPES

#endif
