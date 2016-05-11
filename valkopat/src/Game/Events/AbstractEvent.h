#ifndef CERVISEMESTRALKA_ABSTRACTEVENT_H
#define CERVISEMESTRALKA_ABSTRACTEVENT_H
#include <vector>

namespace Game
{
    namespace Event
    {
        class Abstract
        {
        public:
            virtual ~Abstract(){}

            virtual bool HasActions() = 0;

            virtual void ProccessActions() = 0;
        };
    }
}
#endif //CERVISEMESTRALKA_ABSTRACTEVENT_H
