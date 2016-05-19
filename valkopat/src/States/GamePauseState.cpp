#include "GamePauseState.h"

GameStates::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::GamePauseState::run()
{
    using std::map;
    using std::string;
    using std::pair;
    using ViewModel::SplashPauseScreenAbstractViewModel;
    SplashPauseScreenAbstractViewModel* ViewModel = this->RenderingModel->SplashPauseScreenModel();

    map<int,string> MenuEntries = {
            {0,"ReturnToGamePauseEntry"},
            {1,"ReturnToMenuPauseEntry"}
    };
    AbstractGameState* ArrayWithStates[2] = {this->GameState,this->Menu};

    int Returned = ViewModel->ShowPauseWithMenu(MenuEntries);

    return ArrayWithStates[Returned];
}

void GameStates::GamePauseState::AddStates(PlayingState* StateOfGame, MenuGameState* MenuState)
{
    this->Menu = MenuState;
    this->GameState = StateOfGame;
}








