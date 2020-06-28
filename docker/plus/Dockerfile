## Emacs, make this -*- mode: sh; -*-

FROM rcpp/run

LABEL org.label-schema.license="GPL-2.0" \
      org.label-schema.vcs-url="https://github.com/RcppCore/Rcpp" \
      maintainer="Dirk Eddelbuettel <edd@debian.org>"

RUN apt-get update \
        && apt-get install -y --no-install-recommends \
                r-cran-bit64 \
                r-cran-curl \
                r-cran-httr \
                r-cran-knitr \
                r-cran-lazyeval \
                r-cran-openssl \
                r-cran-rcpparmadillo \
                r-cran-rcppeigen \
                r-cran-rcppgsl \
                r-cran-rmarkdown \
                r-cran-runit \
                r-cran-withr \
        && install.r BH microbenchmark pinp

CMD ["bash"]
