#include "NibbleGame.h"

Game::NibbleGame::NibbleGame(ViewModel::BaseViewModel* RenderingEngine)
        : RenderEngine(RenderingEngine)
{ }

void Game::NibbleGame::run()
{
    using namespace GameState;
    AbstractGameState* ActualState = this->States->GetFirstState();
    while(ActualState!=NULL)
        ActualState = ActualState->run();
}

void Game::NibbleGame::init()
{
    this->States = new GameState::GameStates();
}





