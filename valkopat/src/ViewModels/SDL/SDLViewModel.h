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
        virtual void ShowSplashScreen();
        virtual const char* GetNameofViewModel();
        virtual void init();
    };
}

#endif //CERVISEMESTRALKA_SDLVIEWMODEL_H
#endif
