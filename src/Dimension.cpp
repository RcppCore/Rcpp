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

#include <Rcpp/Dimension.h>

namespace Rcpp{

	Dimension::Dimension() : dims(){}
	
	Dimension::Dimension(SEXP x): dims(){
		dims = as< std::vector<int> >(x) ;
	}
	
	Dimension::Dimension( const Dimension& other ) : dims(){
		dims = other.dims ; /* copy */
	}
	
	Dimension& Dimension::operator=(const Dimension& other){
		dims = other.dims ; /* copy */
		return *this ;
	}
	
	Dimension::Dimension(const size_t& n1) : dims(1){
		dims[0] = n1 ;
	}
	
	Dimension::Dimension(const size_t& n1, const size_t& n2) : dims(2){
		dims[0] = n1 ;
		dims[1] = n2 ;
	}
	
	Dimension::Dimension(const size_t& n1, const size_t& n2, const size_t& n3) : dims(3){
		dims[0] = n1 ;
		dims[1] = n2 ;
		dims[2] = n3 ;
	}
	
	Dimension::operator SEXP() const {
		return wrap( dims.begin(), dims.end() ) ;
	}
	
	int Dimension::size() const {
		return static_cast<int>( dims.size() ) ;
	}
	
	int Dimension::prod() const {
		return std::accumulate( dims.begin(), dims.end(), 1, std::multiplies<int>() ) ;
	}
	
	int& Dimension::operator[](int i) throw(std::range_error){
		if( i < 0 || i>=static_cast<int>(dims.size()) ) throw std::range_error("index out of bounds") ;
		return dims.at(i) ;
	}

} // namespace Rcpp
