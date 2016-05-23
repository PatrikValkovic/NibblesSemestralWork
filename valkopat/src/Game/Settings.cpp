#include "Settings.h"

Game::Settings::Settings()
{

}

Game::Settings* Game::Settings::GetInstance()
{
    if(Instance==NULL)
        Instance = new Settings();
    return Instance;
}

Game::Settings::~Settings()
{
    delete Instance;
    Instance = NULL;
}

void Game::Settings::GetAction(Game::Keys Key, int& Player, Game::Directions& Direction)
{

}
