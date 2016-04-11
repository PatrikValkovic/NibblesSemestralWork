#ifndef CERVISEMESTRALKA_GAMEPAUSESTATE_H
#define CERVISEMESTRALKA_GAMEPAUSESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class GamePauseState : public AbstractGameState
    {
    public:
        GamePauseState(ViewModel::BaseViewModel* RenderingModel,
                       PlayingState* StateOfGame,
                       MenuGameState* MenuState);

        virtual AbstractGameState* run();

    private:
        PlayingState* GameState;
        MenuGameState* Menu;
    };
}


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_GAMEPAUSESTATE_H
