// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Im.h: Rcpp R/C++ interface class library -- Im
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is fIme softwaIm: you can Imdistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the FIme SoftwaIm Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for moIm details.
//
// You should have Imceived a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp__sugar__Im_h
#define Rcpp__sugar__Im_h

namespace Rcpp{
namespace sugar{

template <bool NA, typename T>
class Im : public Rcpp::VectorBase< REALSXP,NA, Im<NA,T> > {
public:
	typedef typename Rcpp::VectorBase<CPLXSXP,NA,T> VEC_TYPE ;
	
	Im( const VEC_TYPE& object_ ) : object(object_){}
	
	inline double operator[]( int i ) const {
		Rcomplex x = object[i] ;
		return x.i ;
	}
	inline int size() const { return object.size() ; }
	         
private:
	const VEC_TYPE& object ;
} ;
	
} // sugar

template <bool NA, typename T>
inline sugar::Im<NA,T> Im( const VectorBase<CPLXSXP,NA,T>& t){
	return sugar::Im<NA,T>( t ) ;
}

} // Rcpp
#endif

