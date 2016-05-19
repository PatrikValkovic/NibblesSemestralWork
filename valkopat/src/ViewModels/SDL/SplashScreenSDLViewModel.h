#ifndef CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/SplashPauseScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenSDLViewModel : public SplashPauseScreenAbstractViewModel
    {
    public:
        SplashScreenSDLViewModel(const Translate::TranslateEngine* Translation);
        virtual void ShowSplashScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
