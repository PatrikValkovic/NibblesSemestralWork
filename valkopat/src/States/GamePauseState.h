#ifndef CERVISEMESTRALKA_GAMEPAUSESTATE_H
#define CERVISEMESTRALKA_GAMEPAUSESTATE_H
#include <map>
#include <string>
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "AbstractGameState.h"

namespace GameStates
{
    /**
     * State to show pause and final score
     */
    class GamePauseState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of GamePauseState
         * @param RenderingModel Rendering submodule
         * @return New instance of GamePauseState
         */
        GamePauseState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Show score of players
         * @return Next state to run
         */
        virtual AbstractGameState* run();

        /**
         * Filling needed states
         * @param StateOfGame State of game
         * @param MenuState State of menu
         */
        void AddStates(PlayingState* StateOfGame, MenuGameState* MenuState);

    private:
        PlayingState* GameState;
        MenuGameState* Menu;
    };
}


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_GAMEPAUSESTATE_H
