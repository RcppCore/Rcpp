// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// seq_along.h: Rcpp R/C++ interface class library -- any
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

#ifndef Rcpp__sugar__seq_along_h
#define Rcpp__sugar__seq_along_h

namespace Rcpp{
namespace sugar{

template <typename T>
class SeqAlong : public VectorBase< INTSXP,false,SeqAlong<T> > {
public:
	SeqAlong( int len_ ) : len(len_){}
	
	inline int operator[]( int i ) const {
		return 1 + i ;
	}
	inline int size() const { return len ; }
	         
private:
	const int len ;
} ;
	
} // sugar

template <int RTYPE, bool _NA_, typename T>
inline sugar::SeqAlong<T> seq_along( const Rcpp::VectorBase<RTYPE,_NA_,T>& t){
	return sugar::SeqAlong<T>( t.size() ) ;
}

} // Rcpp
#endif

