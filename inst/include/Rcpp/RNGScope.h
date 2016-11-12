#ifndef Rcpp__RNGScope_h
#define Rcpp__RNGScope_h

namespace Rcpp {

class RNGScope{
public:
    RNGScope(){ internal::enterRNGScope(); }
    ~RNGScope(){ internal::exitRNGScope(); }
};

} // namespace Rcpp

#endif
