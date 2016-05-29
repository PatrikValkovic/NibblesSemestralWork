#ifndef CERVISEMESTRALKA_SERVERLISTENER_H
#define CERVISEMESTRALKA_SERVERLISTENER_H
#include "BaseTask.h"

namespace Game
{
    namespace Task
    {
        class ServerListener : public BaseTask
        {
            virtual void run();
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERLISTENER_H
