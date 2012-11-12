// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// CharacterVectorExtractionIterator.h: Rcpp R/C++ interface class library -- extract string from CharacterVector
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

#ifndef Rcpp__vector__CharacterVectorExtractionIterator_h
#define Rcpp__vector__CharacterVectorExtractionIterator_h

// const iterator for CharacterVector
// this is faster than the regular proxy iterator because it works directly 
// on a SEXP*. 
class CharacterVectorExtractionIterator {
public:
    typedef int difference_type;
    typedef const char* value_type;
    typedef const char** pointer;
    typedef const char*& reference;
    typedef std::input_iterator_tag iterator_category;
    
    CharacterVectorExtractionIterator( const CharacterVector& vec) : ptr( get_string_ptr(vec) ){}
    
    CharacterVectorExtractionIterator( const CharacterVectorExtractionIterator& other) : ptr(other.ptr){}
    CharacterVectorExtractionIterator& operator=(const CharacterVectorExtractionIterator& other){ ptr = other.ptr ; return *this ;}
    
    int operator-( const CharacterVectorExtractionIterator& other){ return ptr - other.ptr ; }
    
    CharacterVectorExtractionIterator operator+( int n){ return CharacterVectorExtractionIterator(ptr+n); }
    CharacterVectorExtractionIterator operator-( int n){ return CharacterVectorExtractionIterator(ptr-n); }
    
    CharacterVectorExtractionIterator& operator++(){ ptr++ ; return *this ; }
    CharacterVectorExtractionIterator& operator--(){ ptr-- ; return *this ; }
    CharacterVectorExtractionIterator& operator+=(int n){ ptr += n; return *this ; }
    CharacterVectorExtractionIterator& operator-=(int n){ ptr -= n; return *this ; }
    
    bool operator<( const CharacterVectorExtractionIterator& other ){ return ptr < other.ptr ; }
    bool operator>( const CharacterVectorExtractionIterator& other ){ return ptr > other.ptr ; }
    bool operator<=( const CharacterVectorExtractionIterator& other ){ return ptr <= other.ptr ; }
    bool operator>=( const CharacterVectorExtractionIterator& other ){ return ptr >= other.ptr ; }
    
    value_type  operator*(){ return char_nocheck(*ptr) ; }
    value_type  operator[](int n){ return char_nocheck(ptr[n]) ; }
    bool operator==(const CharacterVectorExtractionIterator& other) const { return ptr == other.ptr ;}
    bool operator!=(const CharacterVectorExtractionIterator& other) const { return ptr != other.ptr ;}    
      
        
private:
    SEXP* ptr ; 
    CharacterVectorExtractionIterator( SEXP* ptr_ ) : ptr(ptr_){}
    
};

#endif
