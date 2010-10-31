// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Extractor.h: Rcpp R/C++ interface class library -- faster vectors (less interface)
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__Extractor_h
#define Rcpp__Extractor_h

namespace Rcpp {
namespace traits {
        
    template <int RTYPE, bool NA, typename VECTOR>
    struct Extractor {
        typedef VECTOR type ;  
    } ;  

    // apparently Rcpp::Fast upsets windows, so we stick with 
    // the identity class above, meaning no fast indexing
    // update 30 Oct 2010: that may have been g++ 4.5 rather than Windows
    //                     so rephrasing text in terms of macro from RcppCommon.h
//#ifndef WIN32
#ifndef IS_GCC_450_OR_LATER
    template <> 
    struct Extractor<INTSXP, true, Rcpp::Vector<INTSXP> >{
        typedef Rcpp::Fast< Rcpp::Vector<INTSXP> > type ;
    
    } ;
    
    template <> 
    struct Extractor<REALSXP, true, Rcpp::Vector<REALSXP> >{
        typedef Rcpp::Fast< Rcpp::Vector<REALSXP> > type ;
    } ;
    
    template <> 
    struct Extractor<LGLSXP, true, Rcpp::Vector<LGLSXP> >{
        typedef Rcpp::Fast< Rcpp::Vector<LGLSXP> > type ;
    } ;
    
    template <> 
    struct Extractor<RAWSXP, true, Rcpp::Vector<RAWSXP> >{
        typedef Rcpp::Fast< Rcpp::Vector<RAWSXP> > type ;
    } ;
#endif    
    
} // traits
} // Rcpp 

#endif 
