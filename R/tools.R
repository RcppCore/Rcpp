# Copyright (C) 2010 - 2017  Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

externalptr_address <- function(xp) {
    .Call(as_character_externalptr, xp)			# #nocov
}

# just like assignInNamespace but first checks that the binding exists
forceAssignInNamespace <- function(x, value, env) {
    is_ns <- isNamespace(env)
    unlocker <- get("unlockBinding", baseenv())
    if (is_ns && exists(x, env) && bindingIsLocked(x, env)) {
        unlocker(x, env)
    }
    assign(x, value, env)
    if (is_ns) {
        lockBinding(x, env)
    }
}

# Transform a path for passing to the build system on the command line.
# Leave paths alone for posix. For Windows, mirror the behavior of the
# R package build system by starting with the fully resolved absolute path,
# transforming it to a short path name if it contains spaces, and then
# converting backslashes to forward slashes
asBuildPath <- function(path) {

    if (.Platform$OS.type == "windows") {
        path <- normalizePath(path)			# #nocov start
        if (grepl(' ', path, fixed=TRUE))
            path <- utils::shortPathName(path)
        path <- gsub("\\\\", "/", path)			# #nocov end
    }

    return(path)
}

updateChangeLog <- function(dir = getwd(), text = "") {
    
    clPath <- file.path(dir, "ChangeLog")
    if (is.null(clPath))
        return()
    
    if (!file.exists(clPath))
        file.create(clPath)
    
    on.exit(file.edit(clPath))
    
    git <- Sys.which("git")
    stopifnot(git != "")
    
    gitOutput <- system("git status --porcelain", intern = TRUE)
    if (!length(gitOutput))
        return()
    
    changedFiles <- sort(substr(gitOutput, 4, nchar(gitOutput)))
    
    userName <- getOption("devtools.name", default = Sys.getenv("USER"))
    descOpt <- getOption("devtools.desc")
    if (length(descOpt)) {
        maintainer <- descOpt$Maintainer
        if (length(maintainer))
            mail <- sub(".*<\\s*(.*)\\s*>", "<\\1>", maintainer, perl = TRUE)
    } else {
        mail <- Sys.getenv("MAIL")
    }
    
    date <- as.character(Sys.Date())
    
    header <- paste(date, userName, mail, sep = "  ")
    body <- if (length(changedFiles)) {
        paste(
            sep = "", collapse = "\n",
            "        * ", changedFiles, ": ", text
        )
    }
    
    all <- paste(header, "", body, sep = "\n")
    
    contents <- if (file.exists(clPath))
        paste(readLines(clPath), collapse = "\n")
    
    amended <- paste(all, "", contents, sep = "\n")
    amended <- sub("\\s*$", "", amended, perl = TRUE)
    
    cat(amended, file = clPath, sep = "\n")
    
}
