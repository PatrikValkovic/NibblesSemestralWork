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



















