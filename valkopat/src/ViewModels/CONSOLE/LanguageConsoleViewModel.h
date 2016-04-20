#ifndef CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Abstract/LanguageAbstractViewModel.h"


namespace ViewModel
{
    class LanguageConsoleViewModel : public LanguageAbstractViewModel
    {
    public:
        LanguageConsoleViewModel(const Translate::TranslateEngine* Translate);
        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const;
        virtual void ShowInfo() const;
    };
}



#endif
#endif //CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
