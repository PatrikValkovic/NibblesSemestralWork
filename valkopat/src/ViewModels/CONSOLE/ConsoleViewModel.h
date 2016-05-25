#ifndef CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>

#include "../Abstract/BaseViewModel.h"
#include "SplashPauseScreenConsoleViewModel.h"
#include "MenuConsoleViewModel.h"
#include "LanguageConsoleViewModel.h"
#include "MultiplayerConsoleViewModel.h"
#include "NetMenuConsoleViewModel.h"
#include "SingpleplayerMenuConsoleViewModel.h"
#include "GameConsoleViewModel.h"
#include "ScoreConsoleViewModel.h"
#include "QuitConsoleViewModel.h"
#include "ConsoleInput.h"

namespace ViewModel
{
    class ConsoleViewModel : public BaseViewModel
    {
    public:
        virtual const char* GetNameofViewModel();
        virtual void init(const Translate::TranslateEngine* Translate);

        virtual SplashPauseScreenAbstractViewModel* SplashPauseScreenModel();
        virtual MenuAbstractViewModel* MenuModel();
        virtual LanguageAbstractViewModel* LanguageModel();
        virtual MultiplayerMenuAbstractViewModel* MultiplayerModel();
        virtual NetMenuAbstractViewModel* NetModel();
        virtual SingleplayerMenuAbstractViewModel* SingleplayerModel();
        virtual GameAbstractViewModel* GameModel();
        virtual ScoreAbstractViewModel* ScoreModel();
        virtual QuitAbstractViewModel* QuitModel();
        virtual AbstractInput* InputModel();
    };
}


#endif
#endif //CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
