#include "AIFactory.h"

Game::AIFactory* Game::AIFactory::Instance = NULL;

Game::AIFactory::~AIFactory()
{
    delete Instance;
    Instance = NULL;
}

Game::AIFactory::AIFactory()
{
}

Game::AIFactory* Game::AIFactory::GetInstance()
{
    if(Instance==NULL)
        Instance = new AIFactory();
    return Instance;
}





