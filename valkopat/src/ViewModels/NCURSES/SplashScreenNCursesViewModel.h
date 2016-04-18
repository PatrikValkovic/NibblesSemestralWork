#ifndef CERVISEMESTRALKA_SPLASHSCREENNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/SplashScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenNCursesViewModel : public SplashScreenAbstractViewModel
    {
    public:
        SplashScreenNCursesViewModel(const Translate::TranslateEngine* Translation);
        virtual void ShowSplashScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENNCURSESVIEWMODEL_H
