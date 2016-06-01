#ifndef CERVISEMESTRALKA_NIBBLESGAME_H
#define CERVISEMESTRALKA_NIBBLESGAME_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "../States/GameStates.h"

namespace Game
{
    /**
     * Main container for whole game
     */
    class NibbleGame
    {
    public:
        /**
         * Create new instance of NibbleGame
         * @param RenderingEngine Rendering submodule
         * @return New instance of NibbleGame
         */
        NibbleGame(ViewModel::BaseViewModel* RenderingEngine);

        /**
         * Delete all content of game
         */
        ~NibbleGame();

        /**
         * Start game with first state\n
         * First must be Game::NibbleGame::init called
         */
        void run();

        /**
         * Init the game, so it could by run
         */
        void init();

    private:
        /**
         * Container for States of game
         */
        GameStates::GameStates* States;
        /**
         * Rendering submodule
         */
        ViewModel::BaseViewModel* RenderEngine;
    };
}


#endif //CERVISEMESTRALKA_NIBBLESGAME_H
