// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// logical_operators__Vector__primitive.h: Rcpp R/C++ interface class library -- 
//    logical operators for Vector to primitive comparisons
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

#ifndef Rcpp__sugar__logical_operators__Vector__primitive_h
#define Rcpp__sugar__logical_operators__Vector__primitive_h

/* Vector op primitive */
template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::less<RTYPE> > 
operator<( const Rcpp::Vector<RTYPE>& lhs , typename Rcpp::traits::storage_type<RTYPE>::type rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::less<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::greater<RTYPE> > 
operator>( const Rcpp::Vector<RTYPE>& lhs , typename Rcpp::traits::storage_type<RTYPE>::type rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::greater<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::less_or_equal<RTYPE> > 
operator<=( const Rcpp::Vector<RTYPE>& lhs , typename Rcpp::traits::storage_type<RTYPE>::type rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::less_or_equal<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::greater_or_equal<RTYPE> > 
operator>=( const Rcpp::Vector<RTYPE>& lhs , typename Rcpp::traits::storage_type<RTYPE>::type rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::greater_or_equal<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::equal<RTYPE> > 
operator==( const Rcpp::Vector<RTYPE>& lhs , typename Rcpp::traits::storage_type<RTYPE>::type rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::equal<RTYPE> >( 
		lhs, rhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::not_equal<RTYPE> > 
operator!=( const Rcpp::Vector<RTYPE>& lhs , typename Rcpp::traits::storage_type<RTYPE>::type rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::not_equal<RTYPE> >( 
		lhs, rhs
		) ;
}



/* primitive op Vector */
template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::greater<RTYPE> > 
operator<( typename Rcpp::traits::storage_type<RTYPE>::type lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::greater<RTYPE> >( 
		rhs, lhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::less<RTYPE> > 
operator>( typename Rcpp::traits::storage_type<RTYPE>::type lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::less<RTYPE> >( 
		rhs, lhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::greater_or_equal<RTYPE> > 
operator<=( typename Rcpp::traits::storage_type<RTYPE>::type lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::greater_or_equal<RTYPE> >( 
		rhs, lhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::less_or_equal<RTYPE> > 
operator>=( typename Rcpp::traits::storage_type<RTYPE>::type lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::less_or_equal<RTYPE> >( 
		rhs, lhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::equal<RTYPE> > 
operator==( typename Rcpp::traits::storage_type<RTYPE>::type lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::equal<RTYPE> >( 
		rhs, lhs
		) ;
}

template <int RTYPE>
inline Rcpp::sugar::Comparator_With_One_Value< RTYPE , Rcpp::sugar::not_equal<RTYPE> > 
operator!=( typename Rcpp::traits::storage_type<RTYPE>::type lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::sugar::Comparator_With_One_Value<RTYPE, Rcpp::sugar::not_equal<RTYPE> >( 
		rhs, lhs
		) ;
}

#endif
