#ifndef CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#define CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#include <stdint.h>
#include <chrono>
#include <thread>
#include "AbstractGameState.h"

namespace GameState
{
    class SplashScreenGameState : public AbstractGameState
    {
    public:
        SplashScreenGameState(ViewModel::BaseViewModel* RenderingModel);
        virtual AbstractGameState* run();

    private:
        const uint32_t SleepForSecond = 3;
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
