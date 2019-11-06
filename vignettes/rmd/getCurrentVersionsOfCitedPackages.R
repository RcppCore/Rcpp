#/usr/bin/r

if (!file.exists("Rcpp.bib")) fsetwd("~/git/rcpp/vignettes/rmd")
cmd <- "grep package= Rcpp.bib | cut -c27- | sed -e 's/\"$//' | sort | uniq"
con <- pipe(cmd)
pkgs <- readLines(con)
close(con)

repo <- "https://cloud.r-project.org"
AP <- available.packages(contrib.url(repo),filter=list())	# available package at CRAN

res <- as.data.frame(do.call(rbind, lapply(pkgs, function(p) {
    ind <- which(AP[,"Package"] == p)
    if (length(ind) > 1) ind <- ind[1]
    AP[ind, c("Package", "Version")]
})))
print(res)
