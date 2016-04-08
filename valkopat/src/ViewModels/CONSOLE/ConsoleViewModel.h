#ifdef USE_CONSOLE
#ifndef CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#include <iostream>
#include "../Abstract/BaseViewModel.h"

namespace ViewModel
{
    class ConsoleViewModel : public BaseViewModel
    {
    public:
        virtual void ShowSplashScreen();
        virtual const char* GetNameofViewModel();
        virtual void init();
    };
}


#endif //CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#endif
