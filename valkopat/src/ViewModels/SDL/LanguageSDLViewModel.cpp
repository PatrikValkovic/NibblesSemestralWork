#include "LanguageSDLViewModel.h"
#ifdef USE_SDL

int ViewModel::LanguageSDLViewModel::ShowMenu(std::vector<ViewModel::LanguageAbstractViewModel::LanguageEntry>)
{
    return 0;
}

ViewModel::LanguageSDLViewModel::LanguageSDLViewModel(const Translate::TranslateEngine* Translation)
        : LanguageAbstractViewModel(Translation)
{ }


#endif
