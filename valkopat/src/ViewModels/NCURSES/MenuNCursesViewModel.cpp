#ifdef USE_NCURSES
#include "MenuNCursesViewModel.h"


int ViewModel::MenuNCursesViewModel::ShowMenu(std::vector<ViewModel::MenuAbstractViewModel::MenuEntry>)
{
    //TODO
    return 0;
}

ViewModel::MenuNCursesViewModel::MenuNCursesViewModel(const Translate::TranslateEngine* Translation)
        : MenuAbstractViewModel(Translation)
{ }


#endif
