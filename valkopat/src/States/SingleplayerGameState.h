#ifndef CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#include "AbstractGameState.h"

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


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
