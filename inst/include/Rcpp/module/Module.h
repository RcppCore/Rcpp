// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module.h: Rcpp R/C++ interface class library -- Rcpp modules
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

#ifndef Rcpp_Module_Module_h
#define Rcpp_Module_Module_h
       
    /**
     * holds information about exposed functions and classes
     */
    class Module {
    public:    
        typedef std::map<std::string,CppFunction*> MAP ;
        typedef std::pair<const std::string,CppFunction*> FUNCTION_PAIR ;
                
        typedef std::map<std::string,class_Base*> CLASS_MAP ;
        typedef std::pair<const std::string,class_Base*> CLASS_PAIR ;
        typedef CLASS_MAP::iterator CLASS_ITERATOR ;
        
        Module()  ;
        Module(const char* name_)  ;
          
        /**
         * calls a function from that module with the specified arguments
         *
         * @param name the name of the function to call
         * @param args an array of R objects to use as arguments for the function
         * @param nargs number of arguments
         */
        SEXP invoke( const std::string& /* name */,  SEXP* /* args */, int /* nargs */ ) ;                        
                
        /**
         * vector of arity of all the functions exported by the module 
         */
        Rcpp::IntegerVector functions_arity() ;
        
        /**
         * vector of names of the functions
         */
        Rcpp::CharacterVector functions_names() ;
                
        /** 
         * exposed class names
         */
        Rcpp::CharacterVector class_names() ;
        
        /** 
         * information about the classes
         */
        Rcpp::List classes_info() ;
        
        /**
         * completion information
         */
        Rcpp::CharacterVector complete() ;
        
        /**
         * Returns a list that contains: 
         * - an external pointer that encapsulates a CppFunction*
         * - voidness of the function (logical)
         * - docstring (character)
         * - signature (character)
         * - formal arguments of the function
         *
         * The R code in Module.R uses this information to create a C++Function 
         * object
         */
        SEXP get_function( const std::string& ) ;
           
        /**
         * get the underlying C++ function pointer as a DL_FUNC
         */
        DL_FUNC get_function_ptr( const std::string& ) ;
        
        inline void Add( const char* name_ , CppFunction* ptr){
            R_RegisterCCallable( prefix.c_str(), name_, ptr->get_function_ptr() ) ;
            functions.insert( FUNCTION_PAIR( name_ , ptr ) ) ;
        }
                
        inline void AddClass(const char* name_ , class_Base* cptr){
            classes.insert( CLASS_PAIR( name_ , cptr ) ) ;
        }

        inline bool has_function( const std::string& m){
            return functions.find(m) != functions.end() ;
        }
                
        inline bool has_class( const std::string& m){
            return classes.find(m) != classes.end() ;
        }
                
        Rcpp::CppClass get_class(const std::string& ) ;
        class_Base* get_class_pointer(const std::string& ) ;
        
        std::string name ;
           
        void add_enum( const std::string& parent_class_typeinfo_name, const std::string& enum_name, const std::map<std::string, int>& value ) ;
        
    private:
        MAP functions ;
        CLASS_MAP classes ;
        std::string prefix ;
                           
    };

#endif
