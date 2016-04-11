#include "NetGameState.h"

GameState::AbstractGameState* GameState::NetGameState::run()
{
    //TODO
    return NULL;
}

GameState::NetGameState::NetGameState(ViewModel::BaseViewModel* RenderingModel,
                                      GameState::PlayingState* GameState)
        : AbstractGameState(RenderingModel),
          PlayState(GameState)
{ }



