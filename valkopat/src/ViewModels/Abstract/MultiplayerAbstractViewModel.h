#ifndef CERVISEMESTRALKA_MULTIPLAYERABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_MULTIPLAYERABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class MultiplayerMenuAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        MultiplayerMenuAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~MultiplayerMenuAbstractViewModel()
        { }
    };
}

#endif //CERVISEMESTRALKA_MULTIPLAYERABSTRACTVIEWMODEL_H
