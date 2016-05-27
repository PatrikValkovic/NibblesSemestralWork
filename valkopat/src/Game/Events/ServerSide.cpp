#include "ServerSide.h"

Game::Event::ServerSide::ServerSide(int ServerSock, int CountOfPlayers, Game::PlayGround* Ground)
        : ServerSock(ServerSock), CountOfPlayers(CountOfPlayers), Ground(Ground)
{ }

Game::Event::ServerSide::~ServerSide()
{
    delete Ground;
}

void Game::Event::ServerSide::StartServer()
{
    std::thread Server(ServerSide::ThreadRun, this);
    Server.detach();
}

void Game::Event::ServerSide::ThreadRun(ServerSide* S)
{
    using namespace std;
    vector<int> SocketOfPlayers;
    while ((int) SocketOfPlayers.size() < 4)
    {
        int NewPlayer;
        if ((NewPlayer = S->NewUserSocket()) == -1)
            continue;
    }
}

int Game::Event::ServerSide::NewUserSocket()
{
    struct sockaddr addr;
    socklen_t addrLen = sizeof(addr);
    int NewPlayer = accept(this->ServerSock, &addr, &addrLen);

    ServerActions ActionToSend;
    recv(NewPlayer, &ActionToSend, sizeof(ServerActions), 0);
    if (ActionToSend != ServerActions::Hello)
    {
        ActionToSend = ServerActions::InvalidRequest;
        send(NewPlayer,&ActionToSend,sizeof(ServerActions),0);
        return -1;
    }

    send(NewPlayer,&ActionToSend,sizeof(ServerActions),0);
    return NewPlayer;
}











