#ifndef CERVISEMESTRALKA_BASETASK_H
#define CERVISEMESTRALKA_BASETASK_H

namespace Game
{
    namespace Task
    {
        class BaseTask
        {
        public:
            virtual ~BaseTask();
            virtual void run() = 0;
        };

    }
}


#endif //CERVISEMESTRALKA_BASETASK_H
