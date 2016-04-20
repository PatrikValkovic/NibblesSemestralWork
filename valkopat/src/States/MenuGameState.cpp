#include "MenuGameState.h"

GameState::MenuGameState::MenuGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

GameState::AbstractGameState* GameState::MenuGameState::run()
{
    using namespace ViewModel;
    MenuAbstractViewModel* MenuRendering = this->RenderingModel->MenuModel();
    std::vector<MenuAbstractViewModel::MenuEntry> MenuVector;
    map<int, AbstractGameState*> Actions = FillMenu(MenuVector);
    int Choosed = MenuRendering->ShowMenu(MenuVector);
    return Actions.at(Choosed);
}

void GameState::MenuGameState::AddStates(MultiplayerGameState* Multi, SingleplayerGameState* Single,
                                         NetGameState* OverNet, EndState* End, ChangeLanguageState* Language)
{
    this->Multi = Multi;
    this->Single = Single;
    this->Net = OverNet;
    this->End = End;
    this->Language = Language;
}

map<int,GameState::AbstractGameState*> GameState::MenuGameState::FillMenu(vector<ViewModel::MenuAbstractViewModel::MenuEntry>& VectorWithMenu)
{
    using ViewModel::MenuAbstractViewModel;
    using std::vector;
    using std::map;

    MenuAbstractViewModel::MenuEntry LanguageChange = {0,"ChangeLangaugeMenuEntry"};
    MenuAbstractViewModel::MenuEntry Singleplayer = {1,"SingleplayerMenuEntry"};
    MenuAbstractViewModel::MenuEntry Multiplayer = {2,"MultiplayerMenuEntry"};
    MenuAbstractViewModel::MenuEntry Net = {3,"NetGameMenuEntry"};
    MenuAbstractViewModel::MenuEntry EndEntry = {4,"EndMenuEntry"};

    map<int,AbstractGameState*> MapWithStates;
    MapWithStates.insert(pair<int,AbstractGameState*>(0,this->Language));
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







