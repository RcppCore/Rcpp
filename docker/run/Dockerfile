## Emacs, make this -*- mode: sh; -*-

FROM rcpp/ci

LABEL org.label-schema.license="GPL-2.0" \
      org.label-schema.vcs-url="https://github.com/RcppCore/Rcpp" \
      maintainer="Dirk Eddelbuettel <edd@debian.org>"

## If on CRAN, install the latest version from CRAN
RUN install.r Rcpp

## Alternatively, install from Github (after first installing remotes)
#RUN install.r remotes && installGithub.r RcppCore/Rcpp

CMD ["bash"]
