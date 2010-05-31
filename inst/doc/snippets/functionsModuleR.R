require( Rcpp )

yada <- Module( "yada" )
yada$bar( 2L )
yada$foo( 2L, 10.0 )
yada$hello() 
yada$bla() 
yada$bla1( 2L) 
yada$bla2( 2L, 5.0 )

