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

        virtual int ShowPauseWithMenu(std::map<int,string> MenuEntry);
    };
}

#endif
#endif //CERVISEMESTRALKA_SPLASHSCREENSDLVIEWMODEL_H
