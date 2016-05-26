#ifndef CERVISEMESTRALKA_NETGAMESTATE_H
#define CERVISEMESTRALKA_NETGAMESTATE_H
#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include "AbstractGameState.h"
//TODO replace
#include "../ViewModels/CONSOLE/NetMenuConsoleViewModel.h"

namespace GameStates
{
    class NetGameState : public AbstractGameState
    {
    public:
        NetGameState(ViewModel::BaseViewModel* RenderingModel);

        virtual AbstractGameState* run();

        void AddStates(PlayingState* GameState, MenuGameState* MenuState);

    private:
        PlayingState* PlayState;
        MenuGameState* Menu;

        int CreateServer(std::pair<string,string> IPAndPort,int CountOfPlayers);
    };
}

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_NETGAMESTATE_H
