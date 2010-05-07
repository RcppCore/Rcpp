// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// class_start.h: Rcpp R/C++ interface class library -- preprocessor helpers
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

// no ifdef protection on purpose

#undef RCPP_REGISTER 

#ifndef RCPP_CLASS
#error "the macro RCPP_CLASS must be defined to use the RCPP_CLASS_START"
#else
#define __RCPP__COLLECTOR RCPP_PP_CAT(rcpp__collector__, RCPP_CLASS)
#define RCPP_METHOD(__METHOD__) RCPP_PP_CAT( RCPP_CLASS, RCPP_PP_CAT(__,__METHOD__ ))
static std::vector<std::string> __RCPP__COLLECTOR ;
#define RCPP_REGISTER(__NAME__) __RCPP__COLLECTOR.push_back( #__NAME__ ) ;
#endif

