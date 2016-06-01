#ifndef CERVISEMESTRALKA_CLIENTSIDE_H
#define CERVISEMESTRALKA_CLIENTSIDE_H
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "AbstractEvent.h"
#include "../../Exceptions/ServerException.h"
#include "../../ViewModels/Abstract/AbstractInput.h"
#include "../Enums.h"
#include "../Settings.h"
#include "../Worm.h"
#include "../NetworkCommunication.h"


namespace Game
{
    namespace Event
    {
        class ClientSide : public Abstract
        {
        public:
            /**
             * Create new instance of ClientSide event
             * @param SockedId Socket of client
             * @param Input Specific input for rendering submodule
             * @return new instance of ClientSide event
             */
            ClientSide(int SocketId,ViewModel::AbstractInput* Input);

            /**
             * Destructor, close client side socket
             */
            virtual ~ClientSide();

            /**
             * Always return true
             * @return True
             */
            virtual bool HasActions();

            /**
             * Get inputs from ViewModel::AbstractInput class and send them to server
             * @return Always true
             */
            virtual bool ProccessActions();

        private:
            /**
             * Client socket
             */
            int SocketId;

            /**
             * Rendering submodule specific input
             */
            ViewModel::AbstractInput* InputFromUser;
        };
    }
}

#endif //CERVISEMESTRALKA_CLIENTSIDE_H
