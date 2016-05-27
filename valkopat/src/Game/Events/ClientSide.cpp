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









