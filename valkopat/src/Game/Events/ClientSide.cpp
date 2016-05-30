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
    int PlayerIndex;
    Actions Act;

    Settings* SettingInstance = Settings::GetInstance();

    while ((Key = this->InputFromUser->GetNextStroke()) != Keys::NONE)
        if(SettingInstance->GetAction(Key,PlayerIndex,Act) && PlayerIndex==0)
            NetworkCommunication::SendPlayerAction(this->SocketId,Act);

    return true;
}

Game::Event::ClientSide::~ClientSide()
{
    close(SocketId);
}


















