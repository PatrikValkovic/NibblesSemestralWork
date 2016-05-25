#ifndef CERVISEMESTRALKA_MULTIPLAYERCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_MULTIPLAYERCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>
#include <sstream>
#include "../Abstract/MultiplayerAbstractViewModel.h"
#include "../../Game/PlaygroundFactory.h"


namespace ViewModel
{
    class MultiplayerConsoleViewModel : public MultiplayerMenuAbstractViewModel
    {
    public:
        MultiplayerConsoleViewModel(const Translate::TranslateEngine* Translate);

        virtual string Level();
        virtual int CountOfPlayers(int Max);
        virtual string NameOfPlayer(int Index);
    };
}

#endif
#endif //CERVISEMESTRALKA_MULTIPLAYERCONSOLEVIEWMODEL_H
