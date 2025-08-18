#pragma once
namespace fgt::util {

template <typename T, typename R>
class Callback3 {
public:
    virtual R callback(T context) = 0;
};

} // namespace fgt::util