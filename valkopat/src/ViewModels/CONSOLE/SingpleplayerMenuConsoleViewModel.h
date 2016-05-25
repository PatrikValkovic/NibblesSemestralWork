#ifndef CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>
#include <algorithm>
#include "../Abstract/SingpleplayerAbstractViewModel.h"
#include "../../Game/PlaygroundFactory.h"

namespace ViewModel
{
    class SingpleplayerMenuConsoleViewModel : public SingleplayerMenuAbstractViewModel
    {
    public:
        SingpleplayerMenuConsoleViewModel(const Translate::TranslateEngine* Translate);

        virtual std::string NameOfPlayer();
        virtual int CountOfAI(int Max);
        virtual string Level();
        virtual int LevelOfAI(std::map<int, string> MenuEntries);
    };
}
#endif
#endif //CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
