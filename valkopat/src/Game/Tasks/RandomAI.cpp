#include "RandomAI.h"

void Game::Task::RandomAI::run()
{
    using std::set;

    char** Canvas = this->ContentOfGame->CreateArrayForGame();

    vector<Point> Walls = this->ContentOfGame->Ground->GetWalls();
    for_each(Walls.begin(), Walls.end(), [&Canvas](Point W) {
        Canvas[W.GetPositionY()][W.GetPositionX()] = 'W';
    });

    vector<Worm::Segment> Segments = this->ControlledWorm->GetSegment();
    for_each(++Segments.begin(), Segments.end(), [&Canvas](Worm::Segment S) {
        Canvas[S.GetPositionY()][S.GetPositionX()] = 'S';
    });

    set<Directions> AviableDirections = {Directions::Up, Directions::Down, Directions::Left, Directions::Right};
    Worm::Segment HeadSegment = this->ControlledWorm->GetSegment().at(0);
    while (true)
    {
        int NextMove = rand() % (int) AviableDirections.size();
        set<Directions>::iterator MoveIter = AviableDirections.begin();
        for (int a = 0; a < NextMove; a++)
            MoveIter++;

        int DownMove;
        int RightMove;
        this->ControlledWorm->DecideDirection(*MoveIter, DownMove, RightMove);

        int NewYPosition = (HeadSegment.GetPositionY() + DownMove) % this->ContentOfGame->Ground->GetHeight();
        NewYPosition = NewYPosition < 0 ? this->ContentOfGame->Ground->GetHeight() - 1 : NewYPosition;
        int NewXPosition = (HeadSegment.GetPositionX() + RightMove) % this->ContentOfGame->Ground->GetWidth();
        NewXPosition = NewXPosition < 0 ? this->ContentOfGame->Ground->GetWidth() - 1 : NewXPosition;

        if (Canvas[NewYPosition][NewXPosition] == 0)
        {
            this->ControlledWorm->SetMoveDirection(*MoveIter);
            break;
        }
        AviableDirections.erase(MoveIter);
    }
    this->ContentOfGame->DeleteArrayForGame(Canvas);
}

Game::Task::RandomAI::RandomAI(Worm* AIWorm, GameContent* Content)
        : BaseAITask(AIWorm,Content)
{ }

BaseAITask* Game::Task::RandomAI::CreateInstance(Worm* WormToControl, GameContent* Game)
{
    return new RandomAI(WormToControl,Game);
}





