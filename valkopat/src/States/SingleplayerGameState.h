#ifndef CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class SingleplayerGameState : public AbstractGameState
    {
    public:
        SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();
    };
}

#endif //CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
