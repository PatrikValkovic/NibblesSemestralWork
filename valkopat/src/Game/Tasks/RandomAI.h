#ifndef CERVISEMESTRALKA_RANDOMAI_H
#define CERVISEMESTRALKA_RANDOMAI_H
#include <set>
#include "BaseAITask.h"

namespace Game
{
    namespace Task
    {
        /**
         * Task for AI with random movement
         */
        class RandomAI : public BaseAITask
        {
        public:
            /**
             * Create new instance of RandomAI
             * @param AIWorm Controlled Game::Worm
             * @param Content Game::GameContent Content of game
             * @return New instance of RandomAI
             */
            RandomAI(Worm* AIWorm,GameContent* Content);

            /**
             * Change Game::Worm directory randomly
             */
            virtual void run();
            virtual BaseAITask* CreateInstance(Worm* WormToControl,GameContent* Game);
        };
    }
}



#endif //CERVISEMESTRALKA_RANDOMAI_H
