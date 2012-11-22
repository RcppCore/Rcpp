// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// duplicated.h: Rcpp R/C++ interface class library -- duplicated
//
// Copyright (C) 2012   Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__duplicated_h
#define Rcpp__sugar__duplicated_h
          
namespace Rcpp{
namespace sugar{

template <typename SET, typename STORAGE>
class DuplicatedInserter {
public:
    DuplicatedInserter( SET& set_ ) : set(set_) {}
    
    inline int operator()( STORAGE value ){
        if( set.count(value) ) return TRUE ;
        set.insert(value);
        return FALSE ;
    }
    
private:
    SET& set ;
} ; 

template <int RTYPE, typename TABLE_T>        
class Duplicated {
public:
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    
    Duplicated( const TABLE_T& table ): set(), result(table.size()) {
        std::transform( table.begin(), table.end(), result.begin(), Inserter(set) ) ;
    }
    
    inline operator LogicalVector() const { return result ; }
    
private:
    typedef RCPP_UNORDERED_SET<STORAGE> SET ;
    typedef DuplicatedInserter<SET,STORAGE> Inserter ;
    SET set ; 
    LogicalVector result ;
}; 
  
} // sugar

template <int RTYPE, bool NA, typename T>
inline LogicalVector duplicated( const VectorBase<RTYPE,NA,T>& x ){
    return sugar::Duplicated<RTYPE,T>(x.get_ref()) ;
}


} // Rcpp
#endif

