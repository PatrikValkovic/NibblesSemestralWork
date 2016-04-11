#ifndef CERVISEMESTRALKA_MENUGAMESTATE_H
#define CERVISEMESTRALKA_MENUGAMESTATE_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "AbstractGameState.h"

namespace GameState
{
    class MenuGameState : public AbstractGameState
    {
    public:
        MenuGameState(ViewModel::BaseViewModel* RenderingModel);
        virtual AbstractGameState* run();
    };
}


#endif //CERVISEMESTRALKA_MENUGAMESTATE_H
