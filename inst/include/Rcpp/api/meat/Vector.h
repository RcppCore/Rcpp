// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Vector.h: Rcpp R/C++ interface class library -- Vector meat 
//
// Copyright (C) 2012    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_api_meat_Vector_h
#define Rcpp_api_meat_Vector_h

namespace Rcpp{ 

    template <int RTYPE>
    Vector<RTYPE>::Vector() : RObject() {
        RCPP_DEBUG( "Vector()" ) ;
        RObject::setSEXP( Rf_allocVector( RTYPE, 0 ) ) ;
        init() ;
    }
    
    template <int RTYPE>
    Vector<RTYPE>::~Vector(){
         RCPP_DEBUG( "~Vector()" )   
    }
    
    template <int RTYPE>
    Vector<RTYPE>::Vector( const Vector& other) : RObject(){
         RObject::setSEXP( other.asSexp() ) ;   
    }
    
    template <int RTYPE>
    Vector<RTYPE>& Vector<RTYPE>::operator=(const Vector& other){
        RObject::setSEXP( other.asSexp() ) ;
        return *this ;    
    }
    
    template <int RTYPE>
    Vector<RTYPE>::Vector( const int& size ) : RObject()  {
    	RCPP_DEBUG_2( "Vector<%d>( int = %d )", RTYPE, size ) ;
    	RObject::setSEXP( Rf_allocVector( RTYPE, size) ) ;
        init() ;
    }
    
    template <int RTYPE>
    Vector<RTYPE>::Vector( const Dimension& dims ) : RObject(){
        RObject::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
        init() ;
        if( dims.size() > 1 ){
            RObject::attr( "dim" ) = dims;
        }    
    }
    
    template <int RTYPE>
    template <typename U>
    Vector<RTYPE>::Vector( const Dimension& dims, const U& u) : RObject() {
    	RObject::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
        fill(u) ;
        if( dims.size() > 1 ){
            RObject::attr( "dim" ) = dims;
        }
    }
    
    template <int RTYPE>
    template <typename U>
    Vector<RTYPE>::Vector( const int& size, const U& u){
    	RObject::setSEXP( Rf_allocVector( RTYPE, size) ) ;
        fill_or_generate( u ) ;	
    }
    
    template <int RTYPE>
    template <typename U1>
    Vector<RTYPE>::Vector( const int& siz, stored_type (*gen)(U1), const U1& u1){
    	RObject::setSEXP( Rf_allocVector( RTYPE, siz) ) ;
        iterator first = begin(), last = end() ;
    	while( first != last ) *first++ = gen(u1) ;
    }
    
    template <int RTYPE>
    template <typename U1, typename U2>
    Vector<RTYPE>::Vector( const int& siz, stored_type (*gen)(U1,U2), const U1& u1, const U2& u2){
    	RObject::setSEXP( Rf_allocVector( RTYPE, siz) ) ;
        iterator first = begin(), last = end() ;
    	while( first != last ) *first++ = gen(u1,u2) ;
    }

    template <int RTYPE>
    template <typename U1, typename U2, typename U3>
    Vector<RTYPE>::Vector( const int& siz, stored_type (*gen)(U1,U2,U3), const U1& u1, const U2& u2, const U3& u3){
    	RObject::setSEXP( Rf_allocVector( RTYPE, siz) ) ;
        iterator first = begin(), last = end() ;
    	while( first != last ) *first++ = gen(u1,u2,u3) ;
    }

    template <int RTYPE>
    template <typename InputIterator>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last) : RObject( ){
        int n = std::distance(first, last) ;
        RObject::setSEXP( Rf_allocVector(RTYPE, n) ) ;
        std::copy( first, last, begin() ) ; 
    }

    template <int RTYPE>
    template <typename InputIterator>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last, int n) : RObject( ){
        RObject::setSEXP( Rf_allocVector(RTYPE, n) ) ;
        std::copy( first, last, begin() ) ; 
    }

    template <int RTYPE>
    template <typename InputIterator, typename Func>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last, Func func) : RObject( ){
        RObject::setSEXP( Rf_allocVector( RTYPE, std::distance(first,last) ) ) ;
        std::transform( first, last, begin(), func) ;
    }
    
    template <int RTYPE>
    template <typename InputIterator, typename Func>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last, Func func, int n) : RObject(  ){
        RObject::setSEXP( Rf_allocVector( RTYPE, n ) ) ;
        std::transform( first, last, begin(), func) ;
    }

    
    template <int RTYPE>
    template <bool NA, typename VEC>
    Vector<RTYPE>::Vector( const VectorBase<RTYPE,NA,VEC>& other ) : RObject() {
    	import_sugar_expression( other, typename traits::same_type<Vector,VEC>::type() ) ;
    }
    
    template <>
    template <bool NA, typename T>
    Vector<LGLSXP>::Vector( const sugar::SingleLogicalResult<NA,T>& obj ) : RObject() {
    	RObject::setSEXP( const_cast<sugar::SingleLogicalResult<NA,T>&>( obj ) .get_sexp() ) ;
    }
    
    
    template <int RTYPE>
    template <typename T> 
    Vector<RTYPE>& Vector<RTYPE>::operator=( const T &x ){
        assign_object( x, typename traits::is_sugar_expression<T>::type() ) ;
        return *this ;
    }
    
    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::assign_sugar_expression( const T& x ){
        int n = size() ;
        if( n == x.size() ){
            // just copy the data 
            import_expression<T>(x, n ) ;
        } else{
            // different size, so we change the memory
            RObject::setSEXP( r_cast<RTYPE>( wrap(x) ) ); 
        }
    }
    
    // sugar
    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::assign_object( const T& x, traits::true_type ){
        assign_sugar_expression( x.get_ref() ) ;
    }
    
    // anything else
    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::assign_object( const T& x, traits::false_type ){
        // TODO: maybe we already have the memory to host the results
        RObject::setSEXP( r_cast<RTYPE>( wrap(x) ) ) ;
    }
    
    template <int RTYPE>
    template <bool NA, typename VEC>
    inline void Vector<RTYPE>::import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::false_type ){
        RCPP_DEBUG_4( "Vector<%d>::import_sugar_expression( VectorBase<%d,%d,%s>, false_type )", RTYPE, NA, RTYPE, DEMANGLE(VEC) ) ;
    	int n = other.size() ;
    	RObject::setSEXP( Rf_allocVector( RTYPE, n ) ) ;
    	import_expression<VEC>( other.get_ref() , n ) ;
    }   
    
    template <int RTYPE>
    template <bool NA, typename VEC>
    inline void Vector<RTYPE>::import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::true_type ){
        RCPP_DEBUG_4( "Vector<%d>::import_sugar_expression( VectorBase<%d,%d,%s>, true_type )", RTYPE, NA, RTYPE, DEMANGLE(VEC) ) ;
    	RObject::setSEXP( other.get_ref() ) ;
    }   

    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::import_expression( const T& other, int n ){
        iterator start = begin() ; 
        RCPP_LOOP_UNROLL(start,other)
    }
    
    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::fill_or_generate( const T& t){
    	fill_or_generate__impl( t, typename traits::is_generator<T>::type() ) ;
    }
    
    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::fill_or_generate__impl( const T& gen, traits::true_type){
    	iterator first = begin() ;
    	iterator last = end() ;
    	while( first != last ) *first++ = gen() ;
    }
    
    template <int RTYPE>
    template <typename T>
    inline void Vector<RTYPE>::fill_or_generate__impl( const T& t, traits::false_type){
    	fill(t) ;
    }
    
    
} // namespace Rcpp

#endif
