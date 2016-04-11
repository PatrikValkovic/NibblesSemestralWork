#ifndef CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#include "AbstractGameState.h"
#include "MenuGameState.h"
#include "PlayingState.h"

namespace GameState
{
    class SingleplayerGameState : public AbstractGameState
    {
    public:
        SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel,
                              PlayingState* GameState,
                              MenuGameState* MenuState);

        virtual AbstractGameState* run();

    private:
        MenuGameState* Menu;
        PlayingState* Play;
    };
}

#endif //CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
