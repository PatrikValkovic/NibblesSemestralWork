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
            ;//TODOthis->SendInfoAboutKeyStroke(Act);

    return Continue;
}

Game::Event::ClientSide::~ClientSide()
{
    close(SocketId);
}


















