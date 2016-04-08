#ifndef CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>

#include "../Abstract/BaseViewModel.h"
#include "SplashScreenConsoleViewModel.h"
#include "MenuConsoleViewModel.h"
#include "LanguageConsoleViewModel.h"
#include "MultiplayerConsoleViewModel.h"
#include "NetMenuConsoleViewModel.h"
#include "SingpleplayerMenuConsoleViewModel.h"
#include "GameConsoleViewModel.h"
#include "ScoreConsoleViewModel.h"

namespace ViewModel
{
    class ConsoleViewModel : public BaseViewModel
    {
    public:
        virtual const char* GetNameofViewModel();
        virtual void init();

        virtual SplashScreenAbstractViewModel* SplashScreenModel();
        virtual MenuAbstractViewModel* MenuModel();
        virtual LanguageAbstractViewModel* LanguageModel();
        virtual MultiplayerMenuAbstractViewModel* MultiplayerModel();
        virtual NetMenuAbstractViewModel* NetModel();
        virtual SingleplayerMenuAbstractViewModel* SingleplayerModel();
        virtual GameAbstractViewModel* GameModel();
        virtual ScoreAbstractViewModel* ScoreModel();
    };
}


#endif
#endif //CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
