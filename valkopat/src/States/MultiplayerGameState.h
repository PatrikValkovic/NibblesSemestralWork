#ifndef CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#define CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
#include "AbstractGameState.h"

namespace GameStates
{
    /**
     * State what prepare game for playing more player on one PC
     */
    class MultiplayerGameState : public AbstractGameState
    {
    public:

        /**
         * Create new instance of MultiplayerGameState
         * @param RenderingModel Rendering submodule
         * @return New instance of MultiplayerGameState
         */
        MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Get informations from users and prepare game to run
         * @return Next state to run
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param PlayState State with main loop of game
         * @param MenuState Main game menu state
         */
        void AddStates(PlayingState* PlayState, MenuGameState* MenuState);

    private:
        PlayingState* PlayState;
        MenuGameState* Menu;
    };
}

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_MULTIPLAYERGAMESTATE_H
