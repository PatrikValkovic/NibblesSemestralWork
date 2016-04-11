#include "GamePauseState.h"

GameState::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel,
                                          GameState::PlayingState* StateOfGame,
                                          GameState::MenuGameState* MenuState)
        : AbstractGameState(RenderingModel),
          GameState(StateOfGame),
          Menu(MenuState)
{ }

AbstractGameState* GameState::GamePauseState::run()
{
    return this->GameState;
}






