#ifndef CERVISEMESTRALKA_CLIENTSIDE_H
#define CERVISEMESTRALKA_CLIENTSIDE_H
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "../Enums.h"
#include "../../Exceptions/ServerException.h"
#include "../../ViewModels/Abstract/AbstractInput.h"
#include "../Settings.h"
#include "AbstractEvent.h"
#include "../Worm.h"


namespace Game
{
    namespace Event
    {
        class ClientSide : public Abstract
        {
        public:
            ClientSide(int SocketId,ViewModel::AbstractInput* Input);
            virtual ~ClientSide();

            virtual bool HasActions();

            virtual bool ProccessActions();

            std::pair<std::string,size_t> LevelInfo();

            Worm* AskToWorm(string NameOfPlayer);

            Worm* PlayerConnected();

            void SendInfoAboutKeyStroke(Actions Action);

        private:
            int SocketId;
            ViewModel::AbstractInput* InputFromUser;
        };
    }
}

#endif //CERVISEMESTRALKA_CLIENTSIDE_H
