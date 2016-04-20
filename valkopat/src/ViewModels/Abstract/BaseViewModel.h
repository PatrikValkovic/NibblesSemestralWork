#ifndef CERVISEMESTRALKA_BASEVIEWMODEL_H
#define CERVISEMESTRALKA_BASEVIEWMODEL_H
#include <vector>
#include <cstring>

#include "../../Translation/TranslateEngine.h"
#include "SplashScreenAbstractViewModel.h"
#include "MenuAbstractViewModel.h"
#include "LanguageAbstractViewModel.h"
#include "MultiplayerAbstractViewModel.h"
#include "NetMenuAbstractViewModel.h"
#include "SingpleplayerAbstractViewModel.h"
#include "GameAbstractViewModel.h"
#include "ScoreAbstractViewModel.h"
#include "QuitAbstractViewModel.h"

namespace ViewModel
{
    class BaseViewModel
    {
    public:
        virtual ~BaseViewModel()
        { }

        virtual const char* GetNameofViewModel() = 0;
        virtual void init(const Translate::TranslateEngine* Translate) = 0;

        virtual SplashScreenAbstractViewModel* SplashScreenModel() = 0;
        virtual MenuAbstractViewModel* MenuModel() = 0;
        virtual LanguageAbstractViewModel* LanguageModel() = 0;
        virtual MultiplayerMenuAbstractViewModel* MultiplayerModel() = 0;
        virtual NetMenuAbstractViewModel* NetModel() = 0;
        virtual SingleplayerMenuAbstractViewModel* SingleplayerModel() = 0;
        virtual GameAbstractViewModel* GameModel() = 0;
        virtual ScoreAbstractViewModel* ScoreModel() = 0;
        virtual QuitAbstractViewModel* QuitModel() = 0;
    };

}

#endif //CERVISEMESTRALKA_BASEVIEWMODEL_H
