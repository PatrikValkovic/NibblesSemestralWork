#include "SingleplayerGameState.h"

GameStates::AbstractGameState* GameStates::SingleplayerGameState::run()
{
    using namespace Game;
    using ViewModel::SingleplayerMenuAbstractViewModel;
    using Game::AIFactory;
    using Game::Event::Single;
    using Game::Task::WaitingTask;
    using Game::Task::BaseAITask;
    using Game::Task::DiscardingInput;


    SingleplayerMenuAbstractViewModel* View = this->RenderingModel->SingleplayerModel();

    string NameOfUser = View->NameOfPlayer();

    string Level = View->Level();
    PlayGround* Round = PlaygroundFactory::GetLevel(Level);

    int CountOfAI = View->CountOfAI(Round->CountOfStartPositions() - 1);

    //fill to game
    PlayGround::StartPosition PlayerStartPosition = Round->GetNextStartPosition();
    Worm* Player = new Worm(PlayerStartPosition.Position.GetPositionX(),
                            PlayerStartPosition.Position.GetPositionY(),
                            PlayerStartPosition.Direction);
    Player->SetName(NameOfUser);

    vector<Worm*> AI;
    for (int a = 0; a < CountOfAI; a++)
    {
        PlayGround::StartPosition Starting = Round->GetNextStartPosition();
        Worm* TempWorm = new Worm(Starting.Position.GetPositionX(),
                                  Starting.Position.GetPositionY(),
                                  Starting.Direction);
        char Name[6];
        sprintf(Name, "AI %d", a);
        TempWorm->SetName(string(Name));
        TempWorm->SetName(Name);

        AI.push_back(TempWorm);
    }

    GameContent* NewContent = new GameContent(AI, Player, Round);

    //create events
    Single* SingleEvent = new Single(Player, this->RenderingModel->InputModel(), 0, Settings::GetInstance());
    NewContent->Events.AddEvent(SingleEvent);

    //create TasksForAI
    WaitingTask* WaitTask = new WaitingTask();
    DiscardingInput* DiscardingInputTask = new DiscardingInput(this->RenderingModel->InputModel());
    NewContent->Tasks.push_back(WaitTask);
    NewContent->Tasks.push_back(DiscardingInputTask);
    //create tasks for AI
    string AILevel = View->LevelOfAI(AIFactory::GetInstance()->GetNamesOfAILevels());
    vector<BaseAITask*> TasksForAI = AIFactory::GetInstance()->CreatesTaskForWorms(AI,
                                                               NewContent,
                                                               AILevel);
    for_each(TasksForAI.begin(), TasksForAI.end(), [&NewContent](BaseAITask* T) {
        NewContent->Tasks.push_back(T);
    });

    //fill it to game
    this->Play->ClearContent(NewContent);

    return this->Play;
}

GameStates::SingleplayerGameState::SingleplayerGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::SingleplayerGameState::AddStates(PlayingState* GameState, MenuGameState* MenuState)
{
    this->Play = GameState;
    this->Menu = MenuState;
}




