#include "PlayingState.h"

GameState::AbstractGameState* GameState::PlayingState::run()
{
    //TODO
    return NULL;
}

GameState::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel,
                                      MenuGameState* MenuState)
        : AbstractGameState(RenderingModel),
          Menu(MenuState)
{ }



