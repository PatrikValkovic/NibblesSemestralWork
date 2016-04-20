#include "QuitNCursesViewModel.h"
#ifdef USE_NCURSES

ViewModel::QuitNCursesViewModel::QuitNCursesViewModel(const Translate::TranslateEngine* Translation)
        : QuitAbstractViewModel(Translation)
{ }


void ViewModel::QuitNCursesViewModel::ShowEndScreen()
{
    //TODO
}


#endif

