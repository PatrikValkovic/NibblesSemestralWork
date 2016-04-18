#ifndef CERVISEMESTRALKA_NETMENUABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class NetMenuAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        NetMenuAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~NetMenuAbstractViewModel()
        { }
    };
}
#endif //CERVISEMESTRALKA_NETMENUABSTRACTVIEWMODEL_H
