#include "NetworkCommunication.h"

void Game::NetworkCommunication::SendHeader(int Socket, Game::ServerActions Header)
{
    send(Socket,&Header,sizeof(Game::ServerActions),0);
}

ServerActions Game::NetworkCommunication::RecvHeader(int Socket)
{
    using namespace std;
    ServerActions Recived;
    recv(Socket,&Recived,sizeof(ServerActions),0);
    return Recived;
}

void Game::NetworkCommunication::SendHello(int Socket)
{
    SendHeader(Socket,ServerActions::Hello);
}

void Game::NetworkCommunication::RecvHello(int Socket)
{
    if(RecvHeader(Socket)!=ServerActions::Hello)
        throw new Exceptions::ServerException("Invalid header",__LINE__,__FILE__);
}

void Game::NetworkCommunication::SendMapRequest(int Socket, string Name, size_t Hash)
{
    size_t MapSize = Name.size();

    SendHeader(Socket,ServerActions::RequiredMap);
    send(Socket,&MapSize,sizeof(size_t),0);
    send(Socket,Name.data(),MapSize,0);
    send(Socket,&Hash,sizeof(size_t),0);
}

void Game::NetworkCommunication::RecvMapRequest(int Socket, string& Name, size_t& Hash)
{
    if(RecvHeader(Socket)!=ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header",__LINE__,__FILE__);

    size_t SizeOfMap;
    recv(Socket,&SizeOfMap,sizeof(size_t),0);

    char* Buffer = (char*)calloc(SizeOfMap+1,1);
    recv(Socket,Buffer,SizeOfMap,0);

    recv(Socket,&Hash,sizeof(size_t),0);
}











