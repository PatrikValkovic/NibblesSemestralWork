#ifndef CERVISEMESTRALKA_NETGAMESTATE_H
#define CERVISEMESTRALKA_NETGAMESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class NetGameState : public AbstractGameState
    {
    public:
        NetGameState(ViewModel::BaseViewModel* RenderingModel,
                     PlayingState* GameState,
                     MenuGameState* MenuState);

        virtual AbstractGameState* run();
    private:
        PlayingState* PlayState;
        MenuGameState* Menu;
    };
}

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_NETGAMESTATE_H
