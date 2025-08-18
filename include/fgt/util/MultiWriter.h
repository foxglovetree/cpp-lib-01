#pragma once
#include "fgt/util/Debug.h"
#include "fgt/util/Buffer.h"
#include "fgt/util/Result.h"
#include "fgt/util/Writer.h"

namespace fgt::util {
class MultiWriter : public Writer {

    Buffer<Writer *> writers;

    int write(const char *buf, int bufLen, Result &res) override {
        fgt_TRACE(">>MultiWriter::write");
        for (int i = 0; i < writers.len(); i++) {
            int ret = writers[i]->write(buf, bufLen);
            if (ret < 0) {
                return ret;
            }
        }
        fgt_TRACE("<<MultiWriter::write");
        return bufLen;
    }

public:
    void add(Writer *writer) {
        this->writers.append(writer);
    }
};
} // namespace fgt::util