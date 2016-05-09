#ifndef CERVISEMESTRALKA_SINGPLE_H
#define CERVISEMESTRALKA_SINGPLE_H
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

            virtual std::vector<Action> GetActions();
        };
    }
}


#endif //CERVISEMESTRALKA_SINGPLE_H
