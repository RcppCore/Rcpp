// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// preprocessor.h: Rcpp R/C++ interface class library -- pre processor help
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

#ifndef Rcpp__PREPROCESSOR_h
#define Rcpp__PREPROCESSOR_h

#define RCPP_DECORATE(__FUN__) __FUN__##__rcpp__wrapper__

namespace Rcpp{
namespace internal{	
	class converter {
	public:
		converter( ) : x(R_NilValue){} ;
		converter( SEXP x_) : x(x_){} ;
		converter( const converter& other) : x(other.x){}
		converter& operator=( const converter& other){
			x = other.x ;
			return *this ;
		}
		~converter(){}
	
		template <typename T> operator T(){
			return ::Rcpp::as<T>( x ) ;	
		}
	private:
		SEXP x ;
		
	} ;
} // namespace internal
} // namespace Rcpp

#ifndef BEGIN_RCPP
#define BEGIN_RCPP try{ 
#endif 

#ifndef END_RCPP
#define END_RCPP } catch( std::exception& __ex__ ){ forward_exception_to_r( __ex__ ) ; } catch(...){ ::Rf_error( "c++ exception (unknown reason)" ) ; }
#endif

#include <Rcpp/preprocessor_generated.h>

#define RCPP_XP_FIELD_GET(__NAME__,__CLASS__,__FIELD__)        \
extern "C" SEXP __NAME__( SEXP xp ){                           \
	SEXP res = R_NilValue ;                                    \
	BEGIN_RCPP                                                 \
		::Rcpp::XPtr<__CLASS__> ptr(xp) ;                      \
		res = ::Rcpp::wrap( ptr->__FIELD__ ) ;                 \
	END_RCPP                                                   \
	return res ;                                               \
}

#define RCPP_XP_FIELD_SET(__NAME__,__CLASS__,__FIELD__)        \
extern "C" SEXP __NAME__( SEXP xp, SEXP value ){               \
	BEGIN_RCPP                                                 \
		::Rcpp::XPtr<__CLASS__> ptr(xp) ;                      \
		ptr->__FIELD__ = ::Rcpp::internal::converter(value) ;  \
	END_RCPP                                                   \
	return R_NilValue ;                                        \
}

#define RCPP_XP_FIELD(__PREFIX__,__CLASS__,__FIELD__)          \
RCPP_XP_FIELD_GET( __PREFIX__##_get, __CLASS__, __FIELD__ )    \
RCPP_XP_FIELD_SET( __PREFIX__##_set, __CLASS__, __FIELD__ )    


#define RCPP_TRAITS(__CLASS__,__SEXPTYPE__)                     \
namespace Rcpp{ namespace traits {                                \
template<> struct r_type_traits<__CLASS__>{                       \
	typedef r_type_primitive_tag r_category ;                     \
} ;                                                               \
template<> struct r_type_traits< std::pair< std::string , __CLASS__ > >{   \
	typedef r_type_pairstring_primitive_tag r_category ;          \
} ;                                                               \
template<> struct wrap_type_traits<__CLASS__>{                    \
	typedef wrap_type_primitive_tag wrap_category ;               \
} ;                                                               \
template<> struct r_sexptype_traits<__CLASS__>{                   \
	enum{ rtype = __SEXPTYPE__ } ;                                \
} ;                                                               \
} }
#define RCPP_ENUM_TRAITS(__ENUM__) RCPP_TRAITS(__ENUM__,INTSXP)


#define ___RCPP_HANDLE_CASE___( ___RTYPE___ , ___FUN___ , ___OBJECT___ , ___RCPPTYPE___ )	\
	case ___RTYPE___ :																	\
		return ___FUN___( ::Rcpp::___RCPPTYPE___< ___RTYPE___ >( ___OBJECT___ ) ) ;	
		         
#define ___RCPP_RETURN___( __FUN__, __SEXP__ , __RCPPTYPE__ )						\
	SEXP __TMP__ = __SEXP__ ;															\
	switch( TYPEOF( __TMP__ ) ){														\
		___RCPP_HANDLE_CASE___( INTSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( REALSXP , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( RAWSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( LGLSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( CPLXSXP , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( STRSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( VECSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( EXPRSXP , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
	default:																			\
		throw std::range_error( "not a vector" ) ;									\
	}

#define RCPP_RETURN_VECTOR( _FUN_, _SEXP_ )  ___RCPP_RETURN___( _FUN_, _SEXP_ , Vector ) 
#define RCPP_RETURN_MATRIX( _FUN_, _SEXP_ )  ___RCPP_RETURN___( _FUN_, _SEXP_ , Matrix )


#endif
