#include <iostream>
#include <cstdio>
#include "Exceptions/Exception.h"
#include "Translation/TranslateEngine.h"
#include "ViewModels/ViewModelChooser.h"
#include "Game/NibbleGame.h"
#include "Game/AIFactory.h"
#include "Game/Settings.h"

int main()
{
    try
    {
        using namespace ViewModel;
        using namespace Game;
        ViewModelChooser* ChoosingOfViewModel = new ViewModelChooser();
        BaseViewModel* RenderEngine = ChoosingOfViewModel->ChooseViewModel();
        delete ChoosingOfViewModel;
        Translate::TranslateEngine* Translation = new Translate::TranslateEngine();
        RenderEngine->init(Translation);

        Game::NibbleGame* game = new Game::NibbleGame(RenderEngine);
        game->init();
        game->run();

        delete game;
        delete RenderEngine;
        delete Translation;

        return 0;
    }
    catch (Exceptions::Exception* e)
    {
        std::cout << e->ToString();
        delete e;
        return 1;
    }
}