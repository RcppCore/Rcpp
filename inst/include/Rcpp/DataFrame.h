// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DataFrame.h: Rcpp R/C++ interface class library -- data frames
//
// Copyright (C) 2010 - 2013 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__DataFrame_h
#define Rcpp__DataFrame_h

#include <Rcpp/RObject.h>
#include <Rcpp/vector/00_forward_Vector.h>

namespace Rcpp{
        
    class DataFrame : public Vector<VECSXP> {
    public:     
        DataFrame() ;
        DataFrame(SEXP x) ;
        DataFrame( const DataFrame& other) ;
        DataFrame( const RObject::SlotProxy& proxy ) ;
        DataFrame( const RObject::AttributeProxy& proxy ) ;
                
        DataFrame& operator=( DataFrame& other) ;
        DataFrame& operator=( SEXP x)  ;
                
        ~DataFrame() ;

        int nrows() const ;
        
        static DataFrame create(){ return DataFrame() ; }

#include <Rcpp/generated/DataFrame_generated.h>           

    private:
        void set_sexp(SEXP x) ;
        static DataFrame from_list( Rcpp::List ) ;
        
    } ;
        
}

#endif
