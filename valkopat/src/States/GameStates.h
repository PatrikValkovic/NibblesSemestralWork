#ifndef CERVISEMESTRALKA_GAMESTATES_H
#define CERVISEMESTRALKA_GAMESTATES_H
#include <vector>
#include "AbstractGameState.h"
#include "SplashScreenGameState.h"
#include "MenuGameState.h"

namespace GameState
{
    class GameStates
    {
    public:
        GameStates(ViewModel::BaseViewModel* Model);
        ~GameStates();

        AbstractGameState* GetFirstState() const;

    private:
        ViewModel::BaseViewModel* RenderingModel;
        std::vector<AbstractGameState*> AllStates;
        AbstractGameState* First;
    };
}


#endif //CERVISEMESTRALKA_GAMESTATES_H
