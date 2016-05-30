#include "ServerSide.h"

Game::Event::ServerSide::ServerSide(int ServerSock, int CountOfPlayers, Game::PlayGround* Ground)
        : ServerSock(ServerSock), CountOfPlayers(CountOfPlayers), Ground(Ground)
{ }

Game::Event::ServerSide::~ServerSide()
{
    using namespace std;
    for_each(Players.begin(),Players.end(),[](pair<int,Worm*> P){
        delete P.second;
    });
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
    using namespace Game;
    int ClientIndex = 0;
    while ((int) S->Players.size() < S->CountOfPlayers)
    {
        int NewPlayer;
        if ((NewPlayer = S->NewUserSocket()) == -1 || !NetworkCommunication::RecvHello(NewPlayer))
            continue;
        NetworkCommunication::SendHello(NewPlayer);
        S->SendInfoAboutMap(NewPlayer);
        S->ProccessUserMapRequest(NewPlayer);
        Worm* NewPlayerWorm = S->GetInfoAboutPlayer(NewPlayer, ClientIndex);
        S->SendStartPosition(NewPlayer,NewPlayerWorm);
        S->SendInfoAboutNewPlayer(NewPlayerWorm);
        S->SendInfoAboutConnectedPlayers(NewPlayer);
        S->Players.insert(pair<int,Worm*>(NewPlayer,NewPlayerWorm));
    }
    S->StartGame();

    while(S->StillPlay())
    {
        S->WaitMethod();
        map<Worm*, Actions> ActMap = S->GetActionsFromUsers();
        S->SendActions(ActMap);
        S->NextFrame();
    }

    delete S;
}

int Game::Event::ServerSide::NewUserSocket()
{
    struct sockaddr addr;
    socklen_t addrLen = sizeof(addr);
    int NewPlayer = accept(this->ServerSock, &addr, &addrLen);
    return NewPlayer;
}

void Game::Event::ServerSide::SendInfoAboutMap(int ClientSock)
{
    ServerActions ToSend = ServerActions::RequiredMap;
    send(ClientSock, &ToSend, sizeof(ServerActions), 0);
    int LengthOfName = (int) this->Ground->NameOfLevel.size();
    send(ClientSock, &LengthOfName, sizeof(int), 0);
    send(ClientSock, this->Ground->NameOfLevel.c_str(), this->Ground->NameOfLevel.size(), 0);
    std::hash<std::string> HashFn;
    size_t LengthOfFile = HashFn(PlaygroundFactory::GetLevelInString(this->Ground->NameOfLevel));
    send(ClientSock, &LengthOfFile, sizeof(size_t), 0);
}

void Game::Event::ServerSide::ProccessUserMapRequest(int ClientSock)
{
    ServerActions ToTransfer = ServerActions::MapTransfer;
    recv(ClientSock, &ToTransfer, sizeof(ServerActions), 0);
    if (ToTransfer != ServerActions::MapTransfer)
    {
        ToTransfer = ServerActions::InvalidRequest;
        send(ClientSock, &ToTransfer, sizeof(ServerActions), 0);
        throw new Exceptions::Exception("Invalid header", __LINE__, __FILE__);
    }

    bool HaveMap;
    recv(ClientSock, &HaveMap, sizeof(bool), 0);
    if (HaveMap)
        return;

    string Level = PlaygroundFactory::GetLevelInString(this->Ground->NameOfLevel);
    size_t CountOfCharacters = Level.size();
    send(ClientSock, &ToTransfer, sizeof(ServerActions), 0);
    send(ClientSock, &CountOfCharacters, sizeof(size_t), 0);
    send(ClientSock, Level.c_str(), CountOfCharacters, 0);
}

Game::Worm* Game::Event::ServerSide::GetInfoAboutPlayer(int SocketId, int IndexOfPlayer)
{
    ServerActions ToRecive;
    recv(SocketId, &ToRecive, sizeof(ServerActions), 0);
    if (ToRecive != ServerActions::NameTransfer)
    {
        ToRecive = ServerActions::InvalidRequest;
        send(SocketId, &ToRecive, sizeof(ServerActions), 0);
        throw new Exceptions::Exception("Invalid header", __LINE__, __FILE__);
    }


    size_t LengthOfname;
    recv(SocketId, &LengthOfname, sizeof(size_t), 0);
    char* Buffer = (char*) calloc(LengthOfname + 1, 1);
    recv(SocketId, Buffer, LengthOfname, 0);
    string NameOfPlayer(Buffer);
    free(Buffer);

    PlayGround::StartPosition StartingPosition = this->Ground->GetNextStartPosition();
    Worm* Created = new Worm(StartingPosition.Position.GetPositionX(),
                             StartingPosition.Position.GetPositionY(),
                             StartingPosition.Direction,
                             IndexOfPlayer);
    Created->SetName(NameOfPlayer);
    return Created;
}

void Game::Event::ServerSide::SendStartPosition(int ClientSock, Worm* AssignetWorm)
{
    ServerActions ToSend = ServerActions::PlayerTransfer;
    send(ClientSock,&ToSend,sizeof(ServerActions),0);

    int PositionX = AssignetWorm->GetSegment().at(0).GetPositionX();
    int PositionY = AssignetWorm->GetSegment().at(0).GetPositionY();
    Actions BeginDirection = AssignetWorm->GetMoveDirection();
    int IndexOfPlayer = AssignetWorm->GetId();
    send(ClientSock,&PositionX,sizeof(int),0);
    send(ClientSock,&PositionY,sizeof(int),0);
    send(ClientSock,&BeginDirection,sizeof(Actions),0);
    send(ClientSock,&IndexOfPlayer,sizeof(int),0);
}

void Game::Event::ServerSide::SendInfoAboutNewPlayer(Worm* Player)
{
    using namespace std;
    for_each(this->Players.begin(),this->Players.end(),[&Player](pair<int,Worm*> P){
        ServerActions ToSend = ServerActions::PlayerTransfer;
        size_t LengthOfName = Player->GetName().size();
        const char* Name = Player->GetName().c_str();
        int StartX = Player->GetSegment().at(0).GetPositionX();
        int StartY = Player->GetSegment().at(0).GetPositionY();;
        Actions StartDirection = Player->GetMoveDirection();
        int Index = Player->GetId();

        send(P.first,&ToSend,sizeof(ServerActions),0);
        send(P.first,&LengthOfName,sizeof(size_t),0);
        send(P.first,Name,LengthOfName,0);
        send(P.first,&StartX,sizeof(int),0);
        send(P.first,&StartY,sizeof(int),0);
        send(P.first,&StartDirection,sizeof(Actions),0);
        send(P.first,&Index,sizeof(int),0);
    });
}

void Game::Event::ServerSide::SendInfoAboutConnectedPlayers(int ClientSock)
{
    using namespace std;
    for_each(this->Players.begin(),this->Players.end(),[&ClientSock](pair<int,Worm*> P){
        ServerActions ToSend = ServerActions::PlayerTransfer;
        size_t LengthOfName = P.second->GetName().size();
        const char* Name = P.second->GetName().c_str();
        int StartX = P.second->GetSegment().at(0).GetPositionX();
        int StartY = P.second->GetSegment().at(0).GetPositionY();;
        Actions StartDirection = P.second->GetMoveDirection();
        int Index = P.second->GetId();

        send(ClientSock,&ToSend,sizeof(ServerActions),0);
        send(ClientSock,&LengthOfName,sizeof(size_t),0);
        send(ClientSock,Name,LengthOfName,0);
        send(ClientSock,&StartX,sizeof(int),0);
        send(ClientSock,&StartY,sizeof(int),0);
        send(ClientSock,&StartDirection,sizeof(Actions),0);
        send(ClientSock,&Index,sizeof(int),0);
    });
}

void Game::Event::ServerSide::StartGame()
{
    using namespace std;
    for_each(this->Players.begin(),this->Players.end(),[](pair<int,Worm*> P) {
        ServerActions ToSend = ServerActions::StartGame;
        send(P.first,&ToSend,sizeof(ServerActions),0);
    });
}

bool Game::Event::ServerSide::StillPlay()
{
    using namespace std;
    bool ToReturn = false;
    for_each(Players.begin(),Players.end(),[&ToReturn](pair<int,Worm*> X){
        if(X.second->IsPlaying())
            ToReturn = true;
    });
    return ToReturn;
}

void Game::Event::ServerSide::WaitMethod()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    time_point<system_clock> BeginOfMethod = system_clock::now();

    sleep_until(BeginOfMethod + milliseconds(this->WaitForMiliseconds));
}

map<Game::Worm*, Game::Actions> Game::Event::ServerSide::GetActionsFromUsers()
{
    using namespace std;
    map<Game::Worm*, Game::Actions> ToReturn;
    for_each(Players.begin(),Players.end(),[&ToReturn](pair<int,Worm*> P){
        ServerActions Recived;
        Actions Final;
        while(recv(P.first,&Recived,sizeof(Recived),MSG_DONTWAIT)!=-1 && Recived==ServerActions::KeyStroke)
            recv(P.first,&Final,sizeof(Actions),0);
        ToReturn.insert(pair<Worm*,Actions>(P.second,Final));
    });
    return ToReturn;
}

void Game::Event::ServerSide::NextFrame()
{
    using namespace std;
    for_each(Players.begin(),Players.end(),[](pair<int,Worm*> X){
        if(X.second->IsPlaying())
        {
            ServerActions ToSend = ServerActions::Wait;
            send(X.first,&ToSend,sizeof(ServerActions),0);
        }
    });
}

void Game::Event::ServerSide::SendActions(map<Worm*, Actions> ToSend)
{
    using namespace std;
    for_each(Players.begin(),Players.end(),[&ToSend](pair<int,Worm*> P){
        int SendSocket = P.first;
        for_each(ToSend.begin(),ToSend.end(),[&SendSocket](pair<Worm*,Actions> X){
            ServerActions SendingAction = ServerActions::ActionsSend;
            int IndexOfPlayer = X.first->GetId();
            send(SendSocket,&SendingAction,sizeof(ServerActions),0);
            send(SendSocket,&IndexOfPlayer,sizeof(int),0);
            send(SendSocket,&X.second,sizeof(Actions),0);
        });
    });
}





































