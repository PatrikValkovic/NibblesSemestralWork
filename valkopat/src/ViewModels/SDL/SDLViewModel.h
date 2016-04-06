#ifndef CERVISEMESTRALKA_SDLVIEWMODEL_H
#define CERVISEMESTRALKA_SDLVIEWMODEL_H
#include <SDL2/SDL.h>
#include "../BaseViewModel.h"

namespace ViewModel
{
    class SDLViewModel : public BaseViewModel
    {
    public:
        virtual void ShowSplashScreen();
        virtual const char* GetNameofViewModel();
    };
}

#endif //CERVISEMESTRALKA_SDLVIEWMODEL_H
