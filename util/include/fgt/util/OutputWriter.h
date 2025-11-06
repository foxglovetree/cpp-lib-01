#pragma once
#include "Debug.h"
#include "Output.h"
#include "Writer.h"

namespace fgt::util {
class OutputWriter : public Writer {

    Output *out;

    int write(const char *buf, int bufLen, Result &res) override {
        fgt_TRACE(">>OutputWriter::write");
        out->print(buf, bufLen);
        fgt_TRACE("<<OutputWriter::write");
        return bufLen;
    }

public:
    OutputWriter(Output *output) {
        this->out = output;
    }
};
} // namespace fgt::util