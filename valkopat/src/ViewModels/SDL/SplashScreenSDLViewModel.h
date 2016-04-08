#ifndef CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/SplashScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenSDLViewModel : public SplashScreenAbstractViewModel
    {
    public:
        virtual void ShowSplashScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
