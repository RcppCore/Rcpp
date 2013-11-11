// Copyright (C) 2013 Romain Francois
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

#ifndef Rcpp_FieldProxy_h
#define Rcpp_FieldProxy_h

namespace Rcpp{
    
template <typename CLASS>
class FieldProxyPolicy {
public:
    
    class FieldProxy {
    public:
        FieldProxy( CLASS& v, const std::string& name) : 
            parent(v), field_name( Rf_mkChar(name.c_str())) {}
        
        FieldProxy& operator=(const FieldProxy& rhs) ;
              
        template <typename T> FieldProxy& operator=(const T& rhs) ;
            
        template <typename T> operator T() const ;
        inline operator SEXP() const { return get() ; }
        
    private:
        CLASS& parent; 
        SEXP field_name ;
            
        SEXP get() const ;
        void set(SEXP x ) ;
    } ;
    
    class const_FieldProxy {
    public:
        const_FieldProxy( const CLASS& v, const std::string& name) ;
        const_FieldProxy& operator=(const const_FieldProxy& rhs) ;
              
        template <typename T> operator T() const ;
        inline operator SEXP() const { return get() ; }
        
    private:
        const CLASS& parent; 
        SEXP field_name ;
            
        SEXP get() const ;
    } ;
    
    FieldProxy field(const std::string& name) ;
    const_FieldProxy field(const std::string& name) const ;
    
} ;

}
#endif
