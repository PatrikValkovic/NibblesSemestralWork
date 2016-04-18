#include "LanguageNCursesViewModel.h"
#ifdef USE_NCURSES

int ViewModel::LanguageNCursesViewModel::ShowMenu(std::vector<ViewModel::LanguageAbstractViewModel::LanguageEntry>)
{
    return 0;
}

ViewModel::LanguageNCursesViewModel::LanguageNCursesViewModel(const Translate::TranslateEngine* Translation)
        : LanguageAbstractViewModel(Translation)
{ }


#endif


