#include "SettingsSDLViewModel.h"
#ifdef USE_SDL

int ViewModel::SettingsSDLViewModel::ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const
{
    //TODO
    return 0;
}

ViewModel::SettingsSDLViewModel::SettingsSDLViewModel(const Translate::TranslateEngine* Translation)
        : SettingsAbstractViewModel(Translation)
{ }

void ViewModel::SettingsSDLViewModel::ShowInfo() const
{
    //TODO
}

#endif
