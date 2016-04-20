#ifndef CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#ifdef USE_NCURSES
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
    class NCursesViewModel : public BaseViewModel
    {
    public:
        virtual const char* GetNameofViewModel();
        virtual void init(const Translate::TranslateEngine* Translate);

        virtual SplashScreenAbstractViewModel* SplashScreenModel();
        virtual MenuAbstractViewModel* MenuModel();
        virtual LanguageAbstractViewModel* LanguageModel();
        virtual MultiplayerMenuAbstractViewModel* MultiplayerModel();
        virtual NetMenuAbstractViewModel* NetModel();
        virtual SingleplayerMenuAbstractViewModel* SingleplayerModel();
        virtual GameAbstractViewModel* GameModel();
        virtual ScoreAbstractViewModel* ScoreModel();
        virtual QuitAbstractViewModel* QuitModel();
    };
}


#endif
#endif //CERVISEMESTRALKA_NCURSESVIEWMODEL_H
