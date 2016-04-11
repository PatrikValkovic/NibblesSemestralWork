#include "ChangeLanguageState.h"

GameState::ChangeLanguageState::ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameState::AbstractGameState* GameState::ChangeLanguageState::run()
{
    //TODO
    return NULL;
}

void GameState::ChangeLanguageState::AddStates(MenuGameState* MenuState)
{
    this->Menu = MenuState;
}





