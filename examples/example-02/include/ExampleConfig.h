#pragma once
#include "fgt/util.h"
#include "fgt/config.h"
namespace fgt::example
{
    using fgt::util::Buffer;
    using fgt::config::ConfigContext;
    using fgt::config::ConfigItem;
    using fgt::config::ConfigItems;
    using fgt::util::Directory;
    using fgt::util::EnumType;
    using fgt::util::String;

    class Config : public ConfigItem
    {
    public:
        enum MissionType
        {
            M1,
            M2,
        };

    private:
        EnumType<MissionType> missions;
        ConfigItem *startConfigItem;

    public:
        MissionType missionSelect; // -1 means not selected.

    public:
        Config()
        {
            missions.add(MissionType::M1, "M1");
            missions.add(MissionType::M2, "M2");
            missionSelect = MissionType::M1;
        }
        void onAttached() override
        {
            {
                ConfigItem *ci = ConfigItems::addReturn(this, "Start");
                this->startConfigItem = ci;
                ci->onEnter = [](ConfigContext &cc)
                {
                    cc.navigator->stop(1);
                };
                ci->onBuildTitle = [](TitleBuilder &title)
                {
                    Config *this_ = title.configItem->getRoot<Config>();

                    if (this_->missionSelect == MissionType::M1)
                    {
                        title.set<String>("mission", "M1");
                    }
                    else if (this_->missionSelect == MissionType::M2)
                    {
                        title.set<String>("mission", "M2");
                    }
                    else
                    {
                        title.set<String>("mission", "<Please-select>");
                    }
                };
            }
            {
                ConfigItem *this_ = (ConfigItem *)this;
                ConfigItems::addSelectInput<MissionType>(this_, String() << "Select-Mission", this->missionSelect, missions.options);
            }
        }

        bool isValid() override
        {
            if (this->missionSelect == MissionType::M1)
            {
                return true;
            }
            else if (this->missionSelect == MissionType::M2)
            {
                return true;
            }
            else
            {
                // no such mission type.
                return false;
            }
        }
        void onLeftFailure(ConfigContext &cc) override
        {
            cc.navigator->to(this->startConfigItem->getDirectory());
        }

        void enter(ConfigContext &cc) override
        {
            ConfigItems::runNav(this->dir, cc);
        }
    };
}
