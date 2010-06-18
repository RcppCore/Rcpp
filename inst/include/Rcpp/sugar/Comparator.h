// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// LessThan.h: Rcpp R/C++ interface class library -- vector operators
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

#ifndef Rcpp__sugar__Comparator_h
#define Rcpp__sugar__Comparator_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, typename Operator, typename LHS_TYPE, typename RHS_TYPE>
class Comparator : public ::Rcpp::VectorBase< LGLSXP, true, Comparator<RTYPE,Operator,LHS_TYPE,RHS_TYPE> > {
public:
	typedef typename traits::storage_type<RTYPE>::type STORAGE ;
	typedef r_binary_op<RTYPE,Operator> R_OPERATOR ;
	
	Comparator( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_) : 
		op(), lhs(lhs_), rhs(rhs_){}
	
	inline int operator[]( int i ) const {
		return op.compare( lhs[i], rhs[i] ) ;
	}
	
	inline int size() const { return lhs.size() ; }
	
private:
	R_OPERATOR op ;
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	
} ;

}
}


#endif
