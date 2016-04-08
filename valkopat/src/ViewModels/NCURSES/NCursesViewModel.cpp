#ifdef USE_NCURSES
#include "NCursesViewModel.h"

void ViewModel::NCursesViewModel::ShowSplashScreen()
{
    initscr();
    printw("Splash screen pro libncurses");
    refresh();
    getch();
    endwin();
}

const char* ViewModel::NCursesViewModel::GetNameofViewModel()
{
    return "NCurse";
}

void ViewModel::NCursesViewModel::init()
{

}


#endif



