#ifndef CERVISEMESTRALKA_SETTINGS_H
#define CERVISEMESTRALKA_SETTINGS_H
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "Enums.h"
#include "../Exceptions/InvalidArgumentException.h"

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
            std::map<Keys,Actions> Action;
        };
        std::vector<PlayerSetting> IndividualSetting;
    public:
        bool GetAction(Keys Key,int& Player,Actions& Direction) const;
        bool SetAction(Keys NewKey, int Player, Actions NewDirection);
        std::map<Keys,Actions> GetSettingForPlayer(int IndexOfPlayer);
        int MaxCountOfPlayers() const;
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
