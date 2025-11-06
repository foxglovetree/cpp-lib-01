#pragma once
#include "Buffer.h"
#include "LineReader.h"
#include "Math.h"
#include "Reader.h"
#include "Result.h"
#include "String.h"
#include "StringReader.h"
#include "StringUtil.h"

#define LR_MAX_LEN_ (1024) // 1k

namespace fgt::util {

/**
 */
class BufferReader : public Reader {

    Buffer<char> buf_;
    int from = 0;

public:
    BufferReader() {
    }
    BufferReader(char *buf, int len) {
        this->append(buf, len);
    }
    int read(char *buf, int bufLen, Result &res) override {
        int ret = 0;
        if (from < this->buf_.len()) {
            ret = this->buf_.read(from, buf, bufLen);
        }
        if (ret <= 0) {
            return ret;
        }
        from += ret;
        if (from > LR_MAX_LEN_) {
            this->buf_ = this->buf_.subBuffer(from);
            this->from = 0;
        }
        return ret;
    }

    bool hasMore() {
        return this->from < buf_.len() - 1;
    }

    void append(char *buf, int len) {
        buf_.append(buf, len);
    }
};

} // namespace fgt::util