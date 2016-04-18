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
        LanguageAbstractViewModel(Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        struct LanguageEntry
        {
            int Index;
            std::string Shortcut;
            std::string NameOfLanguage;
        };

        virtual ~LanguageAbstractViewModel()
        { }

        virtual int ShowMenu(std::vector<LanguageEntry>) = 0;
    };
}
#endif //CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
