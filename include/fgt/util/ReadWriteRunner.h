#pragma once
#include "fgt/util/ErrorListener.h"
#include "fgt/util/Logger.h"
#include "fgt/util/Reader.h"
#include "fgt/util/Result.h"
#include "fgt/util/Runnable.h"
#include "fgt/util/String.h"
#include "fgt/util/Writer.h"

namespace fgt::util {

class ReadWriteRunner : public Runnable {
private:
    Reader *reader;
    Writer *writer;
    bool running = true;
    Result state;

public:
    ReadWriteRunner(Reader *reader, Writer *writer) {
        this->reader = reader;
        this->writer = writer;
    }
    ~ReadWriteRunner() {}

    virtual void run() {
        while (running) {
            char buf[100];
            Result res;
            int len = reader->read(buf, 100, res);
            if (len <= 0) {
                if (len < 0) { // error
                    state.errorMessage << "Failed to read, stop receiving.";

                    break; // end loop
                }
            }
            writer->write(buf, len);
        }
    };
};
} // namespace fgt::util