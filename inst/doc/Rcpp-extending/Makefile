
## There is an old bug in texidvi that makes it not swallow the ~
## marker used to denote whitespace. This is actually due to fixing
## another bug they whereby you could not run texidvi on directory
## names containing a tilde (as we happen to do for Debian builds of R
## alpha/beta/rc releases). The 'tilde' bug will go away as it
## reportedly has been squashed upstream but I am still bitten by it
## on Ubuntu so for Dirk will insist on pdflatex and this variable helps
whoami=$(shell whoami)

all: clean Rcpp-extending.pdf

clean:
	touch Rcpp-extending.pdf
	rm -fr Rcpp-extending.pdf

Rcpp-extending.pdf: Rcpp-extending.Rnw
	cp ../Rcpp-modules.bib .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-extending.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-extending.tex', pdf = TRUE, clean = FALSE )"
ifeq ($(whoami),edd)
	pdflatex Rcpp-extending
	pdflatex Rcpp-extending
else
	Rscript -e "tools::texi2dvi( 'Rcpp-extending.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-extending.tex
	rm -fr Rcpp-extending.bbl
	rm -fr Rcpp-extending.blg
	rm -fr Rcpp-extending.aux
	rm -fr Rcpp-extending.out
	rm -fr Rcpp-extending.log
	rm -fr Rcpp-modules.bib

