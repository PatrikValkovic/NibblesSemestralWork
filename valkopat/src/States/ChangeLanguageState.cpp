#include "ChangeLanguageState.h"

GameState::ChangeLanguageState::ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel,
                                                    MenuGameState* MenuState)
        : AbstractGameState(RenderingModel),
          Menu(MenuState)
{ }

GameState::AbstractGameState* GameState::ChangeLanguageState::run()
{
    //TODO
    return NULL;
}



