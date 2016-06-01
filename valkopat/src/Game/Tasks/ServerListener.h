#ifndef CERVISEMESTRALKA_SERVERLISTENER_H
#define CERVISEMESTRALKA_SERVERLISTENER_H
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/socket.h>
#include "BaseTask.h"
#include "../Worm.h"
#include "../NetworkCommunication.h"

using namespace std;
namespace Game
{
    namespace Task
    {
        /**
         * Listen server and move Worms by server requests
         */
        class ServerListener : public BaseTask
        {
        public:
            /**
             * Create new instance of ServerListener
             * @param ClientSocket Socket of client
             * @param Worms Worms to control
             * @param PlayerId ID of player playing on current PC
             * @return New instance of ServerListener
             */
            ServerListener (int ClientSocket,vector<Worm*> Worms,int PlayerId);

            /**
             * Move worms until Game::Server::Wait occurs
             */
            virtual void run();
        private:
            /**
             * Client socket
             */
            int CliSocket;
            /**
             * Id of player playing on current PC
             */
            int IdOfCurrentPlayer;
            /**
             * Controlled worms
             */
            vector<Worm*> InGameWorms;
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERLISTENER_H
