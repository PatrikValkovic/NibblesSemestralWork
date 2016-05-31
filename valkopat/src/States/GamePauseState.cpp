#include "GamePauseState.h"

GameStates::GamePauseState::GamePauseState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::GamePauseState::run()
{
    using namespace std;
    using ViewModel::SplashPauseScreenAbstractViewModel;

    SplashPauseScreenAbstractViewModel* ViewModel = this->RenderingModel->SplashPauseScreenModel();

    map<int, string> MenuEntries;
    if (this->GameState->Playing())
        MenuEntries.insert(pair < int, string > (0, "ReturnToGamePauseEntry"));
    else
        ViewModel->ShowFinalScore(this->GameState->GetWorms());

    MenuEntries.insert(pair < int, string > (1, "ReturnToMenuPauseEntry"));

    AbstractGameState* ArrayWithStates[2] = {this->GameState,this->Menu};

    int Returned = ViewModel->ShowPauseWithMenu(MenuEntries);

    return ArrayWithStates[Returned];
}

void GameStates::GamePauseState::AddStates(PlayingState* StateOfGame, MenuGameState* MenuState)
{
    this->Menu = MenuState;
    this->GameState = StateOfGame;
}








