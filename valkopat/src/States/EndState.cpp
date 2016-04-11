#include "EndState.h"


GameState::EndState::EndState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{

}

GameState::AbstractGameState* GameState::EndState::run()
{
    //TODO
    return NULL;
}

void GameState::EndState::AddStates()
{ }





