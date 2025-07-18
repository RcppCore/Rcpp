## These two functions are borrowed with grateful appreciation from the R.rsp package
## by Henrik Bengtsson licensend under LPGL (>= 2.1) and somewhat simplified / shortened
## feature-reduced here. Please the R.rsp for a full-featured version and documentation

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
    output
}

asisTangle <- function (file, ..., pattern = "(|[.][^.]*)[.]asis$") {
    workdir <- "."
    filename <- basename(file)
    fullname <- gsub(pattern, "", filename)
    filenameR <- sprintf("%s.R", fullname)
    cat(sprintf("### This is an R script tangled from '%s'\n", filename), file = filenameR)
    invisible(filenameR)
}
