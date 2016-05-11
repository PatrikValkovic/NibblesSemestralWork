#include "SingleplayerGameState.h"

GameStates::AbstractGameState* GameStates::SingleplayerGameState::run()
{
    using namespace Game;
    using ViewModel::SingleplayerMenuAbstractViewModel;
    using ViewModel::GameAbstractViewModel;


    SingleplayerMenuAbstractViewModel* View = this->RenderingModel->SingleplayerModel();

    string NameOfUser = View->NameOfPlayer();

    int Level = View->Level();
    PlayGround* Round = PlaygroundFactory::GetLevel(Level);

    int CountOfAI = View->CountOfAI(Round->CountOfStartPositions()-1);

    //fill to game
    PlayGround::StartPosition PlayerStartPosition = Round->GetNextStartPosition();
    Worm* Player = new Worm(PlayerStartPosition.Position.GetPositionX(),
                            PlayerStartPosition.Position.GetPositionY(),
                            PlayerStartPosition.Direction);

    vector<Worm*> AI;
    for(int a=0;a<CountOfAI;a++)
    {
        PlayGround::StartPosition Starting = Round->GetNextStartPosition();
        Worm* TempWorm = new Worm(Starting.Position.GetPositionX(),
                                Starting.Position.GetPositionY(),
                                Starting.Direction);
        AI.push_back(TempWorm);
    }


    //TODO REMOVE
    using ViewModel::GameConsoleViewModel;
    GameAbstractViewModel* Game = this->RenderingModel->GameModel();
    GameConsoleViewModel* ConsoleGame = (GameConsoleViewModel*)Game;
    AI.push_back(Player);
    ConsoleGame->RenderGame(Round,AI);


    return NULL;
}

GameStates::SingleplayerGameState::SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::SingleplayerGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->Play = GameState;
    this->Menu = MenuState;
}




