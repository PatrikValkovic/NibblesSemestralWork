#include "ServerSide.h"

Game::Event::ServerSide::ServerSide(int ServerSock, int CountOfPlayers, Game::PlayGround* Ground)
        : ServerSock(ServerSock), CountOfPlayers(CountOfPlayers), Ground(Ground)
{ }

Game::Event::ServerSide::~ServerSide()
{
    using namespace std;
    for_each(Players.begin(), Players.end(), [](pair<int, Worm*> P) {
        delete P.second;
        close(P.first);
    });
    close(ServerSock);
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
        S->ResolveMap(NewPlayer);
        Worm* NewPlayerWorm = S->CreateWorm(NewPlayer, ClientIndex++);
        S->SendInfoAboutConnectedPlayers(NewPlayer);
        S->SendInfoThatPlayerWasConnected(NewPlayerWorm);
        S->Players.insert(pair<int, Worm*>(NewPlayer, NewPlayerWorm));
    }
    S->StartGame();

    while (S->StillPlay())
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


void Game::Event::ServerSide::SendInfoAboutConnectedPlayers(int ClientSock)
{
    using namespace std;
    using Game::NetworkCommunication;
    for_each(this->Players.begin(), this->Players.end(), [&ClientSock](pair<int, Worm*> P) {
        NetworkCommunication::SendPlayerConnected(ClientSock,
                                                  P.second->GetName(),
                                                  P.second->GetSegment().at(0).GetPositionX(),
                                                  P.second->GetSegment().at(0).GetPositionY(),
                                                  P.second->GetMoveDirection(),
                                                  P.second->GetId());
    });
}

void Game::Event::ServerSide::StartGame()
{
    using namespace std;
    using Game::NetworkCommunication;
    for_each(this->Players.begin(), this->Players.end(), [](pair<int, Worm*> P) {
        NetworkCommunication::SendStartGame(P.first);
    });
}

bool Game::Event::ServerSide::StillPlay()
{
    using namespace std;
    bool ToReturn = false;
    for_each(Players.begin(), Players.end(), [&ToReturn](pair<int, Worm*> X) {
        if (X.second->IsPlaying())
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

void Game::Event::ServerSide::NextFrame()
{
    using namespace std;
    using Game::NetworkCommunication;
    for_each(Players.begin(), Players.end(), [](pair<int, Worm*> X) {
        NetworkCommunication::SendEndOfWait(X.first);
    });
}

void Game::Event::ServerSide::SendActions(map<Worm*, Actions> ToSend)
{
    using namespace std;
    using Game::NetworkCommunication;
    for_each(Players.begin(), Players.end(), [&ToSend](pair<int, Worm*> P) {
        int SendSocket = P.first;
        for_each(ToSend.begin(), ToSend.end(), [&SendSocket](pair<Worm*, Actions> X) {
            NetworkCommunication::SendActionsOfPlayer(SendSocket,X.first->GetId(),X.second);
        });
        if(ToSend.find(P.second)!=ToSend.end() && ToSend.find(P.second)->second==Actions::Pause)
            P.second->StopPlaying();
    });
}

map<Game::Worm*, Game::Actions> Game::Event::ServerSide::GetActionsFromUsers()
{
    using namespace std;
    using namespace Game;

    map<Worm*, Actions> ToReturn;
    for_each(Players.begin(), Players.end(), [&ToReturn](pair<int, Worm*> P) {
        Actions RecivedAction;
        bool SetDirection = false;
        while(NetworkCommunication::TryRecvPlayerAction(P.first,RecivedAction))
            SetDirection = true;

        if(SetDirection)
            ToReturn.insert(pair<Worm*,Actions>(P.second,RecivedAction));
    });
    return ToReturn;
}

void Game::Event::ServerSide::ResolveMap(int ClientSock)
{
    using Game::NetworkCommunication;
    using Game::PlaygroundFactory;

    string ContentOfGame = PlaygroundFactory::GetLevelInString(this->Ground->NameOfLevel);
    std::hash<std::string> HashFn;
    size_t Hashed = HashFn(ContentOfGame);
    NetworkCommunication::SendMapRequest(ClientSock, this->Ground->NameOfLevel, Hashed);

    bool HaveMap;
    NetworkCommunication::RecvMapRequestAnswer(ClientSock, HaveMap);
    if (HaveMap)
        return;

    NetworkCommunication::SendMapTransfer(ClientSock, this->Ground->NameOfLevel, ContentOfGame);
}

Game::Worm* Game::Event::ServerSide::CreateWorm(int SocketId, int IndexOfPlayer)
{
    using Game::NetworkCommunication;
    using Game::PlayGround;

    string NameOfPlayer;
    NetworkCommunication::RecvName(SocketId, NameOfPlayer);
    PlayGround::StartPosition Starting = this->Ground->GetNextStartPosition();

    Worm* Created = new Worm(Starting.Position.GetPositionX(),
                             Starting.Position.GetPositionY(),
                             Starting.Direction,
                             IndexOfPlayer);
    Created->SetName(NameOfPlayer);

    NetworkCommunication::SendInitForPlayer(SocketId,
                                            Starting.Position.GetPositionX(),
                                            Starting.Position.GetPositionY(),
                                            Starting.Direction,
                                            IndexOfPlayer);
    return Created;
}

void Game::Event::ServerSide::SendInfoThatPlayerWasConnected(Game::Worm* ConnectedPlayer)
{
    using namespace std;
    using Game::NetworkCommunication;
    for_each(this->Players.begin(), this->Players.end(), [&ConnectedPlayer](pair<int, Worm*> P) {
        NetworkCommunication::SendPlayerConnected(P.first,
                                                  ConnectedPlayer->GetName(),
                                                  ConnectedPlayer->GetSegment().at(0).GetPositionX(),
                                                  ConnectedPlayer->GetSegment().at(0).GetPositionY(),
                                                  ConnectedPlayer->GetMoveDirection(),
                                                  ConnectedPlayer->GetId());
    });
}











































