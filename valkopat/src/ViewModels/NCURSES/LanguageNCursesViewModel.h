#ifndef CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <vector>
#include "../Abstract/LanguageAbstractViewModel.h"


namespace ViewModel
{
    class LanguageConsoleViewModel : public LanguageAbstractViewModel
    {
    public:
        virtual int ShowMenu(std::vector<LanguageEntry>);
    };
}
#endif


#endif //CERVISEMESTRALKA_LANGUAGECONSOLEVIEWMODEL_H
