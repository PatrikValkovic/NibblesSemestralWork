#include "MultiplayerGameState.h"

GameState::AbstractGameState* GameState::MultiplayerGameState::run()
{
    //TODO
    return NULL;
}

GameState::MultiplayerGameState::MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameState::MultiplayerGameState::AddStates(PlayingState* PlayState, MenuGameState* MenuState)
{
    this->PlayState = PlayState;
    this->Menu = MenuState;
}





