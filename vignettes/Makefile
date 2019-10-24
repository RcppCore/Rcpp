

rnwsources := 		$(wildcard *.Rnw)
rnwvignettes := 	$(rnwsources:.Rnw=.pdf)

%.tex:			%.Rnw
			Rscript -e 'Sweave("$<")'

%.pdf:			%.tex
			Rscript -e 'tools::texi2pdf("$<", texi2dvi="pdflatex")'
			Rscript -e 'tools::texi2pdf("$<", texi2dvi="pdflatex")'
			Rscript -e 'tools::compactPDF("$@", gs_quality="ebook")'

all:			${rnwvignettes}

clean:
			rm -f *.aux *.log *.tex
