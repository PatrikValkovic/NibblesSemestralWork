#ifndef CERVISEMESTRALKA_SETTINGS_H
#define CERVISEMESTRALKA_SETTINGS_H
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "../Exceptions/InvalidArgumentException.h"
#include "Enums.h"

namespace Game
{
    /**
     * Managing setting of keys
     */
    class Settings
    {
    //singleton
    private:
        /**
         * Private contructor, creates base setting
         * @return New instance of Settings
         */
        Settings();
        /**
         * Singleton instance
         */
        static Settings* Instance;

    public:
        /**
         * Return instance of Settings
         * @return Already created instance of Settings
         */
        static Settings* GetInstance();
        Settings(const Settings&) = delete;
        Settings& operator=(const Settings& second) = delete;
        /**
         * Destructor delete instance if exists
         */
        ~Settings();

    //implementation
    private:
        /**
         * Helper class containing informations about setting for specific user
         */
        struct PlayerSetting
        {
            /**
             * Index of player to which setting is apply
             */
            int Playerindex;
            /**
             * Setting of keybinding
             */
            std::map<Keys,Actions> Action;
        };
        /**
         * Vector of settings for every user
         */
        std::vector<PlayerSetting> IndividualSetting;
    public:
        /**
         * Get action for Key
         * @param Key Pressed key
         * @param Player Index of player, for which action is
         * @param Action Action assigned to that key
         * @return True if is Key in settings, false otherwise
         */
        bool GetAction(Keys Key,int& Player,Actions& Action) const;

        /**
         * Replace setting by user's own
         * @param NewKey New key to assigne
         * @param Player Index of player, to which setting apply
         * @param NewAction Action to proccess, when press key
         * @return True if was setting changed, false otherwise
         */
        bool SetAction(Keys NewKey, int Player, Actions NewAction);

        /**
         * Get whole setting for player
         * @param IndexOfPlayer Index of specific player
         * @return map of Actions assigned to Keys in format map<Key,Action>
         */
        std::map<Keys,Actions> GetSettingForPlayer(int IndexOfPlayer);

        /**
         * Return max count of player, for which have setting
         * @return 3 (could change later)
         */
        int MaxCountOfPlayers() const;
    };
}


#endif //CERVISEMESTRALKA_SETTINGS_H
