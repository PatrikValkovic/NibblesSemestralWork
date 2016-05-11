#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
#include <iostream>
#include "AbstractEvent.h"

namespace Game
{
    namespace Event
    {
        class Single : public Abstract
        {
        public:
            Single();

            virtual bool HasActions();

            virtual void ProccessActions();
        };
    }
}


#endif //CERVISEMESTRALKA_SINGPLE_H
