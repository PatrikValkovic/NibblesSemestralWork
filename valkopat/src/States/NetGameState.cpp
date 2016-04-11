#include "NetGameState.h"

GameState::AbstractGameState* GameState::NetGameState::run()
{
    //TODO
    return NULL;
}

GameState::NetGameState::NetGameState(ViewModel::BaseViewModel* RenderingModel,
                                      GameState::PlayingState* GameState,
                                      GameState::MenuGameState* MenuState)
        : AbstractGameState(RenderingModel),
          PlayState(GameState),
          Menu(MenuState)
{ }



