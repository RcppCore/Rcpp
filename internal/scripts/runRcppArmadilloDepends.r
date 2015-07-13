#!/usr/bin/r

cat("Started at ", format(Sys.time()), "\n")
pkg <- "RcppArmadillo"

setwd("/tmp/RcppDepends")

AP <- available.packages(contrib.url("http://cran.r-project.org"), filter=list())	# available package at CRAN
rcpparmaset <- sort(unname(AP[unique(c(grep(pkg, as.character(AP[,"Depends"])),
                                       grep(pkg, as.character(AP[,"LinkingTo"])),
                                       grep(pkg, as.character(AP[,"Imports"])))),"Package"]))
print( rcpparmaset )

res <- data.frame(pkg=rcpparmaset, res=NA)

#for (pi in 1:nrow(res)) {
#lres <- mclapply(1:nrow(res), mc.cores = 4, FUN=function(pi) {
lres <- lapply(1:nrow(res), FUN=function(pi) {
    p <- rcpparmaset[pi]
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
