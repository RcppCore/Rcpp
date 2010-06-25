// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppResultSet.cpp: Rcpp R/C++ interface class library -- Results back to R
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
// Copyright (C) 2010	     Dirk Eddelbuettel and Romain Francois
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

#include <Rcpp.h>

RcppResultSet::RcppResultSet() : numProtected(0), values() { }

namespace Rcpp { 

    // template specialisation for wrap() on the date and datetime classes
    template <> SEXP wrap(const RcppDate &date) {
    return internal::new_date_object( date.getJDN() - RcppDate::Jan1970Offset ) ;
    }                                                

    template <> SEXP wrap(const RcppDatetime &datetime) {
    return internal::new_posixt_object( datetime.getFractionalTimestamp() ) ;
	}

    template <> SEXP wrap(const RcppDateVector& datevec) {
	SEXP value = PROTECT(Rf_allocVector(REALSXP, datevec.size()));
	double* p = REAL(value) ;
	for (int i = 0; i < datevec.size(); i++,p++) {
	    *p = datevec(i).getJDN() - RcppDate::Jan1970Offset;
	}
	Rf_setAttrib(value, R_ClassSymbol, Rf_mkString("Date")); 
	UNPROTECT(1);
	return value;
    }

    template <> SEXP wrap(const RcppDatetimeVector &dtvec) {
	SEXP value = PROTECT(Rf_allocVector(REALSXP, dtvec.size()));
	double* p = REAL(value) ;
	for (int i = 0; i < dtvec.size(); i++,p++) {
	    *p = dtvec(i).getFractionalTimestamp();
	}
	Rf_setAttrib(value, R_ClassSymbol, internal::getPosixClasses() ); 
	UNPROTECT(1);
	return value;
    }

}

void RcppResultSet::add(const std::string& name , SEXP x, bool){
	push_back( name, x ) ;
}

void RcppResultSet::add(const std::string& name , const std::vector<std::vector<double> >& object){
	add__matrix__std( name, object ) ;
}

void RcppResultSet::add(const std::string& name , const std::vector<std::vector<int> >& object){
	add__matrix__std( name, object ) ;
}
    
void RcppResultSet::add(const std::string& name, double *vec, int len) {
	if (vec == 0)
	throw std::range_error("RcppResultSet::add: NULL double vector");
	add__impl( name, Rcpp::wrap( vec, vec + len) );
}

void RcppResultSet::add(const std::string& name, int *vec, int len) {
	if (vec == 0)
	throw std::range_error("RcppResultSet::add: NULL int vector");
	add__impl( name, Rcpp::wrap( vec, vec + len) );
}

void RcppResultSet::add(const std::string& name, double **mat, int nx, int ny) {
    if (mat == 0)
	throw std::range_error("RcppResultSet::add: NULL double matrix");
	add__matrix( name, mat, nx, ny ) ;
}

void RcppResultSet::add(const std::string& name, int **mat, int nx, int ny) {
    if (mat == 0)
	throw std::range_error("RcppResultSet::add: NULL int matrix");
	add__matrix( name, mat, nx, ny ) ;
}

SEXP RcppResultSet::getReturnList() {
    SEXP rl = PROTECT( Rcpp::wrap( values ) ) ;
	UNPROTECT(numProtected+1);
    return rl;
}

SEXP RcppResultSet::getSEXP() {
    if (values.size() != 1) {
	throw std::range_error("RcppResultSet::getSEXP only sensible for single return arguments");
    }
    // FIXME: that looks soooo wrong
    //        is this ever used ?
    SEXP val = values.begin()->second;
    UNPROTECT(numProtected);
    return val;
}

