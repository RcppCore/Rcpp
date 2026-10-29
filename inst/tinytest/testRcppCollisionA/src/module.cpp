#include <Rcpp.h>

using namespace Rcpp;

// unrelated to testRcppCollisionB's Collision, but of the same name, and so
// with the same typeid name
class Collision {
public:
    Collision(double x_) : x(x_) {}
    double get() { return x; }
    double x;
};

RCPP_EXPOSED_CLASS_NODECL(Collision)

Collision make_collision(double x) {
    return Collision(x);
}

RCPP_MODULE(collision_module) {
    class_<Collision>("Collision")
        .constructor<double>()
        .method("get", &Collision::get)
        ;

    function("make_collision", &make_collision);
}
