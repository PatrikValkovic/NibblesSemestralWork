#include "Settings.h"

Game::Settings* Game::Settings::Instance = NULL;

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
    if(Game::Settings::Instance==NULL)
        Game::Settings::Instance = new Settings();
    return Game::Settings::Instance;
}

Game::Settings::~Settings()
{
    delete Game::Settings::Instance;
    Game::Settings::Instance = NULL;
}

bool Game::Settings::GetAction(Game::Keys Key, int& Player, Game::Directions& Direction) const
{
    using std::for_each;
    using Game::Keys;
    using Game::Directions;
    using std::map;
    using std::pair;

    bool Found = false;
    for_each(IndividualSetting.begin(),IndividualSetting.end(),[&](PlayerSetting WorkingSetting){
        map<Keys,Directions>::iterator Finding = WorkingSetting.Actions.find(Key);
        if(Finding!=WorkingSetting.Actions.end())
        {
            Found = true;
            Player = WorkingSetting.Playerindex;
            Direction = Finding->second;
        }
    });

    return Found;
}

bool Game::Settings::SetAction(Keys NewKey, int Player, Directions NewDirection)
{
    int PlayerIndex;
    Directions Direct;
    if(GetAction(NewKey,PlayerIndex,Direct))
        return false;

    using std::for_each;
    using std::pair;
    using std::map;

    bool Changed = false;
    for_each(IndividualSetting.begin(),IndividualSetting.end(),[&NewKey,&Player,&NewDirection,&Changed]
    (PlayerSetting X){
        if(X.Playerindex==Player)
        {
            Changed = true;
            map<Keys,Directions>::iterator Moving = X.Actions.begin();
            map<Keys,Directions>::iterator End = X.Actions.end();
            for(;Moving!=End;Moving++)
                if(Moving->second==NewDirection)
                    Moving->first = NewKey;
        }
    });

    return Changed;
}


