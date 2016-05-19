#ifndef CERVISEMESTRALKA_GAMESDLVIEWMODEL_H
#define CERVISEMESTRALKA_GAMESDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/GameAbstractViewModel.h"

namespace ViewModel
{
    class GameSDLViewModel : public GameAbstractViewModel
    {
    public:
        GameSDLViewModel(const Translate::TranslateEngine* Translation);

        virtual void RenderGame(Game::GameContent* ContentToRender) = 0;
    };
}

#endif
#endif //CERVISEMESTRALKA_GAMESDLVIEWMODEL_H
