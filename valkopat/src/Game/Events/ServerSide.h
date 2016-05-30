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
#include "../NetworkCommunication.h"

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
            const int WaitForMiliseconds = 1400;
            map<int ,Worm*> Players;
            int ServerSock;
            int CountOfPlayers;
            PlayGround* Ground;
            static void ThreadRun(ServerSide* S);
            int NewUserSocket();

            void ResolveMap(int ClientSock);
            Worm* CreateWorm(int SocketId,int IndexOfPlayer);
            void SendInfoAboutConnectedPlayers(int ClientSock);
            void StartGame();
            bool StillPlay();
            void WaitMethod();
            map<Worm*,Actions> GetActionsFromUsers();
            void SendActions(map<Worm*,Actions> ToSend);
            void NextFrame();
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERSIDE_H
