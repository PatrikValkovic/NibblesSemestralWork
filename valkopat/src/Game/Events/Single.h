#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
#include <map>
#include "AbstractEvent.h"
#include "../Worm.h"
#include "../../ViewModels/Abstract/AbstractInput.h"
#include "../Settings.h"

namespace Game
{
    namespace Event
    {
        class Single : public Abstract
        {
        public:
            Single(Worm* Player,ViewModel::AbstractInput* InputMethod, int IndexOfPlayer, Settings* Set);

            virtual bool HasActions();

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
