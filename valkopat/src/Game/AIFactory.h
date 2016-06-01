#ifndef CERVISEMESTRALKA_AIFACTORY_H
#define CERVISEMESTRALKA_AIFACTORY_H
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "../Exceptions/InvalidArgumentException.h"
#include "Tasks/RandomAI.h"
#include "Tasks/BFSAI.h"


namespace Game
{
    /**
     * Creates task for AI
     */
    class AIFactory
    {
        //singleton implementation
    private:
        /**
         * Singleton instance
         */
        static AIFactory* Instance;
        /**
         * Private contructor - create templates of AI tasks
         * @return
         */
        AIFactory();
    public:
        /**
         * Get instance of Game::AIFactory
         * @return
         */
        static AIFactory* GetInstance();
        AIFactory(const AIFactory& Second) = delete;
        AIFactory& operator=(const AIFactory& Second) = delete;
        /**
         * Destructor delete templates of AI tasks
         */
        ~AIFactory();



        //implementation
    protected:
        /**
         * Templates for AI task in format map<name of AI level,tempalte of AI task>
         */
        std::map<string, Game::Task::BaseAITask*> Tasks;
    public:
        /**
         * Return names of all tasks, that Game::AIFactory have templates
         * @return
         */
        std::vector<string> GetNamesOfAILevels();
        /**
         * Create new AI task by template
         * @param Worms Vector of Worms to be controlled from task
         * @param Game Content of current game
         * @param NameOfLevel Name of AI task to use
         * @return Vector of AI tasks
         */
        std::vector<Game::Task::BaseAITask*> CreatesTaskForWorms(std::vector<Worm*> Worms,
                                                                 GameContent* Game,
                                                                 string NameOfLevel);
    };
}


#endif //CERVISEMESTRALKA_AIFACTORY_H
