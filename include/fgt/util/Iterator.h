#pragma once
namespace fgt::util {
template <typename T>
class Iterator {
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};
} // namespace fgt::util