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
        class ServerListener : public BaseTask
        {
        public:
            ServerListener (int ClientSocket,vector<Worm*> Worms);
            virtual void run();
        private:
            int CliSocket;
            vector<Worm*> InGameWorms;
        };
    }
}


#endif //CERVISEMESTRALKA_SERVERLISTENER_H
