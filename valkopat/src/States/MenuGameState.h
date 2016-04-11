#ifndef CERVISEMESTRALKA_MENUGAMESTATE_H
#define CERVISEMESTRALKA_MENUGAMESTATE_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "AbstractGameState.h"

namespace GameState
{
    class MenuGameState : public AbstractGameState
    {
    public:
        MenuGameState(ViewModel::BaseViewModel* RenderingModel);
        virtual AbstractGameState* run();

        void AddStates(MultiplayerGameState* Multi, SingleplayerGameState* Single, NetGameState* OverNet,
                       EndState* End, ChangeLanguageState* Language);

    private:
        MultiplayerGameState* Multi;
        SingleplayerGameState* Single;
        NetGameState* Net;
        EndState* End;
        ChangeLanguageState* Language;
    };
}

#include "MultiplayerGameState.h"
#include "SingleplayerGameState.h"
#include "NetGameState.h"
#include "EndState.cpp"
#include "ChangeLanguageState.h"
#endif //CERVISEMESTRALKA_MENUGAMESTATE_H
