#include "SingleplayerGameState.h"

GameState::AbstractGameState* GameState::SingleplayerGameState::run()
{
    return NULL;
}

GameState::SingleplayerGameState::SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel,
                                                        PlayingState* GameState,
                                                        MenuGameState* MenuState)
        : AbstractGameState(RenderingModel),
          Play(GameState),
          Menu(MenuState)
{ }


