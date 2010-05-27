using namespace Rcpp ;

/** create an external pointer to a World object */
RcppExport SEXP World__new(){
	return Rcpp::XPtr<World>( new World, true ) ;
}

/** invoke the greet method */
RcppExport SEXP World__greet( SEXP xp ) {
	Rcpp::XPtr<World> w(xp) ;
	return Rcpp::wrap( w->greet() ) ;
}

/** invoke the set method */
RcppExport SEXP World__set( SEXP xp, SEXP msg ){
	Rcpp::XPtr<World> w(xp) ;
	w->set( Rcpp::as<std::string>( msg ) ) ;
	return R_NilValue ;
}
