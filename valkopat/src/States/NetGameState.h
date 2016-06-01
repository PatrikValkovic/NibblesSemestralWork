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
    /**
     * Represent state, which manage creating of game objects from server
     */
    class NetGameState : public AbstractGameState
    {
    public:
        /**
         * Create new instance of NetGameState
         * @param RenderingModel Rendering submodule
         * @return New instance of NetGameState
         */
        NetGameState(ViewModel::BaseViewModel* RenderingModel);

        /**
         * Get informations from user and prepare game to run
         * @return Next state to run
         */
        virtual AbstractGameState* run();

        /**
         * Fill needed states
         * @param GameState State with game loop
         * @param MenuState State with main menu of the game
         */
        void AddStates(PlayingState* GameState, MenuGameState* MenuState);

    private:
        PlayingState* PlayState;
        MenuGameState* Menu;

        /**
         * Get informations from server and create Playground
         * @param Socket Socket of client
         * @return New instance of Game::PlayGround
         */
        PlayGround* CreatePlayground(int Socket) const;

        /**
         * Create client socket of player, if needed also create and run server
         * @return Client socket
         */
        int CreateSocket() const;

        /**
         * Check if server responds
         * @param Socket ClientSocket
         * @return True if server respond, false otherwise
         */
        bool SayHello(int Socket) const;

        /**
         * Get informations from user and create his Game::Worm
         * @param Socket Client socket
         * @param Name Name of player
         * @return New instance of Game::Worm representing player on current PC
         */
        Worm* GetInfoAboutPlayer(int Socket,string Name) const;

        /**
         * Wait fot other players to connect
         * @param Socket Client socket
         * @return Vector of other players worms
         */
        vector<Worm*> WaitToRestOfWorms(int Socket) const;
    };
}

#include "PlayingState.h"
#include "MenuGameState.h"
#endif //CERVISEMESTRALKA_NETGAMESTATE_H
