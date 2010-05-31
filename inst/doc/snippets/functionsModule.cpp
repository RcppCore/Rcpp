RCPP_MODULE(yada){
	using namespace Rcpp ;
	
	function( "hello" , &hello ) ;
	function( "bar"   , &bar   ) ;
	function( "foo"   , &foo   ) ;
	function( "bla"   , &bla   ) ;
	function( "bla1"  , &bla1   ) ;
	function( "bla2"  , &bla2   ) ;
}

