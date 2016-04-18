#ifndef CERVISEMESTRALKA_SCORECONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_SCORECONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/ScoreAbstractViewModel.h"


namespace ViewModel
{
    class ScoreConsoleViewModel : public ScoreAbstractViewModel
    {
    public:
        ScoreConsoleViewModel(Translate::TranslateEngine* Translate);
    };
}

#endif
#endif //CERVISEMESTRALKA_SCORECONSOLEVIEWMODEL_H
