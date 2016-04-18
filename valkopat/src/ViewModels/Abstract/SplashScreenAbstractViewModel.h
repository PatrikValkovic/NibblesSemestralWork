#ifndef CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class SplashScreenAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        SplashScreenAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~SplashScreenAbstractViewModel()
        { }

        virtual void ShowSplashScreen() = 0;
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
