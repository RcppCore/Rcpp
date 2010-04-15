#!/usr/bin/r -t
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

test.wrap.map.string.int <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::map< std::string, int > m ;
	m["b"] = 100;
  	m["a"] = 200;
  	m["c"] = 300;
  	return wrap(m) ;
	' )
	
	checkEquals( funx(), c( a = 200L, b = 100L, c = 300L), 
		msg = "wrap( map<string,int>) " )
}

test.wrap.map.string.double <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::map<std::string,double> m ;
	m["b"] = 100;
  	m["a"] = 200;
  	m["c"] = 300;
  	return wrap(m) ;
	' )
	
	checkEquals( funx(), c( a = 200, b = 100, c = 300), 
		msg = "wrap( map<string,double>) " )
}

test.wrap.map.string.bool <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::map<std::string,bool> m ;
	m["b"] = true;
  	m["a"] = false;
  	m["c"] = true;
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = FALSE, b = TRUE, c = TRUE ), 
		msg = "wrap( map<string,bool>) " )
}

test.wrap.map.string.Rbyte <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::map<std::string,Rbyte> m ;
	m["b"] = (Rbyte)0;
  	m["a"] = (Rbyte)1;
  	m["c"] = (Rbyte)2;
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = as.raw(1), b = as.raw(0), c = as.raw(2) ), 
		msg = "wrap( map<string,Rbyte>) " )
}

test.wrap.map.string.string <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::map<std::string,std::string> m ;
	m["b"] = "foo" ;
  	m["a"] = "bar" ;
  	m["c"] = "bling" ;
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = "bar", b = "foo", c = "bling" ), 
		msg = "wrap( map<string,string>) " )
}

test.wrap.map.string.generic <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::map< std::string,std::vector<int> > m ;
	std::vector<int> b ; b.push_back(1) ; b.push_back(2) ; m["b"] = b ;
  	std::vector<int> a ; a.push_back(1) ; a.push_back(2) ; a.push_back(2) ; m["a"] = a ;
  	std::vector<int> c ; c.push_back(1) ; c.push_back(2) ; c.push_back(2) ; c.push_back(2) ; m["c"] = c ;
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), list( a = c(1L, 2L, 2L), b = c(1L, 2L), c = c(1L,2L,2L,2L) ) , 
		msg = "wrap( map<string,vector<int>>) " )
}





test.wrap.multimap.string.int <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::multimap< std::string, int > m ;
	m.insert( std::pair<std::string,int>("b", 100) );
  	m.insert( std::pair<std::string,int>("a", 200) );
  	m.insert( std::pair<std::string,int>("c", 300) );
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = 200L, b = 100L, c = 300L), 
		msg = "wrap( multimap<string,int>) " )
}

test.wrap.multimap.string.double <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::multimap<std::string,double> m ;
	m.insert( std::pair<std::string,double>("b", 100) );
  	m.insert( std::pair<std::string,double>("a", 200) );
  	m.insert( std::pair<std::string,double>("c", 300) );
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = 200, b = 100, c = 300), 
		msg = "wrap( multimap<string,double>) " )
}

test.wrap.multimap.string.bool <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::multimap<std::string,bool> m ;
	m.insert( std::pair<std::string,bool>("b", true ) ) ;
  	m.insert( std::pair<std::string,bool>("a", false) ) ;
  	m.insert( std::pair<std::string,bool>("c", true ) ) ;
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = FALSE, b = TRUE, c = TRUE ), 
		msg = "wrap( multimap<string,bool>) " )
}

test.wrap.multimap.string.Rbyte <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::multimap<std::string,Rbyte> m ;
	m.insert( std::pair<std::string,Rbyte>("b", (Rbyte)0) );
  	m.insert( std::pair<std::string,Rbyte>("a", (Rbyte)1) );
  	m.insert( std::pair<std::string,Rbyte>("c", (Rbyte)2) );
  	return wrap(m) ;
	'  )
	
	checkEquals( funx(), c( a = as.raw(1), b = as.raw(0), c = as.raw(2) ), 
		msg = "wrap( multimap<string,Rbyte>) " )
}

test.wrap.multimap.string.string <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::multimap<std::string,std::string> m ;
	m.insert( std::pair<std::string,std::string>( "b", "foo"  ) ) ;
  	m.insert( std::pair<std::string,std::string>( "a", "bar"  ) ) ;
  	m.insert( std::pair<std::string,std::string>( "c", "bling") ) ;
  	return wrap(m) ;
	' )
	
	checkEquals( funx(), c( a = "bar", b = "foo", c = "bling" ), 
		msg = "wrap( multimap<string,string>) " )
}

test.wrap.multimap.string.generic <- function(){
	
	funx <- cppfunction(signature(), 
	'
	typedef std::pair<std::string,std::vector<int> > _pair ;
	std::multimap< std::string,std::vector<int> > m ;
	std::vector<int> b ; b.push_back(1) ; b.push_back(2) ; 
	m.insert( _pair("b", b) );
  	
	std::vector<int> a ; a.push_back(1) ; a.push_back(2) ; a.push_back(2) ; 
  	m.insert( _pair("a", a) );
  	
  	std::vector<int> c ; c.push_back(1) ; c.push_back(2) ; c.push_back(2) ; c.push_back(2) ; 
  	m.insert( _pair("c",  c) );
  	return wrap(m) ;
	' )
	
	checkEquals( funx(), list( a = c(1L, 2L, 2L), b = c(1L, 2L), c = c(1L,2L,2L,2L) ) , 
		msg = "wrap( multimap<string,vector<int>>) " )
}



# tr1::unordered_map

if( Rcpp:::capabilities()[["tr1 unordered maps"]] ) {
	
test.wrap.unordered.map.string.int <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::tr1::unordered_map< std::string, int > m ;
	m["b"] = 100;
  	m["a"] = 200;
  	m["c"] = 300;
  	return wrap(m) ;
	')
	
	res <- funx()
	checkEquals( res[["a"]], 200L,  msg = "wrap( tr1::unordered_map<string,int>) " )
	checkEquals( res[["b"]], 100L,  msg = "wrap( tr1::unordered_map<string,int>) " )
	checkEquals( res[["c"]], 300L,  msg = "wrap( tr1::unordered_map<string,int>) " )
}

test.wrap.unordered.map.string.double <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::tr1::unordered_map<std::string,double> m ;
	m["b"] = 100;
  	m["a"] = 200;
  	m["c"] = 300;
  	return wrap(m) ;
	')
	
	res <- funx()
	checkEquals( res[["a"]], 200,  msg = "wrap( tr1::unordered_map<string,double>) " )
	checkEquals( res[["b"]], 100,  msg = "wrap( tr1::unordered_map<string,double>) " )
	checkEquals( res[["c"]], 300,  msg = "wrap( tr1::unordered_map<string,double>) " )
}

test.wrap.unordered.map.string.bool <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::tr1::unordered_map<std::string,bool> m ;
	m["b"] = true;
  	m["a"] = false;
  	m["c"] = true;
  	return wrap(m) ;
	' )
	
	res <- funx()
	checkEquals( res[["a"]], FALSE,  msg = "wrap( tr1::unordered_map<string,bool>) " )
	checkEquals( res[["b"]], TRUE ,  msg = "wrap( tr1::unordered_map<string,bool>) " )
	checkEquals( res[["c"]], TRUE ,  msg = "wrap( tr1::unordered_map<string,bool>) " )
}

test.wrap.unordered.map.string.Rbyte <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::tr1::unordered_map<std::string,Rbyte> m ;
	m["b"] = (Rbyte)0;
  	m["a"] = (Rbyte)1;
  	m["c"] = (Rbyte)2;
  	return wrap(m) ;
	' )
	
	res <- funx()
	checkEquals( res[["a"]], as.raw(1),  msg = "wrap( tr1::unordered_map<string,Rbyte>) " )
	checkEquals( res[["b"]], as.raw(0),  msg = "wrap( tr1::unordered_map<string,Rbyte>) " )
	checkEquals( res[["c"]], as.raw(2),  msg = "wrap( tr1::unordered_map<string,Rbyte>) " )
}

test.wrap.unordered.map.string.string <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::tr1::unordered_map<std::string,std::string> m ;
	m["b"] = "foo" ;
  	m["a"] = "bar" ;
  	m["c"] = "bling" ;
  	return wrap(m) ;
	')
	
	res <- funx()
	checkEquals( res[["a"]], "bar"   ,  msg = "wrap( tr1::unordered_map<string,string>) " )
	checkEquals( res[["b"]], "foo"   ,  msg = "wrap( tr1::unordered_map<string,string>) " )
	checkEquals( res[["c"]], "bling" ,  msg = "wrap( tr1::unordered_map<string,string>) " )
}

test.wrap.unordered.map.string.generic <- function(){
	
	funx <- cppfunction(signature(), 
	'
	std::tr1::unordered_map< std::string,std::vector<int> > m ;
	std::vector<int> b ; b.push_back(1) ; b.push_back(2) ; m["b"] = b ;
  	std::vector<int> a ; a.push_back(1) ; a.push_back(2) ; a.push_back(2) ; m["a"] = a ;
  	std::vector<int> c ; c.push_back(1) ; c.push_back(2) ; c.push_back(2) ; c.push_back(2) ; m["c"] = c ;
  	return wrap(m) ;
	')
	
	res <- funx()
	checkEquals( res[["a"]], c(1L,2L,2L) ,  msg = "wrap( tr1::unordered_map<string,vector<int>>) " )
	checkEquals( res[["b"]], c(1L,2L) ,  msg = "wrap( tr1::unordered_map<string,vector<int>>) " )
	checkEquals( res[["c"]], c(1L,2L,2L,2L) ,  msg = "wrap( tr1::unordered_map<string,vector<int>>) " )
	
}
	
} # if( Rcpp:::capabilities("tr1 unordered maps") )




