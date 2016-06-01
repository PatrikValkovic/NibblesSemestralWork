#ifndef CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#define CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "StatesNames.h"

namespace GameStates
{
    /**
     * Base abstract class for all States
     */
    class AbstractGameState
    {
    public:
        /**
         * Create new instance of AbstractGameState and store rendering submodule
         * @param RenderingModel Rendering submodule
         * @return New instance of AbstractGameState
         */
        AbstractGameState(ViewModel::BaseViewModel* RenderingModel)
                : RenderingModel(RenderingModel)
        { }

        /**
         * Destructor
         */
        virtual ~AbstractGameState()
        { }

        /**
         * Main abstract method, that will run where is state changed
         * @return Next state, NULL if should game end
         */
        virtual AbstractGameState* run() = 0;

    protected:

        /**
         * Rendering submodule
         */
        ViewModel::BaseViewModel* RenderingModel;
    };
}


#include "SettingsState.h"
#include "EndState.h"
#include "GamePauseState.h"
#include "MenuGameState.h"
#include "MultiplayerGameState.h"
#include "NetGameState.h"
#include "PlayingState.h"
#include "SingleplayerGameState.h"
#include "SplashScreenGameState.h"
#endif //CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
