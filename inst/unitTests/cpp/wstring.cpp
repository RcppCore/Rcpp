#include <Rcpp.h>
using namespace Rcpp ;

// [[Rcpp::export]]
CharacterVector CharacterVector_wstring( ){
    CharacterVector res(2) ;
    res[0] = L"foo" ;
    res[0] += L"bar" ;
    
    res[1] = std::wstring( L"foo" ) ;
    res[1] += std::wstring( L"bar" ) ;
         
    return res ;
}
            
// [[Rcpp::export]]
std::wstring wstring_return(){
    return L"foo" ;    
}

// [[Rcpp::export]]
String wstring_param(const std::wstring& s1, const std::wstring& s2){
    String s = s1 ;
    s += s2 ;
    return s ;
}

