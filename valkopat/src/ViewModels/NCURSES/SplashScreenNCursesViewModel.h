#ifndef CERVISEMESTRALKA_SPLASHSCREENNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/SplashPauseScreenAbstractViewModel.h"

namespace ViewModel
{
    class SplashScreenNCursesViewModel : public SplashPauseScreenAbstractViewModel
    {
    public:
        SplashScreenNCursesViewModel(const Translate::TranslateEngine* Translation);

        virtual void ShowSplashScreen();

        virtual int ShowPauseWithMenu(std::map<int,string> MenuEntry);

        virtual void ShowFinalScore(std::vector<Game::Worm*> Worms);
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENNCURSESVIEWMODEL_H
