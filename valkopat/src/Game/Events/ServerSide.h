#ifndef CERVISEMESTRALKA_SERVERSIDE_H
#define CERVISEMESTRALKA_SERVERSIDE_H
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <functional>
#include <cstring>
#include "AbstractEvent.h"
#include "../PlayGround.h"
#include "../PlaygroundFactory.h"

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
            int NewUserSocket();
            void SendInfoAboutMap(int ClientSock);
            void ProccessUserMapRequest(int ClientSock);
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERSIDE_H
