#include "fgt/util.h"
#include "fgt/config.h"
#include "ExampleConfig.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace fgt::util;
using namespace fgt::config;
using namespace fgt::example;
System *sys;

int main(int argc, char **argv)
{
    Config *fg = new Config();
    Directory<ConfigItem *> *fgDir = new Directory<ConfigItem *>(String() << "Foreground()", 0);
    fg->attach(fgDir);
    Reader *reader = nullptr;
    Output *out = nullptr;
    Logger *logger = nullptr;
    Result res;
    ConfigContext cc(reader, out, logger, res);
    // Main loop
    while (1)
    {
        fg->enter(cc);
        if (fg->missionSelect == Config::MissionType::M1)
        {
        }
    }
}
