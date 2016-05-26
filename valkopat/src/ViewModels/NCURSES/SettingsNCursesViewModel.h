#ifndef CERVISEMESTRALKA_LANGUAGENCOURSESVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGENCOURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include <vector>
#include "../Abstract/SettingsAbstractViewModel.h"


namespace ViewModel
{
    class SettingsNCursesViewModel : public SettingsAbstractViewModel
    {
    public:
        SettingsNCursesViewModel(const Translate::TranslateEngine* Translation);
        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const;

        virtual void ShowInfo() const;

        virtual map<string,string> GetAviablesLanguages() const;
    };
}


#endif
#endif //CERVISEMESTRALKA_LANGUAGENCOURSESVIEWMODEL_H
