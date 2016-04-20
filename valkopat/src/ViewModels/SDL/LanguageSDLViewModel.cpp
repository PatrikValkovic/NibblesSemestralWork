#include "LanguageSDLViewModel.h"
#ifdef USE_SDL

int ViewModel::LanguageSDLViewModel::ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const
{
    //TODO
    return 0;
}

ViewModel::LanguageSDLViewModel::LanguageSDLViewModel(const Translate::TranslateEngine* Translation)
        : LanguageAbstractViewModel(Translation)
{ }

void ViewModel::LanguageSDLViewModel::ShowInfo() const
{
    //TODO
}

#endif
