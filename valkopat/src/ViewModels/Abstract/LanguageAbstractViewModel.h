#ifndef CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGEABSTRACTVIEWMODEL_H
#include <string>
#include <vector>

namespace ViewModel
{
    class LanguageAbstractViewModel
    {
    public:
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
