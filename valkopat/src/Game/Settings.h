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
    //singleton
    private:
        Settings();
        static Settings* Instance;
    public:
        Settings(const Settings&) = delete;
        Settings& operator=(const Settings& second) = delete;
        static Settings* GetInstance();
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
        void GetAction(Keys Key,int& Player,Directions& Direction);
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
