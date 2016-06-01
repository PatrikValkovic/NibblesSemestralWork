#ifndef CERVISEMESTRALKA_BASETASK_H
#define CERVISEMESTRALKA_BASETASK_H

namespace Game
{
    namespace Task
    {
        /**
         * Base abstract tak for inherit
         */
        class BaseTask
        {
        public:
            /**
             * Destructor
             */
            virtual ~BaseTask();

            /**
             * Abstract method to run every game loop
             */
            virtual void run() = 0;
        };

    }
}


#endif //CERVISEMESTRALKA_BASETASK_H
