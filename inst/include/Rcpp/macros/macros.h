// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// macros.h: Rcpp R/C++ interface class library -- Rcpp macros
//    
// Copyright (C) 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_macros_macros_h
#define Rcpp_macros_macros_h

#include <Rcpp/macros/debug.h>
#include <Rcpp/macros/unroll.h>

#define RCPP_GET_NAMES(x)       Rf_getAttrib(x, R_NamesSymbol)
#define RCPP_GET_CLASS(x)       Rf_getAttrib(x, R_ClassSymbol)

#endif
