#ifndef CERVISEMESTRALKA_SERVERSIDE_H
#define CERVISEMESTRALKA_SERVERSIDE_H
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <functional>
#include <cstring>
#include <map>
#include "../Worm.h"
#include "../PlayGround.h"
#include "../PlaygroundFactory.h"
#include "../NetworkCommunication.h"

namespace Game
{
    namespace Event
    {
        class ServerSide
        {
        public:
            /**
             * Create new instance of ServerSide event
             * @param ServerSock Server's socket
             * @param CountOfPlayers Max count of players
             * @param Ground Playground to use
             * @return New instance of ServerSide event
             */
            ServerSide(int ServerSock,int CountOfPlayers,PlayGround* Ground);

            /**
             * Destructor, delete serverside's objects
             */
            ~ServerSide();

            /**
             * Start server in separate thread in background
             */
            void StartServer();
        private:
            /**
             * How long wait to next turn
             */
            const int WaitForMiliseconds = 750;
            /**
             * Connected players with their sockets in format map<socket,player>
             */
            map<int ,Worm*> Players;
            /**
             * Server socket
             */
            int ServerSock;
            /**
             * Max count of players
             */
            int CountOfPlayers;
            /**
             * Game::PlayGround to use in game
             */
            PlayGround* Ground;
            /**
             * Method to run in separate thread
             * @param S Instance of ServerSide event
             */
            static void ThreadRun(ServerSide* S);

            /**
             * Wait for next player to connect
             * @return Socket of new player
             */
            int NewUserSocket();

            /**
             * Change with user informations about map
             * @param ClientSock Client socket
             */
            void ResolveMap(int ClientSock);

            /**
             * Change with user informations about himself and create new Game::Worm representing that player
             * @param SocketId Client socket
             * @param IndexOfPlayer Future index of player
             * @return New Game::Worm instance that represent player
             */
            Worm* CreateWorm(int SocketId,int IndexOfPlayer);

            /**
             * Send informations about all already connected players to new player
             * @param ClientSock Socket of new player
             */
            void SendInfoAboutConnectedPlayers(int ClientSock);

            /**
             * Send information to rest of players, that new user was connected
             * @param ConnectedPlayer Game::Worm representing new connected palyer
             */
            void SendInfoThatPlayerWasConnected(Worm* ConnectedPlayer);

            /**
             * Send information to all players that the game could start
             */
            void StartGame();

            /**
             * Check if is still any playable player
             * @return
             */
            bool StillPlay();

            /**
             * Wait specific time
             */
            void WaitMethod();

            /**
             * Get actions from users and store them into map
             * @return Stored actions in format map<Worm of player,Action to proccess>
             */
            map<Worm*,Actions> GetActionsFromUsers();

            /**
             * Send all players actions of other players
             * @param ToSend Actions to send
             */
            void SendActions(map<Worm*,Actions> ToSend);

            /**
             * Send players informations that should move
             */
            void NextFrame();
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERSIDE_H
