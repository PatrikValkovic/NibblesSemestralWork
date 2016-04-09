#include "GameStates.h"

GameState::GameStates::GameStates()
{
    SplashScreenGameState* SplashScreen = new SplashScreenGameState;


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

AbstractGameState* GameState::GameStates::GetFirstState() const
{
    return this->First;
}





