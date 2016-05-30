#ifndef CERVISEMESTRALKA_NETWORKCOMMUNICATION_H
#define CERVISEMESTRALKA_NETWORKCOMMUNICATION_H
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "Enums.h"
#include "../Exceptions/ServerException.h"

using namespace std;
namespace Game
{
    class NetworkCommunication
    {
    public:
        static void SendHello(int Socket);
        static void RecvHello(int Socket);

        static void SendMapRequest(int Socket, string Name, size_t Hash);
        static void RecvMapRequest(int Socket, string& Name, size_t& Hash);

        static void SendMapRequestAnswer(int Socket,bool Have);
        static void RecvMapRequestAnswer(int Socket,bool& Have);

        static void SendMapTransfer(int Socket,string Name,string Data);
        static void RecvMapTransfer(int Socket,string& Name,string& Data);

        static void SendName(int Socket,string Name);
        static void RecvName(int Socket,string& Name);

        static void SendInitForPlayer(int Socket,int PosX,int PosY,Actions Direction);
        static void RecvInitForPlayer(int Socket,int& PosX,int PosY,Actions& Direction);

        static void SendPlayerConnected(int Socket,string NameOfPlayer,int PosX,int PosY,Actions Direction);
        static void SendStartGame(int Socket);
        static bool TryRecvPlayerConnected(int Socket,string& NameOfPlayer,int& PosX,int& PosY,Actions& Direction);

        static void SendPlayerAction(int Socket,Actions Action);
        static bool TryRecvPlayerAction(int Socket,Actions& Action);

        static void SendActionsOfPlayer(int Socket,int IDOfPlayer,Actions Action);
        static void SendEndOfWait(int Socket);
        static bool TryRecvActionsOfPlayer(int Socket,int& IDOfPlayer,Actions& Action);
    private:
        static void SendHeader(int Socket, ServerActions Header);
        static ServerActions RecvHeader(int Socket);
    };
}


#endif //CERVISEMESTRALKA_NETWORKCOMMUNICATION_H
