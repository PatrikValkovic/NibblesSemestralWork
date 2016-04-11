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

        void AddStates(PlayingState* GameState, MenuGameState* MenuState);

    private:
        MenuGameState* Menu;
        PlayingState* Play;
    };
}


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
