#if __cplusplus >= 201103L
#    define RCPP_CONSTEXPR constexpr
#else
#    define RCPP_CONSTEXPR const
#endif

namespace Rcpp {
namespace algorithm {

namespace helpers {
    template< typename T >
    struct rtype_helper {
        /*
	typedef T type;
        static RCPP_CONSTEXPR int RTYPE = REALSXP;
        static inline double NA() { return NA_REAL; }
        static inline RCPP_CONSTEXPR double ZERO() { return 0.0; }
        static inline RCPP_CONSTEXPR double ONE() { return 1.0; }
        */
    };

    template<>
    struct rtype_helper< double > {
        typedef double type;
        static RCPP_CONSTEXPR int RTYPE = REALSXP;
        static inline double NA() { return NA_REAL; }
        static inline RCPP_CONSTEXPR double ZERO() { return 0.0; }
        static inline RCPP_CONSTEXPR double ONE() { return 1.0; }
    };

    template<>
    struct rtype_helper< int > {
        typedef int type;
        static RCPP_CONSTEXPR int RTYPE = INTSXP;
        static inline int NA() { return NA_INTEGER; }
        static inline RCPP_CONSTEXPR int ZERO() { return 0; }
        static inline RCPP_CONSTEXPR int ONE() { return 1; }
    };

    template< typename T >
    struct rtype {
        typedef typename rtype_helper< typename traits::remove_const_and_reference< T >::type >::type type;
        static RCPP_CONSTEXPR int RTYPE =
            rtype_helper< typename traits::remove_const_and_reference< T >::type >::RTYPE;
        static inline T NA() { return rtype_helper< typename traits::remove_const_and_reference< T >::type >::NA(); }
        static inline RCPP_CONSTEXPR T ZERO() { return rtype_helper< typename traits::remove_const_and_reference< T >::type >::ZERO(); }
        static inline RCPP_CONSTEXPR T ONE() { return rtype_helper< typename traits::remove_const_and_reference< T >::type >::ONE(); }
    };

    struct log {
        template< typename T >
        inline double operator()(T val) {
            if (!Vector< rtype< T >::RTYPE >::is_na(val)) {
                return std::log(val);
            }

            return rtype< double >::NA();
        }
    };

    struct exp {
        template< typename T >
        inline double operator()(T val) {
            if (!Vector< rtype< T >::RTYPE >::is_na(val)) {
                return std::exp(val);
            }

            return rtype< double >::NA();
        }
    };

    struct sqrt {
        template< typename T >
        inline double operator()(T val) {
            if (!Vector< rtype< T >::RTYPE >::is_na(val)) {
                return std::sqrt(val);
            }

            return rtype< double >::NA();
        }
    };
} // namespace helpers

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type sum(InputIterator begin, InputIterator end) {
    
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
         value_type start = rtype::ZERO();

        while (begin != end) {
            if (!Vector< rtype::RTYPE >::is_na(*begin)) {
                start += *begin++;
            } else {
                return rtype::NA();
            }
        }

        return start;
    }

    return rtype::ZERO();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type sum_nona(InputIterator begin, InputIterator end) {
    
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
         value_type start = rtype::ZERO();

        while (begin != end) {
            start += *begin++;
        }

        return start;
    }

    return rtype::ZERO();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type prod(InputIterator begin, InputIterator end) {

    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type start = rtype::ONE();

        while (begin != end) {
            if (!Vector< rtype::RTYPE >::is_na(*begin)) {
                start *= *begin++;
            } else {
                return rtype::NA();
            }
        }

        return start;
    }

    return rtype::ONE();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type prod_nona(InputIterator begin, InputIterator end) {

    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type start = rtype::ONE();

        while (begin != end) {
            start *= *begin++;
        }

        return start;
    }

    return rtype::ONE();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type max(InputIterator begin, InputIterator end) {
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type max = *begin;

	while (begin != end) {
            if (!Vector< rtype::RTYPE >::is_na(*begin)) {
                max = std::max(max, *begin++);
            } else {
                return rtype::NA();
            }
        }

        return max;
    }

    return std::numeric_limits< typename rtype::type >::infinity() * -rtype::ONE();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type max_nona(InputIterator begin, InputIterator end) {
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type max = *begin;

	while (begin != end) {
            max = std::max(max, *begin++);
        }

        return max;
    }

    return std::numeric_limits< typename rtype::type >::infinity() * -rtype::ONE();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type min(InputIterator begin, InputIterator end) {
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type min = *begin;

	while (begin != end) {
            if (!Vector< rtype::RTYPE >::is_na(*begin)) {
                min = std::min(min, *begin++);
            } else {
                return rtype::NA();
            }
        }

        return min;
    }

    return std::numeric_limits< typename rtype::type >::infinity();
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type min_nona(InputIterator begin, InputIterator end) {
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type min = *begin;

	while (begin != end) {
            min = std::min(min, *begin++);
        }

        return min;
    }

    return std::numeric_limits< typename rtype::type >::infinity();
}

// for REALSXP
template< typename InputIterator >
typename traits::enable_if< traits::same_type< typename std::iterator_traits< InputIterator >::value_type, double >::value, double >::type
mean(InputIterator begin, InputIterator end)
{
    if (begin != end)
    {
        std::size_t n = end - begin;
        long double s = std::accumulate(begin, end, 0.0L);
        s /= n;

        if (R_FINITE((double) s)) {
            long double t = 0.0L;
            while (begin != end) {
                t += *begin++ - s;
            }

            s += t / n;
        }

        return (double) s;
    }

    return helpers::rtype< double >::NA();
}

// for LGLSXP and INTSXP
template< typename InputIterator >
typename traits::enable_if< traits::same_type< typename std::iterator_traits< InputIterator >::value_type, int >::value, double >::type
mean(InputIterator begin, InputIterator end)
{
    if (begin != end)
    {
        std::size_t n = end - begin;
        long double s = std::accumulate(begin, end, 0.0L);
        s /= n;

        if (R_FINITE((double) s)) {
            long double t = 0.0L;
            while (begin != end) {
                if (*begin == helpers::rtype< int >::NA()) return helpers::rtype< double >::NA();
                t += *begin++ - s;
            }

            s += t / n;
        }

        return (double) s;
    }

    return helpers::rtype< double >::NA();
}

template< typename InputIterator, typename OutputIterator >
void log(InputIterator begin, InputIterator end, OutputIterator out) {
    std::transform(begin, end, out, helpers::log());
}

template< typename InputIterator, typename OutputIterator >
void exp(InputIterator begin, InputIterator end, OutputIterator out) {
    std::transform(begin, end, out, helpers::exp());
}

template< typename InputIterator, typename OutputIterator >
void sqrt(InputIterator begin, InputIterator end, OutputIterator out) {
    std::transform(begin, end, out, helpers::sqrt());
}

} // namespace algorithm
} // namespace Rcpp

#undef RCPP_CONSTEXPR
