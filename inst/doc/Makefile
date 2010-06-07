
## There is an old bug in texidvi that makes it not swallow the ~
## marker used to denote whitespace. This is actually due to fixing
## another bug they whereby you could not run texidvi on directory
## names containing a tilde (as we happen to do for Debian builds of R
## alpha/beta/rc releases). The 'tilde' bug will go away as it
## reportedly has been squashed upstream but I am still bitten by it
## on Ubuntu so for Dirk will insist on pdflatex and this variable helps
whoami=$(shell whoami)

all: clean index.html Rcpp-unitTests.pdf Rcpp-introduction.pdf Rcpp-modules.pdf Rcpp-package.pdf Rcpp-FAQ.pdf Rcpp-extending.pdf

clean:
	touch Rcpp-unitTests.pdf
	touch Rcpp-introduction.pdf
	touch Rcpp-modules.pdf
	touch Rcpp-FAQ.pdf
	touch Rcpp-extending.pdf
	rm Rcpp-introduction.pdf
	rm Rcpp-unitTests.pdf
	rm Rcpp-modules.pdf
	rm Rcpp-FAQ.pdf
	rm Rcpp-extending.pdf
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
ifeq ($(whoami),edd)
	pdflatex Rcpp-modules.tex
	pdflatex Rcpp-modules.tex
else
	Rscript -e "tools::texi2dvi( 'Rcpp-modules.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-modules.tex
	rm -fr Rcpp-modules.bbl
	rm -fr Rcpp-modules.blg
	rm -fr Rcpp-modules.aux
	rm -fr Rcpp-modules.out
	rm -fr Rcpp-modules.log
	rm Rcpp-modules.Rnw
	cp Rcpp-modules/Rcpp-modules-fake.Rnw Rcpp-modules.Rnw

Rcpp-package.pdf : Rcpp-package/Rcpp-package.Rnw
	rm Rcpp-package.Rnw
	cp -f Rcpp-package/Rcpp-package.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-package.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-package.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-package
ifeq ($(whoami),edd)
	pdflatex Rcpp-package
	pdflatex Rcpp-package
else
	Rscript -e "tools::texi2dvi( 'Rcpp-package.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-package.tex
	rm -fr Rcpp-package.bbl
	rm -fr Rcpp-package.blg
	rm -fr Rcpp-package.aux
	rm -fr Rcpp-package.out
	rm -fr Rcpp-package.log
	rm Rcpp-package.Rnw
	cp Rcpp-package/Rcpp-package-fake.Rnw Rcpp-package.Rnw

Rcpp-FAQ.pdf : Rcpp-FAQ/Rcpp-FAQ.Rnw
	rm Rcpp-FAQ.Rnw
	cp -f Rcpp-FAQ/Rcpp-FAQ.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-FAQ.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-FAQ.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-FAQ
ifeq ($(whoami),edd)
	pdflatex Rcpp-FAQ
	pdflatex Rcpp-FAQ
else
	Rscript -e "tools::texi2dvi( 'Rcpp-FAQ.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-FAQ.tex
	rm -fr Rcpp-FAQ.bbl
	rm -fr Rcpp-FAQ.blg
	rm -fr Rcpp-FAQ.aux
	rm -fr Rcpp-FAQ.out
	rm -fr Rcpp-FAQ.log
	rm Rcpp-FAQ.Rnw
	cp Rcpp-FAQ/Rcpp-FAQ-fake.Rnw Rcpp-FAQ.Rnw

Rcpp-extending.pdf : Rcpp-extending/Rcpp-extending.Rnw
	rm Rcpp-extending.Rnw
	cp -f Rcpp-extending/Rcpp-extending.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-extending.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-extending.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-extending
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
	rm Rcpp-extending.Rnw
	cp Rcpp-extending/Rcpp-extending-fake.Rnw Rcpp-extending.Rnw
	
