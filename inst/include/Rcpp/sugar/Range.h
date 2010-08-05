// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Range.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPP_SUGAR_RANGE_H
#define RCPP_SUGAR_RANGE_H

namespace Rcpp{

	class Range : public VectorBase<INTSXP,false, Range >{
	public:
		Range( int start_, int end__ ) throw(std::range_error) : start(start_), end_(end__){
			if( start_ > end__ ){
				throw std::range_error( "upper value must be greater than lower value" ) ;
			}
		}
		
		inline int size() const{
			return end_ - start + 1;
		}
		
		inline int operator[]( int i) const {
			return start + i ;
		}
		
	private:
		int start ;
		int end_ ;
	} ;
	
} 

#endif
