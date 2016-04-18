#include <iostream>
#include "ViewModels/ViewModelChooser.h"
#include "Game/NibbleGame.h"
#include "Exceptions/Exception.h"
#include "Translation/TranslateEngine.h"

int main()
{
    try
    {
        using namespace ViewModel;
        ViewModelChooser Chooser;
        BaseViewModel* RenderEngine = Chooser.ChooseViewModel();
        Translate::TranslateEngine engine;
        engine.SetLanguage("asdf");
        RenderEngine->init();

        Game::NibbleGame* game = new Game::NibbleGame(RenderEngine);
        game->init();
        game->run();

        delete game;
        delete RenderEngine;

        return 0;
    }
    catch(Exceptions::Exception* e)
    {
        std::cout << e->ToString();
        delete e;
        return 1;
    }
}