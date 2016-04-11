#include "MenuGameState.h"

GameState::MenuGameState::MenuGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameState::AbstractGameState* GameState::MenuGameState::run()
{
    using namespace ViewModel;
    MenuAbstractViewModel* MenuRendering = this->RenderingModel->MenuModel();
    std::vector<MenuAbstractViewModel::MenuEntry> MenuVector;
    MenuRendering->ShowMenu(MenuVector);
    //TODO
    return NULL;
}



