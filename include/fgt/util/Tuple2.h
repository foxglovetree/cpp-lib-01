#pragma once

namespace fgt::util {

template <typename A, typename B>
class Tuple2 {

public:
    A a;
    B b;

    Tuple2(A a, B b) {
        this->a = a;
        this->b = b;
    }
};

} // namespace fgt::util
