#ifndef CERVISEMESTRALKA_SETTINGS_H
#define CERVISEMESTRALKA_SETTINGS_H
#include <cstdlib>
#include <vector>
#include <map>
#include "Enums.h"

namespace Game
{
    class Settings
    {
    private:
        Settings();
        static Settings* Instance;
        struct PlayerSetting
        {
            int Playerindex;
            std::map<Keys,Directions> Actions;
        };
        std::vector<PlayerSetting> IndividualSetting;
    public:
        Settings(const Settings&) = delete;
        Settings& operator=(const Settings& second) = delete;
        static Settings* GetInstance();
        ~Settings();

        void GetAction(Keys Key,int& Player,Directions& Direction);
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
