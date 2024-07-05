
# Wrappers used for 'convert_using_rfunction' if appropriate
as.pairlist <- function(x) {
    if (is.call(x)) {
        as.pairlist(as.list(x))
    } else {
        base::as.pairlist(x)
    }
}
