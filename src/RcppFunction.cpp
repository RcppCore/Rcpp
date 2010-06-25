// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppFunction.cpp: Rcpp R/C++ interface class library -- function support
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#include <RcppFunction.h>

RcppFunction::RcppFunction(SEXP fn_) : fn(fn_) { 
    if (!Rf_isFunction(fn))
	throw std::range_error("RcppFunction: non-function where function expected");
    numProtected = 0;
    currListPosn = 0;
    listSize = 0;
    vectorArg = listArg = R_NilValue;
}

RcppFunction::~RcppFunction() {
    UNPROTECT(numProtected);
}

SEXP RcppFunction::listCall() {
    if (names.size() != (unsigned)listSize)
	throw std::range_error("RcppFunction::listCall: no. of names != no. of items");
    if (currListPosn != listSize)
	throw std::range_error("RcppFunction::listCall: list has incorrect size");
    SEXP nm = PROTECT(Rf_allocVector(STRSXP,listSize));
    numProtected++;
    for (int i=0; i < listSize; i++)
	SET_STRING_ELT(nm, i, Rf_mkChar(names[i].c_str()));
    Rf_setAttrib(listArg, R_NamesSymbol, nm);
    SEXP R_fcall;
    PROTECT(R_fcall = Rf_lang2(fn, R_NilValue));
    numProtected++;
    SETCADR(R_fcall, listArg);
    SEXP result = Rf_eval(R_fcall, R_NilValue);
    names.clear();
    listSize = currListPosn = 0; // Ready for next call.
    return result;
}

SEXP RcppFunction::vectorCall() {
    if (vectorArg == R_NilValue)
	throw std::range_error("RcppFunction::vectorCall: vector has not been set");
    SEXP R_fcall;
    PROTECT(R_fcall = Rf_lang2(fn, R_NilValue));
    numProtected++;
    SETCADR(R_fcall, vectorArg);
    SEXP result = Rf_eval(R_fcall, R_NilValue);
    vectorArg = R_NilValue; // Ready for next call.
    return result;
}

void RcppFunction::setRVector(std::vector<double>& v) {
    vectorArg = PROTECT(Rf_allocVector(REALSXP,v.size()));
    numProtected++;
    for (int i=0; i < (int)v.size(); i++)
	REAL(vectorArg)[i] = v[i];
}

void RcppFunction::setRListSize(int n) {
    listSize = n;
    listArg = PROTECT(Rf_allocVector(VECSXP, n));
    numProtected++;
}

void RcppFunction::appendToRList(std::string name, double value) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppFunction::appendToRList(double): list posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(REALSXP,1));
    numProtected++;
    REAL(valsxp)[0] = value;
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppFunction::appendToRList(std::string name, int value) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppFunction::appendToRlist(int): posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(INTSXP,1));
    numProtected++;
    INTEGER(valsxp)[0] = value;
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppFunction::appendToRList(std::string name, std::string value) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppFunction::appendToRlist(string): posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(STRSXP,1));
    numProtected++;
    SET_STRING_ELT(valsxp, 0, Rf_mkChar(value.c_str()));
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppFunction::appendToRList(std::string name, RcppDate& date) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppFunction::appendToRlist(RcppDate): list posn out of range");
    SEXP valsxp = PROTECT(Rf_allocVector(REALSXP,1));
    numProtected++;
    REAL(valsxp)[0] = date.getJDN() - RcppDate::Jan1970Offset;
    SEXP dateclass = PROTECT(Rf_allocVector(STRSXP, 1));
    numProtected++;
    SET_STRING_ELT(dateclass, 0, Rf_mkChar("Date"));
    Rf_setAttrib(valsxp, R_ClassSymbol, dateclass);
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppFunction::appendToRList(std::string name, RcppDatetime& datetime) {
    if (currListPosn < 0 || currListPosn >= listSize)
	throw std::range_error("RcppFunction::appendToRlist(RcppDatetime): list posn out of range");
    SEXP valsxp = PROTECT(Rf_ScalarReal(datetime.getFractionalTimestamp()));
    numProtected++;
    Rf_setAttrib(valsxp, R_ClassSymbol, Rcpp::internal::getPosixClasses() );
    SET_VECTOR_ELT(listArg, currListPosn++, valsxp);
    names.push_back(name);
}

void RcppFunction::clearProtectionStack() {
    UNPROTECT(numProtected);
    numProtected = 0;
}
