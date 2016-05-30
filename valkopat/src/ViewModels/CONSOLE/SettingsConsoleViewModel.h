#ifndef CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <climits>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#include "../Abstract/SettingsAbstractViewModel.h"
#include "../../Game/Settings.h"


namespace ViewModel
{
    class SettingsConsoleViewModel : public SettingsAbstractViewModel
    {
    public:
        SettingsConsoleViewModel(const Translate::TranslateEngine* Translate);
        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const;
        virtual void ShowActualLanguage() const;
        virtual void ShowKeySettings() const;
        virtual map<Game::Keys, Game::Actions> CreateNewSetting();
        void NotAbleToSetSettings(Game::Keys K);
    private:
        static const std::map<Game::Keys, char> KeyTranslate;
        static const map<Game::Actions, std::string> TranslateActions;
        void ClearInput();
    };
}



#endif
#endif //CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
