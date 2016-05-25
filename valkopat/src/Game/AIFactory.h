#ifndef CERVISEMESTRALKA_AIFACTORY_H
#define CERVISEMESTRALKA_AIFACTORY_H
#include <cstdlib>
#include "Tasks/RandomAI.h"
#include "Tasks/BFSAI.h"

namespace Game
{
    class AIFactory
    {
    //singleton implementation
    private:
        static AIFactory* Instance;
        AIFactory();
    public:
        static AIFactory* GetInstance();
        AIFactory(const AIFactory& Second) = delete;
        AIFactory& operator=(const AIFactory& Second) = delete;
        ~AIFactory();
    };
}


#endif //CERVISEMESTRALKA_AIFACTORY_H
