#include <iostream>
#include "ViewModels/ViewModelChooser.h"
#include "Game/NibbleGame.h"



int main()
{
    using namespace ViewModel;
    ViewModelChooser Chooser;
    BaseViewModel* RenderEngine = Chooser.ChooseViewModel();
    RenderEngine->init();

    Game::NibbleGame* game = new Game::NibbleGame(RenderEngine);
    game->init();
    game->run();

    delete game;
    delete RenderEngine;

    return 0;
}