// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RObject.cpp: Rcpp R/C++ interface class library -- R Object support
//
// Copyright (C) 2009 - 2011 Dirk Eddelbuettel and Romain Francois
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

#include <RcppCommon.h>
#include <Rcpp/RObject.h>

namespace Rcpp {
    namespace internal{

        SEXPstack::SEXPstack() : 
            stack( Rf_allocVector(VECSXP,1000) ), 
            data( get_vector_ptr(stack) ), 
            len( 1000 ), 
            top( 0 )
        {
            R_PreserveObject( stack ) ;  
        }
    
        void SEXPstack::preserve( SEXP object){
            if( top == len-1) grow() ;
            SET_VECTOR_ELT( stack, top++, object ) ;
        }
    
        void SEXPstack::release( SEXP object ){
            int n = top - 1 ;
            while( n > -1 && data[n] != object ) n-- ;
            while( n < top - 1 ){ 
                data[n] = data[n+1] ; 
                n++ ;
            }
            data[--top] = R_NilValue ;
        }
    
        void SEXPstack::grow( ){
            int newsize = len * 2 ;
            SEXP x = PROTECT( Rf_allocVector( VECSXP, newsize ) ) ;
            SEXP* x_data = get_vector_ptr( x) ;
            std::copy( data, data + len, x_data ) ;
            stack = x ;
            UNPROTECT(1);
            data = x_data ;
        }
    }

    // internal::SEXPstack RObject::PPstack ;    
    
    void RObject::setSEXP(SEXP x){
        RCPP_DEBUG_1( "RObject::setSEXP(SEXP = <%p> )", x ) ; 
    
        /* if we are setting to the same SEXP as we already have, do nothing */
        if( x != m_sexp ){
                
            /* the previous SEXP was not NULL, so release it */
            release() ;
                
            /* set the SEXP */
            m_sexp = x ;
                
            /* the new SEXP is not NULL, so preserve it */
            preserve() ;
                        
            update() ;
        }
    }

    /* copy constructor */
    RObject::RObject( const RObject& other ){
        SEXP x = other.asSexp() ;       
        setSEXP( x ) ; 
    }

    RObject& RObject::operator=( const RObject& other){
        SEXP x = other.asSexp() ;       
        setSEXP( x ) ; 
        return *this ;
    }

    RObject& RObject::operator=( SEXP other ){
        setSEXP( other ) ; 
        return *this ;
    }

    RObject::~RObject() {
        release() ;
        logTxt("~RObject");
    }

    std::vector<std::string> RObject::attributeNames() const {
        /* inspired from do_attributes@attrib.c */
        
        std::vector<std::string> v ;
        SEXP attrs = ATTRIB(m_sexp);
        while( attrs != R_NilValue ){
            v.push_back( std::string(CHAR(PRINTNAME(TAG(attrs)))) ) ;
            attrs = CDR( attrs ) ;
        }
        return v ;
    }

    bool RObject::hasAttribute( const std::string& attr) const {
        SEXP attrs = ATTRIB(m_sexp);
        while( attrs != R_NilValue ){
            if( attr == CHAR(PRINTNAME(TAG(attrs))) ){
                return true ;
            }
            attrs = CDR( attrs ) ;
        }
        return false; /* give up */
    }

    RObject::SlotProxy::SlotProxy( const RObject& v, const std::string& name) : 
        parent(v), slot_name(name)
    {
        SEXP nameSym = Rf_install(name.c_str());            // cannot be gc()'ed  once in symbol table
        if( !R_has_slot( v, nameSym) ){
            throw no_such_slot() ; 
        }
    }

    RObject::SlotProxy& RObject::SlotProxy::operator=(const SlotProxy& rhs){
        set( rhs.get() ) ;
        return *this ;
    }


    SEXP RObject::SlotProxy::get() const {
        SEXP slotSym = Rf_install( slot_name.c_str() );     // cannot be gc()'ed  once in symbol table
        return R_do_slot( parent, slotSym ) ;       
    }

    void RObject::SlotProxy::set( SEXP x) const {
        SEXP slotnameSym = Rf_install( slot_name.c_str() ); // cannot be gc()'ed  once in symbol table
        // the SEXP might change (.Data)
        SEXP new_obj = PROTECT( R_do_slot_assign(parent, slotnameSym, x) ) ;
        const_cast<RObject&>(parent).setSEXP( new_obj ) ;
        UNPROTECT(1) ;
    }

    SEXP RObject::AttributeProxy::get() const {
        SEXP attrnameSym = Rf_install( attr_name.c_str() ); // cannot be gc()'ed  once in symbol table
        return Rf_getAttrib( parent, attrnameSym ) ;
    }

    void RObject::AttributeProxy::set(SEXP x) const{
        SEXP attrnameSym = Rf_install( attr_name.c_str() ); // cannot be gc()'ed  once in symbol table
#if RCPP_DEBUG_LEVEL > 0
        RCPP_DEBUG_1( "RObject::AttributeProxy::set() before = <%p>", parent.asSexp() ) ;
        SEXP res = Rf_setAttrib( parent, attrnameSym, x ) ;
        RCPP_DEBUG_1( "RObject::AttributeProxy::set() after  = <%p>", res ) ;
#else
        Rf_setAttrib( parent, attrnameSym, x ) ;
#endif
    }

    RObject::AttributeProxy::AttributeProxy( const RObject& v, const std::string& name) :
        parent(v), attr_name(name) {}

    RObject::AttributeProxy& RObject::AttributeProxy::operator=(const AttributeProxy& rhs){
        set( rhs.get() ) ;
        return *this ;
    }

    RObject::AttributeProxy RObject::attr( const std::string& name) const{
        return AttributeProxy( *this, name)  ;
    }

    /* S4 */

    bool RObject::hasSlot(const std::string& name) const {
        if( !Rf_isS4(m_sexp) ) throw not_s4() ;
        return R_has_slot( m_sexp, Rf_mkString(name.c_str()) ) ;
    }

    RObject::SlotProxy RObject::slot(const std::string& name) const {
        if( !Rf_isS4(m_sexp) ) throw not_s4() ;
        return SlotProxy( *this, name ) ;
    }

} // namespace Rcpp

