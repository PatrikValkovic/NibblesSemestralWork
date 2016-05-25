#ifdef USE_SDL
#ifndef CERVISEMESTRALKA_SDLVIEWMODEL_H
#define CERVISEMESTRALKA_SDLVIEWMODEL_H
#include <SDL2/SDL.h>
#include "../Abstract/BaseViewModel.h"

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
        virtual Input* InputModel();
    };
}

#endif //CERVISEMESTRALKA_SDLVIEWMODEL_H
#endif
