#ifndef CERVISEMESTRALKA_PLAYINGSTATE_H
#define CERVISEMESTRALKA_PLAYINGSTATE_H
#include "AbstractGameState.h"

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

#include "GamePauseState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_PLAYINGSTATE_H
