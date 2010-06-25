// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppList.h: Rcpp.h: R/C++ interface class library -- 'list' type support
//
// Copyright (C) 2009 Dirk Eddelbuettel
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

#include <classic/RcppList.h>

RcppList::RcppList(void) : listArg(R_NilValue), 
			   listSize(0), 
			   currListPosn(0), 
			   numProtected(0) { 
}

RcppList::~RcppList(void) {
    clearProtectionStack() ;
}

void RcppList::setSize(int n) {
	// FIXME: this should clear the protection stack
    listSize = n;
    listArg = PROTECT(Rf_allocVector(VECSXP, n));
    numProtected++;
}

void RcppList::clearProtectionStack() {
    UNPROTECT(numProtected);
    numProtected = 0;
}

SEXP RcppList::getList(void) const { 
    SEXP li = PROTECT(Rf_duplicate( listArg )) ;
    Rf_setAttrib(li, R_NamesSymbol, Rcpp::wrap(names) );
    UNPROTECT(1) ;
    return li; 
}


