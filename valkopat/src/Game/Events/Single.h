#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
#include <map>
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
        };
    }
}


#endif //CERVISEMESTRALKA_SINGPLE_H
