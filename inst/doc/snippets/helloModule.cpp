
const char* hello( std::string who ){
	std::string result( "hello " ) ;
	result += who ; 
	return result.c_str() ;
}

RCPP_MODULE(yada){
	using namespace Rcpp ;
	function( "hello", &hello ) ;
}

