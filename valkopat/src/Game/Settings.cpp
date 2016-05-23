#include "Settings.h"

Game::Settings::Settings()
{
    using std::pair;
    //first player
    PlayerSetting First;
    First.Playerindex = 0;
    First.Actions.insert(pair<Keys,Directions>(KeyW,Up));
    First.Actions.insert(pair<Keys,Directions>(KeyS,Down));
    First.Actions.insert(pair<Keys,Directions>(KeyD,Right));
    First.Actions.insert(pair<Keys,Directions>(KeyA,Left));

    //second player
    PlayerSetting Second;
    First.Playerindex = 1;
    First.Actions.insert(pair<Keys,Directions>(KeyI,Up));
    First.Actions.insert(pair<Keys,Directions>(KeyK,Down));
    First.Actions.insert(pair<Keys,Directions>(KeyL,Right));
    First.Actions.insert(pair<Keys,Directions>(KeyJ,Left));

    //third player
    PlayerSetting Third;
    First.Playerindex = 2;
    First.Actions.insert(pair<Keys,Directions>(Key8,Up));
    First.Actions.insert(pair<Keys,Directions>(Key5,Down));
    First.Actions.insert(pair<Keys,Directions>(Key6,Right));
    First.Actions.insert(pair<Keys,Directions>(Key4,Left));

    //store it
    this->IndividualSetting.push_back(First);
    this->IndividualSetting.push_back(Second);
    this->IndividualSetting.push_back(Third);
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
