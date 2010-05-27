std::string hello(){
	return "hello" ;
}

int bar( int x){
	return x*2 ;
}
        
double foo( int x, double y){
	return x * y ;
}

void bla( ){
	Rprintf( "hello\\n" ) ;
}

void bla1( int x){
	Rprintf( "hello (x = %d)\\n", x ) ;
}

void bla2( int x, double y){
	Rprintf( "hello (x = %d, y = %5.2f)\\n", x, y ) ;
}

