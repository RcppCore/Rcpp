#!/usr/bin/r

suppressMessages(library(Rcpp))
suppressMessages(library(inline))


foo <- '
	RcppStringVectorView v(x);
	Rprintf( "RcppStringVectorView: size = %d\\n", v.size() ) ;
	Rprintf( "RcppStringVectorView: elem 1 = %s\\n", v(1) ) ;
	return R_NilValue ;
        '
funx <- cfunction(signature(x="character"), foo, Rcpp=TRUE, verbose=FALSE)
funx(x=c("Bling", "Blang"))


foo <- '
	RcppVectorView<int> v(x);
	Rprintf( "RcppVectorView: n = %d \\n", v.size()) ;
	Rprintf( "RcppVectorView: elem 1 = %d \\n", v(1)) ;
        '
funx <- cfunction(signature(x="numeric"), foo, Rcpp=TRUE, verbose=FALSE)
x <- 1:9
funx(x=x)


foo <- '
	RcppVector<int> v(x);
	Rprintf( "RcppVector: n = %d \\n", v.size()) ;
	Rprintf( "RcppVector: elem 1 = %d \\n", v(1)) ;
        '
funx <- cfunction(signature(x="numeric"), foo, Rcpp=TRUE, verbose=FALSE)
x <- 1:9
funx(x=x)


foo <- '
	RcppMatrixView<int> v(x);
	Rprintf( "RcppMatrixView: n = %d times k= %d\\n", v.rows(), v.cols() ) ;
	Rprintf( "RcppMatrixView: elem(1,2) = %d\\n", v(1,2) ) ;
        '
funx <- cfunction(signature(x="numeric"), foo, Rcpp=TRUE, verbose=FALSE)
x <- matrix(1:9, ncol=3)
funx(x=x)

foo <- '
	RcppMatrix<int> v(x);
	Rprintf( "RcppMatrix: n = %d times k= %d\\n", v.rows(), v.cols() ) ;
	Rprintf( "RcppMatrix: elem(1,2) = %d\\n", v(1,2) ) ;
        '
funx <- cfunction(signature(x="numeric"), foo, Rcpp=TRUE, verbose=FALSE)
x <- matrix(1:9, ncol=3)
funx(x=x)

