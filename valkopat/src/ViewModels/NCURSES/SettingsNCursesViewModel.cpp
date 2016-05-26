#include "SettingsNCursesViewModel.h"
#ifdef USE_NCURSES

int ViewModel::SettingsNCursesViewModel::ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const
{
    //TODO
    return 0;
}

ViewModel::SettingsNCursesViewModel::SettingsNCursesViewModel(const Translate::TranslateEngine* Translation)
        : SettingsAbstractViewModel(Translation)
{ }

void ViewModel::SettingsNCursesViewModel::ShowActualLanguage() const
{
    //TODO
}



#endif


