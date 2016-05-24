#include "BFSAI.h"


void Game::Task::BFSAI::run()
{
    using std::set;

    //create map
    uint32_t** Canvas = new uint32_t* [this->ContentOfGame->Ground->GetHeight()];
    for (int a = 0; a < this->ContentOfGame->Ground->GetHeight(); a++)
    {
        Canvas[a] = new uint32_t[this->ContentOfGame->Ground->GetWidth()];
        for (int b = 0; b < this->ContentOfGame->Ground->GetWidth(); b++)
            Canvas[a][b] = 0;
    }

    //fill walls
    vector<Point> Walls = this->ContentOfGame->Ground->GetWalls();
    for_each(Walls.begin(), Walls.end(), [&Canvas](Point W) {
        Canvas[W.GetPositionY()][W.GetPositionX()] = numeric_limits<uint32_t>::max();
    });

    //fill self
    vector<Worm::Segment> Segments = this->ControlledWorm->GetSegment();
    for_each(++Segments.begin(), Segments.end(), [&Canvas](Worm::Segment S) {
        Canvas[S.GetPositionY()][S.GetPositionX()] = numeric_limits<uint32_t>::max();
    });

    Directions NewMove = this->BFS(Canvas, (Point) this->ControlledWorm->GetSegment().at(0),
                                   this->ContentOfGame->GetFood());

    this->ControlledWorm->SetMoveDirection(NewMove);

    //delete
    for (int a = 0; a < this->ContentOfGame->Ground->GetHeight(); a++)
        delete[] Canvas[a];
    delete[] Canvas;
}

Game::Task::BFSAI::BFSAI(Worm* AIWorm, GameContent* Content)
        : ControlledWorm(AIWorm), ContentOfGame(Content)
{ }

#include <iostream>

Game::Directions Game::Task::BFSAI::BFS(uint32_t** map, Game::Point BeginOfSearch, Game::Point EndPoint)
{
    using Game::Point;
    using std::queue;
    using std::set;
    using std::vector;

    queue<Point> Searching;

    Searching.push(BeginOfSearch);

    //construct BFS tree
    while (!Searching.empty())
    {
        Point WorkingPoint = Searching.front();
        Searching.pop();

        if (WorkingPoint == EndPoint)
            break;

        vector<Point> PointsAround = GeneratePointsAround(WorkingPoint);
        for_each(PointsAround.begin(), PointsAround.end(), [&map, &WorkingPoint, &Searching](Point P) {
            if (map[P.GetPositionY()][P.GetPositionX()] == 0)
            {
                map[P.GetPositionY()][P.GetPositionX()] =
                        map[WorkingPoint.GetPositionY()][WorkingPoint.GetPositionX()] + 1;
                Searching.push(P);
            }
        });
    }

    //find path back
    Point Working = EndPoint;
    while (map[Working.GetPositionY()][Working.GetPositionX()] != 1)
    {
        Point temp;
        vector<Point> PointsAround = GeneratePointsAround(Working);
        for_each(PointsAround.begin(), PointsAround.end(), [&map, &temp,&Working](Point P) {
            if (map[P.GetPositionY()][P.GetPositionX()] == map[Working.GetPositionY()][Working.GetPositionX()]-1)
                temp = P;
        });
        Working = temp;
    }

    return this->ResolveDirection(BeginOfSearch, Working);
}

std::vector<Game::Point> Game::Task::BFSAI::GeneratePointsAround(Game::Point AroundToGenerate)
{
    using std::set;
    using Game::Point;
    using std::vector;

    vector<Point> Points{
            Point(AroundToGenerate.GetPositionX(), AroundToGenerate.GetPositionY() - 1),
            Point(AroundToGenerate.GetPositionX(),
                  (AroundToGenerate.GetPositionY() + 1) % ContentOfGame->Ground->GetHeight()),
            Point(AroundToGenerate.GetPositionX() - 1, AroundToGenerate.GetPositionY()),
            Point((AroundToGenerate.GetPositionX() + 1) % ContentOfGame->Ground->GetWidth(),
                  AroundToGenerate.GetPositionY())
    };

    vector<Point>::iterator Moving = Points.begin();
    vector<Point>::iterator End = Points.end();
    for (; Moving != End; Moving++)
    {
        Moving->SetPositionY(Moving->GetPositionY() < 0 ?
                             ContentOfGame->Ground->GetHeight() - 1 :
                             Moving->GetPositionY());
        Moving->SetPositionX(Moving->GetPositionX() < 0 ?
                             ContentOfGame->Ground->GetWidth() - 1 :
                             Moving->GetPositionX());
    }
    return Points;
}

Game::Directions Game::Task::BFSAI::ResolveDirection(Point From, Point To)
{
    if (From.GetPositionX() == To.GetPositionX() + 1 &&
        From.GetPositionY() == To.GetPositionY())
        return Directions::Left;
    else if (From.GetPositionX() == To.GetPositionX() - 1 &&
             From.GetPositionY() == To.GetPositionY())
        return Directions::Right;
    else if (From.GetPositionX() == To.GetPositionX() &&
             From.GetPositionY() == To.GetPositionY() + 1)
        return Directions::Up;
    else if (From.GetPositionX() == To.GetPositionX() &&
             From.GetPositionY() == To.GetPositionY() - 1)
        return Directions::Down;

    //TODO Specific case, where are Points on the other side of map

    return Directions::Left;
}






