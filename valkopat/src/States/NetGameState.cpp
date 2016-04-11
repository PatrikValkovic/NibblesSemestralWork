#include "NetGameState.h"

GameState::AbstractGameState* GameState::NetGameState::run()
{
    return nullptr;
}

GameState::NetGameState::NetGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }



