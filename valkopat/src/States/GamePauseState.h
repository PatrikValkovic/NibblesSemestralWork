#ifndef CERVISEMESTRALKA_GAMEPAUSESTATE_H
#define CERVISEMESTRALKA_GAMEPAUSESTATE_H
#include "AbstractGameState.h"
#include "PlayingState.h"

namespace GameState
{
    class GamePauseState : public AbstractGameState
    {
    public:
        GamePauseState(ViewModel::BaseViewModel* RenderingModel, PlayingState* StateOfGame);

        virtual AbstractGameState* run();

    private:
        PlayingState* GameState;
    };
}


#endif //CERVISEMESTRALKA_GAMEPAUSESTATE_H
