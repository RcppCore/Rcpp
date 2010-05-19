// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Module_generated_function.h: Rcpp R/C++ interface class library -- Rcpp modules
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Module_generated_CppFunction_h
#define Rcpp_Module_generated_CppFunction_h
    
template <typename OUT>
class CppFunction0 : public CppFunction {
	public:
		CppFunction0(OUT (*fun)(void) ) : CppFunction(), ptr_fun(fun){}
		SEXP operator()(SEXP* args) throw(std::range_error) {
			return Rcpp::wrap( ptr_fun() ) ;
		}
		
		inline int nargs(){ return 0; }
		
	private:
		OUT (*ptr_fun)(void) ;	                    
} ;


template <>
class CppFunction0<void> : public CppFunction {
	public:
		CppFunction0(void (*fun)(void) )  ;
		
		SEXP operator()(SEXP* args) throw(std::exception) ;
		
		inline int nargs(){ return 0; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(void) ;	
} ;


template <typename OUT, typename U0>
class CppFunction1 : public CppFunction {
	public:

		CppFunction1(OUT (*fun)(U0) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ) ) ) ;
		}
		
		inline int nargs(){ return 1; }
		
	private:
		OUT (*ptr_fun)(U0) ;	
} ;

template <typename U0>
class CppFunction1<void,U0> : public CppFunction {
	public:
		CppFunction1(void (*fun)(U0) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 1; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0) ;	
} ;



template <typename OUT, typename U0, typename U1>
class CppFunction2 : public CppFunction {
	public:

		CppFunction2(OUT (*fun)(U0, U1) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ) ) ) ;
		}
		
		inline int nargs(){ return 2; }
		
	private:
		OUT (*ptr_fun)(U0, U1) ;	
} ;

template <typename U0, typename U1>
class CppFunction2<void,U0, U1> : public CppFunction {
	public:
		CppFunction2(void (*fun)(U0, U1) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 2; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2>
class CppFunction3 : public CppFunction {
	public:

		CppFunction3(OUT (*fun)(U0, U1, U2) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ) ) ) ;
		}
		
		inline int nargs(){ return 3; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2) ;	
} ;

template <typename U0, typename U1, typename U2>
class CppFunction3<void,U0, U1, U2> : public CppFunction {
	public:
		CppFunction3(void (*fun)(U0, U1, U2) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 3; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3>
class CppFunction4 : public CppFunction {
	public:

		CppFunction4(OUT (*fun)(U0, U1, U2, U3) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ) ) ) ;
		}
		
		inline int nargs(){ return 4; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3>
class CppFunction4<void,U0, U1, U2, U3> : public CppFunction {
	public:
		CppFunction4(void (*fun)(U0, U1, U2, U3) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 4; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4>
class CppFunction5 : public CppFunction {
	public:

		CppFunction5(OUT (*fun)(U0, U1, U2, U3, U4) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ) ) ) ;
		}
		
		inline int nargs(){ return 5; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4>
class CppFunction5<void,U0, U1, U2, U3, U4> : public CppFunction {
	public:
		CppFunction5(void (*fun)(U0, U1, U2, U3, U4) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 5; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5>
class CppFunction6 : public CppFunction {
	public:

		CppFunction6(OUT (*fun)(U0, U1, U2, U3, U4, U5) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ) ) ) ;
		}
		
		inline int nargs(){ return 6; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5>
class CppFunction6<void,U0, U1, U2, U3, U4, U5> : public CppFunction {
	public:
		CppFunction6(void (*fun)(U0, U1, U2, U3, U4, U5) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 6; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6>
class CppFunction7 : public CppFunction {
	public:

		CppFunction7(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ) ) ) ;
		}
		
		inline int nargs(){ return 7; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6>
class CppFunction7<void,U0, U1, U2, U3, U4, U5, U6> : public CppFunction {
	public:
		CppFunction7(void (*fun)(U0, U1, U2, U3, U4, U5, U6) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 7; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7>
class CppFunction8 : public CppFunction {
	public:

		CppFunction8(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ) ) ) ;
		}
		
		inline int nargs(){ return 8; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7>
class CppFunction8<void,U0, U1, U2, U3, U4, U5, U6, U7> : public CppFunction {
	public:
		CppFunction8(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 8; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8>
class CppFunction9 : public CppFunction {
	public:

		CppFunction9(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ) ) ) ;
		}
		
		inline int nargs(){ return 9; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8>
class CppFunction9<void,U0, U1, U2, U3, U4, U5, U6, U7, U8> : public CppFunction {
	public:
		CppFunction9(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 9; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9>
class CppFunction10 : public CppFunction {
	public:

		CppFunction10(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ) ) ) ;
		}
		
		inline int nargs(){ return 10; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9>
class CppFunction10<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9> : public CppFunction {
	public:
		CppFunction10(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 10; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10>
class CppFunction11 : public CppFunction {
	public:

		CppFunction11(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ) ) ) ;
		}
		
		inline int nargs(){ return 11; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10>
class CppFunction11<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10> : public CppFunction {
	public:
		CppFunction11(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 11; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11>
class CppFunction12 : public CppFunction {
	public:

		CppFunction12(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ) ) ) ;
		}
		
		inline int nargs(){ return 12; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11>
class CppFunction12<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11> : public CppFunction {
	public:
		CppFunction12(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 12; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12>
class CppFunction13 : public CppFunction {
	public:

		CppFunction13(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ) ) ) ;
		}
		
		inline int nargs(){ return 13; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12>
class CppFunction13<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12> : public CppFunction {
	public:
		CppFunction13(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 13; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13>
class CppFunction14 : public CppFunction {
	public:

		CppFunction14(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ) ) ) ;
		}
		
		inline int nargs(){ return 14; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13>
class CppFunction14<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13> : public CppFunction {
	public:
		CppFunction14(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 14; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14>
class CppFunction15 : public CppFunction {
	public:

		CppFunction15(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ) ) ) ;
		}
		
		inline int nargs(){ return 15; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14>
class CppFunction15<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14> : public CppFunction {
	public:
		CppFunction15(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 15; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15>
class CppFunction16 : public CppFunction {
	public:

		CppFunction16(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ) ) ) ;
		}
		
		inline int nargs(){ return 16; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15>
class CppFunction16<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15> : public CppFunction {
	public:
		CppFunction16(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 16; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16>
class CppFunction17 : public CppFunction {
	public:

		CppFunction17(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ) ) ) ;
		}
		
		inline int nargs(){ return 17; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16>
class CppFunction17<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16> : public CppFunction {
	public:
		CppFunction17(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 17; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17>
class CppFunction18 : public CppFunction {
	public:

		CppFunction18(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ) ) ) ;
		}
		
		inline int nargs(){ return 18; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17>
class CppFunction18<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17> : public CppFunction {
	public:
		CppFunction18(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 18; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18>
class CppFunction19 : public CppFunction {
	public:

		CppFunction19(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ) ) ) ;
		}
		
		inline int nargs(){ return 19; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18>
class CppFunction19<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18> : public CppFunction {
	public:
		CppFunction19(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 19; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19>
class CppFunction20 : public CppFunction {
	public:

		CppFunction20(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ) ) ) ;
		}
		
		inline int nargs(){ return 20; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19>
class CppFunction20<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19> : public CppFunction {
	public:
		CppFunction20(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 20; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20>
class CppFunction21 : public CppFunction {
	public:

		CppFunction21(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ) ) ) ;
		}
		
		inline int nargs(){ return 21; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20>
class CppFunction21<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20> : public CppFunction {
	public:
		CppFunction21(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 21; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21>
class CppFunction22 : public CppFunction {
	public:

		CppFunction22(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ) ) ) ;
		}
		
		inline int nargs(){ return 22; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21>
class CppFunction22<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21> : public CppFunction {
	public:
		CppFunction22(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 22; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22>
class CppFunction23 : public CppFunction {
	public:

		CppFunction23(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ) ) ) ;
		}
		
		inline int nargs(){ return 23; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22>
class CppFunction23<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22> : public CppFunction {
	public:
		CppFunction23(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 23; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23>
class CppFunction24 : public CppFunction {
	public:

		CppFunction24(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ) ) ) ;
		}
		
		inline int nargs(){ return 24; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23>
class CppFunction24<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23> : public CppFunction {
	public:
		CppFunction24(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 24; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24>
class CppFunction25 : public CppFunction {
	public:

		CppFunction25(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ) ) ) ;
		}
		
		inline int nargs(){ return 25; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24>
class CppFunction25<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24> : public CppFunction {
	public:
		CppFunction25(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 25; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25>
class CppFunction26 : public CppFunction {
	public:

		CppFunction26(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ) ) ) ;
		}
		
		inline int nargs(){ return 26; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25>
class CppFunction26<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25> : public CppFunction {
	public:
		CppFunction26(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 26; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26>
class CppFunction27 : public CppFunction {
	public:

		CppFunction27(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ) ) ) ;
		}
		
		inline int nargs(){ return 27; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26>
class CppFunction27<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26> : public CppFunction {
	public:
		CppFunction27(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 27; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27>
class CppFunction28 : public CppFunction {
	public:

		CppFunction28(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ) ) ) ;
		}
		
		inline int nargs(){ return 28; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27>
class CppFunction28<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27> : public CppFunction {
	public:
		CppFunction28(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 28; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28>
class CppFunction29 : public CppFunction {
	public:

		CppFunction29(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ) ) ) ;
		}
		
		inline int nargs(){ return 29; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28>
class CppFunction29<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28> : public CppFunction {
	public:
		CppFunction29(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 29; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29>
class CppFunction30 : public CppFunction {
	public:

		CppFunction30(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ) ) ) ;
		}
		
		inline int nargs(){ return 30; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29>
class CppFunction30<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29> : public CppFunction {
	public:
		CppFunction30(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 30; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30>
class CppFunction31 : public CppFunction {
	public:

		CppFunction31(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ) ) ) ;
		}
		
		inline int nargs(){ return 31; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30>
class CppFunction31<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30> : public CppFunction {
	public:
		CppFunction31(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 31; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31>
class CppFunction32 : public CppFunction {
	public:

		CppFunction32(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ) ) ) ;
		}
		
		inline int nargs(){ return 32; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31>
class CppFunction32<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31> : public CppFunction {
	public:
		CppFunction32(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 32; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32>
class CppFunction33 : public CppFunction {
	public:

		CppFunction33(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ) ) ) ;
		}
		
		inline int nargs(){ return 33; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32>
class CppFunction33<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32> : public CppFunction {
	public:
		CppFunction33(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 33; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33>
class CppFunction34 : public CppFunction {
	public:

		CppFunction34(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ) ) ) ;
		}
		
		inline int nargs(){ return 34; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33>
class CppFunction34<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33> : public CppFunction {
	public:
		CppFunction34(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 34; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34>
class CppFunction35 : public CppFunction {
	public:

		CppFunction35(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ) ) ) ;
		}
		
		inline int nargs(){ return 35; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34>
class CppFunction35<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34> : public CppFunction {
	public:
		CppFunction35(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 35; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35>
class CppFunction36 : public CppFunction {
	public:

		CppFunction36(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ) ) ) ;
		}
		
		inline int nargs(){ return 36; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35>
class CppFunction36<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35> : public CppFunction {
	public:
		CppFunction36(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 36; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36>
class CppFunction37 : public CppFunction {
	public:

		CppFunction37(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ) ) ) ;
		}
		
		inline int nargs(){ return 37; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36>
class CppFunction37<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36> : public CppFunction {
	public:
		CppFunction37(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 37; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37>
class CppFunction38 : public CppFunction {
	public:

		CppFunction38(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ) ) ) ;
		}
		
		inline int nargs(){ return 38; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37>
class CppFunction38<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37> : public CppFunction {
	public:
		CppFunction38(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 38; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38>
class CppFunction39 : public CppFunction {
	public:

		CppFunction39(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ) ) ) ;
		}
		
		inline int nargs(){ return 39; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38>
class CppFunction39<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38> : public CppFunction {
	public:
		CppFunction39(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 39; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39>
class CppFunction40 : public CppFunction {
	public:

		CppFunction40(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ) ) ) ;
		}
		
		inline int nargs(){ return 40; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39>
class CppFunction40<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39> : public CppFunction {
	public:
		CppFunction40(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 40; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40>
class CppFunction41 : public CppFunction {
	public:

		CppFunction41(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ) ) ) ;
		}
		
		inline int nargs(){ return 41; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40>
class CppFunction41<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40> : public CppFunction {
	public:
		CppFunction41(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 41; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41>
class CppFunction42 : public CppFunction {
	public:

		CppFunction42(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ) ) ) ;
		}
		
		inline int nargs(){ return 42; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41>
class CppFunction42<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41> : public CppFunction {
	public:
		CppFunction42(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 42; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42>
class CppFunction43 : public CppFunction {
	public:

		CppFunction43(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ) ) ) ;
		}
		
		inline int nargs(){ return 43; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42>
class CppFunction43<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42> : public CppFunction {
	public:
		CppFunction43(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 43; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43>
class CppFunction44 : public CppFunction {
	public:

		CppFunction44(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ) ) ) ;
		}
		
		inline int nargs(){ return 44; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43>
class CppFunction44<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43> : public CppFunction {
	public:
		CppFunction44(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 44; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44>
class CppFunction45 : public CppFunction {
	public:

		CppFunction45(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ) ) ) ;
		}
		
		inline int nargs(){ return 45; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44>
class CppFunction45<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44> : public CppFunction {
	public:
		CppFunction45(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 45; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45>
class CppFunction46 : public CppFunction {
	public:

		CppFunction46(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ) ) ) ;
		}
		
		inline int nargs(){ return 46; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45>
class CppFunction46<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45> : public CppFunction {
	public:
		CppFunction46(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 46; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46>
class CppFunction47 : public CppFunction {
	public:

		CppFunction47(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ) ) ) ;
		}
		
		inline int nargs(){ return 47; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46>
class CppFunction47<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46> : public CppFunction {
	public:
		CppFunction47(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 47; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47>
class CppFunction48 : public CppFunction {
	public:

		CppFunction48(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ) ) ) ;
		}
		
		inline int nargs(){ return 48; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47>
class CppFunction48<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47> : public CppFunction {
	public:
		CppFunction48(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 48; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48>
class CppFunction49 : public CppFunction {
	public:

		CppFunction49(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ) ) ) ;
		}
		
		inline int nargs(){ return 49; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48>
class CppFunction49<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48> : public CppFunction {
	public:
		CppFunction49(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 49; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49>
class CppFunction50 : public CppFunction {
	public:

		CppFunction50(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ) ) ) ;
		}
		
		inline int nargs(){ return 50; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49>
class CppFunction50<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49> : public CppFunction {
	public:
		CppFunction50(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 50; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50>
class CppFunction51 : public CppFunction {
	public:

		CppFunction51(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ) ) ) ;
		}
		
		inline int nargs(){ return 51; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50>
class CppFunction51<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50> : public CppFunction {
	public:
		CppFunction51(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 51; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51>
class CppFunction52 : public CppFunction {
	public:

		CppFunction52(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ) ) ) ;
		}
		
		inline int nargs(){ return 52; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51>
class CppFunction52<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51> : public CppFunction {
	public:
		CppFunction52(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 52; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52>
class CppFunction53 : public CppFunction {
	public:

		CppFunction53(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ) ) ) ;
		}
		
		inline int nargs(){ return 53; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52>
class CppFunction53<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52> : public CppFunction {
	public:
		CppFunction53(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 53; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53>
class CppFunction54 : public CppFunction {
	public:

		CppFunction54(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ) ) ) ;
		}
		
		inline int nargs(){ return 54; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53>
class CppFunction54<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53> : public CppFunction {
	public:
		CppFunction54(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 54; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54>
class CppFunction55 : public CppFunction {
	public:

		CppFunction55(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ) ) ) ;
		}
		
		inline int nargs(){ return 55; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54>
class CppFunction55<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54> : public CppFunction {
	public:
		CppFunction55(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 55; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55>
class CppFunction56 : public CppFunction {
	public:

		CppFunction56(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ) ) ) ;
		}
		
		inline int nargs(){ return 56; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55>
class CppFunction56<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55> : public CppFunction {
	public:
		CppFunction56(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 56; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56>
class CppFunction57 : public CppFunction {
	public:

		CppFunction57(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ) ) ) ;
		}
		
		inline int nargs(){ return 57; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56>
class CppFunction57<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56> : public CppFunction {
	public:
		CppFunction57(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 57; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57>
class CppFunction58 : public CppFunction {
	public:

		CppFunction58(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ) ) ) ;
		}
		
		inline int nargs(){ return 58; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57>
class CppFunction58<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57> : public CppFunction {
	public:
		CppFunction58(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 58; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58>
class CppFunction59 : public CppFunction {
	public:

		CppFunction59(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ) ) ) ;
		}
		
		inline int nargs(){ return 59; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58>
class CppFunction59<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58> : public CppFunction {
	public:
		CppFunction59(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 59; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59>
class CppFunction60 : public CppFunction {
	public:

		CppFunction60(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ) ) ) ;
		}
		
		inline int nargs(){ return 60; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59>
class CppFunction60<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59> : public CppFunction {
	public:
		CppFunction60(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 60; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60>
class CppFunction61 : public CppFunction {
	public:

		CppFunction61(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ) ) ) ;
		}
		
		inline int nargs(){ return 61; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60>
class CppFunction61<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60> : public CppFunction {
	public:
		CppFunction61(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 61; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61>
class CppFunction62 : public CppFunction {
	public:

		CppFunction62(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ) ) ) ;
		}
		
		inline int nargs(){ return 62; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61>
class CppFunction62<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61> : public CppFunction {
	public:
		CppFunction62(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 62; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61, typename U62>
class CppFunction63 : public CppFunction {
	public:

		CppFunction63(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ), Rcpp::as<U62>( args[62] ) ) ) ;
		}
		
		inline int nargs(){ return 63; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61, typename U62>
class CppFunction63<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62> : public CppFunction {
	public:
		CppFunction63(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ), Rcpp::as<U62>( args[62] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 63; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61, typename U62, typename U63>
class CppFunction64 : public CppFunction {
	public:

		CppFunction64(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ), Rcpp::as<U62>( args[62] ), Rcpp::as<U63>( args[63] ) ) ) ;
		}
		
		inline int nargs(){ return 64; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61, typename U62, typename U63>
class CppFunction64<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63> : public CppFunction {
	public:
		CppFunction64(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ), Rcpp::as<U62>( args[62] ), Rcpp::as<U63>( args[63] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 64; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63) ;	
} ;



template <typename OUT, typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61, typename U62, typename U63, typename U64>
class CppFunction65 : public CppFunction {
	public:

		CppFunction65(OUT (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63, U64) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception){
			return Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ), Rcpp::as<U62>( args[62] ), Rcpp::as<U63>( args[63] ), Rcpp::as<U64>( args[64] ) ) ) ;
		}
		
		inline int nargs(){ return 65; }
		
	private:
		OUT (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63, U64) ;	
} ;

template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49, typename U50, typename U51, typename U52, typename U53, typename U54, typename U55, typename U56, typename U57, typename U58, typename U59, typename U60, typename U61, typename U62, typename U63, typename U64>
class CppFunction65<void,U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63, U64> : public CppFunction {
	public:
		CppFunction65(void (*fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63, U64) ) : CppFunction(), ptr_fun(fun){}
		
		SEXP operator()(SEXP* args) throw(std::exception) {
			ptr_fun( Rcpp::as<U0>( args[0] ), Rcpp::as<U1>( args[1] ), Rcpp::as<U2>( args[2] ), Rcpp::as<U3>( args[3] ), Rcpp::as<U4>( args[4] ), Rcpp::as<U5>( args[5] ), Rcpp::as<U6>( args[6] ), Rcpp::as<U7>( args[7] ), Rcpp::as<U8>( args[8] ), Rcpp::as<U9>( args[9] ), Rcpp::as<U10>( args[10] ), Rcpp::as<U11>( args[11] ), Rcpp::as<U12>( args[12] ), Rcpp::as<U13>( args[13] ), Rcpp::as<U14>( args[14] ), Rcpp::as<U15>( args[15] ), Rcpp::as<U16>( args[16] ), Rcpp::as<U17>( args[17] ), Rcpp::as<U18>( args[18] ), Rcpp::as<U19>( args[19] ), Rcpp::as<U20>( args[20] ), Rcpp::as<U21>( args[21] ), Rcpp::as<U22>( args[22] ), Rcpp::as<U23>( args[23] ), Rcpp::as<U24>( args[24] ), Rcpp::as<U25>( args[25] ), Rcpp::as<U26>( args[26] ), Rcpp::as<U27>( args[27] ), Rcpp::as<U28>( args[28] ), Rcpp::as<U29>( args[29] ), Rcpp::as<U30>( args[30] ), Rcpp::as<U31>( args[31] ), Rcpp::as<U32>( args[32] ), Rcpp::as<U33>( args[33] ), Rcpp::as<U34>( args[34] ), Rcpp::as<U35>( args[35] ), Rcpp::as<U36>( args[36] ), Rcpp::as<U37>( args[37] ), Rcpp::as<U38>( args[38] ), Rcpp::as<U39>( args[39] ), Rcpp::as<U40>( args[40] ), Rcpp::as<U41>( args[41] ), Rcpp::as<U42>( args[42] ), Rcpp::as<U43>( args[43] ), Rcpp::as<U44>( args[44] ), Rcpp::as<U45>( args[45] ), Rcpp::as<U46>( args[46] ), Rcpp::as<U47>( args[47] ), Rcpp::as<U48>( args[48] ), Rcpp::as<U49>( args[49] ), Rcpp::as<U50>( args[50] ), Rcpp::as<U51>( args[51] ), Rcpp::as<U52>( args[52] ), Rcpp::as<U53>( args[53] ), Rcpp::as<U54>( args[54] ), Rcpp::as<U55>( args[55] ), Rcpp::as<U56>( args[56] ), Rcpp::as<U57>( args[57] ), Rcpp::as<U58>( args[58] ), Rcpp::as<U59>( args[59] ), Rcpp::as<U60>( args[60] ), Rcpp::as<U61>( args[61] ), Rcpp::as<U62>( args[62] ), Rcpp::as<U63>( args[63] ), Rcpp::as<U64>( args[64] ) ) ;
			return R_NilValue ;
		}
		
		inline int nargs(){ return 65; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U60, U61, U62, U63, U64) ;	
} ;



#endif

