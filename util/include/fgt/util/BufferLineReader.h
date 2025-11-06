#pragma once
#include "Buffer.h"
#include "LineReader.h"
#include "Math.h"
#include "Reader.h"
#include "Result.h"
#include "String.h"
#include "StringReader.h"
#include "StringUtil.h"
#include "BufferReader.h"

#define LR_MAX_LEN_ (1024) // 1k

namespace fgt::util {

/**
 */
class BufferLineReader {

    BufferReader *input;

    LineReader *lReader;

    String buffer;

public:
    BufferLineReader() {
        this->input = new BufferReader();
        this->lReader = new LineReader(this->input);
    }
    ~BufferLineReader() {
        delete this->lReader;
        delete this->input;
    }

    int append(String msg) {
        input->append(msg.text(), msg.len());
        return msg.len();
    }

    int readLine(String &ret) {
        Result rst;
        return readLine(ret, true, rst);
    }

    int readLine(String &ret, Result &rst) {
        return readLine(ret, true, rst);
    }

    /**
     * Do not readLine unless append first.
     * Reading an empty buffer will lead to final result.
     */
    int readLine(String &line, bool appendSeparator, Result &rst) {

        String builder;
        int ret = lReader->readLine(builder, appendSeparator, rst);
        if (ret == 0) {
            lReader->setReader(this->input);
            ret = lReader->readLine(builder, appendSeparator, rst);
        }

        if (ret <= 0) {
            return ret;
        }

        if (builder.length() < ret || builder.endWith('\n')) {

            buffer << builder;
            line = buffer;
            ret = buffer.len();
            buffer.clear();
        } else {
            buffer << builder;
            ret = -ret;
        }

        return ret;
    }

    int bufferLen() {
        return this->buffer.len();
    }
};

} // namespace fgt::util