#ifndef CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/GameAbstractViewModel.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../Game/Worm.h"
#include "../../Game/PlayGround.h"
#include "../../Game/Point.h"
#include "../../Game/GameContent.h"

namespace ViewModel
{
    class GameConsoleViewModel : public GameAbstractViewModel
    {
    public:
        GameConsoleViewModel(const Translate::TranslateEngine* Translate);

        void RenderGame(Game::GameContent* ContentToRender);
    };
}

#endif
#endif //CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
