#ifndef CERVISEMESTRALKA_GAMEPAUSESTATE_H
#define CERVISEMESTRALKA_GAMEPAUSESTATE_H
#include <map>
#include <string>
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "AbstractGameState.h"

namespace GameStates
{
    class GamePauseState : public AbstractGameState
    {
    public:
        GamePauseState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();

        void AddStates(PlayingState* StateOfGame, MenuGameState* MenuState);

    private:
        PlayingState* GameState;
        MenuGameState* Menu;
    };
}


#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_GAMEPAUSESTATE_H
