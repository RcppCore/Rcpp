// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exceptions.h: Rcpp R/C++ interface class library -- exceptions
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

#ifndef Rcpp__exceptions__h
#define Rcpp__exceptions__h

namespace Rcpp{

class not_a_matrix : public std::exception{
	public:
		not_a_matrix(){} ;
		virtual ~not_a_matrix() throw() {} ;
		virtual const char* what() const throw() { return "not a matrix" ; };
	} ;

class index_out_of_bounds: public std::exception{
   	public:
   		index_out_of_bounds() throw(){};
   		virtual ~index_out_of_bounds() throw(){};
   		virtual const char* what() const throw(){ return "index out of bounds" ; } ;
   	} ;
   		
	
} // namesapce Rcpp

#endif
