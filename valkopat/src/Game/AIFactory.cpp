#include "AIFactory.h"

Game::AIFactory* Game::AIFactory::Instance = NULL;

Game::AIFactory::~AIFactory()
{
    if (Game::AIFactory::Instance != NULL)
    {
        using namespace std;
        using Game::Task::BaseAITask;
        for_each(this->Tasks.begin(), this->Tasks.end(), [](pair<string, BaseAITask*> X) {
            delete X.second;
        });
        Game::AIFactory::Instance = NULL;
    }
}

Game::AIFactory::AIFactory()
{
    using namespace Game::Task;
    this->Tasks = map<string, BaseAITask*>{
            pair<string, BaseAITask*>("RandomAI", new RandomAI(NULL, NULL)),
            pair<string, BaseAITask*>("BFSAI", new BFSAI(NULL, NULL))
    };
}

Game::AIFactory* Game::AIFactory::GetInstance()
{
    if(Game::AIFactory::Instance==NULL)
        Game::AIFactory::Instance = new AIFactory();
    return Game::AIFactory::Instance;
}

std::vector<std::string> Game::AIFactory::GetNamesOfAILevels()
{
    using namespace std;
    using Game::Task::BaseAITask;
    vector<string> Names;
    for_each(this->Tasks.begin(), this->Tasks.end(), [&Names](pair<string, BaseAITask*> X) {
        Names.push_back(X.first);
    });
    return Names;
}

std::vector<Game::Task::BaseAITask*> Game::AIFactory::CreatesTaskForWorms(std::vector<Worm*> Worms,
                                                                          Game::GameContent* Game,
                                                                          std::string NameOfLevel)
{
    using namespace std;
    using Game::Task::BaseAITask;

    vector<BaseAITask*> Tasks;
    map<string, BaseAITask*>::iterator AITaskIter = this->Tasks.find(NameOfLevel);
    if (AITaskIter == this->Tasks.end())
        throw new Exceptions::InvalidArgumentException("AI level with name " + NameOfLevel + " dont exists", __LINE__,
                                                       __FILE__);

    for_each(Worms.begin(), Worms.end(), [&Game, &Tasks, &AITaskIter](Worm* X) {
        Tasks.push_back(AITaskIter->second->CreateInstance(X, Game));
    });

    return Tasks;
}









