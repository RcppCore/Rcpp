#include <Rcpp.h>

using namespace Rcpp;

// unrelated to testRcppCollisionA's Collision, but of the same name, and so
// with the same typeid name
class Collision {
public:
    Collision() : values(3, 1.0) {}
    std::vector<double> get() { return values; }
    std::vector<double> values;
};

RCPP_EXPOSED_CLASS_NODECL(Collision)

Collision make_collision() {
    return Collision();
}

RCPP_MODULE(collision_module) {
    class_<Collision>("Collision")
        .constructor()
        .method("get", &Collision::get)
        ;

    function("make_collision", &make_collision);
}
