#include "GameStates.h"

GameState::GameStates::GameStates(ViewModel::BaseViewModel* Model)
    :RenderingModel(Model)
{
    MenuGameState* MenuScreen = new MenuGameState(this->RenderingModel);
    SplashScreenGameState* SplashScreen = new SplashScreenGameState(this->RenderingModel,MenuScreen);

    this->AllStates.push_back(MenuScreen);
    this->AllStates.push_back(SplashScreen);
    this->First = SplashScreen;
}

GameState::GameStates::~GameStates()
{
    std::vector<AbstractGameState*>::iterator Moving = this->AllStates.begin();
    std::vector<AbstractGameState*>::iterator End = this->AllStates.end();
    for(;Moving!=End;Moving++)
        delete (*Moving);
}

GameState::AbstractGameState* GameState::GameStates::GetFirstState() const
{
    return this->First;
}





