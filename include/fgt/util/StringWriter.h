#pragma once
#include "fgt/util/Buffer.h"
#include "fgt/util/String.h"
#include "fgt/util/Writer.h"

namespace fgt::util {

/**
 */
class StringWriter : public Writer {
protected:
    String str;
    int from = 0;

public:
    StringWriter() {
    }

    ~StringWriter() {
    }
    /**
     * The length of the string may not expected as the buf may contains the end of string character '\0'.
     */
    virtual int write(const char *buf, int bufLen, Result &res) override {
        str.append(buf, bufLen);
        return bufLen;
    };
    
    String toString() {
        // TODO how to avoid copy.
        return str;
    }
};

} // namespace fgt::util