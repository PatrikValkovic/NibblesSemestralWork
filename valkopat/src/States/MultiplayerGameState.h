#ifndef CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#include "AbstractGameState.h"

namespace GameStates
{
    class MenuGameState;

    class MultiplayerGameState : public AbstractGameState
    {
    public:
        MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();

        void AddStates(PlayingState* PlayState, MenuGameState* MenuState);

    private:
        PlayingState* PlayState;
        MenuGameState* Menu;
    };
}

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
