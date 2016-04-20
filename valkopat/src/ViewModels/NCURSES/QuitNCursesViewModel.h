#ifndef CERVISEMESTRALKA_QUITNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_QUITNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/QuitAbstractViewModel.h"

namespace ViewModel
{
    class QuitNCursesViewModel : public QuitAbstractViewModel
    {
    public:
        QuitNCursesViewModel(Translate::TranslateEngine* Translation);

        virtual void ShowEndScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_QUITNCURSESVIEWMODEL_H
