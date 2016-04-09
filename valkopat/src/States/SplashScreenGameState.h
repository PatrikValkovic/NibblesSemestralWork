#ifndef CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#define CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
#include "AbstractGameState.h"

namespace GameState
{
    class SplashScreenGameState : public AbstractGameState
    {
    public:
        virtual AbstractGameState* run();
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENGAMESTATE_H
