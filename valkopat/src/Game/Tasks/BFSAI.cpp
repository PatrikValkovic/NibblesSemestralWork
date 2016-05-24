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

Directions Game::Task::BFSAI::BFS(uint32_t** map, Game::Point BeginOfSearch, Game::Point EndPoint) const
{
    using Game::Point;
    using std::queue;
    using std::set;

    queue<Point> Searching;
    set<Point> Closed;

    Searching.push(BeginOfSearch);

    while(!Searching.empty())
    {
        Point WorkingPoint = Searching.front();
        Searching.pop;

        if(Closed.find(WorkingPoint)==Closed.end())
            continue;
        if(WorkingPoint == EndPoint)
            break;

        set<Point> PointsAround = GeneratePointsAround(WorkingPoint);
    }

    return Down;
}

set<Point> Game::Task::BFSAI::GeneratePointsAround(Point AroundToGenerate) const
{
    set<Point> Points{
            Point(AroundToGenerate.GetPositionX(),AroundToGenerate.GetPositionY()-1),
            Point(AroundToGenerate.GetPositionX(),AroundToGenerate.GetPositionY()+1),
            Point(AroundToGenerate.GetPositionX()-1,AroundToGenerate.GetPositionY()),
            Point(AroundToGenerate.GetPositionX()+1,AroundToGenerate.GetPositionY())
    };

    set<Point>::iterator Moving = Points.begin();
    set<Point>::iterator End = Points.end();
    for(;Moving!=End;Moving++)
    {
        Moving->SetPositionY(Moving->GetPositionY() < 0 ?
                             this->ContentOfGame->Ground->GetHeight() - 1 :
                             Moving->GetPositionY());
        Moving->SetPositionX(Moving->GetPositionX() < 0 ?
                             this->ContentOfGame->Ground->GetWidth() - 1 :
                             Moving->GetPositionX());
    }
    return Points;
}




