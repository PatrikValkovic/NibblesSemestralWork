#include "SingleplayerGameState.h"

GameState::AbstractGameState* GameState::SingleplayerGameState::run()
{
    return NULL;
}

GameState::SingleplayerGameState::SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }


