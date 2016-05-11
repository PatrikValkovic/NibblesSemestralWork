#include "GamePauseState.h"

GameStates::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::GamePauseState::run()
{
    return this->GameState;
}

void GameStates::GamePauseState::AddStates(PlayingState* StateOfGame, MenuGameState* MenuState)
{
    this->Menu = MenuState;
    this->GameState = StateOfGame;
}








