#ifndef CERVISEMESTRALKA_GAMESTATES_H
#define CERVISEMESTRALKA_GAMESTATES_H
#include <vector>
#include "AbstractGameState.h"

namespace GameStates
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


#include "SettingsState.h"
#include "EndState.h"
#include "GamePauseState.h"
#include "MenuGameState.h"
#include "MultiplayerGameState.h"
#include "NetGameState.h"
#include "PlayingState.h"
#include "SingleplayerGameState.h"
#include "SplashScreenGameState.h"
#endif //CERVISEMESTRALKA_GAMESTATES_H
