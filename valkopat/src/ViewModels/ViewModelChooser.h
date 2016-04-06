#ifndef CERVISEMESTRALKA_VIEWMODELCHOOSER_H
#define CERVISEMESTRALKA_VIEWMODELCHOOSER_H
#include <vector>
#include "BaseViewModel.h"
#ifdef USE_CONSOLE
#include "CONSOLE/ConsoleViewModel.h"
#endif
#ifdef USE_SDL
#include "SDL/SDLViewModel.h"
#endif
#ifdef USE_NCURSES
#include "NCURSES/NCursesViewModel.h"
#endif

namespace ViewModel
{
    class ViewModelChooser
    {
    public:
        BaseViewModel* ChooseViewModel();
    private:
        std::vector<BaseViewModel*> PrepareViewModels();
    };
}

#endif //CERVISEMESTRALKA_VIEWMODELCHOOSER_H
