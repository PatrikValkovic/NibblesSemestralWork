#include "MultiplayerGameState.h"

GameState::AbstractGameState* GameState::MultiplayerGameState::run()
{
    //TODO
    return NULL;
}

GameState::MultiplayerGameState::MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel,
                                                      GameState::PlayingState* PlayingState,
                                                      GameState::MenuGameState* MenuState)
        : AbstractGameState(RenderingModel),
          PlayState(PlayingState),
          Menu(MenuState)
{ }



