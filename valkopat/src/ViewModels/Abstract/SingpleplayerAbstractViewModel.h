#ifndef CERVISEMESTRALKA_SINGPLEPLAYERABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class SingleplayerMenuAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        SingleplayerMenuAbstractViewModel(Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~SingleplayerMenuAbstractViewModel()
        { }
    };
}

#endif //CERVISEMESTRALKA_SINGPLEPLAYERABSTRACTVIEWMODEL_H
