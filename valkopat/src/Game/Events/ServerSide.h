#ifndef CERVISEMESTRALKA_SERVERSIDE_H
#define CERVISEMESTRALKA_SERVERSIDE_H
#include <thread>
#include "AbstractEvent.h"
#include "../PlayGround.h"

//TODO remove
#include <iostream>

namespace Game
{
    namespace Event
    {
        class ServerSide
        {
        public:
            ServerSide(int ServerSock,int CountOfPlayers,PlayGround* Ground);
            ~ServerSide();
            void StartServer();
        private:
            int ServerSock;
            int CountOfPlayers;
            PlayGround* Ground;
            static void ThreadRun(ServerSide* S);
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERSIDE_H
