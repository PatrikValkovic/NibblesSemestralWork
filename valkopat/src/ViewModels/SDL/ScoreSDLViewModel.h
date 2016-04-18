#ifndef CERVISEMESTRALKA_SCORESDLVIEWMODEL_H
#define CERVISEMESTRALKA_SCORESDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/ScoreAbstractViewModel.h"


namespace ViewModel
{
    class ScoreSDLViewModel : ScoreAbstractViewModel
    {
    public:
        ScoreSDLViewModel(const Translate::TranslateEngine* Translation);
    };
}

#endif
#endif //CERVISEMESTRALKA_SCORESDLVIEWMODEL_H
