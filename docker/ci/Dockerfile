## Emacs, make this -*- mode: sh; -*-

FROM r-base:latest

LABEL org.label-schema.license="GPL-2.0" \
      org.label-schema.vcs-url="https://github.com/RcppCore/Rcpp" \
      maintainer="Dirk Eddelbuettel <edd@debian.org>"

RUN apt-get update \
        && apt-get install -y --no-install-recommends \
                r-cran-runit \
                r-cran-inline \
                r-cran-rmarkdown \
                r-cran-knitr \
                r-cran-pkgkitten \
                r-cran-curl \
                r-cran-openssl \
                r-cran-httr \
                r-cran-lazyeval \
                r-cran-withr \
                git \
        && install.r rbenchmark pinp covr

ENV _R_CHECK_FORCE_SUGGESTS_ FALSE
ENV RunAllRcppTests yes

CMD ["bash"]
