#include "GameStates.h"

GameStates::GameStates::GameStates(ViewModel::BaseViewModel* Model)
    :RenderingModel(Model)
{
    ChangeLanguageState* LanguageScreen = new ChangeLanguageState(this->RenderingModel);
    EndState* EndScreen = new EndState(this->RenderingModel);
    GamePauseState* PauseScreen = new GamePauseState(this->RenderingModel);
    MenuGameState* MenuScreen = new MenuGameState(this->RenderingModel);
    MultiplayerGameState* MultiplayerScreen = new MultiplayerGameState(this->RenderingModel);
    NetGameState* NetScreen = new NetGameState(this->RenderingModel);
    PlayingState* PlayScreen = new PlayingState(this->RenderingModel);
    SingleplayerGameState* SingleScreen = new SingleplayerGameState(this->RenderingModel);
    SplashScreenGameState* SplashScreen = new SplashScreenGameState(this->RenderingModel);

    LanguageScreen->AddStates(MenuScreen);
    EndScreen->AddStates();
    PauseScreen->AddStates(PlayScreen,MenuScreen);
    MenuScreen->AddStates(MultiplayerScreen,SingleScreen,NetScreen,EndScreen,LanguageScreen);
    MultiplayerScreen->AddStates(PlayScreen,MenuScreen);
    NetScreen->AddStates(PlayScreen,MenuScreen);
    PlayScreen->AddStates(MenuScreen,PauseScreen);
    SingleScreen->AddStates(PlayScreen,MenuScreen);
    SplashScreen->AddStates(MenuScreen);


    this->AllStates.push_back(LanguageScreen);
    this->AllStates.push_back(EndScreen);
    this->AllStates.push_back(PauseScreen);
    this->AllStates.push_back(MenuScreen);
    this->AllStates.push_back(MultiplayerScreen);
    this->AllStates.push_back(NetScreen);
    this->AllStates.push_back(PlayScreen);
    this->AllStates.push_back(SingleScreen);
    this->AllStates.push_back(SplashScreen);

    this->First = SplashScreen;
}

GameStates::GameStates::~GameStates()
{
    std::vector<AbstractGameState*>::iterator Moving = this->AllStates.begin();
    std::vector<AbstractGameState*>::iterator End = this->AllStates.end();
    for(;Moving!=End;Moving++)
        delete (*Moving);
}

GameStates::AbstractGameState* GameStates::GameStates::GetFirstState() const
{
    return this->First;
}

void GameStates::GameStates::RemoveContent(Game::GameContent* NewContent)
{

}







