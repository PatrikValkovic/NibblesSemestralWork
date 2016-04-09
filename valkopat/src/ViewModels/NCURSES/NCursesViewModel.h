#ifndef CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>

#include "../Abstract/BaseViewModel.h"
#include "SplashScreenNCursesViewModel.h"
#include "MenuNCursesViewModel.h"
#include "LanguageNCursesViewModel.h"
#include "MultiplayerNCursesViewModel.h"
#include "NetMenuNCursesViewModel.h"
#include "SingpleplayerMenuNCursesViewModel.h"
#include "GameNCursesViewModel.h"
#include "ScoreNCursesViewModel.h"

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
