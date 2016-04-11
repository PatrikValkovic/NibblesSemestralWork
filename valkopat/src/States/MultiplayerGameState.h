#ifndef CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class MultiplayerGameState : public AbstractGameState
    {
    public:
        MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();
    };
}

#endif //CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
