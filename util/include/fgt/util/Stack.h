#pragma once
#include "Assert.h"
#include "Buffer.h"
#include "Callback3.h"
#include "Debug.h"
#include "Lang.h"
#include "Math.h"
#include "defines.h"
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
