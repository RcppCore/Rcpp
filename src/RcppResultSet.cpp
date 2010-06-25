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

RcppResultSet::RcppResultSet() : numProtected(0) { }

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

void RcppResultSet::add(std::string name, RcppDate& date) {
    add__impl( name, date );
}

void RcppResultSet::add(std::string name, RcppDatetime& datetime) {
    add__impl( name, datetime );
}

void RcppResultSet::add(std::string name, double x) {
    add__impl( name, x );
}

void RcppResultSet::add(std::string name, int i) {
    add__impl( name, i );
}

void RcppResultSet::add(std::string name, std::string strvalue) {
    add__impl( name, strvalue );
}

void RcppResultSet::add(std::string name, double *vec, int len) {
	if (vec == 0)
	throw std::range_error("RcppResultSet::add: NULL double vector");
	add__impl( name, Rcpp::wrap( vec, vec + len) );
}

void RcppResultSet::add(std::string name, RcppDateVector& datevec) {
    add__impl( name, datevec ) ;
}

void RcppResultSet::add(std::string name, RcppDatetimeVector &dtvec) {
    add__impl( name, dtvec ) ;
}

void RcppResultSet::add(std::string name, RcppStringVector& stringvec) {
    add__impl( name, stringvec ) ;
}

void RcppResultSet::add(std::string name, int *vec, int len) {
	if (vec == 0)
	throw std::range_error("RcppResultSet::add: NULL int vector");
	add__impl( name, Rcpp::wrap( vec, vec + len) );
}

void RcppResultSet::add(std::string name, double **mat, int nx, int ny) {
    if (mat == 0)
	throw std::range_error("RcppResultSet::add: NULL double matrix");
	add__matrix( name, mat, nx, ny ) ;
}

void RcppResultSet::add(std::string name, int **mat, int nx, int ny) {
    if (mat == 0)
	throw std::range_error("RcppResultSet::add: NULL int matrix");
	add__matrix( name, mat, nx, ny ) ;
}

void RcppResultSet::add(std::string name, std::vector<std::string>& vec) {
    if (vec.size() == 0)
	throw std::range_error("RcppResultSet::add; zero length vector<string>");
	add__impl( name, vec ) ;   
}

void RcppResultSet::add(std::string name, std::vector<int>& vec) {
    if (vec.size() == 0)
	throw std::range_error("RcppResultSet::add; zero length vector<int>");
	add__impl( name, vec ) ;   
}

void RcppResultSet::add(std::string name, std::vector<double>& vec) {
    if (vec.size() == 0)
	throw std::range_error("RcppResultSet::add; zero length vector<double>");
	add__impl( name, vec ) ;   
}

void RcppResultSet::add(std::string name, std::vector<std::vector<int> >& mat) {
	add__matrix__std( name, mat ) ;
}

void RcppResultSet::add(std::string name, std::vector<std::vector<double> >& mat) {
	add__matrix__std( name, mat ) ;
}

void RcppResultSet::add(std::string name, RcppVector<int>& vec) {
	add__impl( name, vec ) ;
}

void RcppResultSet::add(std::string name, RcppVector<double>& vec) {
	add__impl( name, vec ) ;
}

void RcppResultSet::add(std::string name, RcppMatrix<int>& mat) {
    add__matrix( name, mat.cMatrix(), mat.getDim1(), mat.getDim2() ) ;
}

void RcppResultSet::add(std::string name, RcppMatrix<double>& mat) {
    add__matrix( name, mat.cMatrix(), mat.getDim1(), mat.getDim2() ) ;
}


void RcppResultSet::add(std::string name, RcppList &list) {
	add__impl( name, list ) ;
}

void RcppResultSet::add(std::string name, SEXP sexp, bool isProtected) {
    push_back(name, sexp);
    if (isProtected)
	numProtected++;
}

// FIXME: this code belongs to RcppFrame::operator SEXP
void RcppResultSet::add(std::string name, RcppFrame& frame) {
    std::vector<std::string> colNames = frame.getColNames();
    std::vector<std::vector<ColDatum> > table = frame.getTableData();
    int ncol = colNames.size();
    int nrow = table.size();
    SEXP rl = PROTECT(Rf_allocVector(VECSXP,ncol));
    SEXP nm = PROTECT(Rf_allocVector(STRSXP,ncol));
    numProtected += 2;
    for (int i=0; i < ncol; i++) {
	SEXP value, names;
	if (table[0][i].getType() == COLTYPE_DOUBLE) {
	    value = PROTECT(Rf_allocVector(REALSXP,nrow));
	    numProtected++;
	    for (int j=0; j < nrow; j++)
		REAL(value)[j] = table[j][i].getDoubleValue();
	} else if (table[0][i].getType() == COLTYPE_INT) {
	    value = PROTECT(Rf_allocVector(INTSXP,nrow));
	    numProtected++;
	    for (int j=0; j < nrow; j++)
		INTEGER(value)[j] = table[j][i].getIntValue();
	} else if (table[0][i].getType() == COLTYPE_FACTOR) {
	    value = PROTECT(Rf_allocVector(INTSXP,nrow));
	    numProtected++;
	    int levels = table[0][i].getFactorNumLevels();
	    names = PROTECT(Rf_allocVector(STRSXP,levels));
	    numProtected++;
	    std::string *levelNames = table[0][i].getFactorLevelNames();
	    for (int k=0; k < levels; k++)
		SET_STRING_ELT(names, k, Rf_mkChar(levelNames[k].c_str()));
	    for (int j=0; j < nrow; j++) {
		int level = table[j][i].getFactorLevel();
		INTEGER(value)[j] = level;
	    }
	    Rf_setAttrib(value, R_LevelsSymbol, names);
	    SEXP factorclass = PROTECT(Rf_allocVector(STRSXP,1));
	    numProtected++;
	    SET_STRING_ELT(factorclass, 0, Rf_mkChar("factor"));
	    Rf_setAttrib(value, R_ClassSymbol, factorclass); 
	} else if (table[0][i].getType() == COLTYPE_STRING) {
	    value = PROTECT(Rf_allocVector(STRSXP,nrow));
	    numProtected++;
	    for (int j=0; j < nrow; j++) {
		SET_STRING_ELT(value, j, Rf_mkChar(table[j][i].getStringValue().c_str()));
	    }
	} else if (table[0][i].getType() == COLTYPE_LOGICAL) {
	    value = PROTECT(Rf_allocVector(LGLSXP,nrow));
	    numProtected++;
	    for (int j=0; j < nrow; j++) {
		LOGICAL(value)[j] = table[j][i].getLogicalValue();
	    }
	} else if (table[0][i].getType() == COLTYPE_DATE) {
	    value = PROTECT(Rf_allocVector(REALSXP,nrow));
	    numProtected++;
	    for (int j=0; j < nrow; j++)
		REAL(value)[j] = table[j][i].getDateRCode();
	    SEXP dateclass = PROTECT(Rf_allocVector(STRSXP,1));
	    numProtected++;
	    SET_STRING_ELT(dateclass, 0, Rf_mkChar("Date"));
	    Rf_setAttrib(value, R_ClassSymbol, dateclass); 
	} else if (table[0][i].getType() == COLTYPE_DATETIME) {
	    value = PROTECT(Rf_allocVector(REALSXP,nrow));
	    numProtected++;
	    for (int j=0; j < nrow; j++) {
		// we could access the seconds as the internal double via getDouble but it's
		// more proper to use the proper accessor (and if we ever added code ...)
		REAL(value)[j] = table[j][i].getDatetimeValue().getFractionalTimestamp();
	    }
	    Rf_setAttrib(value, R_ClassSymbol, Rcpp::internal::getPosixClasses() );
	} else {
	    throw std::range_error("RcppResultSet::add invalid column type");
	}
	SET_VECTOR_ELT(rl, i, value);
	SET_STRING_ELT(nm, i, Rf_mkChar(colNames[i].c_str()));
    }
    Rf_setAttrib(rl, R_NamesSymbol, nm);
    push_back(name, rl);
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

