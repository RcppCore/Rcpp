// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// class_stop.h: Rcpp R/C++ interface class library -- preprocessor helpers
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

#ifndef __RCPP__COLLECTOR
#error "unpaired RCPP_CLASS_START/RCPP_CLASS_STOP"
#else
#undef __RCPP_BOOTSTRAP
#define __RCPP_BOOTSTRAP RCPP_PP_CAT(__rcpp__class__bootstrap__,RCPP_CLASS)
extern "C" __RCPP_BOOTSTRAP(){
	return ::Rcpp::wrap( __RCPP__COLLECTOR ) ;	
}
#undef __RCPP_BOOTSTRAP
#undef __RCPP__COLLECTOR
#undef RCPP_CLASS
#undef RCPP_REGISTER
#undef RCPP_METHOD
#define RCPP_REGISTER(__NAME__) 
#endif

