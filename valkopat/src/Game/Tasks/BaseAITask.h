#ifndef CERVISEMESTRALKA_BASEAITASK_H
#define CERVISEMESTRALKA_BASEAITASK_H
#include "BaseTask.h"
#include "../Worm.h"
#include "../GameContent.h"

namespace Game
{
    namespace Task
    {
        /**
         * Represent base abstract class to inherit by AI
         */
        class BaseAITask : public BaseTask
        {
        protected:
            /**
             * Worm to controll
             */
            Worm* ControlledWorm;

            /**
             * Current content of game
             */
            GameContent* ContentOfGame;
        public:
            /**
             * Create new instance of BaseAITask
             * @param WormToControl Game::Worm to control
             * @param Game Game::GameContent Current content of game
             * @return New instance of BaseAITask
             */
            BaseAITask(Worm* WormToControl,GameContent* Game);

            /**
             * Creates new instance of same class
             * @param WormToControl WormToControl
             * @param Game Current content of game
             * @return New instance of same type as inherited type
             */
            virtual BaseAITask* CreateInstance(Worm* WormToControl,GameContent* Game) = 0;
        };
    }
}



#endif //CERVISEMESTRALKA_BASEAITASK_H
