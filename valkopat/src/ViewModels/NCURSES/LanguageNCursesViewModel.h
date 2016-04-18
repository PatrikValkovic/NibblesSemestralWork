#ifndef CERVISEMESTRALKA_LANGUAGENCOURSESVIEWMODEL_H
#define CERVISEMESTRALKA_LANGUAGENCOURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include <vector>
#include "../Abstract/LanguageAbstractViewModel.h"


namespace ViewModel
{
    class LanguageNCursesViewModel : public LanguageAbstractViewModel
    {
    public:
        LanguageNCursesViewModel(const Translate::TranslateEngine* Translation);
        virtual int ShowMenu(std::vector<LanguageEntry>);
    };
}
#endif


#endif //CERVISEMESTRALKA_LANGUAGENCOURSESVIEWMODEL_H
