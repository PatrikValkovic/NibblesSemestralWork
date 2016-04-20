#ifndef CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
#include <string>
#include <vector>
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class LanguageAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        struct LanguageOverwiew
        {
            string Shortcut;
            string Name;
        };

        LanguageAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }


        virtual ~LanguageAbstractViewModel()
        { }

        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const = 0;

        virtual void ShowInfo() const = 0;

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
