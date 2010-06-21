// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// SingleLogicalResult.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__SingleLogicalResult_h
#define Rcpp__sugar__SingleLogicalResult_h

namespace Rcpp{
namespace sugar{  

template <bool> 
class forbidden_conversion ;

template <> 
class forbidden_conversion<true>{} ;

template <bool x>
class conversion_to_bool_is_forbidden : 
	conversion_to_bool_is_forbidden<x>{
	public:
		void touch(){}
}; 

template <bool NA,typename T>
class SingleLogicalResult {
public:
	const static int UNRESOLVED = -5 ;
	
	SingleLogicalResult() : result(UNRESOLVED) {} ;
	
	void apply(){
		if( result == UNRESOLVED ){
			static_cast<T&>(*this).apply() ;
		}
	}
	
	inline bool is_true(){
		apply() ;
		return result == TRUE ;
	}
	
	inline bool is_false(){
		apply() ;
		return result == FALSE ;
	}
	
	inline bool is_na(){
		apply() ;
		return Rcpp::traits::is_na<LGLSXP>( result ) ;
	}
	
	operator SEXP(){
		apply() ;
		return Rf_ScalarLogical( result ) ;
	}
	
	operator bool(){
		conversion_to_bool_is_forbidden<!NA> x ;
		x.touch() ;
		return is_true() ;
	}
	
	inline int size(){ return 1 ; }
	
	inline int get(){
		apply();
		return result;
	}
	
protected:
	int result ;
	inline void set(int x){ result = x ;}
	inline void reset(){ set(UNRESOLVED) ; }
	inline void set_true(){ set(TRUE); }
	inline void set_false(){ set(FALSE); }
	inline void set_na(){ set(NA_LOGICAL); }
	inline bool is_unresolved(){ return result == UNRESOLVED ; }
} ;

template <bool NA> struct negate{
	static inline int apply( int x ){
		return Rcpp::traits::is_na<LGLSXP>( x ) ? x : 
			( x ? FALSE : TRUE ) ;
	}
} ;
template<> struct negate<false>{
	static inline int apply( int x){
		return x ? FALSE : TRUE ;
	} ;
} ;


template <bool NA, typename T>
class Negate_SingleLogicalResult : public SingleLogicalResult<NA, Negate_SingleLogicalResult<NA,T> >{
public:
	typedef SingleLogicalResult<NA,T> TYPE ;
	typedef SingleLogicalResult<NA, Negate_SingleLogicalResult<NA,T> > BASE ;
	Negate_SingleLogicalResult( const TYPE& orig_ ) : orig(orig_) {}
	
	inline void apply(){
		BASE::set( negate<NA>::apply( orig.get() ) );
	}
	
private:
	const TYPE& orig ;
	
} ;

template <bool LHS_NA, typename LHS_T, bool RHS_NA, typename RHS_T>
class And_SingleLogicalResult_SingleLogicalResult : 
public SingleLogicalResult< 
	(LHS_NA || RHS_NA) , 
	And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,RHS_NA,RHS_T>
	>
{
public: 
	typedef SingleLogicalResult<LHS_NA,LHS_T> LHS_TYPE ;
	typedef SingleLogicalResult<RHS_NA,RHS_T> RHS_TYPE ;
	typedef SingleLogicalResult< 
		(LHS_NA || RHS_NA) , 
		And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,RHS_NA,RHS_T>
	> BASE ;
	
	And_SingleLogicalResult_SingleLogicalResult( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_) :
		lhs(lhs_), rhs(rhs_){} ;
	
	inline void apply(){
		int left = lhs.get() ;
		if( Rcpp::traits::is_na<LGLSXP>( left ) ){
			BASE::set( left ) ;
		} else if( left == FALSE ){
			BASE::set( FALSE ) ;
		} else {
			BASE::set( rhs.get() ) ;
		}
	}
		
private:
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	
} ;

// special version when we know the rhs is not NA     
template <bool LHS_NA, typename LHS_T, typename RHS_T>
class And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,false,RHS_T> : 
public SingleLogicalResult< 
	LHS_NA , 
	And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,false,RHS_T>
	>
{
public: 
	typedef SingleLogicalResult<LHS_NA,LHS_T> LHS_TYPE ;
	typedef SingleLogicalResult<false,RHS_T> RHS_TYPE ;
	typedef SingleLogicalResult< 
		LHS_NA, 
		And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,false,RHS_T>
	> BASE ;
	
	And_SingleLogicalResult_SingleLogicalResult( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_) :
		lhs(lhs_), rhs(rhs_){} ;
	
	inline void apply(){
		// here we know rhs does not have NA, so we start with the rhs
		int right = rhs.get() ;
		if( right == FALSE ){
			BASE::set( FALSE ) ;
		} else {
			BASE::set( lhs.get() ) ;
		}
	}
		
private:
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	
} ;


// special version when we know the lhs is not NA     
template <typename LHS_T, bool RHS_NA, typename RHS_T>
class And_SingleLogicalResult_SingleLogicalResult<false,LHS_T,RHS_NA,RHS_T> : 
public SingleLogicalResult< 
	RHS_NA , 
	And_SingleLogicalResult_SingleLogicalResult<false,LHS_T,RHS_NA,RHS_T>
	>
{
public: 
	typedef SingleLogicalResult<false,LHS_T> LHS_TYPE ;
	typedef SingleLogicalResult<RHS_NA,RHS_T> RHS_TYPE ;
	typedef SingleLogicalResult< 
		RHS_NA, 
		And_SingleLogicalResult_SingleLogicalResult<false,LHS_T,RHS_NA,RHS_T>
	> BASE ;
	
	And_SingleLogicalResult_SingleLogicalResult( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_) :
		lhs(lhs_), rhs(rhs_){} ;
	
	inline void apply(){
		// here we know lhs does not have NA, so we start with the rhs
		int left = lhs.get() ;
		if( left == FALSE ){
			BASE::set( FALSE ) ;
		} else {
			BASE::set( rhs.get() ) ;
		}
	}
		
private:
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	
} ;

// special version when we know both the lhs and the rhs are not NA     
template <typename LHS_T, typename RHS_T>
class And_SingleLogicalResult_SingleLogicalResult<false,LHS_T,false,RHS_T> : 
public SingleLogicalResult< 
	false , 
	And_SingleLogicalResult_SingleLogicalResult<false,LHS_T,false,RHS_T>
	>
{
public: 
	typedef SingleLogicalResult<false,LHS_T> LHS_TYPE ;
	typedef SingleLogicalResult<false,RHS_T> RHS_TYPE ;
	typedef SingleLogicalResult< 
		false, 
		And_SingleLogicalResult_SingleLogicalResult<false,LHS_T,false,RHS_T>
	> BASE ;
	
	And_SingleLogicalResult_SingleLogicalResult( const LHS_TYPE& lhs_, const RHS_TYPE& rhs_) :
		lhs(lhs_), rhs(rhs_){} ;
	
	inline void apply(){
		int left = lhs.get() ;
		if( left == FALSE ){
			BASE::set( FALSE ) ;
		} else {
			BASE::set( rhs.get() ) ;
		}
	}
		
private:
	const LHS_TYPE& lhs ;
	const RHS_TYPE& rhs ;
	
} ;

}
}

template <bool NA,typename T>
inline Rcpp::sugar::Negate_SingleLogicalResult<NA,T> 
operator!( const Rcpp::sugar::SingleLogicalResult<NA,T>& x){
	return Rcpp::sugar::Negate_SingleLogicalResult<NA,T>( x );
}

template <bool LHS_NA, typename LHS_T, bool RHS_NA, typename RHS_T>
inline Rcpp::sugar::And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,RHS_NA,RHS_T>
operator&&( 
	const Rcpp::sugar::SingleLogicalResult<LHS_NA,LHS_T>& lhs, 
	const Rcpp::sugar::SingleLogicalResult<LHS_NA,LHS_T>& rhs
){
	return Rcpp::sugar::And_SingleLogicalResult_SingleLogicalResult<LHS_NA,LHS_T,RHS_NA,RHS_T>( lhs, rhs ) ;
}


#endif
