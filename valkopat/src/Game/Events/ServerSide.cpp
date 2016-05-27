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
        S->SendInfoAboutMap(NewPlayer);
        S->ProccessUserMapRequest(NewPlayer);
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

void Game::Event::ServerSide::SendInfoAboutMap(int ClientSock)
{
    ServerActions ToSend = ServerActions::RequiredMap;
    send(ClientSock,&ToSend,sizeof(ServerActions),0);
    int LengthOfName = (int)this->Ground->NameOfLevel.size();
    send(ClientSock,&LengthOfName,sizeof(int),0);
    send(ClientSock, this->Ground->NameOfLevel.c_str(), this->Ground->NameOfLevel.size(), 0);
    std::hash<std::string> HashFn;
    size_t LengthOfFile = HashFn(PlaygroundFactory::GetLevelInString(this->Ground->NameOfLevel));
    send(ClientSock,&LengthOfFile,sizeof(size_t),0);
}

void Game::Event::ServerSide::ProccessUserMapRequest(int ClientSock)
{
    ServerActions ToTransfer = ServerActions::MapTransfer;
    recv(ClientSock,&ToTransfer,sizeof(ServerActions),0);
    if(ToTransfer!=ServerActions::MapTransfer)
    {
        ToTransfer = ServerActions::InvalidRequest;
        send(ClientSock,&ToTransfer,sizeof(ServerActions),0);
        throw new Exceptions::Exception("Invalid header",__LINE__,__FILE__);
    }

    bool HaveMap;
    recv(ClientSock,&HaveMap,sizeof(bool),0);
    if(HaveMap)
        return;

    string Level = PlaygroundFactory::GetLevelInString(this->Ground->NameOfLevel);
    size_t CountOfCharacters = Level.size();
    send(ClientSock,&ToTransfer,sizeof(ServerActions),0);
    send(ClientSock,&CountOfCharacters,sizeof(size_t),0);
    send(ClientSock,Level.c_str(),CountOfCharacters,0);
}

















