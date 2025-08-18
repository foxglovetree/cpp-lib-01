#pragma once
#include "fgt/util/String.h"
namespace fgt::util {

class Assert {
private:
    void emptyMethod() const {
    }

public:

    static void illegalArgument(const String msg) {
        static_cast<Assert *>(0)->emptyMethod();
    }
};

} // namespace fgt::util
