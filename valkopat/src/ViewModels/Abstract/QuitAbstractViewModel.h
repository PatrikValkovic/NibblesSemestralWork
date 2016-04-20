#ifndef CERVISEMESTRALKA_QUITABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_QUITABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class QuitAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        QuitAbstractViewModel(Translate::TranslateEngine* Translation)
                : ViewModelAbstractClass(Translation)
        { }

        virtual void ShowEndScreen() = 0;

        virtual ~QuitAbstractViewModel()
        { }
    };
}

#endif //CERVISEMESTRALKA_QUITABSTRACTVIEWMODEL_H
