#ifndef CERVISEMESTRALKA_NETGAMESTATE_H
#define CERVISEMESTRALKA_NETGAMESTATE_H
#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include "AbstractGameState.h"
#include "../ViewModels/Abstract/NetMenuAbstractViewModel.h"
#include "../Game/Events/ServerSide.h"
#include "../Game/Events/ClientSide.h"
#include "../Game/Tasks/DiscardingInput.h"
#include "../Game/Tasks/ServerListener.h"
#include "../Game/GameContent.h"
#include "../Game/NetworkCommunication.h"

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

        PlayGround* CreatePlayground(int Socket) const;
        int CreateSocket() const;
        bool SayHello(int Socket) const;
        Worm* GetInfoAboutPlayer(int Socket,string Name) const;
        vector<Worm*> WaitToRestOfWorms(int Socket) const;
    };
}

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_NETGAMESTATE_H
