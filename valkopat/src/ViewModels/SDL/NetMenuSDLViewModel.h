#ifndef CERVISEMESTRALKA_NETMENUSDLVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/NetMenuAbstractViewModel.h"

namespace ViewModel
{
    class NetMenuSDLViewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuSDLViewModel(const Translate::TranslateEngine* Translation);
    };
}

#endif
#endif //CERVISEMESTRALKA_NETMENUSDLVIEWMODEL_H
