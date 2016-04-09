#ifndef CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#define CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#include "../ViewModels/Abstract/BaseViewModel.h"


namespace GameState
{
    class AbstractGameState
    {
    public:
        AbstractGameState(ViewModel::BaseViewModel* RenderingModel)
                : RenderingModel(RenderingModel)
        { }

        virtual ~AbstractGameState()
        { }

        virtual AbstractGameState* run() = 0;

    protected:
        ViewModel::BaseViewModel* RenderingModel;
    };


}
#endif //CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
