#pragma once
#include "Buffer.h"
#include "Reader.h"
#include "String.h"
#include "Result.h"

namespace fgt::util {

/**
 */
class StringReader : public Reader {
protected:
    Buffer<char> buffer;
    int from = 0;

public:
    StringReader() {
    }
    StringReader(const char *str) {
        buffer.append(str, Array::strLength(str));
    }
    StringReader(const String str) {
        buffer.append(str.text(), str.len());
    }

    ~StringReader() {
    }
    void append(String msg) {
        buffer.append(msg.text(), msg.length());
    }

    int read(char *buf, int bufLen, Result &res) override {
        if (from == buffer.len()) {
            return 0; // end of reading.
        }
        int ret = buffer.read(from, buf, bufLen);
        if (ret < 0) {
            return ret;
        }
        int len = ret;
        from += len;
        return len;
    };
};

} // namespace fgt::util