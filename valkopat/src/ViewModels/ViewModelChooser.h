#ifndef CERVISEMESTRALKA_VIEWMODELCHOOSER_H
#define CERVISEMESTRALKA_VIEWMODELCHOOSER_H
#include <iostream>
#include <vector>
#include "Abstract/BaseViewModel.h"
#ifdef USE_CONSOLE
#include "CONSOLE/ConsoleViewModel.h"
#endif
#ifdef USE_SDL
#include "SDL/ConsoleViewModel.h"
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
