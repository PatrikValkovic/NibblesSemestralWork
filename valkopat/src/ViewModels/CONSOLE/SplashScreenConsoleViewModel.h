#ifndef CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/SplashScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenNCursesViewModel : public SplashScreenAbstractViewModel
    {
    public:
        virtual void ShowSplashScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
