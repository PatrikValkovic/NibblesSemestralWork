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

Directions Game::Task::BFSAI::BFS(uint32_t** map, Game::Point BeginOfSearch, Game::Point EndPoint) const
{
    using Game::Point;
    using std::queue;
    using std::set;

    queue<Point> Searching;

    Searching.push(BeginOfSearch);

    //construct BFS tree
    while (!Searching.empty())
    {
        Point WorkingPoint = Searching.front();
        Searching.pop;

        if (WorkingPoint == EndPoint)
            break;

        set<Point> PointsAround = GeneratePointsAround(WorkingPoint);
        for_each(PointsAround.begin(), PointsAround.end(), [&map, &WorkingPoint, &Searching](Point P) {
            if (map[P.GetPositionY()][P.GetPositionX()] == 0)
            {
                map[P.GetPositionY()][P.GetPositionX()] =
                        map[WorkingPoint.GetPositionY()][WorkingPoint.GetPositionX()] + 1;
                Searching.push(P);
            }
        });
    }

    Point Working = EndPoint;
    while (map[Working.GetPositionY()][Working.GetPositionX()] != 1)
    {
        set<Point> PointsAround = GeneratePointsAround(Working);
        for_each(PointsAround.begin(), PointsAround.end(), [&map, &Working](Point P) {
            if (map[P.GetPositionY()][P.GetPositionX()] == map[Working.GetPositionY()][Working.GetPositionX()] - 1)
                Working = P;
        });
    }

    return this->ResolveDirection(BeginOfSearch, Working);
}

set<Point> Game::Task::BFSAI::GeneratePointsAround(Point AroundToGenerate) const
{
    set<Point> Points{
            Point(AroundToGenerate.GetPositionX(), AroundToGenerate.GetPositionY() - 1),
            Point(AroundToGenerate.GetPositionX(), AroundToGenerate.GetPositionY() + 1),
            Point(AroundToGenerate.GetPositionX() - 1, AroundToGenerate.GetPositionY()),
            Point(AroundToGenerate.GetPositionX() + 1, AroundToGenerate.GetPositionY())
    };

    set<Point>::iterator Moving = Points.begin();
    set<Point>::iterator End = Points.end();
    for (; Moving != End; Moving++)
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

Directions Game::Task::BFSAI::ResolveDirection(Point From, Point To) const
{
    if (From.GetPositionX() == To.GetPositionX()+1 &&
        From.GetPositionY() == To.GetPositionY())
        return Directions::Left;
    else if (From.GetPositionX() == To.GetPositionX()-1 &&
             From.GetPositionY() == To.GetPositionY())
        return Directions::Right;
    else if (From.GetPositionX() == To.GetPositionX() &&
             From.GetPositionY() == To.GetPositionY()+1)
        return Directions::Up;
    else if (From.GetPositionX() == To.GetPositionX() &&
             From.GetPositionY() == To.GetPositionY()-1)
        return Directions::Down;
    throw new Exceptions::InvalidArgumentException("Points are non-adjacent", __LINE__, __FILE__);
}






