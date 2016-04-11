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

void GameState::MenuGameState::AddStates(MultiplayerGameState* Multi, SingleplayerGameState* Single,
                                         NetGameState* OverNet, EndState* End, ChangeLanguageState* Language)
{
    this->Multi = Multi;
    this->Single = Single;
    this->Net = OverNet;
    this->End = End;
    this->Language = Language;
}





