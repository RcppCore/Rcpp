// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Function.h: Rcpp R/C++ interface class library -- functions (also primitives and builtins)
//
// Copyright (C) 2010 - 2013  Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Function_h
#define Rcpp_Function_h

#include <RcppCommon.h>

#include <Rcpp/grow.h>

namespace Rcpp{

    /**
     * functions
     */
    RCPP_API_CLASS(Function_Impl) {
    public:

        RCPP_GENERATE_CTOR_ASSIGN(Function_Impl)

        Function_Impl(SEXP x){
            switch( TYPEOF(x) ){
            case CLOSXP:
            case SPECIALSXP:
            case BUILTINSXP:
                Storage::set__(x);
                break;
            default:
                throw not_compatible("cannot convert to function") ;
            }
        }

        /**
         * Finds a function, searching from the global environment
         *
         * @param name name of the function
         */
        Function_Impl(const std::string& name) {
            SEXP nameSym = Rf_install( name.c_str() );	// cannot be gc()'ed  once in symbol table
            Shield<SEXP> x( Rf_findFun( nameSym, R_GlobalEnv ) ) ;
            Storage::set__(x) ;
        }

        SEXP operator()() const {
            return Rcpp_eval( Rf_lang1( Storage::get__()  ) ) ;
        }

        #include <Rcpp/generated/Function__operator.h>

        /**
         * Returns the environment of this function
         */
        SEXP environment() const {
            SEXP fun = Storage::get__() ;
            if( TYPEOF(fun) != CLOSXP ) {
                throw not_a_closure() ;
            }
            return CLOENV(fun) ;
        }

        /**
         * Returns the body of the function
         */
        SEXP body() const {
            return BODY( Storage::get__() ) ;
        }

        void update(SEXP){}
    };

    typedef Function_Impl<PreserveStorage> Function ;

} // namespace Rcpp

#endif
