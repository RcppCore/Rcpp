

rmdsources := 		$(wildcard *.Rmd)
rmdvignettes := 	$(rmdsources:.Rmd=.pdf)

%.pdf:			%.Rmd
			Rscript -e 'rmarkdown::render("$<")'
			Rscript -e 'tools::compactPDF("$@", gs_quality="ebook")'
			cp -vax $@ ../pdf

all:			${rmdvignettes} Rcpp-jss-2011.pdf

Rcpp-jss-2011.pdf:	Rcpp-jss-2011.Rnw
			Rscript -e 'Sweave("$<")'
			Rscript -e 'tools::compactPDF("$@", gs_quality="ebook")'

clean:
			rm -rf *.aux *.log *.tex *.pdf Rcpp-introduction_cache pinp.cls jss.bst
