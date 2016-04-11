#ifndef CERVISEMESTRALKA_MENUGAMESTATE_H
#define CERVISEMESTRALKA_MENUGAMESTATE_H
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "SingleplayerGameState.h"
#include "NetGameState.h"
#include "MultiplayerGameState.h"
#include "AbstractGameState.h"
#include "EndState.h"
#include "ChangeLanguageState.h"

namespace GameState
{
    class MenuGameState : public AbstractGameState
    {
    public:
        MenuGameState(ViewModel::BaseViewModel* RenderingModel,
                      MultiplayerGameState* Multi,
                      SingleplayerGameState* Single,
                      NetGameState* OverNet,
                      EndState* End,
                      ChangeLanguageState* Language);
        virtual AbstractGameState* run();

    private:
        MultiplayerGameState* Multi;
        SingleplayerGameState* Single;
        NetGameState* Net;
        EndState* End;
        ChangeLanguageState* Language;
    };
}


#endif //CERVISEMESTRALKA_MENUGAMESTATE_H
