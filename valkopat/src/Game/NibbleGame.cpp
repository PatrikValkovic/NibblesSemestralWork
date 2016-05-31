#include "NibbleGame.h"

Game::NibbleGame::NibbleGame(ViewModel::BaseViewModel* RenderingEngine)
        : RenderEngine(RenderingEngine)
{ }

void Game::NibbleGame::run()
{
    using namespace GameStates;
    AbstractGameState* ActualState = this->States->GetFirstState();
    while(ActualState!=nullptr)
        ActualState = ActualState->run();
}

void Game::NibbleGame::init()
{
    this->States = new GameStates::GameStates(this->RenderEngine);
}

Game::NibbleGame::~NibbleGame()
{
    delete this->States;
}







