#include "MenuGameState.h"

GameStates::MenuGameState::MenuGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameStates::AbstractGameState* GameStates::MenuGameState::run()
{
    using namespace ViewModel;
    MenuAbstractViewModel* MenuRendering = this->RenderingModel->MenuModel();
    std::vector<MenuAbstractViewModel::MenuEntry> MenuVector;
    map<int, AbstractGameState*> Actions = FillMenu(MenuVector);
    int Choosed = MenuRendering->ShowMenu(MenuVector);
    return Actions.at(Choosed);
}

void GameStates::MenuGameState::AddStates(MultiplayerGameState* Multi, SingleplayerGameState* Single,
                                         NetGameState* OverNet, EndState* End, SettingsState* Settting)
{
    this->Multi = Multi;
    this->Single = Single;
    this->Net = OverNet;
    this->End = End;
    this->Settings = Settting;
}

map<int,GameStates::AbstractGameState*> GameStates::MenuGameState::FillMenu(vector<ViewModel::MenuAbstractViewModel::MenuEntry>& VectorWithMenu)
{
    using ViewModel::MenuAbstractViewModel;
    using std::vector;
    using std::map;

    MenuAbstractViewModel::MenuEntry LanguageChange = {0,"SettingsMenuEntry"};
    MenuAbstractViewModel::MenuEntry Singleplayer = {1,"SingleplayerMenuEntry"};
    MenuAbstractViewModel::MenuEntry Multiplayer = {2,"MultiplayerMenuEntry"};
    MenuAbstractViewModel::MenuEntry Net = {3,"NetGameMenuEntry"};
    MenuAbstractViewModel::MenuEntry EndEntry = {4,"EndMenuEntry"};

    map<int,AbstractGameState*> MapWithStates;
    MapWithStates.insert(pair<int,AbstractGameState*>(0,this->Settings));
    MapWithStates.insert(pair<int,AbstractGameState*>(1,this->Single));
    MapWithStates.insert(pair<int,AbstractGameState*>(2,this->Multi));
    MapWithStates.insert(pair<int,AbstractGameState*>(3,this->Net));
    MapWithStates.insert(pair<int,AbstractGameState*>(4,this->End));

    VectorWithMenu.push_back(LanguageChange);
    VectorWithMenu.push_back(Singleplayer);
    VectorWithMenu.push_back(Multiplayer);
    VectorWithMenu.push_back(Net);
    VectorWithMenu.push_back(EndEntry);

    return MapWithStates;
}







