#ifndef CERVISEMESTRALKA_PLAYINGSTATE_H
#define CERVISEMESTRALKA_PLAYINGSTATE_H
#include <map>
#include <algorithm>
#include <cstdint>
#include <vector>
#include "AbstractGameState.h"
#include "../Game/Enums.h"
#include "../Game/GameContent.h"

namespace GameStates
{
    /**
     * Represent state with game loop
     */
    class PlayingState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of PlayingState
         * @param RenderingModel Rendering submodule
         * @return New instance of PlayingState
         */
        PlayingState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Destructor delete Game::GameContent
         */
        ~PlayingState();

        /**
         * Run game loop
         * @return Next state to run
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param MenuState State with main game menu
         * @param PauseState Pause state
         */
        void AddStates(MenuGameState* MenuState, GamePauseState* PauseState);

        /**
         * Delete old Game::GameContent and replace it with new one
         * @param NewContent New content of game
         */
        void ClearContent(Game::GameContent* NewContent);

        /**
         * Check if still existing playable worm
         * @return True if still exists playable worm, false otherwise
         */
        bool Playing();

        /**
         * Return all worms in current Game::GameContent (shallow copy)
         * @return Vector of all Game::Worm
         */
        std::vector<Game::Worm*> GetWorms();

    private:
        MenuGameState* Menu;
        GamePauseState* Pause;

        /**
         * Current content of game
         */
        Game::GameContent* ContentOfGame = NULL;

        /**
         * Move worms in their directions
         */
        void MoveWorms();

        /**
         * Check if there are events to run and proccess them
         * @return
         */
        bool ProccessEvents() const;

        /**
         * Check if there are overlaps objects and resolve it
         */
        void CheckCollisions();

        /**
         * Run all tasks in current Game::GameContent
         */
        void RunTasks() const;

        /**
         * Check if worm is out of playiled and if yes, move it the other side of playiled
         */
        void ValidatePositionsOfWorms();
    };
}

#include "GamePauseState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_PLAYINGSTATE_H
