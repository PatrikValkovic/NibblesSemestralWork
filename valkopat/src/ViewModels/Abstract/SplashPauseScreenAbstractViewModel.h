#ifndef CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#include <string>
#include <map>
#include <vector>
#include "ViewModelDerivatingClass.h"
#include "../../Game/Worm.h"

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

        virtual void ShowFinalScore(std::vector<Game::Worm*> Worms) = 0;
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
