#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
#include <iostream>
#include <map>
#include <termios.h>
#include <sys/ioctl.h>
#include "AbstractEvent.h"
#include "../Worm.h"

namespace Game
{
    namespace Event
    {
        class Single : public Abstract
        {
        public:
            Single(Worm* Player);

            virtual bool HasActions();

            virtual bool ProccessActions();

        private:
            Worm* Player;
            char Buffer;
            void BackMode(termios old);
            termios SetMode();
            int kbhit();
        };
    }
}


#endif //CERVISEMESTRALKA_SINGPLE_H
