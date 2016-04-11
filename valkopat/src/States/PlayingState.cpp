#include "PlayingState.h"

GameState::AbstractGameState* GameState::PlayingState::run()
{
    //TODO
    return NULL;
}

GameState::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameState::PlayingState::AddStates(MenuGameState* MenuState, GamePauseState* PauseState)
{
    this->Menu = MenuState;
    this->Pause = PauseState;
}





