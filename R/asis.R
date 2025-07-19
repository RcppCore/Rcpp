## These two functions are borrowed with grateful appreciation from the R.rsp package
## by Henrik Bengtsson licensed under LGPL (>= 2.1) and somewhat simplified / shortened
## feature-reduced here. Please see the R.rsp for a full-featured version and documentation

##' Simple \sQuote{asis} Vignette Processor
##'
##' To pass pre-made pdf vignettes through \dQuote{as is}, a simple vignette
##' process is added. It is derived from the more feature-complete one in the \pkg{R.rsp}
##' package. To use it, add files named like the pdf file plus an appended \code{.asis}
##' with the vignette metainformation and register the vignette processor, see the examples.
##'
##' @title Process pdf vignettes \sQuote{asis}
##' @name asisWeave
##' @param file character Filename to be processed
##' @param ... dots Currently ignored
##' @param pattern character A regular expression describing the filename pattern
##' @return The respective filename is returned, invisibly
##' @author Henrik Bengtsson for the original versions in package \pkg{R.rsp},
##' Dirk Eddelbuettel for the shortened ones used here
##' @examples
##' # To register this vignette engine in another package, add
##' # \code{VignetteBuilder: Rcpp} as well as \code{Suggests: Rcpp} to \code{DESCRIPTION}
##' # which uses the registration this package provides via
##' \dontrun{tools::vignetteEngine("asis", package = pkgname, pattern = "[.](pdf|html)[.]asis$",
##'                                weave = asisWeave, tangle = asisTangle)}
##'
##' # Use a .asis file as in the Rcpp package, for example Rcpp-FAQ.pdf.asis has these lines:
##' #   %\VignetteIndexEntry{Rcpp-FAQ}
##' #   %\VignetteKeywords{Rcpp, FAQ, R, Cpp}
##' #   %\VignettePackage{Rcpp}
##' #   %\VignetteEncoding{UTF-8}
##' #   %\VignetteEngine{Rcpp::asis}
asisWeave <- function (file, ...) {
    output <- tools::file_path_sans_ext(basename(file))
    if (!file.exists(output)) {
        outputS <- file.path("..", "inst", "doc", output)
        if (file.exists(outputS)) {
            file.copy(outputS, output, overwrite = TRUE)
            output <- outputS
        } else {
            stop("No file to process", call. = FALSE)
        }
    }
    Sys.setFileTime(output, time = Sys.time())
    invisible(output)
}

##' @rdname asisWeave
asisTangle <- function (file, ..., pattern = "(|[.][^.]*)[.]asis$") {
    workdir <- "."
    filename <- basename(file)
    fullname <- gsub(pattern, "", filename)
    filenameR <- sprintf("%s.R", fullname)
    cat(sprintf("### This is an R script tangled from '%s'\n", filename), file = filenameR)
    invisible(filenameR)
}
