#ifdef USE_SDL
#include "SplashScreenSDLViewModel.h"

void ViewModel::SplashScreenSDLViewModel::ShowSplashScreen()
{

}

ViewModel::SplashScreenSDLViewModel::SplashScreenSDLViewModel(const Translate::TranslateEngine* Translation)
    : SplashPauseScreenAbstractViewModel(Translation)
{}

int ViewModel::SplashScreenSDLViewModel::ShowPauseWithMenu(std::map<int, string> MenuEntry)
{
    return 0;
}


#endif

