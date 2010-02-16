// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RObject.cpp: Rcpp R/C++ interface class library -- R Object support
//
// Copyright (C) 2009 Dirk Eddelbuettel and Romain Francois
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

namespace Rcpp {

void RObject::setSEXP(SEXP x){
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
	if( !R_has_slot( v, Rf_install(name.c_str())) ){
		throw no_such_slot() ; 
	}
} ;

RObject::SlotProxy& RObject::SlotProxy::operator=(const SlotProxy& rhs){
	set( rhs.get() ) ;
	return *this ;
}

const char* RObject::no_such_slot::what( ) const throw() {
	return "no such slot" ;
}

SEXP RObject::SlotProxy::get() const {
	return internal::try_catch( 
		Rf_lcons( Rf_install("slot"), Rf_cons( parent , 
			Rf_cons( Rf_mkString(slot_name.c_str()) , R_NilValue)))) ; 
			
}

void RObject::SlotProxy::set( SEXP x) const {
	internal::try_catch( 
		Rf_lcons( Rf_install("slot<-"), 
				Rf_cons( parent, Rf_cons( Rf_mkString(slot_name.c_str()), 
					Rf_cons( Rf_ScalarLogical(TRUE) , 
						Rf_cons( x , R_NilValue)  ) )))) ; 
}

SEXP RObject::AttributeProxy::get() const {
	return Rf_getAttrib( parent, Rf_install( attr_name.c_str() ) ) ;
}

void RObject::AttributeProxy::set(SEXP x) const{
	Rf_setAttrib( parent, Rf_install(attr_name.c_str()), x ) ;
}

RObject::AttributeProxy::AttributeProxy( const RObject& v, const std::string& name) :
	parent(v), attr_name(name) {};

RObject::AttributeProxy& RObject::AttributeProxy::operator=(const AttributeProxy& rhs){
	set( rhs.get() ) ;
	return *this ;
}

RObject::AttributeProxy RObject::attr( const std::string& name) const{
	return AttributeProxy( *this, name)  ;
}

/* S4 */

bool RObject::hasSlot(const std::string& name) const throw(not_s4){
	if( !Rf_isS4(m_sexp) ) throw not_s4() ;
	return R_has_slot( m_sexp, Rf_mkString(name.c_str()) ) ;
}

RObject::SlotProxy RObject::slot(const std::string& name) const throw(not_s4){
	if( !Rf_isS4(m_sexp) ) throw not_s4() ;
	return SlotProxy( *this, name ) ;
}


const char* RObject::not_compatible::what( ) const throw() {
	return message.c_str() ;
}
const char* RObject::not_s4::what( ) const throw() {
	return "not an S4 object" ;
}
const char* RObject::index_out_of_bounds::what( ) const throw() {
	return "array or list out of bounds" ;
}

} // namespace Rcpp

