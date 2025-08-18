#pragma once
#include "fgt/util/Assert.h"
#include "fgt/util/Buffer.h"
#include "fgt/util/Callback3.h"
#include "fgt/util/Debug.h"
#include "fgt/util/Lang.h"
#include "fgt/util/Math.h"
#include "fgt/util/defines.h"
#include "debug.h"

namespace fgt::util {

template <typename T>
class Stack : public Buffer<T> {
public:
    Stack() {
    }
    void push(T ele) {
        this->append(ele);
    }

    int peek(T &ele) {        
        return this->getLast(ele);
    }

    int pop() {
        T ele;
        return this->pop(ele);
    }

    int pop(T &ele) {
        return this->removeLast(ele);
    }
};

// implementation

} // namespace fgt::util
