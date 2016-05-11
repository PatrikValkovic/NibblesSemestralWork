#include "PlayingState.h"

GameStates::AbstractGameState* GameStates::PlayingState::run()
{
    //TODO
    return NULL;
}

GameStates::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::PlayingState::AddStates(MenuGameState* MenuState, GamePauseState* PauseState)
{
    this->Menu = MenuState;
    this->Pause = PauseState;
}

void GameStates::PlayingState::ClearContent(Game::GameContent* NewContent)
{
    delete ContentOfGame;
    ContentOfGame = NewContent;
}

GameStates::PlayingState::~PlayingState()
{
    delete ContentOfGame;
}









