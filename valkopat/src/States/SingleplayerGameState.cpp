#include "SingleplayerGameState.h"

GameState::AbstractGameState* GameState::SingleplayerGameState::run()
{
    return NULL;
}

GameState::SingleplayerGameState::SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameState::SingleplayerGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->Play = GameState;
    this->Menu = MenuState;
}




