#ifndef CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/SplashScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenSDLViewModel : public SplashScreenAbstractViewModel
    {
    public:
        SplashScreenSDLViewModel(const Translate::TranslateEngine* Translation);
        virtual void ShowSplashScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
