#include "rcpp_hello_world.h"

SEXP rcpp_hello_world(){
	using namespace Rcpp ;
	CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
	NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
	List z = List::create( x, y ) ;
	return z ;
}

SEXP hello_world_ex(){
	throw std::range_error( "boom" ) ;
	return R_NilValue ;
}

#if defined(WIN32)
extern "C" void R_init_RcppTestB( DllInfo* info){
	std::set_terminate( forward_uncaught_exceptions_to_r ) ;
}
#endif
