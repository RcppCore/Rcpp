
all: clean index.html Rcpp-unitTests.pdf

clean:
	touch Rcpp-unitTests.pdf
	rm Rcpp-unitTests.pdf
	rm index.html

index.html: rcpp.index.html
	cp rcpp.index.html index.html

Rcpp-unitTests.pdf:
	rm -fr unitTests-results/*
	cp unitTests/Rcpp-unitTests.Rnw .
	Rscript unitTests/Rcpp-unitTests.R
	R CMD Sweave unitTests/Rcpp-unitTests.Rnw
	Rscript -e "tools::texi2dvi( 'Rcpp-unitTests.tex', pdf = TRUE, clean = TRUE )"
	rm -fr Rcpp-unitTests.tex

Rcpp-api.pdf: Rcpp-api.Rnw
	R CMD Sweave Rcpp-api.Rnw
	Rscript -e "tools::texi2dvi( 'Rcpp-api.tex', pdf = TRUE, clean = TRUE ) "
	rm -fr Rcpp-api.tex


