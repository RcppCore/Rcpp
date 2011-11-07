// LongVector.h : 64 bit integers
//
// Copyright (C) 2011 Romain Francois and Dirk Eddelbuettel
// Copyright (C) 2011 Google Inc.  All rights reserved.
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
  
#ifndef Rcpp__int64__LongVector_h
#define Rcpp__int64__LongVector_h

namespace Rcpp{
    namespace int64{

template <class LONG>
    class LongVector {
    private :
        SEXP data ;
        
    public:
        LongVector(SEXP x) : data(R_NilValue) {
            if( Rf_inherits( x, get_class<LONG>().c_str() ) ){
                data = x ;
                R_PreserveObject(data) ;
            } else {
                switch( TYPEOF(x) ){
                    case INTSXP:
                        {
                            int n = Rf_length(x) ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            int* p_i_x = INTEGER(x) ;
                            for( int i=0; i<n; i++){
                                tmp = (LONG) p_i_x[i] ;
                                hb = get_high_bits<LONG>(tmp) ;
                                lb = get_low_bits<LONG>(tmp) ;
                                SET_VECTOR_ELT( y, i, Rcpp::int64::int2(hb,lb) ) ;    
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            break ;
                        }
                    case REALSXP: 
                        {
                            int n = Rf_length(x) ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            double* p_d_x = REAL(x) ;
                            for( int i=0; i<n; i++){
                                tmp = (LONG) p_d_x[i] ;
                                hb = get_high_bits<LONG>(tmp) ;
                                lb = get_low_bits<LONG>(tmp) ;
                                SET_VECTOR_ELT( y, i, Rcpp::int64::int2(hb,lb) ) ;    
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            break ;  
                        }
                    case STRSXP:
                        {
                            int n = Rf_length(x) ;
                            SEXP y = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
                            int hb, lb ;
                            LONG tmp ;
                            for( int i=0; i<n; i++){
                                tmp = read_string<LONG>( CHAR(STRING_ELT(x,i)) ) ;
                                hb = get_high_bits<LONG>(tmp) ;
                                lb = get_low_bits<LONG>(tmp) ;
                                SET_VECTOR_ELT( y, i, Rcpp::int64::int2(hb,lb) ) ;    
                            }
                            UNPROTECT(1) ; // y
                            data = y ;
                            R_PreserveObject(data) ;  
                            break ;        
                        }
                    default:
                        {
                            Rf_error( "unimplemented conversion" ) ;   
                        }
                }
            }
        }
        
        operator SEXP(){ 
            std::string klass = get_class<LONG>() ;
            SEXP res = PROTECT( 
                R_do_slot_assign( 
                    R_do_new_object( R_do_MAKE_CLASS( klass.c_str() ) ), 
                    Rf_install(".Data"), 
                    data ) ) ;
            UNPROTECT(1) ;
            return res ;    
        
        }
        
        LongVector(int n) : data(R_NilValue) {
            SEXP x = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
            for( int i=0; i<n; i++){
                SET_VECTOR_ELT( x, i, Rcpp::int64::int2(0,0) ) ;    
            }
            UNPROTECT(1) ; // x
            data = x ;
            R_PreserveObject(data) ;
        }
        
        template <typename ITERATOR>
        LongVector(int n, ITERATOR start, ITERATOR end) : data(R_NilValue) {
            SEXP x = PROTECT( Rf_allocVector( VECSXP, n ) ) ;
            int hb, lb ;
            for( int i=0; i<n; i++, ++start){
                hb = get_high_bits<LONG>(*start) ;
                lb = get_low_bits<LONG>(*start) ;
                SET_VECTOR_ELT( x, i, Rcpp::int64::int2(hb,lb) ) ;    
            }
            UNPROTECT(1) ; // x
            data = x ;
            R_PreserveObject(data) ;
        }
        
        
        ~LongVector(){
            if( !Rf_isNull(data)) R_ReleaseObject(data) ;   
        }
        
        inline LONG get(int i) const {
            int* p = INTEGER(VECTOR_ELT(data,i)) ;
            return Rcpp::int64::get_long<LONG>( p[0], p[1] ) ;
        }
        
        inline void set(int i, LONG x){
            int* p = INTEGER(VECTOR_ELT(data,i)) ;
            p[0] = Rcpp::int64::get_high_bits(x) ;
            p[1] = Rcpp::int64::get_low_bits(x) ;
        }
        
        inline int size() const { return Rf_length(data); }
        
    } ;

        
    }
}
#endif
