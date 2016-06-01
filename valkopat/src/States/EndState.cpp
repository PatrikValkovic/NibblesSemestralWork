#include "EndState.h"


GameStates::EndState::EndState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::EndState::run()
{
    this->RenderingModel->QuitModel()->ShowEndScreen();
    return NULL;
}

void GameStates::EndState::AddStates()
{ }





