#ifdef USE_SDL
#ifndef CERVISEMESTRALKA_SDLVIEWMODEL_H
#define CERVISEMESTRALKA_SDLVIEWMODEL_H
#include <SDL2/SDL.h>
#include "../Abstract/BaseViewModel.h"
#include "SplashScreenSDLViewModel.h"
#include "SingpleplayerMenuSDLViewModel.h"
#include "SDLInput.h"
#include "ScoreSDLViewModel.h"
#include "QuitSDLViewModel.h"
#include "NetMenuSDLViewModel.h"
#include "MultiplayerSDLViewModel.h"
#include "MenuSDLViewModel.h"
#include "LanguageSDLViewModel.h"
#include "GameSDLViewModel.h"

namespace ViewModel
{
    class SDLViewModel : public BaseViewModel
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

#endif //CERVISEMESTRALKA_SDLVIEWMODEL_H
#endif
