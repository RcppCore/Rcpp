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

#ifndef Rcpp__sugar__logical_operators_h
#define Rcpp__sugar__logical_operators_h

namespace Rcpp{
namespace sugar{

#undef RCPP_OP
#define RCPP_OP(NAME,OP)   	                                     \
template <int RTYPE>                                                \
class NAME {                                                        \
public:                                                             \
	typedef typename traits::storage_type<RTYPE>::type STORAGE ;    \
	inline bool compare_one( STORAGE lhs, STORAGE rhs) const {      \
		return lhs OP rhs ;                                         \
	}                                                               \
} ;
RCPP_OP(less,<)
RCPP_OP(greater,>)
RCPP_OP(less_or_equal,<=)
RCPP_OP(greater_or_equal,>=)
RCPP_OP(equal,==)
RCPP_OP(not_equal,!=)
#undef RCPP_OP

	
template <int RTYPE, typename T>
class r_binary_op : public T {
public:
	typedef typename traits::storage_type<RTYPE>::type STORAGE ;
	
	r_binary_op(){}
	
	inline int compare( STORAGE lhs, STORAGE rhs) const {
		return ( traits::is_na<RTYPE>(lhs) || traits::is_na<RTYPE>(rhs) ) ? 
		NA_LOGICAL : static_cast<int>( compare_one( lhs, rhs ) ) ;
	}
	
} ;


template <int RTYPE, typename Operator>
class Comparator : public LogicalResult< Comparator<RTYPE,Operator> > {
public:
	typedef Vector<RTYPE> VEC ;
	typedef typename traits::storage_type<RTYPE>::type STORAGE ;
	typedef r_binary_op<RTYPE,Operator> R_OPERATOR ;
	
	Comparator( const VEC& lhs_, const VEC& rhs_) : 
		op(), lhs(lhs_), rhs(rhs_){}
	
	inline int operator[]( int i ) const {
		return op.compare( lhs[i], rhs[i] ) ;
	}
	
	inline int size() const { return lhs.size() ; }
	
private:
	R_OPERATOR op ;
	const VEC& lhs ;
	const VEC& rhs ;
	
} ;


} // sugar
} // Rcpp


template <int RTYPE>
inline Rcpp::sugar::Comparator< RTYPE , Rcpp::sugar::less<RTYPE> > 
operator<( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator<RTYPE, Rcpp::sugar::less<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator< RTYPE , Rcpp::sugar::greater<RTYPE> > 
operator>( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator<RTYPE, Rcpp::sugar::greater<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator< RTYPE , Rcpp::sugar::less_or_equal<RTYPE> > 
operator<=( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator<RTYPE, Rcpp::sugar::less_or_equal<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator< RTYPE , Rcpp::sugar::greater_or_equal<RTYPE> > 
operator>=( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator<RTYPE, Rcpp::sugar::greater_or_equal<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator< RTYPE , Rcpp::sugar::equal<RTYPE> > 
operator==( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator<RTYPE, Rcpp::sugar::equal<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator< RTYPE , Rcpp::sugar::not_equal<RTYPE> > 
operator!=( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator<RTYPE, Rcpp::sugar::not_equal<RTYPE> >( 
		lhs, rhs
		) ;
}

#endif
