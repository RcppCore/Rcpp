#include <rcpp_hello_world.h>

SEXP rcpp_hello_world(){
	using namespace Rcpp ;
	
	CharacterVector x(2) ;
	x[0] = "foo" ; 
	x[1] = "bar" ;
	
	NumericVector y(2) ;
	y[0] = 0.0 ;
	y[1] = 1.0 ;
	
	List z(2) ; 
	z[0] = x ; 
	z[1] = y ;
	
	return z ;
}
