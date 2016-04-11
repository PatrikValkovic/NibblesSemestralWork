#ifndef CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#include "AbstractGameState.h"
#include "PlayingState.h"

namespace GameState
{
    class MultiplayerGameState : public AbstractGameState
    {
    public:
        MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel,
                             PlayingState* PlayState,
                             MenuGameState* MenuState);

        virtual AbstractGameState* run();

    private:
        PlayingState* PlayState;
        MenuGameState* Menu;
    };
}

#endif //CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
