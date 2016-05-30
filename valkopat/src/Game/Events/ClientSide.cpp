#include "ClientSide.h"

Game::Event::ClientSide::ClientSide(int SockedId,ViewModel::AbstractInput* Input)
    : SocketId(SockedId), InputFromUser(Input)
{}

bool Game::Event::ClientSide::HasActions()
{
    return true;
}

bool Game::Event::ClientSide::ProccessActions()
{
    Keys Key;
    bool Continue = true;
    int PlayerI;
    Actions Act;

    Settings* SettingInstance = Settings::GetInstance();

    while ((Key = this->InputFromUser->GetNextStroke()) != Keys::NONE)
        if(SettingInstance->GetAction(Key,PlayerI,Act))
            this->SendInfoAboutKeyStroke(Act);

    return Continue;
}

Game::Event::ClientSide::~ClientSide()
{
    close(SocketId);
}


std::pair<std::string,size_t> Game::Event::ClientSide::LevelInfo()
{
    using namespace std;

    ServerActions RecivedAction;
    recv(SocketId,&RecivedAction,sizeof(ServerActions),0);
    if(RecivedAction!=ServerActions::RequiredMap)
        throw new Exceptions::ServerException("Invalid header of packet",__LINE__,__FILE__);

    pair<string,size_t> Data;
    int Length;
    recv(SocketId,&Length,sizeof(int),0);
    char* NameOfLevel = new char[Length];
    recv(SocketId,NameOfLevel,(size_t)Length,0);
    Data.first.insert(0,NameOfLevel,(size_t)Length);

    size_t HashOfMap;
    recv(SocketId,&HashOfMap,sizeof(size_t),0);
    Data.second = HashOfMap;

    delete [] NameOfLevel;
    return Data;
}

Game::Worm* Game::Event::ClientSide::AskToWorm(string NameOfPlayer)
{
    using Game::Worm;
    using Game::Actions;
    //send info
    ServerActions ToSend = ServerActions::NameTransfer;
    send(SocketId,&ToSend,sizeof(ServerActions),0);
    size_t SizeOfname = NameOfPlayer.size();
    send(SocketId,&SizeOfname,sizeof(size_t),0);
    send(SocketId,NameOfPlayer.data(),SizeOfname,0);

    //wait to position
    ToSend = ServerActions::PlayerTransfer;
    recv(SocketId,&ToSend,sizeof(ServerActions),0);
    if(ToSend!=ServerActions::PlayerTransfer)
        throw new Exceptions::ServerException("Invalid header of packet",__LINE__,__FILE__);

    int PositionX;
    int PositionY;
    Actions BeginDirection;
    int PlayerId;
    recv(SocketId,&PositionX,sizeof(int),0);
    recv(SocketId,&PositionY,sizeof(int),0);
    recv(SocketId,&BeginDirection,sizeof(Actions),0);
    recv(SocketId,&PlayerId,sizeof(int),0);

    Worm* PlayerWorm = new Worm(PositionX,PositionY,BeginDirection,PlayerId);
    PlayerWorm->SetName(NameOfPlayer);

    return PlayerWorm;
}

Game::Worm* Game::Event::ClientSide::PlayerConnected()
{
    ServerActions Receive;
    recv(SocketId,&Receive,sizeof(ServerActions),0);
    if(Receive==ServerActions::StartGame)
        return NULL;
    if(Receive!=ServerActions::PlayerTransfer)
        throw new Exceptions::ServerException("Invalid header of packet",__LINE__,__FILE__);

    size_t LengthOfName;
    recv(SocketId,&LengthOfName,sizeof(size_t),0);
    char* Name = (char*)calloc(LengthOfName+1,1);
    recv(SocketId,Name,LengthOfName,0);
    string NameOfPlayer(Name);
    free(Name);

    int StartX;
    int StartY;
    Actions StartDirection;
    int Index;
    recv(SocketId,&StartX,sizeof(int),0);
    recv(SocketId,&StartY,sizeof(int),0);
    recv(SocketId,&StartDirection,sizeof(Actions),0);
    recv(SocketId,&Index,sizeof(int),0);

    Worm* Created = new Worm(StartX,StartY,StartDirection,Index);
    Created->SetName(NameOfPlayer);

    return Created;
}

void Game::Event::ClientSide::SendInfoAboutKeyStroke(Actions Action)
{
    ServerActions ToSend = ServerActions::KeyStroke;
    send(SocketId,&ToSend,sizeof(Action),0);
    send(SocketId,&Action,sizeof(Actions),0);
}



















