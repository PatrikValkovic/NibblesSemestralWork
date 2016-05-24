#include "BFSAI.h"


void Game::Task::BFSAI::run()
{
    using std::set;

    //create map
    uint32_t** Canvas = new uint32_t*[this->ContentOfGame->Ground->GetHeight()];
    for(int a=0;a<this->ContentOfGame->Ground->GetHeight();a++)
    {
        Canvas[a] = new uint32_t[this->ContentOfGame->Ground->GetWidth()];
        for(int b=0;b<this->ContentOfGame->Ground->GetWidth();b++)
            Canvas[a][b] = 0;
    }

    //fill walls
    vector<Point> Walls = this->ContentOfGame->Ground->GetWalls();
    for_each(Walls.begin(), Walls.end(), [&Canvas](Point W) {
        Canvas[W.GetPositionY()][W.GetPositionX()] = numeric_limits::max();
    });

    //fill self
    vector<Worm::Segment> Segments = this->ControlledWorm->GetSegment();
    for_each(++Segments.begin(), Segments.end(), [&Canvas](Worm::Segment S) {
        Canvas[S.GetPositionY()][S.GetPositionX()] = numeric_limits::max();
    });

    Directions NewMove = this->BFS(Canvas, (Point) this->ControlledWorm->GetSegment().at(0), this->ContentOfGame->GetFood());
    this->ControlledWorm->SetMoveDirection(NewMove);

    //delete
    for(int a=0;a<this->ContentOfGame->Ground->GetHeight();a++)
        delete [] Canvas[a];
    delete [] Canvas;
}

Game::Task::BFSAI::BFSAI(Worm* AIWorm, GameContent* Content)
        : ControlledWorm(AIWorm), ContentOfGame(Content)
{ }

Directions Game::Task::BFSAI::BFS(uint32_t** map, Point BeginOfSearch, Point EndPoint) const
{
    return Down;
}


