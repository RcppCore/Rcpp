// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// is.h: Rcpp R/C++ interface class library -- is implementations 
//
// Copyright (C) 2013    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_api_meat_is_h
#define Rcpp_api_meat_is_h

namespace Rcpp{ 
    
    inline bool is_atomic( SEXP x){ return Rf_length(x) == 1 ; } 
    inline bool is_matrix(SEXP x){
        SEXP dim = Rf_getAttrib( x, R_DimSymbol) ;
        return dim != R_NilValue && Rf_length(dim) == 2 ;
    }
    
    template <> inline bool is<int>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == INTSXP ;
    }

    template <> inline bool is<double>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == REALSXP ;
    }
    
    template <> inline bool is<bool>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == LGLSXP ;
    }
    
    template <> inline bool is<std::string>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == STRSXP ;
    }
    
    template <> inline bool is<String>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == STRSXP ;
    }
    
    template <> inline bool is<RObject>( SEXP x ){
        return true ;
    }
    template <> inline bool is<IntegerVector>( SEXP x ){
        return TYPEOF(x) == INTSXP ;
    }
    template <> inline bool is<ComplexVector>( SEXP x ){
        return TYPEOF(x) == CPLXSXP ;
    }
    template <> inline bool is<RawVector>( SEXP x ){
        return TYPEOF(x) == RAWSXP ;
    }
    template <> inline bool is<NumericVector>( SEXP x ){
        return TYPEOF(x) == REALSXP ;
    }
    template <> inline bool is<LogicalVector>( SEXP x ){
        return TYPEOF(x) == LGLSXP ;
    }
    template <> inline bool is<List>( SEXP x ){
        return TYPEOF(x) == VECSXP ;
    }
    template <> inline bool is<IntegerMatrix>( SEXP x ){
        return TYPEOF(x) == INTSXP && is_matrix(x) ;
    }
    template <> inline bool is<ComplexMatrix>( SEXP x ){
        return TYPEOF(x) == CPLXSXP && is_matrix(x) ;
    }
    template <> inline bool is<RawMatrix>( SEXP x ){
        return TYPEOF(x) == RAWSXP && is_matrix(x) ;
    }
    template <> inline bool is<NumericMatrix>( SEXP x ){
        return TYPEOF(x) == REALSXP && is_matrix(x) ;
    }
    template <> inline bool is<LogicalMatrix>( SEXP x ){
        return TYPEOF(x) == LGLSXP && is_matrix(x) ;
    }
    template <> inline bool is<GenericMatrix>( SEXP x ){
        return TYPEOF(x) == VECSXP && is_matrix(x) ;
    }
    
    
    template <> inline bool is<DataFrame>( SEXP x ){
        if( TYPEOF(x) != VECSXP ) return false ;
        return Rf_inherits( x, "data.frame" ) ;
    }
    template <> inline bool is<WeakReference>( SEXP x ){
        return TYPEOF(x) == WEAKREFSXP ;
    }
    template <> inline bool is<Symbol>( SEXP x ){
        return TYPEOF(x) == SYMSXP ;
    }
    template <> inline bool is<S4>( SEXP x ){
        return ::Rf_isS4(x);
    }
    template <> inline bool is<Reference>( SEXP x ){
        if( ! ::Rf_isS4(x) ) return false ;
        return ::Rf_inherits(x, "envRefClass" ) ;
    }
    template <> inline bool is<Promise>( SEXP x ){
        return TYPEOF(x) == PROMSXP ;
    }
    template <> inline bool is<Pairlist>( SEXP x ){
        return TYPEOF(x) == LISTSXP ;
    }
    template <> inline bool is<Function>( SEXP x ){
        return TYPEOF(x) == CLOSXP || TYPEOF(x) == SPECIALSXP || TYPEOF(x) == BUILTINSXP ;
    }
    template <> inline bool is<Environment>( SEXP x ){
        return TYPEOF(x) == ENVSXP ;
    }
    template <> inline bool is<Formula>( SEXP x ){
        if( TYPEOF(x) != LANGSXP ) return false ; 
        return Rf_inherits( x, "formula" ) ;
    }
    
    template <> inline bool is<Date>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == REALSXP && Rf_inherits( x, "Date" ) ;
    }
    template <> inline bool is<Datetime>( SEXP x ){
        return is_atomic(x) && TYPEOF(x) == REALSXP && Rf_inherits( x, "POSIXt" ) ;
    }
    template <> inline bool is<DateVector>( SEXP x ){
        return TYPEOF(x) == REALSXP && Rf_inherits( x, "Date" ) ;
    }
    template <> inline bool is<DatetimeVector>( SEXP x ){
        return TYPEOF(x) == REALSXP && Rf_inherits( x, "POSIXt" ) ;
    }
     
} // namespace Rcpp

#endif
