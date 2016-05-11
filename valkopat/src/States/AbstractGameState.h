#ifndef CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#define CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "StatesNames.h"

namespace GameStates
{
    class AbstractGameState
    {
    public:
        AbstractGameState(ViewModel::BaseViewModel* RenderingModel)
                : RenderingModel(RenderingModel)
        { }

        virtual ~AbstractGameState()
        { }

        virtual AbstractGameState* run() = 0;

    protected:
        ViewModel::BaseViewModel* RenderingModel;
    };
}


#include "ChangeLanguageState.h"
#include "EndState.h"
#include "GamePauseState.h"
#include "MenuGameState.h"
#include "MultiplayerGameState.h"
#include "NetGameState.h"
#include "PlayingState.h"
#include "SingleplayerGameState.h"
#include "SplashScreenGameState.h"

#endif //CERVISEMESTRALKA_ABSTRACTGAMESTATE_H
