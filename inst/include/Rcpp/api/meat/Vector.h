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

    template <int RTYPE>
    Vector<RTYPE>::Vector() : RObject( Rf_allocVector( RTYPE, 0 ) ) {
        RCPP_DEBUG( "Vector()" )
        update_vector() ;
        init() ;
    }
    
    template <int RTYPE>
    Vector<RTYPE>::~Vector(){
         RCPP_DEBUG_1( "~Vector(<%p>)", m_sexp )   
    }
    
    template <int RTYPE>
    Vector<RTYPE>::Vector( const Vector& other) : RObject(other.asSexp()){
        RCPP_DEBUG_2( "Vector<%d>( const Vector& other ), SEXP= <%p>", RTYPE, m_sexp )
        update_vector() ;
    }
    
    template <int RTYPE>
    Vector<RTYPE>& Vector<RTYPE>::operator=(const Vector& other){
        set_sexp( other.asSexp() ) ;
        return *this ;    
    }
    
    template <int RTYPE>
    Vector<RTYPE>::Vector( const int& size ) : RObject( Rf_allocVector( RTYPE, size) )  {
    	RCPP_DEBUG_3( "Vector<%d>( int = %d )   m_sexp = <%p> ", RTYPE, size, m_sexp )
    	update_vector(); 
    	init() ;
    }
    
    template <int RTYPE>
    Vector<RTYPE>::Vector( const Dimension& dims ) : RObject( Rf_allocVector( RTYPE, dims.prod() ) ){
        RCPP_DEBUG_3( "Vector<%s>( const Dimension& (%d) )   m_sexp = <%p>", sexp_to_name(RTYPE), dims.size(), m_sexp )
        update_vector();
        init() ;
        if( dims.size() > 1 ){
            RObject::attr( "dim" ) = dims;
        }
    }
    
    template <int RTYPE>
    template <typename U>
    Vector<RTYPE>::Vector( const Dimension& dims, const U& u) : RObject( Rf_allocVector( RTYPE, dims.prod() ) ) {
        RCPP_DEBUG_2( "Vector<%d>( const Dimension& (%d), const U& )", RTYPE, dims.size() )
        update_vector(); 
        fill(u) ;
        if( dims.size() > 1 ){
            RObject::attr( "dim" ) = dims;
        }
    }
    
    template <int RTYPE>
    template <typename U>
    Vector<RTYPE>::Vector( const int& size, const U& u): RObject( Rf_allocVector( RTYPE, size) ) {
        RCPP_DEBUG_2( "Vector<%d>( const int& size, const U& u )", RTYPE, size )
        update_vector() ;
        fill_or_generate( u ) ;	
    }
    
    template <int RTYPE>
    template <typename U1>
    Vector<RTYPE>::Vector( const int& siz, stored_type (*gen)(U1), const U1& u1) : RObject( Rf_allocVector( RTYPE, siz) ) {
        update_vector();
        RCPP_DEBUG_2( "const int& siz, stored_type (*gen)(U1), const U1& u1 )", RTYPE, siz )
        iterator first = begin(), last = end() ;
        while( first != last ) *first++ = gen(u1) ;
    }
    
    template <int RTYPE>
    template <typename U1, typename U2>
    Vector<RTYPE>::Vector( const int& siz, stored_type (*gen)(U1,U2), const U1& u1, const U2& u2) : RObject(Rf_allocVector( RTYPE, siz)){
        update_vector();
        RCPP_DEBUG_2( "const int& siz, stored_type (*gen)(U1,U2), const U1& u1, const U2& u2)", RTYPE, siz )
        iterator first = begin(), last = end() ;
        while( first != last ) *first++ = gen(u1,u2) ;
    }

    template <int RTYPE>
    template <typename U1, typename U2, typename U3>
    Vector<RTYPE>::Vector( const int& siz, stored_type (*gen)(U1,U2,U3), const U1& u1, const U2& u2, const U3& u3): RObject(  Rf_allocVector( RTYPE, siz) ){
        update_vector() ;
        RCPP_DEBUG_2( "const int& siz, stored_type (*gen)(U1,U2,U3), const U1& u1, const U2& u2, const U3& u3)", RTYPE, siz )
        iterator first = begin(), last = end() ;
        while( first != last ) *first++ = gen(u1,u2,u3) ;
    }

    template <int RTYPE>
    template <typename InputIterator>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last) : RObject( Rf_allocVector(RTYPE, std::distance(first, last) ) ){
        RCPP_DEBUG_1( "Vector<%d>( InputIterator first, InputIterator last", RTYPE )
        update_vector();
        std::copy( first, last, begin() ) ; 
    }

    template <int RTYPE>
    template <typename InputIterator>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last, int n) : RObject( Rf_allocVector(RTYPE, n) ){
        update_vector() ;
        RCPP_DEBUG_2( "Vector<%d>( InputIterator first, InputIterator last, int n = %d)", RTYPE, n )
        std::copy( first, last, begin() ) ; 
    }

    template <int RTYPE>
    template <typename InputIterator, typename Func>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last, Func func) : RObject( Rf_allocVector( RTYPE, std::distance(first,last) ) ){
        update_vector() ;
        RCPP_DEBUG_1( "Vector<%d>( InputIterator, InputIterator, Func )", RTYPE )
        std::transform( first, last, begin(), func) ;
    }
    
    template <int RTYPE>
    template <typename InputIterator, typename Func>
    Vector<RTYPE>::Vector( InputIterator first, InputIterator last, Func func, int n) : RObject( Rf_allocVector( RTYPE, n ) ){
        update_vector();
        RCPP_DEBUG_2( "Vector<%d>( InputIterator, InputIterator, Func, int n = %d )", RTYPE, n )
        std::transform( first, last, begin(), func) ;
    }
          
    
    template <int RTYPE>
    template <bool NA, typename VEC>
    Vector<RTYPE>::Vector( const VectorBase<RTYPE,NA,VEC>& other ) : RObject() {
        RCPP_DEBUG_2( "Vector<%d>( const VectorBase<RTYPE,NA,VEC>& ) [VEC = %s]", RTYPE, DEMANGLE(VEC) )
        import_sugar_expression( other, typename traits::same_type<Vector,VEC>::type() ) ;
    }
    
    template <int RTYPE>
    template <bool NA, typename T>
    Vector<RTYPE>::Vector( const sugar::SingleLogicalResult<NA,T>& obj ) : RObject( r_cast<RTYPE>( const_cast<sugar::SingleLogicalResult<NA,T>&>(obj).get_sexp() ) ) {
        update_vector() ;
        RCPP_DEBUG_2( "Vector<%d>( const sugar::SingleLogicalResult<NA,T>& ) [T = %s]", RTYPE, DEMANGLE(T) )
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
            set_sexp( r_cast<RTYPE>( wrap(x) ) ); 
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
        set_sexp( r_cast<RTYPE>( wrap(x) ) ) ;
    }
    
    template <int RTYPE>
    template <bool NA, typename VEC>
    inline void Vector<RTYPE>::import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::false_type ){
        RCPP_DEBUG_4( "Vector<%d>::import_sugar_expression( VectorBase<%d,%d,%s>, false_type )", RTYPE, NA, RTYPE, DEMANGLE(VEC) ) ;
    	int n = other.size() ;
    	set_sexp( Rf_allocVector( RTYPE, n ) ) ;
    	import_expression<VEC>( other.get_ref() , n ) ;
    }   
    
    template <int RTYPE>
    template <bool NA, typename VEC>
    inline void Vector<RTYPE>::import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::true_type ){
        RCPP_DEBUG_4( "Vector<%d>::import_sugar_expression( VectorBase<%d,%d,%s>, true_type )", RTYPE, NA, RTYPE, DEMANGLE(VEC) ) ;
    	set_sexp( other.get_ref() ) ;
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
    
    template <int RTYPE>
    typename Vector<RTYPE>::iterator Vector<RTYPE>::erase_single__impl( iterator position ){
        if( position < begin() || position > end() ) throw index_out_of_bounds( ) ;
        int n = size() ;
        Vector target( n - 1 ) ;
        iterator target_it(target.begin()) ;
        iterator it(begin()) ;
        iterator this_end(end()) ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        if( names == R_NilValue ){
            int i=0; 
            for( ; it < position; ++it, ++target_it, i++){
                *target_it = *it;
            }
            ++it ;
            for( ; it < this_end ; ++it, ++target_it){
                *target_it = *it;
            }
            set_sexp( target.asSexp() ) ;
            return begin()+i ;
        } else {
            SEXP newnames = PROTECT(::Rf_allocVector( STRSXP, n-1 ));
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
            UNPROTECT(1) ; /* newnames */
            set_sexp( target.asSexp() ) ;
            return begin()+result ;
        }
    }
    
    template <int RTYPE>
    typename Vector<RTYPE>::iterator Vector<RTYPE>::erase_range__impl( iterator first, iterator last ){
        if( first > last ) throw std::range_error("invalid range") ;
        if( last > end() || first < begin() ) throw index_out_of_bounds() ;
		
        iterator it = begin() ;
        iterator this_end = end() ;
        int nremoved = std::distance(first,last) ;
        int target_size = size() - nremoved  ;
        Vector target( target_size ) ;
        iterator target_it = target.begin() ;
		
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        iterator result ;
        if( names == R_NilValue ){
            int i=0; 
            for( ; it < first; ++it, ++target_it, i++ ){
                *target_it = *it ;
            }
            result = begin() + i + 1 ;
            for( it = last ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else{
            SEXP newnames = PROTECT( ::Rf_allocVector(STRSXP, target_size) ) ;
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
            UNPROTECT(1) ; /* newnames */
        }
        set_sexp(target.asSexp() );
        return result ;
    }
    
 
    template <int RTYPE>
    void Vector<RTYPE>::push_back__impl(const stored_type& object, traits::false_type){
        int n = size() ;
        Vector target( n + 1 ) ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        if( names == R_NilValue ){
            for( ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else {
            SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1) ) ;
            int i = 0 ;
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
            SET_STRING_ELT( newnames, i, Rf_mkChar("") ) ;
            target.attr("names") = newnames ;
            UNPROTECT(1) ; /* newnames */
        }
        *target_it = object;
        set_sexp( target.asSexp() ) ;
    }	
    
    template <int RTYPE>
    void Vector<RTYPE>::push_back__impl(const stored_type& object, traits::true_type){
        SEXP object_sexp = PROTECT( object ) ;
        int n = size() ;
        Vector target( n + 1 ) ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        if( names == R_NilValue ){
            for( ; it < this_end; ++it, ++target_it ){
                *target_it = *it ;
            }
        } else {
            SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1) ) ;
            int i = 0 ;
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
            SET_STRING_ELT( newnames, i, Rf_mkChar("") ) ;
            target.attr("names") = newnames ;
            UNPROTECT(1) ; /* newnames */
        }
        *target_it = object_sexp;
        set_sexp( target.asSexp() ) ;
        UNPROTECT(1) ;
    }	
    	
    template <int RTYPE>
    void Vector<RTYPE>::push_back_name__impl(const stored_type& object, const std::string& name, traits::false_type ){
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=0;
        if( names == R_NilValue ){
            SEXP dummy = PROTECT( Rf_mkChar("") );
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , dummy );
            }
            UNPROTECT(1) ; /* dummy */
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
        }
        SET_STRING_ELT( newnames, i, Rf_mkChar( name.c_str() ) );
        target.attr("names") = newnames ;
    		
        *target_it = object;
        UNPROTECT(1) ; /* newnames, */
        set_sexp( target.asSexp() ) ;
    }
    	
    template <int RTYPE>
    void Vector<RTYPE>::push_back_name__impl(const stored_type& object, const std::string& name, traits::true_type ){
        SEXP object_sexp = PROTECT( object ) ;
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=0;
        if( names == R_NilValue ){
            SEXP dummy = PROTECT( Rf_mkChar("") );
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , dummy );
            }
            UNPROTECT(1) ; /* dummy */
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
            }
        }
        SET_STRING_ELT( newnames, i, Rf_mkChar( name.c_str() ) );
        target.attr("names") = newnames ;
    		
        *target_it = object_sexp;
        UNPROTECT(2) ; /* newnames, object_sexp */
        set_sexp( target.asSexp() ) ;
    }
    	
    template <int RTYPE>
    void Vector<RTYPE>::push_front__impl(const stored_type& object, traits::false_type ){
        int n = size() ;
        Vector target( n+1);
        iterator target_it(target.begin());
        iterator it(begin());
        iterator this_end(end());
        *target_it = object ;
        ++target_it ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        if( names == R_NilValue ){
            for( ; it<this_end; ++it, ++target_it){
                *target_it = *it ;
            }
        } else{
            SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1) );
            int i=1 ;
            SET_STRING_ELT( newnames, 0, Rf_mkChar("") ) ;
            for( ; it<this_end; ++it, ++target_it, i++){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
            target.attr("names") = newnames ;
            UNPROTECT(1) ; /* newnames */
        }
        set_sexp( target.asSexp() ) ;
    }
    	
    template <int RTYPE>
    void Vector<RTYPE>::push_front__impl(const stored_type& object, traits::true_type ){
        SEXP object_sexp = PROTECT( object ) ;
        int n = size() ;
        Vector target( n+1);
        iterator target_it(target.begin());
        iterator it(begin());
        iterator this_end(end());
        *target_it = object_sexp ;
        UNPROTECT(1); /* object_sexp */
        ++target_it ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        if( names == R_NilValue ){
            for( ; it<this_end; ++it, ++target_it){
                *target_it = *it ;
            }
        } else{
            SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1) );
            int i=1 ;
            SET_STRING_ELT( newnames, 0, Rf_mkChar("") ) ;
            for( ; it<this_end; ++it, ++target_it, i++){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
            target.attr("names") = newnames ;
            UNPROTECT(1) ; /* newnames */
        }
        set_sexp( target.asSexp() ) ;
    }
    	
    template <int RTYPE>
    void Vector<RTYPE>::push_front_name__impl(const stored_type& object, const std::string& name, traits::false_type ){
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=1;
        SET_STRING_ELT( newnames, 0, Rf_mkChar( name.c_str() ) );
        *target_it = object;
        ++target_it ;
    		
        if( names == R_NilValue ){
            SEXP dummy = PROTECT( Rf_mkChar("") );
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , dummy );
            }
            UNPROTECT(1) ; /* dummy */
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
        }
        target.attr("names") = newnames ;
    		
        UNPROTECT(1) ; /* newnames, */
        set_sexp( target.asSexp() ) ;
    }
    	
    template <int RTYPE>
    void Vector<RTYPE>::push_front_name__impl(const stored_type& object, const std::string& name, traits::true_type ){
        SEXP object_sexp = PROTECT(object) ;
        int n = size() ;
        Vector target( n + 1 ) ;
        iterator target_it( target.begin() ) ;
        iterator it(begin()) ;
        iterator this_end(end());
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n+1 ) ) ;
        int i=1;
        SET_STRING_ELT( newnames, 0, Rf_mkChar( name.c_str() ) );
        *target_it = object_sexp;
        ++target_it ;
    		
        if( names == R_NilValue ){
            SEXP dummy = PROTECT( Rf_mkChar("") );
            for( ; it < this_end; ++it, ++target_it,i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i , dummy );
            }
            UNPROTECT(1) ; /* dummy */
        } else {
            for( ; it < this_end; ++it, ++target_it, i++ ){
                *target_it = *it ;
                SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
            }
        }
        target.attr("names") = newnames ;
    		
        UNPROTECT(2) ; /* newnames, object_sexp */
        set_sexp( target.asSexp() ) ;
    }
    	
    template <int RTYPE>
    typename Vector<RTYPE>::iterator Vector<RTYPE>::insert__impl( iterator position, const stored_type& object, traits::false_type){
        int n = size() ;
        Vector target( n+1 ) ;
        iterator target_it = target.begin();
        iterator it = begin() ;
        iterator this_end = end() ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        iterator result ;
        if( names == R_NilValue ){
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
            SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1 ) ) ;
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
            UNPROTECT(1) ; /* newmanes */
        }
        set_sexp( target.asSexp() );
        return result ;
    }
    
    template <int RTYPE>
    typename Vector<RTYPE>::iterator Vector<RTYPE>::insert__impl( iterator position, const stored_type& object, traits::true_type){
        PROTECT( object ) ;
        int n = size() ;
        Vector target( n+1 ) ;
        iterator target_it = target.begin();
        iterator it = begin() ;
        iterator this_end = end() ;
        SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
        iterator result ;
        if( names == R_NilValue ){
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
            SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1 ) ) ;
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
            UNPROTECT(1) ; /* newmanes */
        }
        set_sexp( target.asSexp() );
        UNPROTECT(1); /* object */
        return result ;
    }
	
    template <int RTYPE>
    template <typename EXPR_VEC>
    Vector<RTYPE>& Vector<RTYPE>::operator+=( const VectorBase<RTYPE,true,EXPR_VEC>& rhs ){
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
    
    template <int RTYPE>
    template <typename EXPR_VEC>
    Vector<RTYPE>& Vector<RTYPE>::operator+=( const VectorBase<RTYPE,false,EXPR_VEC>& rhs ){
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
    
    template <>
    template <typename EXPR_VEC>
    Vector<REALSXP>& Vector<REALSXP>::operator+=( const VectorBase<REALSXP,false,EXPR_VEC>& rhs ){
        const EXPR_VEC& vec = rhs.get_ref() ;
        int n = size() ;
        iterator start = begin() ;
        for( int i=0; i<n; i++){
            start[i] += vec[i] ;        
        }
        return *this ;
    }
    
    template <>
    template <typename EXPR_VEC>
    Vector<REALSXP>& Vector<REALSXP>::operator+=( const VectorBase<REALSXP,true,EXPR_VEC>& rhs ){
        const EXPR_VEC& vec = rhs.get_ref() ;
        int n = size() ;
        iterator start = begin() ;
        for( int i=0; i<n; i++){
            start[i] += vec[i] ;        
        }
        return *this ;
    }
    
    
    template <int RTYPE>
    bool Vector<RTYPE>::containsElementNamed( const char* target ) const {
        SEXP names = RCPP_GET_NAMES(m_sexp) ; 
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
