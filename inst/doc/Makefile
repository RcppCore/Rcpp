
all: clean index.html Rcpp-unitTests.pdf Rcpp-introduction.pdf Rcpp-modules.pdf

clean:
	touch Rcpp-unitTests.pdf
	touch Rcpp-introduction.pdf
	touch Rcpp-modules.pdf
	rm Rcpp-introduction.pdf
	rm Rcpp-unitTests.pdf
	rm Rcpp-modules.pdf
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

Rcpp-modules.pdf: Rcpp-modules/Rcpp-modules.Rnw
	rm Rcpp-modules.Rnw 
	cp -f Rcpp-modules/Rcpp-modules.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-modules.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-modules.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-modules
	Rscript -e "tools::texi2dvi( 'Rcpp-modules.tex', pdf = TRUE, clean = TRUE )"
	rm -fr Rcpp-modules.tex
	rm -fr Rcpp-modules.bbl
	rm -fr Rcpp-modules.blg
	rm -fr Rcpp-modules.aux
	rm -fr Rcpp-modules.out
	rm -fr Rcpp-modules.log
	rm Rcpp-modules.Rnw
	cp Rcpp-modules/Rcpp-modules-fake.Rnw Rcpp-modules.Rnw
