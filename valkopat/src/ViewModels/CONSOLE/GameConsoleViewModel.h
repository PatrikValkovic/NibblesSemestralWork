#ifndef CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/GameAbstractViewModel.h"

namespace ViewModel
{
    class GameConsoleViewModel : public GameAbstractViewModel
    {
    public:
        GameConsoleViewModel(const Translate::TranslateEngine* Translate);
    };
}

#endif
#endif //CERVISEMESTRALKA_GAMECONSOLEVIEWMODEL_H
