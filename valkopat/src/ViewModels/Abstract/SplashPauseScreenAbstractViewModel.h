#ifndef CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#include <string>
#include <map>
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class SplashPauseScreenAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        SplashPauseScreenAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~SplashPauseScreenAbstractViewModel()
        { }

        virtual void ShowSplashScreen() = 0;

        virtual int ShowPauseWithMenu(std::map<int,string> MenuEntry) = 0;
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
