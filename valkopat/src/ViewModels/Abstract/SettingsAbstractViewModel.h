#ifndef CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
#include <string>
#include <vector>
#include "ViewModelDerivatingClass.h"
#include "../../Game/Settings.h"

namespace ViewModel
{
    class SettingsAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        struct LanguageOverwiew
        {
            string Shortcut;
            string Name;
        };

        SettingsAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }


        virtual ~SettingsAbstractViewModel()
        { }

        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const = 0;
        virtual void ShowActualLanguage() const = 0;
        virtual void ShowKeySettings() const = 0;
        virtual map<Game::Keys, Game::Actions> CreateNewSetting() = 0;
        virtual void NotAbleToSetSettings(Game::Keys K) = 0;

        inline map<string,string> GetAviablesLanguages() const
        {
            return Translation->GetAviablesLanguages();
        };

        inline void SetLanguage(string Shortcut)
        {
            Translate::TranslateEngine* EngineToTranslate = dynamic_cast<Translate::TranslateEngine*>(
                    const_cast<Translate::TranslateEngine*>(Translation));
            EngineToTranslate->SetLanguage(Shortcut);
        }
    };
}
#endif //CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
