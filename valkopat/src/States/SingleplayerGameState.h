#ifndef CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
#include <string>
#include "AbstractGameState.h"
#include "../Game/PlaygroundFactory.h"
#include "../Game/Worm.h"
#include "../Game/GameContent.h"
#include "../Game/Events/Single.h"
#include "../Game/Tasks/WaitingTask.h"
#include "../Game/Tasks/DiscardingInput.h"
#include "../Game/AIFactory.h"

namespace GameStates
{
    /**
     * Represent state that create Game::Content to play again AI
     */
    class SingleplayerGameState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of SingleplayerGameState
         * @param RenderingModel Rendering submodule
         * @return New instance of SingleplayerGameState
         */
        SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Ask user for informations and create GameContent with AI player
         * @return Next state to run
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param GameState State with game loop
         * @param MenuState State with game menu
         */
        void AddStates(PlayingState* GameState, MenuGameState* MenuState);

    private:
        MenuGameState* Menu;
        PlayingState* Play;
    };
}


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SINGLEPLAYERGAMESTATE_H
