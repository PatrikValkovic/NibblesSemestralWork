#include "BaseViewModel.h"

ViewModel::BaseViewModel::~BaseViewModel()
{
    delete SplashScren;
    delete Menu;
    delete Language;
    delete Multiplayer;
    delete NetMenu;
    delete Singpleplayer;
    delete Game;
    delete Score;
    delete Quit;
    delete Input;
}

