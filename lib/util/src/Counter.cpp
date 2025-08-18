#include "fgt/util/Counter.h"

#define INC (10)
namespace fgt {
namespace util {

Counter::Counter() {
}
Counter::~Counter() {
}
int Counter::get() {
    return this->value;
}
Counter *Counter::add() {
    this->value++;
    return this;
}
Counter *Counter::minus() {
    this->value--;
    return this;
}

} // namespace util
} // namespace fgt