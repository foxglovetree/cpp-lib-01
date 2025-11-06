#ifndef Counter__
#define Counter__

namespace fgt {
namespace util {

class Counter {
public:
    Counter();
    ~Counter();
    Counter* add();
    Counter * minus();
    int get();    
private:
    int value;
};
} // namespace util

} // namespace fgt

#endif