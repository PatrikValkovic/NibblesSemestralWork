#ifndef CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>
#include <algorithm>
#include "../Abstract/NetMenuAbstractViewModel.h"
#include "../../Game/PlaygroundFactory.h"


namespace ViewModel
{
    class NetMenuConsoleViewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuConsoleViewModel(const Translate::TranslateEngine* Translate);

        virtual string Level();
    };
}

#endif
#endif //CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
