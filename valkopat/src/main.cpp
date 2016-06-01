#include "Exceptions/Exception.h"
#include "Translation/TranslateEngine.h"
#include "ViewModels/ViewModelChooser.h"
#include "Game/NibbleGame.h"

/*! \mainpage Nibbles game
 * Nibbles game remake of Nibbles (https://en.wikipedia.org/wiki/Nibbles_%28video_game%29)\n
 * Author: Patrik Valkovič\n
 * Semestral work\n
 * Summer semester 2015/2016\n
 * Czech Technical University in Prague\n
 * Faculty of Information Technology\n
 */


/**
 * Entry point of application
 * @return 1 if error occurs, 0 otherwise
 */
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