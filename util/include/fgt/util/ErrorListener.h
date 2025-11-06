#pragma once
#include "String.h"

namespace fgt::util {
class ErrorListener {
public:
    virtual void onError(int error, String message);
};

} // namespace fgt::util
