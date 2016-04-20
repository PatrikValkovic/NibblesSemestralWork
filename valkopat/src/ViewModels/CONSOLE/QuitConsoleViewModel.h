#ifndef CERVISEMESTRALKA_QUITCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_QUITCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include "../Abstract/QuitAbstractViewModel.h"


namespace ViewModel
{
    class QuitConsoleViewModel : public QuitAbstractViewModel
    {
    public:
        QuitConsoleViewModel(Translate::TranslateEngine* Translation);

        virtual void ShowEndScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_QUITCONSOLEVIEWMODEL_H
