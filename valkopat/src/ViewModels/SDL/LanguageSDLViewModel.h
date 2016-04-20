#ifndef CERVISEMESTRALKA_LANGUAGESDLVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGESDLVIEWMODEL_H
#ifdef USE_SDL
#include <vector>
#include "../Abstract/LanguageAbstractViewModel.h"


namespace ViewModel
{
    class LanguageSDLViewModel : public LanguageAbstractViewModel
    {
    public:
        LanguageSDLViewModel(const Translate::TranslateEngine* Translation);

        virtual int ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const;

        virtual void ShowInfo() const;
    };
}
#endif


#endif //CERVISEMESTRALKA_LANGUAGESDLVIEWMODEL_H
