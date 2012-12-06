// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Environment.h: Rcpp R/C++ interface class library -- access R environments
//
// Copyright (C) 2009 - 2012    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Environment_h
#define Rcpp_Environment_h

#include <Rcpp/RObject.h>

namespace Rcpp{ 

    class Environment: public RObject{
    public:
    
        /**
         * proxy class to allow read and write access to a binding in
         * an environment
         */
        class Binding {
        public:
            /**
             * Creates  a binding
             * 
             * @param env environment in which the binding is
             * @param name name of the binding
             */
            Binding( Environment& env, const std::string& name) ;
            
            /**
             * Is the binding an active binding
             */
            bool active() const ;
            
            /**
             * Is the binding locked
             */
            bool locked() const ;
            
            /**
             * Is the binding defined
             */
            bool exists() const ;
            
            /**
             * lock the binding
             */
            void lock( ) ;
            
            /**
             * unlock the binding
             */
            void unlock() ;
            
            /* lvalue uses */
            
            /**
             * Assigning another binding to this has the effect of 
             * assigning the rhs to the environment. 
             *
             * For example :
             * Environment e = ... // get an environment somehow
             * Environment f = ... // get an environment somehow
             * e["x"] = f["y"] ;
             *
             * after this, the variable x in the environment e will
             * contain the same variable as "y" in the environment "f"
             */
            Binding& operator=(const Binding& rhs) ;
            
            /**
             * Assign the rhs to the binding
             *
             * For example: 
             * Environment e= ... ; // get some environment
             * e["foo"] = SclalarInteger( 10 ) ;
             * 
             * after this e will contain the variable "foo" with the value 
             * 10L
             */
            Binding& operator=(SEXP rhs) ;
            
            /**
             * templated assignement. The rhs if first wrapped using one
             * of the forms of "wrap" and then the wrapped value is
             * assigned to the binding
             *
             * For example: 
             * Environment e = ... ;
             * e[ "foo" ] = 10 ;
             * e[ "bar"] = "foobar" ;
             * 
             * vector<int> v; v.push_back(10); v.push_back(20 );
             * e[ "foo" ] = v ;
             * 
             * with GCC4.4 :
             * e["bla" ] = { 1,2,3};
             */
            template <typename WRAPPABLE> Binding& operator=(const WRAPPABLE& rhs) ;
            
            /* rvalue */
            /**
             * Retrieves the value of the binding as a T object
             *
             * The requirement on the T type is that as<T> makes sense
             * which can either mean that a specialization exists
             * or that T has a T(SEXP) constructor
             */
            template <typename T> operator T() const ;
            
            
        private:
            /**
             * Reference to the environment if the binding
             */
            Environment& env ;
            
            /**
             * name of the binding
             */
            std::string name ;
        } ;
    
        /**
         * Creates a binding for a variable in this environment
         *
         * The Binding class is a proxy class, so depending on how the result
         * of this operator call is used, the variable is either retrieved 
         * or modified. See the Binding class for details
         */
        const Binding operator[]( const std::string& name) const ;
    
        /**
         * Same as above, but for a non-const Environment
         */
        Binding operator[](const std::string& name) ;
    
        friend class Binding ;
    
        Environment() ;

        /**
         * wraps the given environment
         *
         * if the SEXP is not an environment, and exception is thrown
         */
        Environment(SEXP x);
    
        /**
         * copy constructor
         */
        Environment(const Environment& other);
    
        /**
         * assignment
         */
        Environment& operator=(const Environment& other); 
    
        /**
         * Gets the environment associated with the given name
         *
         * @param name name of the environment, e.g "package:Rcpp"
         */
        Environment( const std::string& name );
    
        /**
         * Gets the environment in the given position of the search path
         * 
         * @param pos (1-based) position of the environment, e.g pos=1 gives the
         *        global environment
         */
        Environment( int pos );
    
        /**
         * Nothing specific
         */ 
        ~Environment() ;
        
        /**
         * The list of objects in the environment
         * 
         * the same as calling this from R: 
         * > ls( envir = this, all = all )
         *
         * @param all same meaning as in ?ls
         */ 
        SEXP ls(bool all) const ;
    
        /**
         * Get an object from the environment
         *
         * @param name name of the object
         *
         * @return a SEXP (possibly R_NilValue)
         */
        SEXP get(const std::string& name) const ;
    
        /**
         * Get an object from the environment or one of its
         * parents
         *
         * @param name name of the object
         *
         */
        SEXP find( const std::string& name) const;
    
        /**
         * Indicates if an object called name exists in the 
         * environment
         *
         * @param name name of the object
         *
         * @return true if the object exists in the environment
         */
        bool exists( const std::string& name ) const ;
    
        /**
         * Attempts to assign x to name in this environment
         *
         * @param name name of the object to assign
         * @param x object to assign
         *
         * @return true if the assign was successfull
         * see ?bindingIsLocked
         *
         * @throw binding_is_locked if the binding is locked
         */
        bool assign( const std::string& name, SEXP x ) const;
    
        /**
         * wrap and assign. If there is a wrap method taking an object 
         * of WRAPPABLE type, then it is wrapped and the corresponding SEXP
         * is assigned in the environment
         *
         * @param name name of the object to assign
         * @param x wrappable object. anything that has a wrap( WRAPPABLE ) is fine
         */
        template <typename WRAPPABLE>
        bool assign( const std::string& name, const WRAPPABLE& x) const ;
    
        /**
         * @return true if this environment is locked
         * see ?environmentIsLocked for details of what this means
         */
        bool isLocked() const ;
    
        /**
         * remove an object from this environment
         */
        bool remove( const std::string& name );
    
        /**
         * locks this environment. See ?lockEnvironment
         *
         * @param bindings also lock the bindings of this environment ?
         */
        void lock(bool bindings) ;
    
        /**
         * Locks the given binding in the environment. 
         * see ?bindingIsLocked
         *
         * @throw no_such_binding if there is no such binding in this environment
         */
        void lockBinding(const std::string& name);
    
        /**
         * unlocks the given binding
         * see ?bindingIsLocked
         *
         * @throw no_such_binding if there is no such binding in this environment
         */
        void unlockBinding(const std::string& name);
    
        /**
         * @param name name of a potential binding
         *
         * @return true if the binding is locked in this environment
         * see ?bindingIsLocked
         *
         * @throw no_such_binding if there is no such binding in this environment
         */
        bool bindingIsLocked(const std::string& name) const;
    
        /**
         *
         * @param name name of a binding
         * 
         * @return true if the binding is active in this environment
         * see ?bindingIsActive
         *
         * @throw no_such_binding if there is no such binding in this environment
         */
        bool bindingIsActive(const std::string& name) const;
    
        /** 
         * Indicates if this is a user defined database.
         */
        bool is_user_database() const ;
    
        /**
         * @return the global environment. See ?globalenv
         */
        static Environment global_env();
    
        /**
         * @return The empty environment. See ?emptyenv
         */
        static Environment empty_env();
    
        /**
         * @return the base environment. See ?baseenv
         */
        static Environment base_env();
    
        /**
         * @return the base namespace. See ?baseenv
         */
        static Environment base_namespace();
    
        /**
         * @return the Rcpp namespace
         */
        static Environment Rcpp_namespace();
    
        /**
         * @param name the name of the package of which we want the namespace
         *
         * @return the namespace of the package
         *
         * @throw no_such_namespace 
         */
        static Environment namespace_env(const std::string& );
    
        /**
         * The parent environment of this environment
         */
        Environment parent() const;
    
        /**
         * creates a new environment whose this is the parent
         */
        Environment new_child(bool hashed) ; 
        
    };

} // namespace Rcpp

#endif
