#ifndef CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/GameAbstractViewModel.h"
#include <iostream>
#include <vector>
#include <algorithm>


namespace ViewModel
{
    class GameConsoleViewModel : public GameAbstractViewModel
    {
    public:
        GameConsoleViewModel(const Translate::TranslateEngine* Translate);

        virtual void RenderGame(Game::GameContent* ContentToRender);
    };
}

#endif
#endif //CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
