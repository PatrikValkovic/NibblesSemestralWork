#ifndef CERVISEMESTRALKA_VIEWMODELCHOOSER_H
#define CERVISEMESTRALKA_VIEWMODELCHOOSER_H
#include <iostream>
#include <vector>
#include <climits>
#include "Abstract/BaseViewModel.h"
#include "../Translation/TranslateEngine.h"
#include "../Exceptions/Exception.h"
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
