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

#ifndef Rcpp_SlotProxy_h
#define Rcpp_SlotProxy_h

namespace Rcpp{
    
template <typename CLASS>
class SlotProxyPolicy {
public:
    
    class SlotProxy {
    public:
        SlotProxy( CLASS& v, const std::string& name) : parent(v), slot_name(Rf_install(name.c_str())) {
            if( !R_has_slot( v, slot_name) ){
                throw no_such_slot() ; 
            }  
        }
        
        SlotProxy& operator=(const SlotProxy& rhs) ;
              
        template <typename T> SlotProxy& operator=(const T& rhs) ;
            
        template <typename T> operator T() const ;
        inline operator SEXP() const { return get() ; }
        
    private:
        CLASS& parent; 
        SEXP slot_name ;
            
        SEXP get() const ;
        void set(SEXP x ) ;
    } ;
    
    class const_SlotProxy {
    public:
        const_SlotProxy( const CLASS& v, const std::string& name) ;
        const_SlotProxy& operator=(const const_SlotProxy& rhs) ;
              
        template <typename T> operator T() const ;
        inline operator SEXP() const { return get() ; }
        
    private:
        const CLASS& parent; 
        SEXP slot_name ;
            
        SEXP get() const ;
    } ;
    
    SlotProxy slot(const std::string& name) ;
    const_SlotProxy slot(const std::string& name) const ;
    
    bool hasSlot(const std::string& name) const ;
    
} ;

}
#endif
