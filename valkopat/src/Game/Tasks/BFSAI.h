#ifndef CERVISEMESTRALKA_BFSAI_H
#define CERVISEMESTRALKA_BFSAI_H
#include <climits>
#include <set>
#include "BaseTask.h"
#include "../GameContent.h"
#include "../Worm.h"

namespace Game
{
    namespace Task
    {
        class BFSAI : public BaseTask
        {
        public:
            BFSAI(Worm* AIWorm,GameContent* Content);
            virtual void run();
        private:
            Worm* ControlledWorm;
            GameContent* ContentOfGame;
        };
    }
}


#endif //CERVISEMESTRALKA_BFSAI_H
