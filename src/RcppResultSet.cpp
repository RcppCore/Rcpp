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

#include <RcppResultSet.h>

RcppResultSet::RcppResultSet() : numProtected(0) { }

namespace Rcpp { 
SEXP wrap(RcppDate &date) {
    SEXP value = PROTECT(Rf_allocVector(REALSXP, 1));
    //numProtected++;
    REAL(value)[0] = date.getJDN() - RcppDate::Jan1970Offset;
    SEXP dateclass = PROTECT(Rf_allocVector(STRSXP,1));
    //numProtected++;
    SET_STRING_ELT(dateclass, 0, Rf_mkChar("Date"));
    Rf_setAttrib(value, R_ClassSymbol, dateclass); 
    UNPROTECT(2);
    return value;
}
}

void RcppResultSet::add(std::string name, RcppDate& date) {
    values.push_back(make_pair(name, Rcpp::wrap(date)));
}

namespace Rcpp { 
SEXP wrap(RcppDatetime &datetime) {
    SEXP value = PROTECT(Rf_allocVector(REALSXP, 1));
    //numProtected++;
    REAL(value)[0] = datetime.getFractionalTimestamp();
    SEXP datetimeclass = PROTECT(Rf_allocVector(STRSXP,2));
    //numProtected++;
    SET_STRING_ELT(datetimeclass, 0, Rf_mkChar("POSIXt"));
    SET_STRING_ELT(datetimeclass, 1, Rf_mkChar("POSIXct"));
    Rf_setAttrib(value, R_ClassSymbol, datetimeclass); 
    UNPROTECT(2);
    return value;
}
}

void RcppResultSet::add(std::string name, RcppDatetime& datetime) {
    values.push_back(make_pair(name, Rcpp::wrap(datetime)));
}

void RcppResultSet::add(std::string name, double x) {
    SEXP value = PROTECT(Rf_allocVector(REALSXP, 1));
    numProtected++;
    REAL(value)[0] = x;
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, int i) {
    SEXP value = PROTECT(Rf_allocVector(INTSXP, 1));
    numProtected++;
    INTEGER(value)[0] = i;
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, std::string strvalue) {
    SEXP value = PROTECT(Rf_allocVector(STRSXP, 1));
    numProtected++;
    SET_STRING_ELT(value, 0, Rf_mkChar(strvalue.c_str()));
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, double *vec, int len) {
    if (vec == 0)
	throw std::range_error("RcppResultSet::add: NULL double vector");
    SEXP value = PROTECT(Rf_allocVector(REALSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
	REAL(value)[i] = vec[i];
    values.push_back(make_pair(name, value));
}

namespace Rcpp { 
SEXP wrap(RcppDateVector& datevec) {
    SEXP value = PROTECT(Rf_allocVector(REALSXP, datevec.size()));
    //numProtected++;
    for (int i = 0; i < datevec.size(); i++) {
	REAL(value)[i] = datevec(i).getJDN() - RcppDate::Jan1970Offset;
    }
    SEXP dateclass = PROTECT(Rf_allocVector(STRSXP,1));
    //numProtected++;
    SET_STRING_ELT(dateclass, 0, Rf_mkChar("Date"));
    Rf_setAttrib(value, R_ClassSymbol, dateclass); 
    UNPROTECT(2);
    return value;
}
}

void RcppResultSet::add(std::string name, RcppDateVector& datevec) {
    values.push_back(make_pair(name, Rcpp::wrap(datevec)));
}

namespace Rcpp { 
SEXP wrap(RcppDatetimeVector &dtvec) {
    SEXP value = PROTECT(Rf_allocVector(REALSXP, dtvec.size()));
    //numProtected++;
    for (int i = 0; i < dtvec.size(); i++) {
	REAL(value)[i] = dtvec(i).getFractionalTimestamp();
    }
    SEXP datetimeclass = PROTECT(Rf_allocVector(STRSXP,2));
    //numProtected++;
    SET_STRING_ELT(datetimeclass, 0, Rf_mkChar("POSIXt"));
    SET_STRING_ELT(datetimeclass, 1, Rf_mkChar("POSIXct"));
    Rf_setAttrib(value, R_ClassSymbol, datetimeclass); 
    UNPROTECT(2);
    return value;
}
}

void RcppResultSet::add(std::string name, RcppDatetimeVector &dtvec) {
    values.push_back(make_pair(name, Rcpp::wrap(dtvec)));
}

void RcppResultSet::add(std::string name, RcppStringVector& stringvec) {
    int len = (int)stringvec.size();
    SEXP value = PROTECT(Rf_allocVector(STRSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
        SET_STRING_ELT(value, i, Rf_mkChar(stringvec(i).c_str()));
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, int *vec, int len) {
    if (vec == 0)
	throw std::range_error("RcppResultSet::add: NULL int vector");
    SEXP value = PROTECT(Rf_allocVector(INTSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
	INTEGER(value)[i] = vec[i];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, double **mat, int nx, int ny) {
    if (mat == 0)
	throw std::range_error("RcppResultSet::add: NULL double matrix");
    SEXP value = PROTECT(Rf_allocMatrix(REALSXP, nx, ny));
    numProtected++;
    for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    REAL(value)[i + nx*j] = mat[i][j];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, int **mat, int nx, int ny) {
    if (mat == 0)
	throw std::range_error("RcppResultSet::add: NULL int matrix");
    SEXP value = PROTECT(Rf_allocMatrix(INTSXP, nx, ny));
    numProtected++;
    for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    INTEGER(value)[i + nx*j] = mat[i][j];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, std::vector<std::string>& vec) {
    if (vec.size() == 0)
	throw std::range_error("RcppResultSet::add; zero length vector<string>");
    int len = (int)vec.size();
    SEXP value = PROTECT(Rf_allocVector(STRSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
        SET_STRING_ELT(value, i, Rf_mkChar(vec[i].c_str()));
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, std::vector<int>& vec) {
    if (vec.size() == 0)
	throw std::range_error("RcppResultSet::add; zero length vector<int>");
    int len = (int)vec.size();
    SEXP value = PROTECT(Rf_allocVector(INTSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
	INTEGER(value)[i] = vec[i];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, std::vector<double>& vec) {
    if (vec.size() == 0)
	throw std::range_error("RcppResultSet::add; zero length vector<double>");
    int len = (int)vec.size();
    SEXP value = PROTECT(Rf_allocVector(REALSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
	REAL(value)[i] = vec[i];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, std::vector<std::vector<int> >& mat) {
    if (mat.size() == 0)
	throw std::range_error("RcppResultSet::add: zero length vector<vector<int> >");
    else if (mat[0].size() == 0)
	throw std::range_error("RcppResultSet::add: no columns in vector<vector<int> >");
    int nx = (int)mat.size();
    int ny = (int)mat[0].size();
    SEXP value = PROTECT(Rf_allocMatrix(INTSXP, nx, ny));
    numProtected++;
    for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    INTEGER(value)[i + nx*j] = mat[i][j];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, std::vector<std::vector<double> >& mat) {
    if (mat.size() == 0)
	throw std::range_error("RcppResultSet::add: zero length vector<vector<double> >");
    else if (mat[0].size() == 0)
	throw std::range_error("RcppResultSet::add: no columns in vector<vector<double> >");
    int nx = (int)mat.size();
    int ny = (int)mat[0].size();
    SEXP value = PROTECT(Rf_allocMatrix(REALSXP, nx, ny));
    numProtected++;
    for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    REAL(value)[i + nx*j] = mat[i][j];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, RcppVector<int>& vec) {
    int len = vec.size();
    int *a = vec.cVector();
    SEXP value = PROTECT(Rf_allocVector(INTSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
	INTEGER(value)[i] = a[i];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, RcppVector<double>& vec) {
    int len = vec.size();
    double *a = vec.cVector();
    SEXP value = PROTECT(Rf_allocVector(REALSXP, len));
    numProtected++;
    for (int i = 0; i < len; i++)
	REAL(value)[i] = a[i];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, RcppMatrix<int>& mat) {
    int nx = mat.getDim1();
    int ny = mat.getDim2();
    int **a = mat.cMatrix();
    SEXP value = PROTECT(Rf_allocMatrix(INTSXP, nx, ny));
    numProtected++;
    for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    INTEGER(value)[i + nx*j] = a[i][j];
    values.push_back(make_pair(name, value));
}

void RcppResultSet::add(std::string name, RcppMatrix<double>& mat) {
    int nx = mat.getDim1();
    int ny = mat.getDim2();
    double **a = mat.cMatrix();
    SEXP value = PROTECT(Rf_allocMatrix(REALSXP, nx, ny));
    numProtected++;
    for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    REAL(value)[i + nx*j] = a[i][j];
    values.push_back(make_pair(name, value));
}

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
	    SEXP dateclass = PROTECT(Rf_allocVector(STRSXP,2));
	    numProtected++;
	    SET_STRING_ELT(dateclass, 0, Rf_mkChar("POSIXt"));
	    SET_STRING_ELT(dateclass, 1, Rf_mkChar("POSIXct"));
	    Rf_setAttrib(value, R_ClassSymbol, dateclass); 
	} else {
	    throw std::range_error("RcppResultSet::add invalid column type");
	}
	SET_VECTOR_ELT(rl, i, value);
	SET_STRING_ELT(nm, i, Rf_mkChar(colNames[i].c_str()));
    }
    Rf_setAttrib(rl, R_NamesSymbol, nm);
    values.push_back(make_pair(name, rl));
}

void RcppResultSet::add(std::string name, RcppList &list) {
    // we let RcppList export itself as a SEXP and send it along
    values.push_back(make_pair(name, list.getList()));
}

void RcppResultSet::add(std::string name, SEXP sexp, bool isProtected) {
    values.push_back(make_pair(name, sexp));
    if (isProtected)
	numProtected++;
}

SEXP RcppResultSet::getReturnList() {
    int nret = (int)values.size();
    SEXP rl = PROTECT(Rf_allocVector(VECSXP,nret));
    SEXP nm = PROTECT(Rf_allocVector(STRSXP,nret));
    std::list<std::pair<std::string,SEXP> >::iterator iter = values.begin();
    for (int i = 0; iter != values.end(); iter++, i++) {
	SET_VECTOR_ELT(rl, i, iter->second);
	SET_STRING_ELT(nm, i, Rf_mkChar(iter->first.c_str()));
    }
    Rf_setAttrib(rl, R_NamesSymbol, nm);
    UNPROTECT(numProtected+2);
    return rl;
}

SEXP RcppResultSet::getSEXP() {
    if (values.size() != 1) {
	throw std::range_error("RcppResultSet::getSEXP only sensible for single return arguments");
    }
    SEXP val = values.begin()->second;
    UNPROTECT(numProtected);
    return val;
}

