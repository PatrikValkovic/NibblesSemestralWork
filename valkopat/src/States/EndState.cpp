#include <iostream>
#include "EndState.h"


GameState::EndState::EndState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameState::AbstractGameState* GameState::EndState::run()
{
    this->RenderingModel->QuitModel()->ShowEndScreen();
    return NULL;
}

void GameState::EndState::AddStates()
{ }





