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
    return true;
}

Game::Event::ClientSide::~ClientSide()
{
    close(SocketId);
}









