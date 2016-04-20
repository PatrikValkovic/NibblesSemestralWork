#include "LanguageNCursesViewModel.h"
#ifdef USE_NCURSES

int ViewModel::LanguageNCursesViewModel::ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const
{
    //TODO
    return 0;
}

ViewModel::LanguageNCursesViewModel::LanguageNCursesViewModel(const Translate::TranslateEngine* Translation)
        : LanguageAbstractViewModel(Translation)
{ }

void ViewModel::LanguageNCursesViewModel::ShowInfo() const
{
    //TODO
}

map<string, string> ViewModel::LanguageNCursesViewModel::GetAviablesLanguages() const
{
    //TODO
    return std::map<std::__cxx11::string, std::__cxx11::string>();
}


#endif


