
## This Makefile is not included in the package sources so we can use GNUmake idioms. Yay.

rmdsources := 		$(wildcard *.Rmd)
rmdvignettes := 	$(rmdsources:.Rmd=.pdf)

%.pdf:			%.Rmd
			Rscript -e 'rmarkdown::render("$<")'
			Rscript -e 'tools::compactPDF("$@", gs_quality="ebook")'
			cp -vax $@ ../pdf

all:			${rmdvignettes} Rcpp-jss-2011.pdf

Rcpp-jss-2011.tex:	Rcpp-jss-2011.Rnw
			Rscript -e 'Sweave("$<")'

Rcpp-jss-2011.pdf:	Rcpp-jss-2011.tex
			Rscript -e 'tools::texi2pdf("$<", texi2dvi="pdflatex")'
			bibtex Rcpp-jss-2011.aux
			Rscript -e 'tools::texi2pdf("$<", texi2dvi="pdflatex")'
			Rscript -e 'tools::compactPDF("$@", gs_quality="ebook")'
			cp -vax $@ ../pdf

clean:
			@rm -rf *.aux *.log *.out *.toc *.tex *.pdf Rcpp-introduction_cache Rcpp-libraries_cache pinp.cls Rcpp-jss-2011.bbl Rcpp-jss-2011.blg auto
