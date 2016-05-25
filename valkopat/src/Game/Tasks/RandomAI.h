#ifndef CERVISEMESTRALKA_RANDOMAI_H
#define CERVISEMESTRALKA_RANDOMAI_H
#include <set>
#include "BaseAITask.h"
#include "../GameContent.h"
#include "../Worm.h"

namespace Game
{
    namespace Task
    {
        class RandomAI : public BaseAITask
        {
        public:
            RandomAI(Worm* AIWorm,GameContent* Content);
            virtual void run();
        private:
            Worm* ControlledWorm;
            GameContent* ContentOfGame;
        };
    }
}



#endif //CERVISEMESTRALKA_RANDOMAI_H
