#pragma once
#include "Math.h"
#include "String.h"
#include "StringUtil.h"
namespace fgt::util {
using namespace fgt::util;
class Bool {
public:
    static bool parse(const String &bStr) {        
        return bStr.equalsIgnoreCase("true") || bStr.equalsIgnoreCase("y") || bStr.equalsIgnoreCase("yes");
    }
};

} // namespace fgt::util
