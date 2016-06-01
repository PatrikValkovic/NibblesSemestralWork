#ifndef CERVISEMESTRALKA_WAITINGTASK_H
#define CERVISEMESTRALKA_WAITINGTASK_H
#include <chrono>
#include <pthread.h>
#include "BaseTask.h"

namespace Game
{
    namespace Task
    {
        /**
         * Task that represent waiting cycle in main loop
         */
        class WaitingTask : public BaseTask
        {
        private:
            /**
             * How long to wait
             */
            static const int WaitingTimeInMiliseconds;
        public:
            /**
             * Start waiting
             */
            virtual void run();
        };

    }
}

#endif //CERVISEMESTRALKA_WAITINGTASK_H
