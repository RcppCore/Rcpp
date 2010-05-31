// convenience typedef
typedef std::vector<double> vec ;

// helpers
void vec_assign( vec* obj, Rcpp::NumericVector data ){
	obj->assign( data.begin(), data.end() ) ;
}

void vec_insert( vec* obj, int position, Rcpp::NumericVector data){
	vec::iterator it = obj->begin() + position ;
	obj->insert( it, data.begin(), data.end() ) ;
}

Rcpp::NumericVector vec_asR( vec* obj ){
	return Rcpp::wrap( *obj ) ;
}

void vec_set( vec* obj, int i, double value ){
	obj->at( i ) = value ;
}

RCPP_MODULE(yada){
	using namespace Rcpp ;
	
	// we expose the class std::vector<double> as "vec" on the R side
	class_<vec>( "vec")
	
		// exposing member functions
	 	.method( "size", &vec::size)
 		.method( "max_size", &vec::max_size) 
 		.method( "resize", &vec::resize) 
 		.method( "capacity", &vec::capacity) 
 		.method( "empty", &vec::empty) 
 		.method( "reserve", &vec::reserve) 
 		.method( "push_back", &vec::push_back )
 		.method( "pop_back", &vec::pop_back )
 		.method( "clear", &vec::clear )
 		
 		// specifically exposing const member functions
 		.const_method( "back", &vec::back )
		.const_method( "front", &vec::front )
		.const_method( "at", &vec::at )
		
		// exposing free functions taking a std::vector<double>*
		// as their first argument
		.method( "assign", &vec_assign )
		.method( "insert", &vec_insert )
		.method( "as.vector", &vec_asR ) 
		
		// special methods for indexing
		.const_method( "[[", &vec::at )
		.method( "[[<-", &vec_set )

	;
}                     

