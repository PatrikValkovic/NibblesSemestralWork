#ifndef CERVISEMESTRALKA_SETTINGS_H
#define CERVISEMESTRALKA_SETTINGS_H
#include <cstdlib>

namespace Game
{
    class Settings
    {
    private:
        Settings();
        static Settings* Instance;
    public:
        Settings(const Settings&) = delete;
        Settings& operator=(const Settings& second) = delete;
        static Settings* GetInstance();
        ~Settings();
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
