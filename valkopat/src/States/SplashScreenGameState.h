#ifndef CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#define CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#include <cstdint>
#include <chrono>
#include <thread>
#include "AbstractGameState.h"

namespace GameState
{
    class SplashScreenGameState : public AbstractGameState
    {
    public:
        SplashScreenGameState(ViewModel::BaseViewModel* RenderingModel,MenuGameState* NextState);
        virtual AbstractGameState* run();

    private:
        MenuGameState* NextState;
        const uint32_t SleepForSecond = 1;
    };
}

#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
