#ifndef CERVISEMESTRALKA_GAMESTATES_H
#define CERVISEMESTRALKA_GAMESTATES_H
#include <vector>
#include "AbstractGameState.h"
#include "SplashScreenGameState.h"

namespace GameState
{
    class GameStates
    {
    public:
        GameStates();
        ~GameStates();

        AbstractGameState* GetFirstState() const;

    private:
        std::vector<AbstractGameState*> AllStates;
        AbstractGameState* First;
    };
}


#endif //CERVISEMESTRALKA_GAMESTATES_H
