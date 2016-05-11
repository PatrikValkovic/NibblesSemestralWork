#ifndef CERVISEMESTRALKA_CLIENTSIDE_H
#define CERVISEMESTRALKA_CLIENTSIDE_H
#include "AbstractEvent.h"

namespace Game
{
    namespace Event
    {
        class ClientSide : public Abstract
        {
        public:
            ClientSide();

            virtual bool HasActions();

            virtual bool ProccessActions();
        };
    }
}

#endif //CERVISEMESTRALKA_CLIENTSIDE_H
