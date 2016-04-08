#ifdef USE_NCURSES
#ifndef CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#include <ncurses.h>
#include "../BaseViewModel.h"

namespace ViewModel
{
    class NCursesViewModel : public BaseViewModel
    {
    public:
        virtual void ShowSplashScreen();
        virtual const char* GetNameofViewModel();
        virtual void init();
    };
}

#endif //CERVISEMESTRALKA_NCURSESVIEWMODEL_H
#endif