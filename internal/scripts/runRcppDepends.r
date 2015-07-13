#!/usr/bin/r

cat("Started at ", format(Sys.time()), "\n")
#library(parallel)

## use a test-local directory, install Rcpp, RcppArmadillo, ... there
## this will work for sub-shells such as the ones started by system() below
Sys.setenv("R_LIBS_USER"="/tmp/RcppDepends/lib")

## for the borked src/Makevars of ExactNumCI
Sys.setenv("BOOSTLIB"="/usr/include")

setwd("/tmp/RcppDepends")

AP <- available.packages(contrib.url("http://cran.r-project.org"),filter=list())	# available package at CRAN
rcppset <- sort(unname(AP[unique(c(grep("Rcpp", as.character(AP[,"Depends"])),
                                   grep("Rcpp", as.character(AP[,"LinkingTo"])),
                                   grep("Rcpp", as.character(AP[,"Imports"])))),"Package"]))
#if (grep("transnet", rcppset)) {        ## not really an Rcpp user
#    rcppset <- rcppset[ ! grepl("transnet", rcppset) ]
#}
if (grep("BioGeoBEARS", rcppset)) {     ## indirect match, no need to test
    rcppset <- rcppset[ ! grepl("BioGeoBEARS", rcppset) ]
}
if (grep("quadrupen", rcppset)) {       ## takes hours, skipping
    rcppset <- rcppset[ ! grepl("quadrupen", rcppset) ]
}
if (grep("roxygen2", rcppset)) {       ## seems to hang for reasons that are unclear
    rcppset <- rcppset[ ! grepl("roxygen2", rcppset) ]
}

print( rcppset )

res <- data.frame(pkg=rcppset, res=NA)

#for (pi in 1:nrow(res)) {
#lres <- mclapply(1:nrow(res), mc.cores = 4, FUN=function(pi) {
lres <- lapply(1:nrow(res), FUN=function(pi) {
    p <- rcppset[pi]
    i <- which(AP[,"Package"]==p)
    pkg <- paste(AP[i,"Package"], "_", AP[i,"Version"], ".tar.gz", sep="")
    pathpkg <- paste(AP[i,"Repository"], "/", pkg, sep="")
    #print(pathpkg)
    if (!file.exists(pkg)) download.file(pathpkg, pkg, quiet=TRUE)
    rc <- system(paste("R CMD check --no-manual --no-vignettes ", pkg, " > ", pkg, ".log", sep=""))
    res[pi, "res"] <- rc
    cat(rc, ":", pkg, "\n")
    res[pi, ]
})

res <- do.call(rbind, lres)
print(res)
write.table(res, file=paste("result-", strftime(Sys.time(), "%Y%m%d-%H%M%S"), ".txt", sep=""), sep=",")
save(res, file=paste("result-", strftime(Sys.time(), "%Y%m%d-%H%M%S"), ".RData", sep=""))
cat("Ended at ", format(Sys.time()), "\n")
