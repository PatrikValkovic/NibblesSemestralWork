#include "LanguageConsoleViewModel.h"
#ifdef USE_CONSOLE

int ViewModel::LanguageConsoleViewModel::ShowMenu(std::vector<ViewModel::LanguageAbstractViewModel::LanguageEntry>)
{
    return 0;
}

ViewModel::LanguageConsoleViewModel::LanguageConsoleViewModel(const Translate::TranslateEngine* Translate)
        : LanguageAbstractViewModel(Translate)
{ }


#endif
