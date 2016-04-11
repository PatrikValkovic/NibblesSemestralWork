#ifndef CERVISEMESTRALKA_NETGAMESTATE_H
#define CERVISEMESTRALKA_NETGAMESTATE_H
#include "AbstractGameState.h"
#include "PlayingState.h"

namespace GameState
{
    class NetGameState : public AbstractGameState
    {
    public:
        NetGameState(ViewModel::BaseViewModel* RenderingModel,
        PlayingState* GameState);

        virtual AbstractGameState* run();
    private:
        PlayingState* PlayState;
    };
}

#endif //CERVISEMESTRALKA_NETGAMESTATE_H
