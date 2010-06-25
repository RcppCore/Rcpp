// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppResultSet.h: Rcpp R/C++ interface class library -- Results back to R
//
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

#ifndef RcppResultSet__backward_h
#define RcppResultSet__backward_h

template <typename T> 
void RcppResultSet::add__impl( const std::string& name, const T& t ){
	push_back( name, Rcpp::wrap(t) );
}

template <typename T> 
void RcppResultSet::add__matrix( const std::string& name, T** input, int nx, int ny ){
	Rcpp::Matrix< Rcpp::traits::r_sexptype_traits<T>::rtype > mat( nx, ny ) ;
	for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    mat[i + nx*j] = input[i][j];
    push_back( name, mat );
}

template <typename T> 
void RcppResultSet::add__matrix__std( const std::string& name, const std::vector<std::vector<T> >& mat ) throw(std::range_error) {
    int nx = (int)mat.size();
    if (nx == 0)
	throw std::range_error("RcppResultSet::add: zero length vector<vector<> >");
    
	int ny = (int)mat[0].size();
    if (ny == 0)
	throw std::range_error("RcppResultSet::add: no columns in vector<vector<> >");

	Rcpp::Matrix< Rcpp::traits::r_sexptype_traits<T>::rtype > out( nx, ny ) ;
	for (int i = 0; i < nx; i++)
	for (int j = 0; j < ny; j++)
	    out[i + nx*j] = mat[i][j];
    push_back( name, out );
}

#endif
