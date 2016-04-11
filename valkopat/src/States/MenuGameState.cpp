#include "MenuGameState.h"

GameState::MenuGameState::MenuGameState(ViewModel::BaseViewModel* RenderingModel,
                                        MultiplayerGameState* Multi,
                                        SingleplayerGameState* Single,
                                        NetGameState* OverNet,
                                        EndState* EndingState,
                                        ChangeLanguageState* LanguageChangingState)
        : AbstractGameState(RenderingModel),
          Single(Single),
          Multi(Multi),
          Net(OverNet),
          Language(LanguageChangingState),
          End(EndingState)
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



