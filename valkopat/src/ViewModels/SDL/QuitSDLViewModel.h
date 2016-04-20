#ifndef CERVISEMESTRALKA_QUITSDLVIEWMODEL_H
#define CERVISEMESTRALKA_QUITSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/QuitAbstractViewModel.h"

namespace ViewModel
{
    class QuitSDLViewModel : public QuitAbstractViewModel
    {
    public:
        QuitSDLViewModel(const Translate::TranslateEngine* Translate);

        virtual void ShowEndScreen();
    };
}

#endif
#endif //CERVISEMESTRALKA_QUITSDLVIEWMODEL_H
