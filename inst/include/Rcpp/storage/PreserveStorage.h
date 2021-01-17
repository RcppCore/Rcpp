#ifndef Rcpp_PreserveStorage_h
#define Rcpp_PreserveStorage_h

namespace Rcpp{

    template <typename CLASS>
    class PreserveStorage {
    public:

        PreserveStorage() : data(R_NilValue), token(R_NilValue){}

        ~PreserveStorage(){
            Rcpp_ReleaseObject(token) ;
            data = R_NilValue;
            token = R_NilValue;
        }

        inline void set__(SEXP x){
            if (data != x) {
                data = x;
                Rcpp_ReleaseObject(token);
                token = Rcpp_PreserveObject(data);
            }

            // calls the update method of CLASS
            // this is where to react to changes in the underlying SEXP
            static_cast<CLASS&>(*this).update(data) ;
        }

        inline SEXP get__() const {
            return data ;
        }

        inline SEXP invalidate__(){
            SEXP out = data ;
            Rcpp_ReleaseObject(token);
            data = R_NilValue ;
            token = R_NilValue ;
            return out ;
        }

        template <typename T>
        inline T& copy__(const T& other){
            if( this != &other){
                set__(other.get__());
            }
            return static_cast<T&>(*this) ;
        }

        inline bool inherits(const char* clazz) const {
            return ::Rf_inherits( data, clazz) ;
        }

        inline operator SEXP() const { return data; }

    private:
        SEXP data ;
        SEXP token ;
    } ;

}

#endif
