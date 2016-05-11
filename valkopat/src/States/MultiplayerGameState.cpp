#include "MultiplayerGameState.h"

GameStates::AbstractGameState* GameStates::MultiplayerGameState::run()
{
    //TODO
    return NULL;
}

GameStates::MultiplayerGameState::MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::MultiplayerGameState::AddStates(PlayingState* PlayState, MenuGameState* MenuState)
{
    this->PlayState = PlayState;
    this->Menu = MenuState;
}





