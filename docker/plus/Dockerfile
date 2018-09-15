## Emacs, make this -*- mode: sh; -*-

FROM rcpp/run

LABEL org.label-schema.license="GPL-2.0" \
      org.label-schema.vcs-url="https://github.com/RcppCore/Rcpp" \
      maintainer="Dirk Eddelbuettel <edd@debian.org>"

RUN apt-get update \
        && apt-get install -y --no-install-recommends \
                r-cran-rcpparmadillo \
                r-cran-rcppeigen \
                r-cran-rcppgsl \
        && install.r microbenchmark BH

CMD ["bash"]
