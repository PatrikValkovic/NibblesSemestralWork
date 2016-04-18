#ifndef CERVISEMESTRALKA_MULTIPLAYERNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_MULTIPLAYERNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/MultiplayerAbstractViewModel.h"


namespace ViewModel
{
    class MultiplayerNCursesViewModel : public MultiplayerMenuAbstractViewModel
    {
    public:
        MultiplayerNCursesViewModel(const Translate::TranslateEngine* Translation);
    };
}

#endif
#endif //CERVISEMESTRALKA_MULTIPLAYERNCURSESVIEWMODEL_H
