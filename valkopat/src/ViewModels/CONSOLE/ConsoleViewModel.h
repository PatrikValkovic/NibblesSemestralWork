#ifndef CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_CONSOLEVIEWMODEL_H
#include <iostream>
#include "../BaseViewModel.h"

namespace ViewModel
{
    class ConsoleViewModel : public BaseViewModel
    {
    public:
        virtual void ShowSplashScreen();
        virtual const char* GetNameofViewModel();
    };
}


#endif //CERVISEMESTRALKA_CONSOLEVIEWMODEL_H