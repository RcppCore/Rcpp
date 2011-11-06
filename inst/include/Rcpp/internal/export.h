// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// export.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__internal__export__h
#define Rcpp__internal__export__h

namespace Rcpp{
    namespace internal{

        /* iterating */
        
        template <typename InputIterator, typename value_type>
        void export_range__impl( SEXP x, InputIterator first, ::Rcpp::traits::false_type ) {
	    const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
	    typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	    SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
	    STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
	    std::copy( start, start + ::Rf_length(y), first ) ;
	    UNPROTECT(1) ;
        }
        
        template <typename InputIterator, typename value_type>
        void export_range__impl( SEXP x, InputIterator first, ::Rcpp::traits::true_type ) {
	    const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
	    typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	    SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
	    STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
	    std::transform( start, start + ::Rf_length(y) , first, caster<STORAGE,value_type> ) ;
	    UNPROTECT(1) ;
        }
        
        template <typename InputIterator, typename value_type>
        void export_range__dispatch( SEXP x, InputIterator first, ::Rcpp::traits::r_type_primitive_tag ) {
	    export_range__impl<InputIterator,value_type>(
							 x, 
							 first,
							 typename ::Rcpp::traits::r_sexptype_needscast<value_type>() );
        }
        
        template <typename InputIterator, typename value_type>
        void export_range__dispatch( SEXP x, InputIterator first, ::Rcpp::traits::r_type_string_tag ) {
	    if( ! ::Rf_isString( x) ) throw ::Rcpp::not_compatible( "expecting a string vector" ) ;
	    std::string buf ;
	    R_len_t n = ::Rf_length(x) ;
	    for( R_len_t i=0; i<n; i++, ++first ){
		*first = CHAR( STRING_ELT(x, i )) ;
	    }
        }
        
        /* iterators over int64_t */
        template <typename InputIterator, typename value_type>
        void export_range__dispatch( SEXP x, InputIterator first, ::Rcpp::traits::r_type_int64_tag ) {
        	int n = Rf_length(x) ;
        	if( Rf_inherits( x, "int64" ) ){
        		Rcpp::int64::LongVector<int64_t> data(x) ;
        		for( int i=0; i<n; i++, ++first){
        			*first = data.get(i) ;	
        		}
        	} else if( TYPEOF(x) == INTSXP ){
        		int* p_i_x = INTEGER(x) ;
        		for( int i=0; i<n; i++, ++first){
        			*first = (int64_t)p_i_x[i] ;	
        		}	
        	} else if( TYPEOF(x) == REALSXP ){
        		double* p_d_x = REAL(x) ;
        		for( int i=0; i<n; i++, ++first){
        			*first = (int64_t)p_d_x[i] ;	
        		}	
        	}
        }
        
        /* iterators over uint64_t */
        template <typename InputIterator, typename value_type>
        void export_range__dispatch( SEXP x, InputIterator first, ::Rcpp::traits::r_type_uint64_tag ) {
        	int n = Rf_length(x) ;
        	if( Rf_inherits( x, "uint64" ) ){
        		Rcpp::int64::LongVector<uint64_t> data(x) ;
        		for( int i=0; i<n; i++, ++first){
        			*first = data.get(i) ;	
        		}
        	} else if( TYPEOF(x) == INTSXP ){
        		int* p_i_x = INTEGER(x) ;
        		for( int i=0; i<n; i++, ++first){
        			*first = (uint64_t)p_i_x[i] ;	
        		}	
        	} else if( TYPEOF(x) == REALSXP ){
        		double* p_d_x = REAL(x) ;
        		for( int i=0; i<n; i++, ++first){
        			*first = (uint64_t)p_d_x[i] ;	
        		}	
        	}
        }
        
        template <typename InputIterator>
        void export_range( SEXP x, InputIterator first ) {
	    export_range__dispatch<InputIterator,typename std::iterator_traits<InputIterator>::value_type>( 
													   x, 
													   first, 
													   typename ::Rcpp::traits::r_type_traits<typename std::iterator_traits<InputIterator>::value_type>::r_category() 
													    );
        }
        
        /* indexing */
        
        template <typename T, typename value_type>
        void export_indexing__impl( SEXP x, T& res, ::Rcpp::traits::false_type ) {
	    const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
	    typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	    SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
	    STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
	    R_len_t size = ::Rf_length(y)  ;
	    for( R_len_t i=0; i<size; i++){
		res[i] =  start[i] ;
	    }
	    UNPROTECT(1) ; /* y */
        }
        
        template <typename T, typename value_type>
        void export_indexing__impl( SEXP x, T& res, ::Rcpp::traits::true_type ) {
	    const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
	    typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	    SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
	    STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
	    R_len_t size = ::Rf_length(y)  ;
	    for( R_len_t i=0; i<size; i++){
		res[i] = caster<STORAGE,value_type>(start[i]) ;
	    }
	    UNPROTECT(1) ; /* y */
        }

        template <typename T, typename value_type>
        void export_indexing__dispatch( SEXP x, T& res, ::Rcpp::traits::r_type_primitive_tag ) {
	    export_indexing__impl<T,value_type>(
						x, 
						res,
						typename ::Rcpp::traits::r_sexptype_needscast<value_type>() );
        }
        
        template <typename T, typename value_type>
        void export_indexing__dispatch( SEXP x, T& res, ::Rcpp::traits::r_type_string_tag ) {
	    if( ! ::Rf_isString( x) ) throw Rcpp::not_compatible( "expecting a string vector" ) ;
	    std::string buf ;
	    R_len_t n = ::Rf_length(x) ;
	    for( R_len_t i=0; i<n; i++ ){
		res[i] = CHAR( STRING_ELT(x, i )) ;
	    }
        }
        
        /* indexing int64_t */
        template <typename T, typename value_type>
        void export_indexing__dispatch( SEXP x, T& res, ::Rcpp::traits::r_type_int64_tag ) {
        	int n = Rf_length(x) ;
        	if( Rf_inherits( x, "int64")){
        		Rcpp::int64::LongVector<int64_t> data(x) ;
        		for( int i=0; i<n; i++){
        			res[i] = data.get(i) ;
        		}
        	} else if( TYPEOF(x) == INTSXP ){
        		int* p_i_x = INTEGER(x) ;
        		for( int i=0; i<n; i++){
        			res[i] = (int64_t)p_i_x[i] ;	
        		}
        	} else if( TYPEOF(x) == REALSXP ){
        		double* p_d_x = REAL(x) ;
        		for( int i=0; i<n; i++){
        			res[i] = (int64_t)p_d_x[i] ;	
        		}
        	} else {
        		Rf_error( "expecting an int64 an integer or a numeric vector" );	
        	}
        }
        
        /* indexing int64_t */
        template <typename T, typename value_type>
        void export_indexing__dispatch( SEXP x, T& res, ::Rcpp::traits::r_type_uint64_tag ) {
        	int n = Rf_length(x) ;
        	if( Rf_inherits( x, "uint64")){
        		Rcpp::int64::LongVector<uint64_t> data(x) ;
        		for( int i=0; i<n; i++){
        			res[i] = data.get(i) ;
        		}
        	} else if( TYPEOF(x) == INTSXP ){
        		int* p_i_x = INTEGER(x) ;
        		for( int i=0; i<n; i++){
        			res[i] = (uint64_t)p_i_x[i] ;	
        		}
        	} else if( TYPEOF(x) == REALSXP ){
        		double* p_d_x = REAL(x) ;
        		for( int i=0; i<n; i++){
        			res[i] = (uint64_t)p_d_x[i] ;	
        		}
        	} else {
        		Rf_error( "expecting an uint64 an integer or a numeric vector" );	
        	}
        }
        
        
        template <typename T, typename value_type>
        void export_indexing( SEXP x, T& res ) {
	    export_indexing__dispatch<T,value_type>( 
						    x, 
						    res, 
						    typename ::Rcpp::traits::r_type_traits<value_type>::r_category() );
        }
        
    }
}

#endif
