// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// minmax.h: Rcpp R/C++ interface class library -- min, mx, range
//
// Copyright (C) 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__minmax_h
#define Rcpp__sugar__minmax_h

namespace Rcpp{
namespace sugar{

    template <int RTYPE, bool NA, typename T>
    class MinMax {
    public:
        typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
        
        MinMax( const T& obj_) : obj(obj_) {}
        
        STORAGE min() {
            min_ = obj[0] ;
            if( Rcpp::traits::is_na<RTYPE>( min_ ) ) return min_ ;
            
            int n = obj.size() ;
            for( int i=1; i<n; i++){
                current = obj[i] ;
                if( Rcpp::traits::is_na<RTYPE>( current ) ) return current;
                if( current < min_ ) min_ = current ;
            }
            return min_ ;
        }
        STORAGE max() {
            max_ = obj[0] ;
            if( Rcpp::traits::is_na<RTYPE>( max_ ) ) return max_ ;
            
            int n = obj.size() ;
            for( int i=1; i<n; i++){
                current = obj[i] ;
                if( Rcpp::traits::is_na<RTYPE>( current ) ) return current;
                if( current > max_ ) max_ = current ;
            }
            return max_ ;
        }
        Vector<RTYPE> range(){
            min_ = max_ = obj[0] ;
            if( Rcpp::traits::is_na<RTYPE>( min_ ) ) return Vector<RTYPE>::create( min_, max_ ) ;
            
            int n = obj.size() ;
            for( int i=1; i<n; i++){
                current = obj[i] ;
                if( Rcpp::traits::is_na<RTYPE>( current ) ) return Vector<RTYPE>::create( min_, max_ ) ;
                if( current < min_ ) min_ = current ;
                if( current > max_ ) max_ = current ;
                
            }
            return Vector<RTYPE>::create( min_, max_ ) ;
        }
        
        
    private:
        const T& obj ;
        STORAGE min_, max_, current ;
    } ;

    // version for NA = false
    template <int RTYPE, typename T>
    class MinMax<RTYPE,false,T> {
    public:
        typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
        
        MinMax( const T& obj_) : obj(obj_) {}
        
        STORAGE min() {
            min_ = obj[0] ;
            
            int n = obj.size() ;
            for( int i=1; i<n; i++){
                current = obj[i] ;
                if( current < min_ ) min_ = current ;
            }
            return min_ ;
        }
        STORAGE max() {
            max_ = obj[0] ;
            
            int n = obj.size() ;
            for( int i=1; i<n; i++){
                current = obj[i] ;
                if( current > max_ ) max_ = current ;
            }
            return max_ ;
        }
        Vector<RTYPE> range(){
            min_ = max_ = obj[0] ;
            
            int n = obj.size() ;
            for( int i=1; i<n; i++){
                current = obj[i] ;
                if( current < min_ ) min_ = current ;
                if( current > max_ ) max_ = current ;
            }
            return Vector<RTYPE>::create( min_, max_ ) ;
        }
        
        
    private:
        const T& obj ;
        STORAGE min_, max_, current ;
    } ;
         

} // sugar


template <int RTYPE, bool NA, typename T>
typename traits::storage_type<RTYPE>::type min( const VectorBase<RTYPE,NA,T>& x){
    sugar::MinMax<RTYPE,NA,T> obj(x.get_ref()) ;
    return obj.min() ;
}
template <int RTYPE, bool NA, typename T>
typename traits::storage_type<RTYPE>::type max( const VectorBase<RTYPE,NA,T>& x){
    sugar::MinMax<RTYPE,NA,T> obj(x.get_ref()) ;
    return obj.max() ;
}
template <int RTYPE, bool NA, typename T>
Vector<RTYPE> range( const VectorBase<RTYPE,NA,T>& x){
    sugar::MinMax<RTYPE,NA,T> obj(x.get_ref()) ;
    return obj.range() ;
}

} // Rcpp

#endif
