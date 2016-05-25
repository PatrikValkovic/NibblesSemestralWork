#include "AIFactory.h"

Game::AIFactory* Game::AIFactory::Instance = NULL;

Game::AIFactory::~AIFactory()
{
    using namespace std;
    using Game::Task::BaseAITask;
    for_each(this->Tasks.begin(),this->Tasks.end(),[](pair<string,BaseAITask*> X){
        delete X.second;
    });
    delete Instance;
    Instance = NULL;
}

Game::AIFactory::AIFactory()
{
    using namespace Game::Task;
    this->Tasks = map<string,BaseAITask*>{
            pair<string,BaseAITask*>("RandomAI",new RandomAI(NULL,NULL)),
            pair<string,BaseAITask*>("BFSAI", new BFSAI(NULL,NULL))
    };
}

Game::AIFactory* Game::AIFactory::GetInstance()
{
    if(Instance==NULL)
        Instance = new AIFactory();
    return Instance;
}

std::vector<std::string> Game::AIFactory::GetNamesOfAILevels()
{
    return std::vector<std::__cxx11::string>();
}

std::vector<Game::Task::BaseAITask*> Game::AIFactory::CreatesTaskForWorms(std::vector<Worm*> Worms, GameContent* Game)
{
    return std::vector<BaseAITask*>();
}









