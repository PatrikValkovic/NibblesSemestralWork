#include "Settings.h"

Game::Settings* Game::Settings::Instance = NULL;

Game::Settings::Settings()
{
    using std::pair;
    //first player
    PlayerSetting First;
    First.Playerindex = 0;
    First.Actions.insert(pair<Keys,Actions>(KeyW,MoveUp));
    First.Actions.insert(pair<Keys,Actions>(KeyS,MoveDown));
    First.Actions.insert(pair<Keys,Actions>(KeyD,moveRight));
    First.Actions.insert(pair<Keys,Actions>(KeyA,MoveLeft));

    //second player
    PlayerSetting Second;
    First.Playerindex = 1;
    First.Actions.insert(pair<Keys,Actions>(KeyI,MoveUp));
    First.Actions.insert(pair<Keys,Actions>(KeyK,MoveDown));
    First.Actions.insert(pair<Keys,Actions>(KeyL,moveRight));
    First.Actions.insert(pair<Keys,Actions>(KeyJ,MoveLeft));

    //third player
    PlayerSetting Third;
    First.Playerindex = 2;
    First.Actions.insert(pair<Keys,Actions>(Key8,MoveUp));
    First.Actions.insert(pair<Keys,Actions>(Key5,MoveDown));
    First.Actions.insert(pair<Keys,Actions>(Key6,moveRight));
    First.Actions.insert(pair<Keys,Actions>(Key4,MoveLeft));

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

bool Game::Settings::GetAction(Game::Keys Key, int& Player, Game::Actions& Direction) const
{
    using std::for_each;
    using Game::Keys;
    using Game::Actions;
    using std::map;
    using std::pair;

    bool Found = false;
    for_each(IndividualSetting.begin(),IndividualSetting.end(),[&](PlayerSetting WorkingSetting){
        map<Keys,Actions>::iterator Finding = WorkingSetting.Actions.find(Key);
        if(Finding!=WorkingSetting.Actions.end())
        {
            Found = true;
            Player = WorkingSetting.Playerindex;
            Direction = Finding->second;
        }
    });

    return Found;
}

bool Game::Settings::SetAction(Keys NewKey, int Player, Actions NewDirection)
{
    int PlayerIndex;
    Actions Direct;
    if(GetAction(NewKey,PlayerIndex,Direct))
        return false;

    using std::for_each;
    using std::pair;
    using std::map;

    bool Changed = false;
    for(int a=0;a<(int)IndividualSetting.size();a++)
    {
        PlayerSetting WorkingPlayerSettings = IndividualSetting[a];
        if(WorkingPlayerSettings.Playerindex==Player)
        {
            Changed = true;
            Keys OldKey = Keys::Key1;
            for_each(WorkingPlayerSettings.Actions.begin(),WorkingPlayerSettings.Actions.end(),
                [&NewDirection,&OldKey](pair<Keys,Actions> X){
                    if(X.second==NewDirection)
                        OldKey = X.first;
                });
            WorkingPlayerSettings.Actions.erase(OldKey);
            WorkingPlayerSettings.Actions.insert(pair<Keys,Actions>(NewKey,NewDirection));
        }
    };

    return Changed;
}


