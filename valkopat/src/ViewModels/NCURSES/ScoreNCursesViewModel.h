#ifndef CERVISEMESTRALKA_SCORENCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_SCORENCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/ScoreAbstractViewModel.h"


namespace ViewModel
{
    class ScoreNCursesViewModel : public ScoreAbstractViewModel
    {
    public:
        ScoreNCursesViewModel(const Translate::TranslateEngine* Translation);


    };
}

#endif
#endif //CERVISEMESTRALKA_SCORENCURSESVIEWMODEL_H
