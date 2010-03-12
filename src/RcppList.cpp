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

#include <RcppList.h>

RcppList::RcppList(void) : listArg(R_NilValue), 
			   listSize(0), 
			   currListPosn(0), 
			   numProtected(0) { 
}

RcppList::~RcppList(void) {
    UNPROTECT(numProtected);
}

void RcppList::setSize(int n) {
    listSize = n;
    listArg = PROTECT(Rf_allocVector(VECSXP, n));
    numProtected++;
}

void RcppList::append(std::string name, double value) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppList::append(double): list posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(REALSXP,1));
    numProtected++;
    REAL(valsxp)[0] = value;
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppList::append(std::string name, int value) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppList::append(int): posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(INTSXP,1));
    numProtected++;
    INTEGER(valsxp)[0] = value;
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppList::append(std::string name, std::string value) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppList::append(string): posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(STRSXP,1));
    numProtected++;
    SET_STRING_ELT(valsxp, 0, Rf_mkChar(value.c_str()));
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppList::append(std::string name, SEXP sexp) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppList::append(sexp): posn out of range");
    SET_VECTOR_ELT(listArg, currListPosn++, sexp);
    names.push_back(name);
}

void RcppList::clearProtectionStack() {
    UNPROTECT(numProtected);
    numProtected = 0;
}

SEXP RcppList::getList(void) const { 
    SEXP li = PROTECT(Rf_allocVector(VECSXP, listSize));
    SEXP nm = PROTECT(Rf_allocVector(STRSXP, listSize));
    for (int i=0; i<listSize; i++) {
	SET_VECTOR_ELT(li, i, VECTOR_ELT(listArg, i));
	SET_STRING_ELT(nm, i, Rf_mkChar(names[i].c_str()));
    }
    Rf_setAttrib(li, R_NamesSymbol, nm);
    UNPROTECT(2);
    return li; 
}


