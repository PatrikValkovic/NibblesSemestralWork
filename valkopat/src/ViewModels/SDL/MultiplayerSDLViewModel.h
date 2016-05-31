#ifndef CERVISEMESTRALKA_MULTIPLAYERSDLVIEWMODEL_H
#define CERVISEMESTRALKA_MULTIPLAYERSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/MultiplayerAbstractViewModel.h"


namespace ViewModel
{
    class MultiplayerSDLViewModel : public MultiplayerMenuAbstractViewModel
    {
    public:
        MultiplayerSDLViewModel(const Translate::TranslateEngine* Translation);
    };
}

#endif
#endif //CERVISEMESTRALKA_MULTIPLAYERSDLVIEWMODEL_H
