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

namespace Rcpp{
         
    namespace internal{
        inline SEXP empty_data_frame(){
            Shield<SEXP> df( Rf_allocVector(VECSXP, 0) );
            Rf_setAttrib(df, R_NamesSymbol, Rf_allocVector(STRSXP, 0));
            Rf_setAttrib(df, R_RowNamesSymbol, Rf_allocVector(INTSXP, 0));
            Rf_setAttrib(df, R_ClassSymbol, Rf_mkString("data.frame"));
            return df;
        }
    }
    
    template <template <class> class StoragePolicy>
    class DataFrame_Impl : public Vector<VECSXP, StoragePolicy> {
    public:  
        typedef Vector<VECSXP, StoragePolicy> Parent ;
        
        DataFrame_Impl() : Parent( internal::empty_data_frame() ){}
        DataFrame_Impl(SEXP x) {
            set_sexp(x);     
        }
        DataFrame_Impl( const DataFrame_Impl& other){
            set_sexp(other) ;    
        }
        
        template <typename T>
        DataFrame_Impl( const T& obj ) ;
        
        DataFrame_Impl& operator=( DataFrame_Impl& other){
            if( *this != other) set_sexp(other) ;    
        }
        
        DataFrame_Impl& operator=( SEXP x){
            set_sexp(x) ;
            return *this ;
        }
                
        inline int nrows() const {
            return Rf_length( VECTOR_ELT(Parent::get__(), 0) );     
        }
        
        static DataFrame_Impl create(){ 
            return DataFrame_Impl() ; 
        }

        #include <Rcpp/generated/DataFrame_generated.h>           

    private:
        void set_sexp(SEXP x){
            if( ::Rf_inherits( x, "data.frame" )){
                Parent::set__( x ) ;
            } else{
                SEXP y = internal::convert_using_rfunction( x, "as.data.frame" ) ;
                Parent::set__( y ) ;
            }
        }
        
        static DataFrame_Impl from_list( Parent obj ){
            bool use_default_strings_as_factors = true ;
            bool strings_as_factors = true ;
            int strings_as_factors_index = -1 ;
            int n = obj.size() ;
            CharacterVector names = obj.attr( "names" ) ;
            if( !names.isNULL() ){
                for( int i=0; i<n; i++){
                    if( names[i] == "stringsAsFactors" ){
                        strings_as_factors_index = i ;
                        use_default_strings_as_factors = false ;        
                        if( !as<bool>(obj[i]) ) strings_as_factors = false ;
                        break ;         
                    }
                }
            }
            if( use_default_strings_as_factors ) 
                return DataFrame_Impl(obj) ;
            SEXP as_df_symb = Rf_install("as.data.frame");
            SEXP strings_as_factors_symb = Rf_install("stringsAsFactors");
            
            obj.erase(strings_as_factors_index) ;
            names.erase(strings_as_factors_index) ;
            obj.attr( "names") = names ;
            Shield<SEXP> call( Rf_lang3(as_df_symb, obj, wrap( strings_as_factors ) ) ) ;
            SET_TAG( CDDR(call),  strings_as_factors_symb ) ;   
            Shield<SEXP> res( Rcpp_eval( call ) ) ; 
            DataFrame_Impl out( res ) ;
            return out ;
       
        }
        
    } ;
 
    typedef DataFrame_Impl<PreserveStorage> DataFrame ;
}

#endif
