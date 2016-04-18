#ifndef CERVISEMESTRALKA_GAMEABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_GAMEABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class GameAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        GameAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~GameAbstractViewModel()
        { }
    };
}

#endif //CERVISEMESTRALKA_GAMEABSTRACTVIEWMODEL_H
