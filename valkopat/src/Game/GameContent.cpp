#include "GameContent.h"

Game::GameContent::~GameContent()
{
    using Game::Task::BaseTask;
    std::for_each(Worms.begin(), Worms.end(), [](Worm* X) {
        delete X;
    });
    std::for_each(Tasks.begin(), Tasks.end(), [](BaseTask* X) {
        delete X;
    });
    delete Ground;
    delete Player;
    Events.DeleteAllEvents();

    Ground = NULL;
    Player = NULL;
}

Game::GameContent::GameContent(vector<Worm*> Worms, Worm* Player, PlayGround* Playground)
        : Ground(Playground), Player(Player)
{
    this->Worms = Worms;
}

Game::Point Game::GameContent::GetFood() const
{
    return this->Food;
}

void Game::GameContent::GenerateFood()
{
    using std::vector;
    using Game::Point;
    using Game::Worm;
    //prepare collision map
    char** Canvas = new char* [this->Ground->GetHeight()];
    for (int a = 0; a < this->Ground->GetHeight(); a++)
    {
        Canvas[a] = new char[this->Ground->GetWidth()];
        for (int b = 0; b < this->Ground->GetWidth(); b++)
            Canvas[a][b] = 0;
    }

    //fill it with walls
    vector<Point> Walls = this->Ground->GetWalls();
    for_each(Walls.begin(), Walls.end(), [&Canvas](Point W) {
        Canvas[W.GetPositionY()][W.GetPositionX()] = 'W';
    });

    //fill it with snakes
    vector<Worm*> Worms(this->Worms.begin(), this->Worms.end());
    Worms.push_back(this->Player);
    for_each(Worms.begin(), Worms.end(), [&Canvas](Worm* Snake) {
        if (!Snake->IsPlaying())
            return;
        vector<Worm::Segment> Segments = Snake->GetSegment();
        for_each(Segments.begin(), Segments.end(), [&Canvas](Worm::Segment S) {
            Canvas[S.GetPositionY()][S.GetPositionX()] = 'S';
        });
    });

    int CountOfFreeTiles = 0;
    for (int a = 0; a < this->Ground->GetHeight(); a++)
        for (int b = 0; b < this->Ground->GetWidth(); b++)
            if (Canvas[a][b] == 0)
                CountOfFreeTiles++;

    int IndexOfNewGrub = rand() % CountOfFreeTiles;
    bool Cycling = true;
    for (int a = 0; a < this->Ground->GetHeight() && Cycling; a++)
        for (int b = 0; b < this->Ground->GetWidth() && Cycling; b++)
        {
            if (IndexOfNewGrub == 0 && Canvas[a][b] == 0)
            {
                Food = Point(b, a);
                Cycling = false;
            }
            else if (Canvas[a][b] == 0)
                IndexOfNewGrub--;
        }
    return;
}

char** Game::GameContent::CreateArrayForGame()
{
    char** Array = new char*[this->Ground->GetHeight()];
    for(int a=0;a<this->Ground->GetHeight();a++)
    {
        Array[a] = new char[this->Ground->GetWidth()];
        for(int b=0;b<this->Ground->GetWidth();b++)
            Array[a][b] = 0;
    }
    return Array;
}

void Game::GameContent::DeleteArrayForGame(char**& Array)
{
    for(int a=0;a<this->Ground->GetHeight();a++)
        delete [] Array[a];
    delete [] Array;
    Array = NULL;
}











