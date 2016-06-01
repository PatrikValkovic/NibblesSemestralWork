#ifndef CERVISEMESTRALKA_MENUGAMESTATE_H
#define CERVISEMESTRALKA_MENUGAMESTATE_H
#include <algorithm>
#include "../ViewModels/Abstract/BaseViewModel.h"
#include "AbstractGameState.h"

namespace GameStates
{
    class MenuGameState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of MenuGameState
         * @param RenderingModel Rendering submodule
         * @return New instance of GameState
         */
        MenuGameState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Show main menu of game
         * @return Next state to run
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param Multi Multiplayer state
         * @param Single Singleplayer state
         * @param OverNet State of playing over net
         * @param End End of game state
         * @param Settting Setting state
         */
        void AddStates(MultiplayerGameState* Multi, SingleplayerGameState* Single, NetGameState* OverNet,
                       EndState* End, SettingsState* Settting);

    private:
        MultiplayerGameState* Multi;
        SingleplayerGameState* Single;
        NetGameState* Net;
        EndState* End;
        SettingsState* Settings;

        /**
         * Create menu to render
         * @param VectorWithMenu Out parameter containing menu entries
         * @return Map of states to return in run method in format <index,state>
         */
        map<int,AbstractGameState*> FillMenu(vector<ViewModel::MenuAbstractViewModel::MenuEntry>& VectorWithMenu);
    };
}

#include "MultiplayerGameState.h"
#include "SingleplayerGameState.h"
#include "NetGameState.h"
#include "EndState.h"
#include "SettingsState.h"
#endif //CERVISEMESTRALKA_MENUGAMESTATE_H
