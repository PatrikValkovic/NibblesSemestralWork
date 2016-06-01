#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
#include <map>
#include "AbstractEvent.h"
#include "../../ViewModels/Abstract/AbstractInput.h"
#include "../Worm.h"
#include "../Settings.h"

namespace Game
{
    namespace Event
    {
        /**
         * Event for singleplayer
         */
        class Single : public Abstract
        {
        public:
            /**
             * Create new instance of Single event
             * @param Player Game::Worm to controll
             * @param InputMethod Rendering submodule specific input
             * @param IndexOfPlayer Index of player to control
             * @param Set Setting of keybindings
             * @return New instance of Single event
             */
            Single(Worm* Player,ViewModel::AbstractInput* InputMethod, int IndexOfPlayer, Settings* Set);

            /**
             * Always return true
             * @return True
             */
            virtual bool HasActions();

            /**
             * Get inputs and proccess it
             * @return True if game should continue, false otherwise
             */
            virtual bool ProccessActions();

        private:
            Worm* Player;
            int PlayerIndex;
            ViewModel::AbstractInput* InputClass;
            Settings* ActualSetting;
        };
    }
}


#endif //CERVISEMESTRALKA_SINGPLE_H
