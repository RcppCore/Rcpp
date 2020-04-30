
## No GNUmake for R so replacing efficient wildcard ops with explicit enumeration
## Remove spaces between ': =' and '$ ( ... )' to re-activate

##rnwsources : = 	$ ( wildcard *.Rnw )
##rnwvignettes : = 	$ ( rnwsources:.Rnw=.pdf )

rnwsources  = 		Rcpp-attributes.Rnw \
			Rcpp-extending.Rnw \
			Rcpp-FAQ.Rnw \
			Rcpp-introduction.Rnw \
			Rcpp-jss-2011.Rnw \
			Rcpp-libraries.Rnw \
			Rcpp-modules.Rnw \
			Rcpp-package.Rnw \
			Rcpp-quickref.Rnw \
			Rcpp-sugar.Rnw

rnwvignettes  = 	Rcpp-attributes.pdf \
			Rcpp-extending.pdf \
			Rcpp-FAQ.pdf \
			Rcpp-introduction.pdf \
			Rcpp-jss-2011.pdf \
			Rcpp-libraries.pdf \
			Rcpp-modules.pdf \
			Rcpp-package.pdf \
			Rcpp-quickref.pdf \
			Rcpp-sugar.pdf

%.tex:			%.Rnw
			Rscript -e 'Sweave("$<")'

%.pdf:			%.tex
			Rscript -e 'tools::texi2pdf("$<", texi2dvi="pdflatex")'
			Rscript -e 'tools::texi2pdf("$<", texi2dvi="pdflatex")'
			Rscript -e 'tools::compactPDF("$@", gs_quality="ebook")'

all:			${rnwvignettes}
			@rm -f *.aux *.log *.tex

clean:
			@rm -f *.aux *.log *.tex
