#ifndef CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#define CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#include <cstdint>
#include <chrono>
#include <thread>
#include "AbstractGameState.h"

namespace GameStates
{
    class SplashScreenGameState : public AbstractGameState
    {
    public:
        SplashScreenGameState(ViewModel::BaseViewModel* RenderingModel);
        virtual AbstractGameState* run();

        void AddStates(MenuGameState* NextState);

    private:
        MenuGameState* NextState;
        const uint32_t SleepForSecond = 0; //TODO replace by 1
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
