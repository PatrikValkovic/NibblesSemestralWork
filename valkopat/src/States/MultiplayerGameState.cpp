#include "MultiplayerGameState.h"
//TODO remove
#include "../ViewModels/CONSOLE/MultiplayerConsoleViewModel.h"

GameStates::AbstractGameState* GameStates::MultiplayerGameState::run()
{
    using namespace Game;
    using ViewModel::MultiplayerConsoleViewModel;
    using Game::AIFactory;
    using Game::Event::Single;
    using Game::Task::WaitingTask;
    using Game::Task::BaseAITask;
    using Game::Task::DiscardingInput;

    MultiplayerConsoleViewModel* Rendering = (MultiplayerConsoleViewModel*) this->RenderingModel->MultiplayerModel();
    string Level = Rendering->Level();
    PlayGround* NewPlayground = PlaygroundFactory::GetLevel(Level);

    GameContent* NewGameContent = new GameContent();

    int CountOfPlayer = Rendering->CountOfPlayers(min(NewPlayground->CountOfStartPositions(), 3));
    vector<Worm*> Players;
    for (int a = 0; a < CountOfPlayer; a++)
    {
        PlayGround::StartPosition StartPositionForPlayer = NewPlayground->GetNextStartPosition();
        Worm* WorkingPlayer = new Worm(StartPositionForPlayer.Position.GetPositionX(),
                                       StartPositionForPlayer.Position.GetPositionY(),
                                       StartPositionForPlayer.Direction);
        WorkingPlayer->SetName(Rendering->NameOfPlayer(a));
    }

    this->PlayState->ClearContent(NewGameContent);

    return this->PlayState;
}

GameStates::MultiplayerGameState::MultiplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::MultiplayerGameState::AddStates(PlayingState* PlayState, MenuGameState* MenuState)
{
    this->PlayState = PlayState;
    this->Menu = MenuState;
}
