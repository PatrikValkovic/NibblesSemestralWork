#include "PlayingState.h"

GameState::AbstractGameState* GameState::PlayingState::run()
{
    //TODO
    return nullptr;
}

GameState::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }



