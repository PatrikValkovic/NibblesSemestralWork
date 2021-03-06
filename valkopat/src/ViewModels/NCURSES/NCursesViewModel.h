#ifndef CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include <iostream>
#include "../Abstract/BaseViewModel.h"
#include "SplashScreenNCursesViewModel.h"
#include "MenuNCursesViewModel.h"
#include "SettingsNCursesViewModel.h"
#include "MultiplayerNCursesViewModel.h"
#include "NetMenuNCursesViewModel.h"
#include "SingleplayerMenuNCursesViewModel.h"
#include "GameNCursesViewModel.h"
#include "ScoreNCursesViewModel.h"
#include "QuitNCursesViewModel.h"
#include "NCursesInput.h"

namespace ViewModel
{
    class NCursesViewModel : public BaseViewModel
    {
    public:
        virtual const char* GetNameofViewModel();
        virtual void init(const Translate::TranslateEngine* Translate);

        virtual SplashPauseScreenAbstractViewModel* SplashPauseScreenModel();
        virtual MenuAbstractViewModel* MenuModel();
        virtual SettingsAbstractViewModel* LanguageModel();
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
#endif //CERVISEMESTRALKA_NCURSESVIEWMODEL_H
