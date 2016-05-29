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
#include <map>
#include "AbstractEvent.h"
#include "../Worm.h"
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
            map<int ,Worm*> Players;
            int ServerSock;
            int CountOfPlayers;
            PlayGround* Ground;
            static void ThreadRun(ServerSide* S);
            int NewUserSocket();
            void SendInfoAboutMap(int ClientSock);
            void ProccessUserMapRequest(int ClientSock);
            Worm* GetInfoAboutPlayer(int SocketId,int IndexOfPlayer);
            void SendStartPosition(int ClientSock, Worm* AssignetWorm);
            void SendInfoAboutNewPlayer(Worm* Player);
            void SendInfoAboutConnectedPlayers(int ClientSock);
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERSIDE_H
