#pragma once
namespace fgt::util {

template <typename T>
class Callback2 {
public:
    virtual void callback(T context) = 0;
};

} // namespace fgt::util