#ifndef CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class MenuGameState;

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

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
