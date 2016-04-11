#include "GamePauseState.h"

GameState::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel,
                                          GameState::PlayingState* StateOfGame)
        : AbstractGameState(RenderingModel),
          GameState(StateOfGame)
{ }

AbstractGameState* GameState::GamePauseState::run()
{
    return this->GameState;
}



