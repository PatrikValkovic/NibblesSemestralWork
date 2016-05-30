#include "PlayingState.h"

GameStates::AbstractGameState* GameStates::PlayingState::run()
{
    using Game::Worm;
    using Game::Actions;
    ViewModel::GameAbstractViewModel* Rendering = this->RenderingModel->GameModel();

    while (this->Playing())
    {
        Rendering->RenderGame(this->ContentOfGame);

        this->RunTasks();

        if (!this->ProccessEvents())
            return this->Pause;
        this->MoveWorms();
        this->CheckCollisions();
    }
    return NULL;
}

GameStates::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::PlayingState::AddStates(MenuGameState* MenuState, GamePauseState* PauseState)
{
    this->Menu = MenuState;
    this->Pause = PauseState;
}

void GameStates::PlayingState::ClearContent(Game::GameContent* NewContent)
{
    delete ContentOfGame;
    ContentOfGame = NewContent;
    ContentOfGame->GenerateFood();
}

GameStates::PlayingState::~PlayingState()
{
    delete ContentOfGame;
}

void GameStates::PlayingState::ValidatePositionsOfWorms()
{
    vector<Worm*> WormsToRender(this->ContentOfGame->Worms.begin(), this->ContentOfGame->Worms.end());

    vector<Worm*>::iterator Moving = WormsToRender.begin();
    vector<Worm*>::iterator End = WormsToRender.end();
    for (; Moving != End; Moving++)
        (*Moving)->ValidatePosition(this->ContentOfGame->Ground->GetWidth(),
                                    this->ContentOfGame->Ground->GetHeight());
}

void GameStates::PlayingState::MoveWorms()
{
    for_each(this->ContentOfGame->Worms.begin(), this->ContentOfGame->Worms.end(), [](Worm* W) {
        W->Move(W->GetMoveDirection());
    });

    this->ValidatePositionsOfWorms();
}

bool GameStates::PlayingState::ProccessEvents()
{
    return this->ContentOfGame->Events.ProccessEvents();
}

void GameStates::PlayingState::CheckCollisions()
{
    using std::vector;
    using Game::Point;
    using Game::Worm;
    //prepare collision map
    char** Canvas = this->ContentOfGame->CreateArrayForGame();

    //fill it with walls
    vector<Point> Walls = this->ContentOfGame->Ground->GetWalls();
    for_each(Walls.begin(), Walls.end(), [&Canvas](Point W) {
        Canvas[W.GetPositionY()][W.GetPositionX()] = 'W';
    });
    //fill it with snake's tails
    vector<Worm*> Worms(this->ContentOfGame->Worms.begin(), this->ContentOfGame->Worms.end());
    for_each(Worms.begin(), Worms.end(), [&Canvas](Worm* Snake) {
        if (!Snake->IsPlaying())
            return;
        vector<Worm::Segment> Segments = Snake->GetSegment();
        for_each(++(Segments.begin()), Segments.end(), [&Canvas](Worm::Segment S) {
            Canvas[S.GetPositionY()][S.GetPositionX()] = 'S';
        });
    });

    //fill grub
    Canvas[this->ContentOfGame->GetFood().GetPositionY()]
    [this->ContentOfGame->GetFood().GetPositionX()] = 'G';

    //check heads
    for_each(Worms.begin(), Worms.end(), [&Canvas, this](Worm* Snake) {
        Worm::Segment HeadSegment = Snake->GetSegment().at(0);
        if (Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()] == 'G')
        {
            Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()] = 'H';
            Snake->IncrementSize();
            this->ContentOfGame->GenerateFood();
        }
        else if (Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()] != 0)
            Snake->StopPlaying();
        else
            Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()] = 'H';
    });

    //delete collision map
    this->ContentOfGame->DeleteArrayForGame(Canvas);
}

void GameStates::PlayingState::RunTasks()
{
    using Game::Task::BaseTask;
    for_each(this->ContentOfGame->Tasks.begin(), this->ContentOfGame->Tasks.end(), [](BaseTask* X) {
        X->run();
    });
}

bool GameStates::PlayingState::Playing()
{
    using namespace std;
    vector<Worm*>::iterator Moving = ContentOfGame->Worms.begin();
    vector<Worm*>::iterator End = ContentOfGame->Worms.end();
    return this->ContentOfGame != NULL && find_if(Moving,End,[](Worm* W){
        return W->IsPlaying();
    }) != End;
}























