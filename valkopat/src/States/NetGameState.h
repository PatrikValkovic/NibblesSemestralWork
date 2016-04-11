#ifndef CERVISEMESTRALKA_NETGAMESTATE_H
#define CERVISEMESTRALKA_NETGAMESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class NetGameState : public AbstractGameState
    {
    public:
        NetGameState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();
    };
}

#endif //CERVISEMESTRALKA_NETGAMESTATE_H
