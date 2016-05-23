#ifndef CERVISEMESTRALKA_SETTINGS_H
#define CERVISEMESTRALKA_SETTINGS_H

namespace Game
{
    class Settings
    {
    private:
        Settings();
        Settings* Instance;
    public:
        Settings(const Settings&) = delete;
        Settings& operator=(const Settings& second) = delete;
        Settings* GetInstance();
        ~Settings();
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
