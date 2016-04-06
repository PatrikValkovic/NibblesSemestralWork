#include "NCursesViewModel.h"

void ViewModel::NCursesViewModel::ShowSplashScreen()
{
    initscr();
    printw("Splash screen pro libncurses");
    refresh();
    getch();
    endwin();

}

