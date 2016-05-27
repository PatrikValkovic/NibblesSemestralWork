#include "ClientSide.h"

Game::Event::ClientSide::ClientSide(int SockedId)
    : SocketId(SockedId)
{}

bool Game::Event::ClientSide::HasActions()
{
    //TODO
    return false;
}

bool Game::Event::ClientSide::ProccessActions()
{
    //TODO
}

bool Game::Event::ClientSide::SendHello()
{
    ServerActions ActionToSend = ServerActions::Hello;
    send(SocketId,&ActionToSend,sizeof(ServerActions),0);
    recv(SocketId,&ActionToSend,sizeof(ServerActions),0);
    return ActionToSend==ServerActions::Hello;
}

Game::Event::ClientSide::~ClientSide()
{
    close(SocketId);
}


std::pair<std::string,int> Game::Event::ClientSide::LevelInfo()
{
    using namespace std;

    ServerActions RecivedAction;
    recv(SocketId,&RecivedAction,sizeof(ServerActions),0);
    if(RecivedAction!=ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header of packet",__LINE__,__FILE__);

    pair<string,int> Data;
    int Length;
    recv(SocketId,&Length,sizeof(int),0);
    char* NameOfLevel = new char[Length];
    recv(SocketId,NameOfLevel,(size_t)Length,0);
    Data.first.insert(0,NameOfLevel,(size_t)Length);

    recv(SocketId,&Length,sizeof(int),0);
    Data.second = Length;

    delete [] NameOfLevel;
    return Data;
}











