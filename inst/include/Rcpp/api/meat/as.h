// Copyright (C) 2013    Romain Francois
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

#ifndef Rcpp_api_meat_as_h
#define Rcpp_api_meat_as_h

namespace Rcpp{
namespace internal{

    // the address of the C++ object held by the module object whose
    // environment is env (see cpp_object_initializer() in R/Module.R)
    inline void* module_object_address(const Environment& env){
        SEXP xp = env.get(".pointer") ;
        if( xp == R_NilValue )
            throw not_compatible( "Expecting a C++ module object" ) ;

        // the dummy object of a class without a default constructor
        if( TYPEOF(xp) != EXTPTRSXP )
            throw not_initialized() ;

        // e.g. a deserialized object
        void* ptr = R_ExternalPtrAddr(xp) ;
        if( ptr == NULL )
            throw ::Rcpp::exception( "external pointer is not valid" ) ;

        return ptr ;
    }

#ifndef RCPP_NO_MODULES
    // whether the module class cl is the C++ class typeinfo_name, or derives
    // from it through class_::derives(), which records each parent by its R
    // class name, "Rcpp_" followed by its name in the module
    inline bool module_class_is( class_Base* cl, Module* module, const char* typeinfo_name ){
        if( cl->has_typeinfo_name(typeinfo_name) )
            return true ;

        std::vector<class_Base*> todo(1, cl) ;
        std::set<class_Base*> seen ;
        while( module && !todo.empty() ){
            class_Base* current = todo.back() ;
            todo.pop_back() ;
            if( !seen.insert(current).second )
                continue ;

            if( current->has_typeinfo_name(typeinfo_name) )
                return true ;

            for( size_t i = 0; i < current->parents.size(); i++ ){
                const std::string& parent = current->parents[i] ;
                if( parent.compare(0, 5, "Rcpp_") != 0 )
                    continue ;
                std::string name = parent.substr(5) ;
                if( module->has_class(name) )
                    todo.push_back( module->get_class_pointer(name) ) ;
            }
        }
        return false ;
    }
#endif

    // packages call this one directly, so it stays; it cannot check the class
    inline void* as_module_object_internal(SEXP obj){
        if( !Rf_isS4(obj) )
            throw not_compatible( "Expecting a C++ module object" ) ;
        Environment env(obj) ;
        return module_object_address(env) ;
    }

    inline void* as_module_object_internal(SEXP obj, const char* typeinfo_name){
        if( !Rf_isS4(obj) ){
            throw not_compatible(
                "Expecting an object of C++ class '%s'",
                demangle(typeinfo_name)
            ) ;
        }
        Environment env(obj) ;
        void* ptr = module_object_address(env) ;

#ifndef RCPP_NO_MODULES
        SEXP cppclass = env.get(".cppclass") ;
        if( TYPEOF(cppclass) != EXTPTRSXP || R_ExternalPtrAddr(cppclass) == NULL ){
            throw not_compatible(
                "Expecting an object of C++ class '%s'",
                demangle(typeinfo_name)
            ) ;
        }
        class_Base* cl = reinterpret_cast<class_Base*>( R_ExternalPtrAddr(cppclass) ) ;

        SEXP module_xp = env.get(".module") ;
        Module* module = NULL ;
        if( TYPEOF(module_xp) == EXTPTRSXP )
            module = reinterpret_cast<Module*>( R_ExternalPtrAddr(module_xp) ) ;

        if( !module_class_is(cl, module, typeinfo_name) ){
            throw not_compatible(
                "Expecting an object of C++ class '%s', got an object of class '%s'",
                demangle(typeinfo_name),
                cl->name
            ) ;
        }
#endif

        return ptr ;
    }

}
}

#endif
