#pragma once
#include "Stack.h"
#include "String.h"
namespace fgt::util {

using fgt::util::String;
/**
 *
 */
class Result {
private:
    Result(Result &);
    Result &operator=(Result &);

public:
    Result() {
    }
    String errorMessage;
    Stack<String> stack;

    int reset() {
        int ret = this->errorMessage.len();
        this->errorMessage.clear();
        return ret;
    }

    void push(String entry) {
        stack.push(entry);
    }

    int pop() {
        return stack.pop();
    }
    Result &operator<<(const String &str) {
        this->errorMessage << str;
        return *this;
    }

    friend String &operator<<(String &str, const Result &rst) {
        return str << rst.errorMessage;
    }
};
} // namespace fgt::util