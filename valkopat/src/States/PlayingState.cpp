#include "PlayingState.h"

const int GameStates::PlayingState::WaitingTimeInMiliseconds = 1500;

GameStates::AbstractGameState* GameStates::PlayingState::run()
{
    using Game::Worm;
    using Game::Directions;
    ViewModel::GameAbstractViewModel* Rendering = this->RenderingModel->GameModel();

    vector<Worm*> WormsToRender(this->ContentOfGame->Worms.begin(),this->ContentOfGame->Worms.end());
    WormsToRender.push_back(this->ContentOfGame->Player);
    while(true)
    {
        Rendering->RenderGame(this->ContentOfGame);

        this->WaitToNextTurn();

        if(!this->ProccessEvents())
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
}

GameStates::PlayingState::~PlayingState()
{
    delete ContentOfGame;
}

void GameStates::PlayingState::ValidatePositionsOfWorms()
{
    vector<Worm*> WormsToRender(this->ContentOfGame->Worms.begin(),this->ContentOfGame->Worms.end());
    WormsToRender.push_back(this->ContentOfGame->Player);

    vector<Worm*>::iterator Moving = WormsToRender.begin();
    vector<Worm*>::iterator End = WormsToRender.end();
    for(;Moving!=End;Moving++)
        (*Moving)->ValidatePosition(this->ContentOfGame->Ground->GetWidth(),
                                    this->ContentOfGame->Ground->GetHeight());
}

void GameStates::PlayingState::WaitToNextTurn()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    time_point<system_clock> BeginOfMethod = system_clock::now();

    sleep_until(BeginOfMethod + milliseconds(WaitingTimeInMiliseconds));
}

void GameStates::PlayingState::MoveWorms()
{
    this->ContentOfGame->Player->Move(this->ContentOfGame->Player->GetMoveDirection());
    for_each(this->ContentOfGame->Worms.begin(),this->ContentOfGame->Worms.end(),[](Worm* W)
    {
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
    char** Canvas = new char*[this->ContentOfGame->Ground->GetHeight()];
    for(int a=0;a<this->ContentOfGame->Ground->GetHeight();a++)
    {
        Canvas[a] = new char[this->ContentOfGame->Ground->GetWidth()];
        for(int b=0;b<this->ContentOfGame->Ground->GetWidth();b++)
            Canvas[a][b] = 0;
    }

    //fill it with walls
    vector<Point> Walls = this->ContentOfGame->Ground->GetWalls();
    for_each(Walls.begin(),Walls.end(),[&Canvas](Point W){
        Canvas[W.GetPositionY()][W.GetPositionX()] = 'W';
    });
    //fill it with snake's tails
    vector<Worm*> Worms(this->ContentOfGame->Worms.begin(),this->ContentOfGame->Worms.end());
    Worms.push_back(this->ContentOfGame->Player);
    for_each(Worms.begin(),Worms.end(),[&Canvas](Worm* Snake){
        if(!Snake->IsPlaying())
            return;
        vector<Worm::Segment> Segments = Snake->GetSegment();
        for_each(++(Segments.begin()),Segments.end(),[&Canvas](Worm::Segment S) {
            Canvas[S.GetPositionY()][S.GetPositionX()] = 'S';
        });
    });

    //fill grub
    Canvas[this->ContentOfGame->GetGrub().GetPositionY()]
          [this->ContentOfGame->GetGrub().GetPositionX()] = 'G';

    //check heads
    for_each(Worms.begin(),Worms.end(),[&Canvas](Worm* Snake){
        Worm::Segment HeadSegment = Snake->GetSegment().at(0);
        if(Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()]=='G')
        {
            
        }
        else if(Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()]!=0)
            Snake->StopPlaying();
        else
            Canvas[HeadSegment.GetPositionY()][HeadSegment.GetPositionX()] = 'H';
    });

    //delete collision map
    for(int a=0;a<this->ContentOfGame->Ground->GetHeight();a++)
        delete [] Canvas[a];
    delete [] Canvas;
}





















