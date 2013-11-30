// StretchyList.h: Rcpp R/C++ interface class library -- stretchy lists
//
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

#ifndef Rcpp_StretchyList_h
#define Rcpp_StretchyList_h

namespace Rcpp{

    RCPP_API_CLASS(StretchyList_Impl),
        public DottedPairProxyPolicy<StretchyList_Impl<StoragePolicy> > {
    public:
        
        RCPP_GENERATE_CTOR_ASSIGN(StretchyList_Impl) 
        
        typedef typename DottedPairProxyPolicy<StretchyList_Impl>::DottedPairProxy Proxy ;
        typedef typename DottedPairProxyPolicy<StretchyList_Impl>::const_DottedPairProxy const_Proxy ;
        
        StretchyList_Impl(){
            SEXP s = Rf_cons(R_NilValue, R_NilValue);
            SETCAR(s, s);
            Storage::set__(s) ;
        }
        StretchyList_Impl(SEXP x){
            Storage::set__(r_cast<LISTSXP>(x)) ;    
        }
        
        void update(SEXP x){}
        
        inline operator SEXP() const{
            return CDR(Storage::get__() );    
        }
        
        template <typename T>
        StretchyList_Impl& push_back(const T& obj ) ;
        
        template <typename T>
        StretchyList_Impl& push_front(const T& obj ) ;
        
    } ;
    
    typedef StretchyList_Impl<PreserveStorage> StretchyList ;
}
#endif
