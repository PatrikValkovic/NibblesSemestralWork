#ifndef CERVISEMESTRALKA_ENDSTATE_H
#define CERVISEMESTRALKA_ENDSTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class EndState : public AbstractGameState
    {
    public:
        EndState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();
    };
}

#endif //CERVISEMESTRALKA_ENDSTATE_H
