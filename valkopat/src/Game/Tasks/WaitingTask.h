#ifndef CERVISEMESTRALKA_WAITINGTASK_H
#define CERVISEMESTRALKA_WAITINGTASK_H
#include <chrono>
#include <pthread.h>
#include "BaseTask.h"

namespace Game
{
    namespace Task
    {
        class WaitingTask : BaseTask
        {
        private:
            static const int WaitingTimeInMiliseconds;
        public:
            virtual void run();
        };

    }
}

#endif //CERVISEMESTRALKA_WAITINGTASK_H
