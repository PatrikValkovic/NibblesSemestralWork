#ifndef CERVISEMESTRALKA_PLAYINGSTATE_H
#define CERVISEMESTRALKA_PLAYINGSTATE_H
#include "AbstractGameState.h"
#include "MenuGameState.h"
#include "GamePauseState.h"

namespace GameState
{
    class PlayingState : public AbstractGameState
    {
    public:
        PlayingState(ViewModel::BaseViewModel* RenderingModel,
                     MenuGameState* MenuState,
                     GamePauseState* PauseState);

        virtual AbstractGameState* run();

    private:
        MenuGameState* Menu;
        GamePauseState* Pause;
    };
}

#endif //CERVISEMESTRALKA_PLAYINGSTATE_H
