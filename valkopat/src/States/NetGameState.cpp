#include "NetGameState.h"

GameStates::AbstractGameState* GameStates::NetGameState::run()
{
    using ViewModel::NetMenuConsoleViewModel;
    using Game::PlayGround;
    using Game::PlaygroundFactory;

    NetMenuConsoleViewModel* Rendering = (NetMenuConsoleViewModel*)this->RenderingModel->NetModel();

    if(Rendering->CreateNewServer())
    {
        string LevelName = Rendering->Level();
        PlayGround* NewPlayGround = PlaygroundFactory::GetLevel(LevelName);
        int CountOfPlayers = Rendering->CountOfPlayers(NewPlayGround->CountOfStartPositions());
        pair<string,string> ServerIPWithPort = Rendering->GetServerIPAndPort();
    }




    return NULL;
}

GameStates::NetGameState::NetGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::NetGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->PlayState = GameState;
    this->Menu = MenuState;
}





