RcppExport SEXP hello_wrapper( SEXP who){
    std::string input = Rcpp::as<std::string>( who )
    const char* result = hello( input ) ;
    return Rcpp::wrap( result );
}
