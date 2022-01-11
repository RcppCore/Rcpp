#!/usr/bin/r

stopifnot(`Needs data.table` = requireNamespace("data.table", quietly = TRUE))
library(data.table)

if (!file.exists("Rcpp.bib")) setwd("~/git/rcpp/vignettes/rmd")

cmd <- "awk '/package=/ { print($5) }' Rcpp.bib | sed -e 's/\"//g' - | awk -F= '{print($2)}' | sort | uniq"
con <- pipe(cmd)
pkgs <- readLines(con)
close(con)

pkg <- data.table(Package=pkgs)

db <- data.table(tools::CRAN_package_db())

print(db[pkg, on="Package"][, .(Package, Version, Date)])
