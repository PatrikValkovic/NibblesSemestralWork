#ifndef CERVISEMESTRALKA_BASEAITASK_H
#define CERVISEMESTRALKA_BASEAITASK_H
#include "BaseTask.h"
#include "../Worm.h"
#include "../GameContent.h"

namespace Game
{
    namespace Task
    {
        class BaseAITask : public BaseTask
        {
        protected:
            Worm* ControlledWorm;
            GameContent* ContentOfGame;
        public:
            BaseAITask(Worm* WormToControl,GameContent* Game);
        };
    }
}



#endif //CERVISEMESTRALKA_BASEAITASK_H
