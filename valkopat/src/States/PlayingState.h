#ifndef CERVISEMESTRALKA_PLAYINGSTATE_H
#define CERVISEMESTRALKA_PLAYINGSTATE_H
#include "AbstractGameState.h"
#include "MenuGameState.h"

namespace GameState
{
    class PlayingState : public AbstractGameState
    {
    public:
        PlayingState(ViewModel::BaseViewModel* RenderingModel,
        MenuGameState* MenuState);

        virtual AbstractGameState* run();

    private:
        MenuGameState* Menu;
    };
}

#endif //CERVISEMESTRALKA_PLAYINGSTATE_H
