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

void ViewModel::SettingsNCursesViewModel::ShowInfo() const
{
    //TODO
}

map<string, string> ViewModel::SettingsNCursesViewModel::GetAviablesLanguages() const
{
    //TODO
    return std::map<std::__cxx11::string, std::__cxx11::string>();
}


#endif


