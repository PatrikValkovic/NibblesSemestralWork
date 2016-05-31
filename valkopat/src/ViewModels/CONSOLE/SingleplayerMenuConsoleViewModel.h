#ifndef CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <climits>
#include <iostream>
#include <algorithm>
#include "../Abstract/SingleplayerMenuAbstractViewModel.h"
#include "../../Game/PlaygroundFactory.h"

namespace ViewModel
{
    class SingleplayerMenuConsoleViewModel : public SingleplayerMenuAbstractViewModel
    {
    public:
        SingleplayerMenuConsoleViewModel(const Translate::TranslateEngine* Translate);

        virtual std::string NameOfPlayer();
        virtual int CountOfAI(int Max);
        virtual string Level();
        virtual string LevelOfAI(std::vector<string> MenuEntries);
    };
}
#endif
#endif //CERVISEMESTRALKA_SINGPLEPLAYERMENUCONSOLEVIEWMODEL_H
