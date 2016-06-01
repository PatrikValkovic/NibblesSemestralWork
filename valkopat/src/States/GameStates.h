#ifndef CERVISEMESTRALKA_GAMESTATES_H
#define CERVISEMESTRALKA_GAMESTATES_H
#include <vector>
#include "AbstractGameState.h"

namespace GameStates
{
    /**
     * Class that create all states
     */
    class GameStates
    {
    public:
        /**
         * Create new instance of GameStates and also create all needed states for game
         * @param Model Rendering submodule
         * @return New instance of GameState
         */
        GameStates(ViewModel::BaseViewModel* Model);

        /**
         * Destructor - delete all states of game
         */
        ~GameStates();

        /**
         * Return starting state, which will the game begin
         * @return Starting state of game
         */
        AbstractGameState* GetFirstState() const;

    private:

        /**
         * Rendering submodule
         */
        ViewModel::BaseViewModel* RenderingModel;

        /**
         * Vector of all created states
         */
        std::vector<AbstractGameState*> AllStates;

        /**
         * First state of game
         */
        AbstractGameState* First;
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
#endif //CERVISEMESTRALKA_GAMESTATES_H
