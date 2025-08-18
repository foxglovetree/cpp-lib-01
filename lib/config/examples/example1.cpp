
#include "fgt/config.h"
#include "Arduino.h"

using namespace fgt::util;
using namespace fgt::config;

class HelloWorld : public ConfigItem
{
public:
    void onAttached() override
    {
        ConfigItem *ci1 = ConfigItems::addReturn(this, "Hello");
        ci1->onEnter = [](ConfigContext &cc)
        {
            cc.navigator->stop(1);
        };
        ConfigItem *ci2 = ConfigItems::addReturn(this, "World");
    }

    void enter(ConfigContext &cc) override
    {
        ConfigItems::runNav(this->dir, cc);
    }
};


class ArduinoInput : public Reader
{

public:
    ArduinoInput()
    {
        while (Serial.available())
        {
            Serial.read();
        }
    }
    ~ArduinoInput() {}
    int read(char *buf, int bufLen, Result &res) override
    {
        while (!Serial.available())
        {
            delay(10);
        }
        buf[0] = Serial.read();
        return 1;
    }
};
class ArduinoOutput : public Output
{

public:
    void print(const fgt::util::String msg) override
    {
        // A8_TRACE2(">>ArduinoOutput::print,msg:", msg.text());
        Serial.print(msg.text());
        // A8_TRACE("<<ArduinoOutput::print");
    }
};
class EmptyLogger : public Logger
{
public:
    EmptyLogger() : Logger("Empty.Logger")
    {
    }
    void log(Level level, const fgt::util::String &msg) override
    {
    }
};


void main()
{
    HelloWorld *fg = new HelloWorld();
    Directory<ConfigItem *> *fgDir = new Directory<ConfigItem *>(fgt::util::String() << "HelloWorldDir", 0);
    fg->attach(fgDir);
    Reader *reader = new ArduinoInput();
    Output *out = new ArduinoOutput();
    Logger *logger = new EmptyLogger();
    Result res;
    ConfigContext cc(reader, out, logger, res);
    // Main loop
    while (1)
    {
        fg->enter(cc);
    }
}
