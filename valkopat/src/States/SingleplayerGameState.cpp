#include "SingleplayerGameState.h"

GameState::AbstractGameState* GameState::SingleplayerGameState::run()
{

    using ViewModel::SingleplayerMenuAbstractViewModel;

    SingleplayerMenuAbstractViewModel* View = this->RenderingModel->SingleplayerModel();

    int CountOfPC = 0;
    string NameOfUser;

    return NULL;
}

GameState::SingleplayerGameState::SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameState::SingleplayerGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->Play = GameState;
    this->Menu = MenuState;
}




