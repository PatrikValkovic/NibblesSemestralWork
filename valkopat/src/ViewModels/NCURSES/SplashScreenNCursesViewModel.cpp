#ifdef USE_NCURSES
#include "SplashScreenNCursesViewModel.h"

void ViewModel::SplashScreenNCursesViewModel::ShowSplashScreen()
{

}

ViewModel::SplashScreenNCursesViewModel::SplashScreenNCursesViewModel(const Translate::TranslateEngine* Translation)
        : SplashPauseScreenAbstractViewModel(Translation)
{ }

int ViewModel::SplashScreenNCursesViewModel::ShowPauseWithMenu(std::map<int, string> MenuEntry)
{
    return 0;
}


#endif

