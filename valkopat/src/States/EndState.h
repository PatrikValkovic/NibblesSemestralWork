#ifndef CERVISEMESTRALKA_ENDSTATE_H
#define CERVISEMESTRALKA_ENDSTATE_H
#include "AbstractGameState.h"

namespace GameStates
{
    /**
     * States that represent end of game
     */
    class EndState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of EndState
         * @param RenderingModel Rendering submodule
         * @return New instance of EndState
         */
        EndState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Show labels for end of game
         * @return Return NULL that indicate end of game
         */
        virtual AbstractGameState* run();

        /**
         * Method to get needed states, no parameters indicates that no next states are needed
         */
        void AddStates();
    };
}

#endif //CERVISEMESTRALKA_ENDSTATE_H
