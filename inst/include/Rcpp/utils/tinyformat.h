namespace Rcpp {
void stop(const std::string& message);
}
#define TINYFORMAT_ERROR(REASON) ::Rcpp::stop(REASON)

#if __cplusplus >= 201103L
#define TINYFORMAT_USE_VARIADIC_TEMPLATES
#else
// Don't use C++11 features (support older compilers)
#define TINYFORMAT_NO_VARIADIC_TEMPLATES
#endif

#include "tinyformat/tinyformat.h"
