#ifndef CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/NetMenuAbstractViewModel.h"

namespace ViewModel
{
    class NetMenuConsoleViewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuConsoleViewModel(const Translate::TranslateEngine* Translate);
    };
}

#endif
#endif //CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
