extern "C" SEXP hello_wrapper( SEXP who){
    std::string input = CHAR(STRING_ELT(input,0)) ;
    const char* result = hello( input ) ;
    return mkString( result );
}
