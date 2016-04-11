#include "PlayingState.h"

GameState::AbstractGameState* GameState::PlayingState::run()
{
    //TODO
    return NULL;
}

GameState::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel,
                                      GameState::MenuGameState* MenuState,
                                      GameState::GamePauseState* PauseState)
        : AbstractGameState(RenderingModel),
          Menu(MenuState),
          Pause(PauseStates)
{ }



