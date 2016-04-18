#ifndef CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>
#include "../Abstract/SplashScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenConsoleViewModel : public SplashScreenAbstractViewModel
    {
    public:
        SplashScreenConsoleViewModel(Translate::TranslateEngine* Translate);
        virtual void ShowSplashScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
