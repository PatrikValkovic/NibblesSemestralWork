#ifndef CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <climits>
#include <algorithm>
#include <iostream>
#include "../Abstract/SplashPauseScreenAbstractViewModel.h"
#include "ConsoleInput.h"

namespace ViewModel
{
    class SplashPauseScreenConsoleViewModel : public SplashPauseScreenAbstractViewModel
    {
    public:
        SplashPauseScreenConsoleViewModel(const Translate::TranslateEngine* Translate);
        virtual void ShowSplashScreen();

        virtual int ShowPauseWithMenu(std::map<int,string> MenuEntry);

        virtual void ShowFinalScore(std::vector<Game::Worm*> Worms);
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENCONSOLEVIEWMODEL_H
