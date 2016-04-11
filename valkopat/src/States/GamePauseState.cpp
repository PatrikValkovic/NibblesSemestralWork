#include "GamePauseState.h"

GameState::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

AbstractGameState* GameState::GamePauseState::run()
{
    return this->GameState;
}






