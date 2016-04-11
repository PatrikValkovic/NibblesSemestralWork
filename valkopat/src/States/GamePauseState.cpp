#include "GamePauseState.h"

GameState::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameState::AbstractGameState* GameState::GamePauseState::run()
{
    return this->GameState;
}

void GameState::GamePauseState::AddStates(PlayingState* StateOfGame, MenuGameState* MenuState)
{
    this->Menu = MenuState;
    this->GameState = StateOfGame;
}








