#ifndef CERVISEMESTRALKA_CLIENTSIDE_H
#define CERVISEMESTRALKA_CLIENTSIDE_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "../Enums.h"
#include "AbstractEvent.h"

namespace Game
{
    namespace Event
    {
        class ClientSide : public Abstract
        {
        public:
            ClientSide(int SocketId);
            virtual ~ClientSide();

            virtual bool HasActions();

            virtual bool ProccessActions();

            bool SendHello();

        private:
            int SocketId;
        };
    }
}

#endif //CERVISEMESTRALKA_CLIENTSIDE_H
