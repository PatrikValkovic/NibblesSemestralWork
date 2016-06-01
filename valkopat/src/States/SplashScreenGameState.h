#ifndef CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#define CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#include <cstdint>
#include <chrono>
#include <thread>
#include "AbstractGameState.h"

namespace GameStates
{
    /**
     * Starting state, show welcome message
     */
    class SplashScreenGameState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of SplashScreenGameState
         * @param RenderingModel Rendering submodule
         * @return New instance of SplashScreenGameState
         */
        SplashScreenGameState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Show welcome message, wait for a specific time and return next state
         * @return State with game menu
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param NextState State with game menu
         */
        void AddStates(MenuGameState* NextState);

    private:
        MenuGameState* NextState;
        /**
         * How long wait to show menu
         */
        const uint32_t SleepForSecond;
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
