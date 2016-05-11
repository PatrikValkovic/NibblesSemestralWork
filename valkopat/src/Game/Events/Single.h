#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
#include <iostream>
#include <map>
#include "AbstractEvent.h"
#include "../Worm.h"
#include <unistd.h>
#include <termios.h>


namespace Game
{
    namespace Event
    {
        class Single : public Abstract
        {
        public:
            Single(Worm* Player);

            virtual bool HasActions();

            virtual void ProccessActions();

        private:
            Worm* Player;
            char Buffer;
            char MyGetCh();
        };
    }
}


#endif //CERVISEMESTRALKA_SINGPLE_H
