#ifndef CERVISEMESTRALKA_LANGUAGESDLVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGESDLVIEWMODEL_H
#ifdef USE_SDL
#include <vector>
#include "../Abstract/SettingsAbstractViewModel.h"


namespace ViewModel
{
    class SettingsSDLViewModel : public SettingsAbstractViewModel
    {
    public:
        SettingsSDLViewModel(const Translate::TranslateEngine* Translation);

        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const;

        virtual void ShowActualLanguage() const;
    };
}
#endif


#endif //CERVISEMESTRALKA_LANGUAGESDLVIEWMODEL_H
