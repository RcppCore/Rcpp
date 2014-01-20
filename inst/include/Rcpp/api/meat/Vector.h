// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Vector.h: Rcpp R/C++ interface class library -- Vector meat 
//
// Copyright (C) 2012 - 2013    Dirk Eddelbuettel and Romain Francois
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

    template <int RTYPE, template <class> class StoragePolicy>
    Vector<RTYPE, StoragePolicy>::Vector() {
        Storage::set__( Rf_allocVector(RTYPE, 0 ) );
        init() ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <bool NA, typename VEC>
    Vector<RTYPE, StoragePolicy>::Vector( const VectorBase<RTYPE,NA,VEC>& other ) {
        RCPP_DEBUG_2( "Vector<%d>( const VectorBase<RTYPE,NA,VEC>& ) [VEC = %s]", RTYPE, DEMANGLE(VEC) )
        import_sugar_expression( other, typename traits::same_type<Vector,VEC>::type() ) ;
    }
        
    template <int RTYPE, template <class> class StoragePolicy>
    Vector<RTYPE, StoragePolicy>::Vector( const int& size ) {
        Storage::set__( Rf_allocVector( RTYPE, size) ) ;
        init() ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    Vector<RTYPE, StoragePolicy>::Vector( const Dimension& dims ) {
        Storage::set__( Rf_allocVector( RTYPE, dims.prod() ) ) ;
        init() ;
        if( dims.size() > 1 ){
            AttributeProxyPolicy<Vector>::attr( "dim" ) = dims;
        }
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename U>
    Vector<RTYPE, StoragePolicy>::Vector( const Dimension& dims, const U& u) {
        RCPP_DEBUG_2( "Vector<%d>( const Dimension& (%d), const U& )", RTYPE, dims.size() )
        Storage::set__( Rf_allocVector( RTYPE, dims.prod() ) ) ; 
        fill(u) ;
        if( dims.size() > 1 ){
            AttributeProxyPolicy<Vector>::attr( "dim" ) = dims;
        }
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename U>
    Vector<RTYPE, StoragePolicy>::Vector( const int& size, const U& u) {
        RCPP_DEBUG_2( "Vector<%d>( const int& size, const U& u )", RTYPE, size )
        Storage::set__( Rf_allocVector( RTYPE, size) ) ;
        fill_or_generate( u ) ;	
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename U1>
    Vector<RTYPE, StoragePolicy>::Vector( const int& siz, stored_type (*gen)(U1), const U1& u1) {
        Storage::set__( Rf_allocVector( RTYPE, siz) ) ;
        RCPP_DEBUG_2( "const int& siz, stored_type (*gen)(U1), const U1& u1 )", RTYPE, siz )
        iterator first = begin(), last = end() ;
        while( first != last ) *first++ = gen(u1) ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename U1, typename U2>
    Vector<RTYPE, StoragePolicy>::Vector( const int& siz, stored_type (*gen)(U1,U2), const U1& u1, const U2& u2) {
        Storage::set__( Rf_allocVector( RTYPE, siz) ) ;
        RCPP_DEBUG_2( "const int& siz, stored_type (*gen)(U1,U2), const U1& u1, const U2& u2)", RTYPE, siz )
        iterator first = begin(), last = end() ;
        while( first != last ) *first++ = gen(u1,u2) ;
    }

    template <int RTYPE, template <class> class StoragePolicy>
    template <typename U1, typename U2, typename U3>
    Vector<RTYPE, StoragePolicy>::Vector( const int& siz, stored_type (*gen)(U1,U2,U3), const U1& u1, const U2& u2, const U3& u3) {
        Storage::set__( Rf_allocVector( RTYPE, siz) ) ;
        RCPP_DEBUG_2( "const int& siz, stored_type (*gen)(U1,U2,U3), const U1& u1, const U2& u2, const U3& u3)", RTYPE, siz )
        iterator first = begin(), last = end() ;
        while( first != last ) *first++ = gen(u1,u2,u3) ;
    }

    template <int RTYPE, template <class> class StoragePolicy>
    template <typename InputIterator>
    Vector<RTYPE, StoragePolicy>::Vector( InputIterator first, InputIterator last) {
        RCPP_DEBUG_1( "Vector<%d>( InputIterator first, InputIterator last", RTYPE )
        Storage::set__( Rf_allocVector(RTYPE, std::distance(first, last) ) ) ;
        std::copy( first, last, begin() ) ; 
    }

    template <int RTYPE, template <class> class StoragePolicy>
    template <typename InputIterator>
    Vector<RTYPE, StoragePolicy>::Vector( InputIterator first, InputIterator last, int n) {
        Storage::set__(Rf_allocVector(RTYPE, n)) ; 
        RCPP_DEBUG_2( "Vector<%d>( InputIterator first, InputIterator last, int n = %d)", RTYPE, n )
        std::copy( first, last, begin() ) ; 
    }

    template <int RTYPE, template <class> class StoragePolicy>
    template <typename InputIterator, typename Func>
    Vector<RTYPE, StoragePolicy>::Vector( InputIterator first, InputIterator last, Func func) {
        Storage::set__( Rf_allocVector( RTYPE, std::distance(first,last) ) );
        RCPP_DEBUG_1( "Vector<%d>( InputIterator, InputIterator, Func )", RTYPE )
        std::transform( first, last, begin(), func) ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename InputIterator, typename Func>
    Vector<RTYPE, StoragePolicy>::Vector( InputIterator first, InputIterator last, Func func, int n) {
        Storage::set__( Rf_allocVector( RTYPE, n ) );
        RCPP_DEBUG_2( "Vector<%d>( InputIterator, InputIterator, Func, int n = %d )", RTYPE, n )
        std::transform( first, last, begin(), func) ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <bool NA, typename T>
    Vector<RTYPE, StoragePolicy>::Vector( const sugar::SingleLogicalResult<NA,T>& obj ) {
        Storage::set__( r_cast<RTYPE>( const_cast<sugar::SingleLogicalResult<NA,T>&>(obj).get_sexp() ) ) ;
        RCPP_DEBUG_2( "Vector<%d>( const sugar::SingleLogicalResult<NA,T>& ) [T = %s]", RTYPE, DEMANGLE(T) )
    }
    
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T> 
    Vector<RTYPE, StoragePolicy>& Vector<RTYPE, StoragePolicy>::operator=( const T &x ){
        assign_object( x, typename traits::is_sugar_expression<T>::type() ) ;
        return *this ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::assign_sugar_expression( const T& x ){
        int n = size() ;
        if( n == x.size() ){
            // just copy the data 
            import_expression<T>(x, n ) ;
        } else{
            // different size, so we change the memory
            Storage::set__( r_cast<RTYPE>( wrap(x) ) ); 
        }
    }
    
    // sugar
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::assign_object( const T& x, traits::true_type ){
        assign_sugar_expression( x.get_ref() ) ;
    }
    
    // anything else
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::assign_object( const T& x, traits::false_type ){
        Storage::set__( r_cast<RTYPE>( wrap(x) ) ) ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <bool NA, typename VEC>
    inline void Vector<RTYPE, StoragePolicy>::import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::false_type ){
        RCPP_DEBUG_4( "Vector<%d>::import_sugar_expression( VectorBase<%d,%d,%s>, false_type )", RTYPE, NA, RTYPE, DEMANGLE(VEC) ) ;
        int n = other.size() ;
        Storage::set__( Rf_allocVector( RTYPE, n ) ) ;
        import_expression<VEC>( other.get_ref() , n ) ;
    }   
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <bool NA, typename VEC>
    inline void Vector<RTYPE, StoragePolicy>::import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::true_type ){
        RCPP_DEBUG_4( "Vector<%d>::import_sugar_expression( VectorBase<%d,%d,%s>, true_type )", RTYPE, NA, RTYPE, DEMANGLE(VEC) ) ;
        Storage::set__( other.get_ref() ) ;
    }   

    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::import_expression( const T& other, int n ){
        iterator start = begin() ; 
        RCPP_LOOP_UNROLL(start,other)
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::fill_or_generate( const T& t){
        fill_or_generate__impl( t, typename traits::is_generator<T>::type() ) ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::fill_or_generate__impl( const T& gen, traits::true_type){
        iterator first = begin() ;
        iterator last = end() ;
        while( first != last ) *first++ = gen() ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename T>
    inline void Vector<RTYPE, StoragePolicy>::fill_or_generate__impl( const T& t, traits::false_type){
        fill(t) ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    typename Vector<RTYPE, StoragePolicy>::iterator Vector<RTYPE, StoragePolicy>::erase_single__impl( iterator position ){
        if( position < begin() || position > end() ) throw index_out_of_bounds( ) ;
        int n = size() ;
        Vector target( n - 1 ) ;
        iterator target_it(target.begin()) ;
        iterator it(begin()) ;
        iterator this_end(end()) ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        if( Rf_isNull(names) ){
            int i=0; 
            for( ; it < position; ++it, ++target_it, i++){
                *target_it = *it;
            }
            ++it ;
            for( ; it < this_end ; ++it, ++target_it){
                *target_it = *it;
            }
            Storage::set__( target.get__() ) ;
            return begin()+i ;
        } else {
            Shield<SEXP> newnames(::Rf_allocVector( STRSXP, n-1 ));
            int i= 0 ;
            for( ; it < position; ++it, ++target_it,i++){
                *target_it = *it;
                SET_STRING_ELT( newnames, i , STRING_ELT(names,i) ) ;
            }
            int result=i ;
            ++it ;
            i++ ;
            for( ; it < this_end ; ++it, ++target_it, i++){
                *target_it = *it;
                SET_STRING_ELT( newnames, i-1, STRING_ELT(names,i) ) ;
            }
            target.attr( "names" ) = newnames ;
            Storage::set__( target.get__() ) ;
            return begin()+result ;
        }
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    typename Vector<RTYPE, StoragePolicy>::iterator Vector<RTYPE, StoragePolicy>::erase_range__impl( iterator first, iterator last ){
        if( first > last ) throw std::range_error("invalid range") ;
        if( last > end() || first < begin() ) throw index_out_of_bounds() ;
		
        iterator it = begin() ;
        iterator this_end = end() ;
        int nremoved = std::distance(first,last) ;
        int target_size = size() - nremoved  ;
        Vector target( target_size ) ;
        iterator target_it = target.begin() ;
		
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        iterator result ;
        if( Rf_isNull(names) ){
            int i=0; 
            for( ; it < first; ++it, ++target_it, i++ ){
                *target_it = *it ;
            }
            result = begin() + i + 1 ;
            for( it = last ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else{
            Shield<SEXP> newnames( ::Rf_allocVector(STRSXP, target_size) ) ;
            int i= 0 ;
            for( ; it < first; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) );
            }
            result = begin() + i + 1 ;
            for( it = last ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i + nremoved ) );
            }
            target.attr("names" ) = newnames ;
        }
        Storage::set__( target.get__() ) ;
            
        return result ;
    }
    
 
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_back__impl(const stored_type& object, traits::false_type){
        int n = size() ;
        Vector target( n + 1 ) ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        if( Rf_isNull(names) ){
            for( ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else {
            Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n + 1) ) ;
            int i = 0 ;
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
            SET_STRING_ELT( newnames, i, Rf_mkChar("") ) ;
            target.attr("names") = newnames ;
        }
        *target_it = object;
        Storage::set__( target.get__() ) ;
            
    }	
    
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_back__impl(const stored_type& object, traits::true_type){
        Shield<SEXP> object_sexp( object ) ;
        int n = size() ;
        Vector target( n + 1 ) ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        if( Rf_isNull(names) ){
            for( ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else {
            Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n + 1) ) ;
            int i = 0 ;
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
            SET_STRING_ELT( newnames, i, Rf_mkChar("") ) ;
            target.attr("names") = newnames ;
        }
        *target_it = object_sexp;
        Storage::set__( target.get__() ) ;
    }	
    	
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_back_name__impl(const stored_type& object, const std::string& name, traits::false_type ){
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=0;
        if( Rf_isNull(names) ){
            Shield<SEXP> dummy( Rf_mkChar("") );
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , dummy );
            }
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
        }
        SET_STRING_ELT( newnames, i, Rf_mkChar( name.c_str() ) );
        target.attr("names") = newnames ;
    		
        *target_it = object;
        Storage::set__( target.get__() ) ;
    }
    	
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_back_name__impl(const stored_type& object, const std::string& name, traits::true_type ){
        Shield<SEXP> object_sexp( object ) ;
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=0;
        if( Rf_isNull(names) ){
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , R_BlankString );
            }
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
        }
        SET_STRING_ELT( newnames, i, Rf_mkChar( name.c_str() ) );
        target.attr("names") = newnames ;
    		
        *target_it = object_sexp;
        Storage::set__( target.get__() ) ;
    }
    	
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_front__impl(const stored_type& object, traits::false_type ){
        int n = size() ;
        Vector target( n+1);
        iterator target_it(target.begin());
        iterator it(begin());
        iterator this_end(end());
        *target_it = object ;
        ++target_it ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        if( Rf_isNull(names) ){
            for( ; it<this_end; ++it, ++target_it){
                *target_it = *it ;
            }
        } else{
            Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n + 1) );
            int i=1 ;
            SET_STRING_ELT( newnames, 0, Rf_mkChar("") ) ;
            for( ; it<this_end; ++it, ++target_it, i++){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
            target.attr("names") = newnames ;
        }
        Storage::set__( target.get__() ) ;
    }
    	
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_front__impl(const stored_type& object, traits::true_type ){
        Shield<SEXP> object_sexp( object ) ;
        int n = size() ;
        Vector target( n+1);
        iterator target_it(target.begin());
        iterator it(begin());
        iterator this_end(end());
        *target_it = object_sexp ;
        ++target_it ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        if( Rf_isNull(names) ){
            for( ; it<this_end; ++it, ++target_it){
                *target_it = *it ;
            }
        } else{
            Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n + 1) );
            int i=1 ;
            SET_STRING_ELT( newnames, 0, Rf_mkChar("") ) ;
            for( ; it<this_end; ++it, ++target_it, i++){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
            target.attr("names") = newnames ;
        }
        Storage::set__( target.get__() ) ;
    }
    	
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_front_name__impl(const stored_type& object, const std::string& name, traits::false_type ){
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=1;
        SET_STRING_ELT( newnames, 0, Rf_mkChar( name.c_str() ) );
        *target_it = object;
        ++target_it ;
    		
        if( Rf_isNull(names) ){
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , R_BlankString );
            }
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
        }
        target.attr("names") = newnames ;
    		
        Storage::set__( target.get__() ) ;
    }
    	
    template <int RTYPE, template <class> class StoragePolicy>
    void Vector<RTYPE, StoragePolicy>::push_front_name__impl(const stored_type& object, const std::string& name, traits::true_type ){
        Shield<SEXP> object_sexp(object) ;
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=1;
        SET_STRING_ELT( newnames, 0, Rf_mkChar( name.c_str() ) );
        *target_it = object_sexp;
        ++target_it ;
    		
        if( Rf_isNull(names) ){
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , R_BlankString );
            }
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
        }
        target.attr("names") = newnames ;
        Storage::set__( target.get__() ) ;
    }
    	
    template <int RTYPE, template <class> class StoragePolicy>
    typename Vector<RTYPE, StoragePolicy>::iterator Vector<RTYPE, StoragePolicy>::insert__impl( iterator position, const stored_type& object, traits::false_type){
        int n = size() ;
        Vector target( n+1 ) ;
        iterator target_it = target.begin();
        iterator it = begin() ;
        iterator this_end = end() ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        iterator result ;
        if( Rf_isNull(names) ){
            for( ; it < position; ++it, ++target_it){
                *target_it = *it ;
            }
            result = target_it;
            *target_it = object ; 
            ++target_it ;
            for( ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else{
            Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n + 1 ) ) ;
            int i=0;
            for( ; it < position; ++it, ++target_it, i++){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
            result = target_it;
            *target_it = object ;
            SET_STRING_ELT( newnames, i, ::Rf_mkChar("") ) ;
            i++ ;
            ++target_it ;
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i - 1) ) ;
            }
            target.attr( "names" ) = newnames ;
        }
        Storage::set__( target.get__() ) ;
        return result ;
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    typename Vector<RTYPE, StoragePolicy>::iterator Vector<RTYPE, StoragePolicy>::insert__impl( iterator position, const stored_type& object_, traits::true_type){
        Shield<SEXP> object( object_ ) ;
        int n = size() ;
        Vector target( n+1 ) ;
        iterator target_it = target.begin();
        iterator it = begin() ;
        iterator this_end = end() ;
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ;
        iterator result ;
        if( Rf_isNull(names) ){
            for( ; it < position; ++it, ++target_it){
                *target_it = *it ;
            }
            result = target_it;
            *target_it = object ; 
            ++target_it ;
            for( ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else{
            Shield<SEXP> newnames( ::Rf_allocVector( STRSXP, n + 1 ) ) ;
            int i=0;
            for( ; it < position; ++it, ++target_it, i++){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
            result = target_it;
            *target_it = object ;
            SET_STRING_ELT( newnames, i, ::Rf_mkChar("") ) ;
            i++ ;
            ++target_it ;
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i - 1) ) ;
            }
            target.attr( "names" ) = newnames ;
        }
        Storage::set__( target.get__() ) ;
        return result ;
    }
	
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename EXPR_VEC>
    Vector<RTYPE,StoragePolicy>& Vector<RTYPE, StoragePolicy>::operator+=( const VectorBase<RTYPE,true,EXPR_VEC>& rhs ){
        const EXPR_VEC& ref = rhs.get_ref() ;
        iterator start = begin() ;
        int n = size() ;
        // TODO: maybe unroll this
        stored_type tmp ;
        for( int i=0; i<n; i++){
            Proxy left = start[i] ;
            if( ! traits::is_na<RTYPE>( left ) ){
                tmp = ref[i] ;
                left = traits::is_na<RTYPE>( tmp ) ? tmp : ( left + tmp ) ;
            }
        }
        return *this ;  
    }
    
    template <int RTYPE, template <class> class StoragePolicy>
    template <typename EXPR_VEC>
    Vector<RTYPE,StoragePolicy>& Vector<RTYPE, StoragePolicy>::operator+=( const VectorBase<RTYPE,false,EXPR_VEC>& rhs ){
        const EXPR_VEC& ref = rhs.get_ref() ;
        iterator start = begin() ;
        int n = size() ;
        stored_type tmp ;
        for( int i=0; i<n; i++){
            if( ! traits::is_na<RTYPE>(start[i]) ){
                start[i] += ref[i] ;
            }
        }
        return *this ;  
    }
    
    // template <template <class> class StoragePolicy>
    // template <typename EXPR_VEC>
    // Vector<REALSXP,StoragePolicy>& Vector<REALSXP,StoragePolicy>::operator+=( const VectorBase<REALSXP,false,EXPR_VEC>& rhs ){
    //     const EXPR_VEC& vec = rhs.get_ref() ;
    //     int n = size() ;
    //     iterator start = begin() ;
    //     for( int i=0; i<n; i++){
    //         start[i] += vec[i] ;        
    //     }
    //     return *this ;
    // }
    
    // template <template <class> class StoragePolicy>
    // template <typename EXPR_VEC>
    // Vector<REALSXP,StoragePolicy>& Vector<REALSXP,StoragePolicy>::operator+=( const VectorBase<REALSXP,true,EXPR_VEC>& rhs ){
    //     const EXPR_VEC& vec = rhs.get_ref() ;
    //     int n = size() ;
    //     iterator start = begin() ;
    //     for( int i=0; i<n; i++){
    //         start[i] += vec[i] ;        
    //     }
    //     return *this ;
    // }
    
    
    template <int RTYPE, template <class> class StoragePolicy>
    bool Vector<RTYPE, StoragePolicy>::containsElementNamed( const char* target ) const {
        SEXP names = RCPP_GET_NAMES(Storage::get__()) ; 
        if( Rf_isNull(names) ) return false ;
        int n = Rf_length(names) ;
        for( int i=0; i<n; i++){
            if( !strcmp( target, CHAR(STRING_ELT(names, i)) ) ) 
                return true ;   
        }
        return false ;
    }
     
    namespace internal {
    
        template <typename T>
        inline SEXP wrap_range_sugar_expression( const T& object, Rcpp::traits::true_type) {
            RCPP_DEBUG_1( "wrap_range_sugar_expression<%s>(., true  )", DEMANGLE(T) )
            const int RTYPE = T::r_type::value ;
            return Rcpp::Vector<RTYPE>(object) ;
        }

    }
    
} // namespace Rcpp

#endif
