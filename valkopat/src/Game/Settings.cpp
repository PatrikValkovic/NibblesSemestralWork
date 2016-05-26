#include "Settings.h"

Game::Settings* Game::Settings::Instance = NULL;

Game::Settings::Settings()
{
    using std::pair;
    //first player
    PlayerSetting First;
    First.Playerindex = 0;
    First.Action.insert(pair<Keys,Actions>(KeyW,MoveUp));
    First.Action.insert(pair<Keys,Actions>(KeyS,MoveDown));
    First.Action.insert(pair<Keys,Actions>(KeyD,moveRight));
    First.Action.insert(pair<Keys,Actions>(KeyA,MoveLeft));
    First.Action.insert(pair<Keys,Actions>(KeyQ,Pause));

    //second player
    PlayerSetting Second;
    Second.Playerindex = 1;
    Second.Action.insert(pair<Keys,Actions>(KeyI,MoveUp));
    Second.Action.insert(pair<Keys,Actions>(KeyK,MoveDown));
    Second.Action.insert(pair<Keys,Actions>(KeyL,moveRight));
    Second.Action.insert(pair<Keys,Actions>(KeyJ,MoveLeft));
    Second.Action.insert(pair<Keys,Actions>(KeyU,Pause));

    //third player
    PlayerSetting Third;
    Third.Playerindex = 2;
    Third.Action.insert(pair<Keys,Actions>(Key8,MoveUp));
    Third.Action.insert(pair<Keys,Actions>(Key5,MoveDown));
    Third.Action.insert(pair<Keys,Actions>(Key6,moveRight));
    Third.Action.insert(pair<Keys,Actions>(Key4,MoveLeft));
    Third.Action.insert(pair<Keys,Actions>(Key0,Pause));

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
        map<Keys,Actions>::iterator Finding = WorkingSetting.Action.find(Key);
        if(Finding!=WorkingSetting.Action.end())
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
            for_each(WorkingPlayerSettings.Action.begin(),WorkingPlayerSettings.Action.end(),
                [&NewDirection,&OldKey](pair<Keys,Actions> X){
                    if(X.second==NewDirection)
                        OldKey = X.first;
                });
            WorkingPlayerSettings.Action.erase(OldKey);
            WorkingPlayerSettings.Action.insert(pair<Keys,Actions>(NewKey,NewDirection));
        }
    };

    return Changed;
}

std::map<Keys, Actions> Game::Settings::GetSettingForPlayer(int IndexOfPlayer)
{
    using Exceptions::InvalidArgumentException;
    using namespace std;
    if(IndexOfPlayer<1 || IndexOfPlayer>3)
        throw new InvalidArgumentException("Player with index " + to_string(IndexOfPlayer) + " dont exists",__LINE__,__FILE__);
    map<Keys,Actions> ToReturn;
    for_each(IndividualSetting.begin(),IndividualSetting.end(),[&ToReturn,&IndexOfPlayer](PlayerSetting S){
        if(S.Playerindex==IndexOfPlayer)
            ToReturn = S.Action;
    });
    return ToReturn;
}




