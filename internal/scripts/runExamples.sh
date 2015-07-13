#!/bin/bash

set -e 

function runConvolveBennchmark {
    cd Rcpp/inst/examples/ConvolveBenchmarks
    ./buildAndRun.sh
    cd -
}

function runFastLM {
    cd Rcpp/inst/examples/FastLM
    Rscript ./benchmark.r
    cd -
}

function runFunctionCallback {
    cd Rcpp/inst/examples/functionCallback
    Rscript ./newApiExample.r
    cd -
}

function runRcppInline {
    cd Rcpp/inst/examples/RcppInline
    Rscript ./external_pointer.r
    Rscript ./RcppInlineExample.r
    Rscript ./RcppInlineWithLibsExamples.r
    Rscript ./RcppSimpleExample.r
    Rscript ./RObject.r
    Rscript ./UncaughtExceptions.r
    cd -
}


function runSugarPerformance {
    cd Rcpp/inst/examples/SugarPerformance
    Rscript ./sugarBenchmarks.R
    cd -
}

function runRInsideExamples {
    cd ../../rinside/pkg/inst/examples/standard
    make clean
    make
    ./rinside_sample0
    ./rinside_sample1
    ./rinside_sample2
    ./rinside_sample3
    ./rinside_sample4
    ./rinside_sample5
    ./rinside_sample6
    ./rinside_sample7
    ./rinside_sample8
    ./rinside_sample9
    ./rinside_sample10
    ./rinside_sample11
    ./rinside_module_sample0
    ./rinside_callbacks0
    echo "DONE RInside standard examples"
    cd -
}

runConvolveBennchmark
runFastLM
runFunctionCallback
runRcppInline
runSugarPerformance
runRInsideExamples
