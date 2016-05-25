#ifndef CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#include <string>
#include "AbstractGameState.h"
#include "../Game/PlaygroundFactory.h"
#include "../Game/Worm.h"
#include "../Game/GameContent.h"
#include "../Game/Events/Single.h"
#include "../Game/Tasks/WaitingTask.h"
#include "../Game/Tasks/RandomAI.h"
#include "../Game/Tasks/BFSAI.h"

namespace GameStates
{
    class SingleplayerGameState : public AbstractGameState
    {
    public:
        SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();

        void AddStates(PlayingState* GameState, MenuGameState* MenuState);

    private:
        MenuGameState* Menu;
        PlayingState* Play;
    };
}


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
