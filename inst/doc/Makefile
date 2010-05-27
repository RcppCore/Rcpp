
all: clean index.html Rcpp-unitTests.pdf Rcpp-introduction.pdf Rcpp-modules.pdf

clean:
	touch Rcpp-unitTests.pdf
	touch Rcpp-introduction.pdf
	rm Rcpp-introduction.pdf
	rm Rcpp-unitTests.pdf
	touch index.html
	rm index.html

index.html: rcpp.index.html
	cp rcpp.index.html index.html

Rcpp-unitTests.pdf:
	rm -fr unitTests-results/*
	Rscript unitTests/Rcpp-unitTests.R
	R CMD Sweave Rcpp-unitTests.Rnw
	Rscript -e "tools::texi2dvi( 'Rcpp-unitTests.tex', pdf = TRUE, clean = TRUE )"
	rm -fr Rcpp-unitTests.tex

Rcpp-api.pdf: Rcpp-api.Rnw
	R CMD Sweave Rcpp-api.Rnw
	Rscript -e "tools::texi2dvi( 'Rcpp-api.tex', pdf = TRUE, clean = TRUE ) "
	rm -fr Rcpp-api.tex

Rcpp-introduction.pdf: Rcpp-introduction.Rnw
	R CMD Sweave Rcpp-introduction.Rnw
	Rscript -e "tools::texi2dvi( 'Rcpp-introduction.tex', pdf = TRUE, clean = TRUE )"
	rm -fr Rcpp-introduction.tex

Rcpp-modules.pdf: snippets Rcpp-modules.Rnw 
	( cd snippets ; Rscript highlight.R ; cd .. )
	R CMD Sweave Rcpp-modules.Rnw
	Rscript -e "tools::texi2dvi( 'Rcpp-modules.tex', pdf = TRUE, clean = TRUE )"
	rm -fr Rcpp-modules.tex

