#include "NetGameState.h"

GameState::AbstractGameState* GameState::NetGameState::run()
{
    //TODO
    return NULL;
}

GameState::NetGameState::NetGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameState::NetGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->PlayState = GameState;
    this->Menu = MenuState;
}





