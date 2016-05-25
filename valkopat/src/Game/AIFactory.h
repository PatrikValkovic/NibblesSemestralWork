#ifndef CERVISEMESTRALKA_AIFACTORY_H
#define CERVISEMESTRALKA_AIFACTORY_H
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
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

    //implementation
    protected:
        std::map<string,Game::Task::BaseAITask*> Tasks;
    public:
        std::vector<string> GetNamesOfAILevels();
        std::vector<Game::Task::BaseAITask*> CreatesTaskForWorms(std::vector<Worm*> Worms,GameContent* Game);
    };
}


#endif //CERVISEMESTRALKA_AIFACTORY_H
