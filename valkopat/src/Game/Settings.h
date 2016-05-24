#ifndef CERVISEMESTRALKA_SETTINGS_H
#define CERVISEMESTRALKA_SETTINGS_H
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "Enums.h"

namespace Game
{
    class Settings
    {
    //singleton
    private:
        Settings();
        static Settings* Instance;
    public:
        static Settings* GetInstance();
        Settings(const Settings&) = delete;
        Settings& operator=(const Settings& second) = delete;
        ~Settings();

    //implementation
    private:
        struct PlayerSetting
        {
            int Playerindex;
            std::map<Keys,Directions> Actions;
        };
        std::vector<PlayerSetting> IndividualSetting;
    public:
        bool GetAction(Keys Key,int& Player,Directions& Direction) const;
        bool SetAction(Keys NewKey, int Player, Directions NewDirection);
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
