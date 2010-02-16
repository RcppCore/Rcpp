// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// grow.cpp: Rcpp R/C++ interface class library -- grow a pairlist
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

#include <Rcpp/grow.h>

namespace Rcpp{

SEXP pairlist(){ return R_NilValue ; }

template<> SEXP grow<Named>(const Named& head, SEXP tail){
	SEXP x;
	x = PROTECT( Rf_cons( head.getSEXP(), tail) ) ;
	SET_TAG( x, Rf_install( head.getTag().c_str() ) ); 
	UNPROTECT(1); 
	return x; 
}

} //namespace Rcpp
