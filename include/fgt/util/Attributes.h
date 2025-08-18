#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
namespace fgt {
namespace util {

class Attributes {
public:
    Attributes();
    ~Attributes();
    void *get(int key);
    void set(int key, void *value);

private:
    void **ensureCapacity(int key);
    int capacity;
    void **attributes;
};
} // namespace util

} // namespace fgt

#endif