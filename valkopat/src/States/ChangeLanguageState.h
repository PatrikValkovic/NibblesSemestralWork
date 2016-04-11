#ifndef CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#define CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class ChangeLanguageState : public AbstractGameState
    {
    public:
        ChangeLanguageState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();
    };
}

#endif //CERVISEMESTRALKA_CHANGELANGUAGESTATE_H
