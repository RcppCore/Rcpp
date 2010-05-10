// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Dimension.h: Rcpp R/C++ interface class library -- dimensions
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

#ifndef Rcpp_Dimension_h
#define Rcpp_Dimension_h

#include <RcppCommon.h>
 
namespace Rcpp{ 

class Dimension {
public:
	typedef std::vector<int>::reference reference ;
	typedef std::vector<int>::const_reference const_reference ;
	
	Dimension() ;
	Dimension(SEXP dims);
	Dimension( const Dimension& other ) ;
	Dimension& operator=( const Dimension& other ) ;
	Dimension(const size_t& n1) ;
	Dimension(const size_t& n1, const size_t& n2) ;
	Dimension(const size_t& n1, const size_t& n2, const size_t& n3) ;
	operator SEXP() const ;
	
	int size() const ;
	int prod() const ;
	
	reference operator[](int i) throw(std::range_error) ;
	const_reference operator[](int i) const throw(std::range_error) ;
	
private:
	std::vector<int> dims ;
} ;

}
#endif
