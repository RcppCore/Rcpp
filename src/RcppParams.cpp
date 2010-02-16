// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppParams.h: Rcpp R/C++ interface class library -- Parameters from R
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

#include <RcppParams.h>

RcppParams::RcppParams(SEXP params) {
    if (!Rf_isNewList(params))
	throw std::range_error("RcppParams: non-list passed to constructor");
    int len = Rf_length(params);
    SEXP names = Rf_getAttrib(params, R_NamesSymbol);
    if (names == R_NilValue)
	throw std::range_error("RcppParams: list must have named elements");
    for (int i = 0; i < len; i++) {
	std::string nm = std::string(CHAR(STRING_ELT(names,i)));
	if (nm.size() == 0)
	    throw std::range_error("RcppParams: all list elements must be named");
	pmap[nm] = i;
    }
    _params = params;
}

void RcppParams::checkNames(char *inputNames[], int len) {
    for (int i = 0; i < len; i++) {
	std::map<std::string,int>::iterator iter = pmap.find(inputNames[i]);
	if (iter == pmap.end()) {
	    std::string mesg = "RcppParams::checkNames: missing required parameter ";
	    throw std::range_error(mesg+inputNames[i]);
	}
    }
}

bool RcppParams::exists(std::string name) {
    bool rc = true;
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
	rc = false;
    }
    return rc;
}

double RcppParams::getDoubleValue(std::string name) {
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
	std::string mesg = "RcppParams::getDoubleValue: no such name: ";
	throw std::range_error(mesg+name);
    }
    int posn = iter->second;
    SEXP elt = VECTOR_ELT(_params,posn);
    if (!Rf_isNumeric(elt) || Rf_length(elt) != 1) {
	std::string mesg = "RcppParams::getDoubleValue: must be scalar ";
	throw std::range_error(mesg+name);
    }
    if (Rf_isInteger(elt))
	return (double)INTEGER(elt)[0];
    else if (Rf_isReal(elt))
	return REAL(elt)[0];
    else {
	std::string mesg = "RcppParams::getDoubleValue: invalid value for ";
	throw std::range_error(mesg+name);
    }
    return 0; // never get here
}

int RcppParams::getIntValue(std::string name) {
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
	std::string mesg = "RcppParams::getIntValue: no such name: ";
	throw std::range_error(mesg+name);
    }
    int posn = iter->second;
    SEXP elt = VECTOR_ELT(_params,posn);
    if (!Rf_isNumeric(elt) || Rf_length(elt) != 1) {
	std::string mesg = "RcppParams::getIntValue: must be scalar: ";
	throw std::range_error(mesg+name);
    }
    if (Rf_isInteger(elt))
	return INTEGER(elt)[0];
    else if (Rf_isReal(elt))
	return (int)REAL(elt)[0];
    else {
	std::string mesg = "RcppParams::getIntValue: invalid value for: ";
	throw std::range_error(mesg+name);
    }
    return 0; // never get here
}

std::string RcppParams::getStringValue(std::string name) {
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
	std::string mesg = "RcppParams::getStringValue: no such name: ";
	throw std::range_error(mesg+name);
    }
    int posn = iter->second;
    SEXP elt = VECTOR_ELT(_params,posn);
    if (Rf_isString(elt))
		return std::string(CHAR(STRING_ELT(elt,0)));
    else {
	std::string mesg = "RcppParams::getStringValue: invalid value for: ";
	throw std::range_error(mesg+name);
    }
    return ""; // never get here
}

bool RcppParams::getBoolValue(std::string name) {
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
	std::string mesg = "RcppParams::getBoolValue: no such name: ";
	throw std::range_error(mesg+name);
    }
    int posn = iter->second;
    SEXP elt = VECTOR_ELT(_params,posn);
    if (Rf_isLogical(elt))
	return INTEGER(elt)[0];
    else {
	std::string mesg = "RcppParams::getBoolValue: invalid value for: ";
	throw std::range_error(mesg+name);
    }
    return false; // never get here
}

RcppDate RcppParams::getDateValue(std::string name) {
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
	std::string mesg = "RcppParams::getDateValue: no such name: ";
	throw std::range_error(mesg+name);
    }
    int posn = iter->second;
    SEXP elt = VECTOR_ELT(_params,posn);
    if (!Rf_isNumeric(elt) || Rf_length(elt) != 1) {
	std::string mesg = "RcppParams::getDateValue: invalide date: ";
	throw std::range_error(mesg+name);
    }

    int d;
    if (Rf_isReal(elt)) // R stores julian value in a double.
	d = (int)REAL(elt)[0];
    else {
	std::string mesg = "RcppParams::getDateValue: invalid value for: ";
	throw std::range_error(mesg+name);
    }
    return RcppDate(d);
}

RcppDatetime RcppParams::getDatetimeValue(std::string name) {
    std::map<std::string,int>::iterator iter = pmap.find(name);
    if (iter == pmap.end()) {
        std::string mesg = "RcppParams::getDatetimeValue: no such name: ";
	throw std::range_error(mesg+name);
    }
    int posn = iter->second;
    SEXP elt = VECTOR_ELT(_params, posn);
    if (!Rf_isNumeric(elt) || Rf_length(elt) != 1) {
	std::string mesg = "RcppParams::getDateValue: invalide date: ";
	throw std::range_error(mesg+name);
    }
    double d;
    if (Rf_isReal(elt)) 	// R stores POSIXt as a double
	d = REAL(elt)[0];
    else {
	std::string mesg = "RcppParams::getDatetimeValue: invalid value for: ";
	throw std::range_error(mesg+name);
    }
    return RcppDatetime(d);
}
