#ifndef CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <algorithm>
#include <iostream>
#include "../Abstract/SplashPauseScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashPauseScreenConsoleViewModel : public SplashPauseScreenAbstractViewModel
    {
    public:
        SplashPauseScreenConsoleViewModel(const Translate::TranslateEngine* Translate);
        virtual void ShowSplashScreen();

        virtual int ShowPauseWithMenu(std::map<int,string> MenuEntry);
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
