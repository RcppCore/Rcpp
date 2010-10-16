
## There is an old bug in texidvi that makes it not swallow the ~
## marker used to denote whitespace. This is actually due to fixing
## another bug they whereby you could not run texidvi on directory
## names containing a tilde (as we happen to do for Debian builds of R
## alpha/beta/rc releases). The 'tilde' bug will go away as it
## reportedly has been squashed upstream but I am still bitten by it
## on Ubuntu so for Dirk will insist on pdflatex and this variable helps
whoami=$(shell whoami)

all: clean index.html Rcpp-unitTests.pdf Rcpp-introduction.pdf Rcpp-modules.pdf Rcpp-package.pdf Rcpp-FAQ.pdf Rcpp-extending.pdf Rcpp-sugar.pdf Rcpp-quickref.pdf

clean:
	rm -f index.html
	rm -f *.tex *.bbl *.blg *.aux *.out *.log
	cp -f Rcpp-extending/Rcpp-extending-fake.Rnw Rcpp-extending.Rnw
	cp -f Rcpp-FAQ/Rcpp-FAQ-fake.Rnw Rcpp-FAQ.Rnw
	cp -f Rcpp-modules/Rcpp-modules-fake.Rnw Rcpp-modules.Rnw
	cp -f Rcpp-package/Rcpp-package-fake.Rnw Rcpp-package.Rnw
	cp -f Rcpp-quickref/Rcpp-quickref-fake.Rnw Rcpp-quickref.Rnw
	cp -f Rcpp-sugar/Rcpp-sugar-fake.Rnw Rcpp-sugar.Rnw

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
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-introduction.tex
	bibtex Rcpp-introduction
	pdflatex Rcpp-introduction.tex
	pdflatex Rcpp-introduction.tex
else
	Rscript -e "tools::texi2dvi( 'Rcpp-introduction.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-introduction.tex

Rcpp-modules.pdf: Rcpp-modules/Rcpp-modules.Rnw
	cp -f Rcpp-modules/Rcpp-modules.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-modules.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-modules.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-modules
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-modules.tex
	pdflatex Rcpp-modules.tex
else
	Rscript -e "tools::texi2dvi( 'Rcpp-modules.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-modules.tex Rcpp-modules.bbl Rcpp-modules.blg Rcpp-modules.aux Rcpp-modules.out Rcpp-modules.log
	rm Rcpp-modules.Rnw
	cp Rcpp-modules/Rcpp-modules-fake.Rnw Rcpp-modules.Rnw

Rcpp-package.pdf : Rcpp-package/Rcpp-package.Rnw
	cp -f Rcpp-package/Rcpp-package.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-package.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-package.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-package
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-package
	pdflatex Rcpp-package
else
	Rscript -e "tools::texi2dvi( 'Rcpp-package.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-package.tex Rcpp-package.bbl Rcpp-package.blg Rcpp-package.aux Rcpp-package.out Rcpp-package.log
	rm Rcpp-package.Rnw
	cp Rcpp-package/Rcpp-package-fake.Rnw Rcpp-package.Rnw

Rcpp-FAQ.pdf : Rcpp-FAQ/Rcpp-FAQ.Rnw
	cp -f Rcpp-FAQ/Rcpp-FAQ.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-FAQ.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-FAQ.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-FAQ
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-FAQ
	pdflatex Rcpp-FAQ
else
	Rscript -e "tools::texi2dvi( 'Rcpp-FAQ.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-FAQ.tex Rcpp-FAQ.bbl Rcpp-FAQ.blg Rcpp-FAQ.aux Rcpp-FAQ.out Rcpp-FAQ.log
	rm Rcpp-FAQ.Rnw
	cp Rcpp-FAQ/Rcpp-FAQ-fake.Rnw Rcpp-FAQ.Rnw

Rcpp-extending.pdf : Rcpp-extending/Rcpp-extending.Rnw
	cp -f Rcpp-extending/Rcpp-extending.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-extending.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-extending.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-extending
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-extending
	pdflatex Rcpp-extending
else
	Rscript -e "tools::texi2dvi( 'Rcpp-extending.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-extending.tex Rcpp-extending.bbl Rcpp-extending.blg Rcpp-extending.aux Rcpp-extending.out Rcpp-extending.log
	rm Rcpp-extending.Rnw
	cp Rcpp-extending/Rcpp-extending-fake.Rnw Rcpp-extending.Rnw

Rcpp-sugar.pdf : Rcpp-sugar/Rcpp-sugar.Rnw
	cp -f Rcpp-sugar/Rcpp-sugar.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-sugar.Rnw', driver = driver ); "
	Rscript -e "tools::texi2dvi( 'Rcpp-sugar.tex', pdf = TRUE, clean = FALSE )"
	bibtex Rcpp-sugar
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-sugar
	pdflatex Rcpp-sugar
else
	Rscript -e "tools::texi2dvi( 'Rcpp-sugar.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-sugar.tex Rcpp-sugar.bbl Rcpp-sugar.blg Rcpp-sugar.aux Rcpp-sugar.out Rcpp-sugar.log
	rm Rcpp-sugar.Rnw
	cp Rcpp-sugar/Rcpp-sugar-fake.Rnw Rcpp-sugar.Rnw

Rcpp-quickref.pdf : Rcpp-quickref/Rcpp-quickref.Rnw
	cp -f Rcpp-quickref/Rcpp-quickref.Rnw .
	Rscript -e "require(highlight); driver <- HighlightWeaveLatex(boxes = TRUE, bg = 'white' ); Sweave( 'Rcpp-quickref.Rnw', driver = driver ); "
	Rscript -e "tex <- readLines('Rcpp-quickref.tex'); tex <- gsub( 'begin{minipage}{0.9', 'begin{minipage}{0.42', tex, fixed = TRUE ) ; writeLines( tex, 'Rcpp-quickref.tex' )  "
	Rscript -e "tools::texi2dvi( 'Rcpp-quickref.tex', pdf = TRUE, clean = FALSE )"
ifneq (,$(findstring edd,$(whoami)))
	pdflatex Rcpp-quickref
	pdflatex Rcpp-quickref
else
	Rscript -e "tools::texi2dvi( 'Rcpp-quickref.tex', pdf = TRUE, clean = TRUE )"
endif
	rm -fr Rcpp-quickref.tex
	rm -fr Rcpp-quickref.bbl
	rm -fr Rcpp-quickref.blg
	rm -fr Rcpp-quickref.aux
	rm -fr Rcpp-quickref.out
	rm -fr Rcpp-quickref.log
	rm -fr Rcpp-quickref.Rnw
	cp Rcpp-quickref/Rcpp-quickref-fake.Rnw Rcpp-quickref.Rnw

