#pragma once
#include "fgt/util/Logger.h"
#include "fgt/util/System.h"
#include "fgt/util/Writer.h"

namespace fgt::util {
using namespace fgt::util;

class WriterLogger : public Logger {
protected:
    Writer *writer;
    System *sys;

public:
    WriterLogger(String name, Writer *writer, System *sys) : Logger(name) {
        this->writer = writer;
        this->sys = sys;
    }
    ~WriterLogger() {
    }

    void writeLevel(Logger::Level level, String &msg) {
    }

    void writeTime() {
    }

    void log(Logger::Level level, const String &msg) override {
        fgt_TRACE(">>WriterLogger::log()");
        long long stime = sys->getSysTime();
        String formatTime;
        sys->formatTime(stime, &formatTime);
        String msg2;
        msg2 << "[" << formatTime << "] [" << level << "] " << msg;
        writer->write(msg2.text(), msg2.length());
        writer->write("\n", 1);
        fgt_TRACE("<<WriterLogger::log()");
    };
};

} // namespace fgt::util
