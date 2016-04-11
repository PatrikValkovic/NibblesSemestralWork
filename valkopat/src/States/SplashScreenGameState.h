#ifndef CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#define CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#include <cstdint>
#include <chrono>
#include <thread>
#include "AbstractGameState.h"
#include "MenuGameState.h"

namespace GameState
{
    class SplashScreenGameState : public AbstractGameState
    {
    public:
        SplashScreenGameState(ViewModel::BaseViewModel* RenderingModel,MenuGameState* NextState);
        virtual AbstractGameState* run();

    private:
        MenuGameState* NextState;
        const uint32_t SleepForSecond = 3;
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
