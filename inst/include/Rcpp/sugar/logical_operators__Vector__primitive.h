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

/* Vector < primitive */
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::less<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator<( 
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs , 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::less<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::less<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator>( 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs,
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::less<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}



/* Vector > primitive */
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::greater<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator>( 
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs , 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::greater<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::greater<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator<( 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs,
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::greater<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}



/* Vector <= primitive */
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::less_or_equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator<=( 
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs , 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::less_or_equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::less_or_equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator>=( 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs,
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs 
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::less_or_equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}




/* Vector >= primitive */
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::greater_or_equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator>=( 
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs , 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::greater_or_equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::greater_or_equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator<=( 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs,
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::greater_or_equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}



/* Vector == primitive */
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator==( 
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs , 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator==( 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs,
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}



/* Vector != primitive */
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::not_equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator!=( 
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs , 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::not_equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}
template <int RTYPE, bool na, typename VEC_TYPE>
inline Rcpp::sugar::Comparator_With_One_Value<
	RTYPE , 
	Rcpp::sugar::not_equal<RTYPE>, 
	na, 
	Rcpp::VectorBase<RTYPE,na,VEC_TYPE>
	> 
operator!=( 
	typename Rcpp::traits::storage_type<RTYPE>::type rhs,
	const Rcpp::VectorBase<RTYPE,na,VEC_TYPE>& lhs 
	){
	return Rcpp::sugar::Comparator_With_One_Value<
		RTYPE, 
		Rcpp::sugar::not_equal<RTYPE>, 
		na,
		Rcpp::VectorBase<RTYPE,na,VEC_TYPE> 
		>( 
			lhs, rhs
		) ;
}


#endif
