#include "GameContent.h"

Game::GameContent::~GameContent()
{
    std::for_each(Worms.begin(),Worms.end(),[](Worm* X){
        delete X;
    });
    delete Ground;
    delete Player;
    Events.DeleteAllEvents();

    Ground = NULL;
    Player = NULL;
}

Game::GameContent::GameContent(vector<Worm*> Worms,Worm* Player, PlayGround* Playground)
        : Ground(Playground), Player(Player)
{
    this->Worms = Worms;
}

Game::Point Game::GameContent::GetGrub() const
{
    return this->Grub;
}
void Game::GameContent::GenerateGrub()
{
    using std::vector;
    using Game::Point;
    using Game::Worm;
    //prepare collision map
    char** Canvas = new char*[this->Ground->GetHeight()];
    for(int a=0;a<this->Ground->GetHeight();a++)
    {
        Canvas[a] = new char[this->Ground->GetWidth()];
        for(int b=0;b<this->Ground->GetWidth();b++)
            Canvas[a][b] = 0;
    }

    //fill it with walls
    vector<Point> Walls = this->Ground->GetWalls();
    for_each(Walls.begin(),Walls.end(),[&Canvas](Point W){
        Canvas[W.GetPositionY()][W.GetPositionX()] = 'W';
    });

    //fill it with snakes
    vector<Worm*> Worms(this->Worms.begin(),this->Worms.end());
    Worms.push_back(this->Player);
    for_each(Worms.begin(),Worms.end(),[&Canvas](Worm* Snake){
        if(!Snake->IsPlaying())
            return;
        vector<Worm::Segment> Segments = Snake->GetSegment();
        for_each(Segments.begin(),Segments.end(),[&Canvas](Worm::Segment S) {
            Canvas[S.GetPositionY()][S.GetPositionX()] = 'S';
        });
    });

    int CountOfFreeTiles = 0;
    for(int a=0;a<this->Ground->GetHeight();a++)
        for(int b=0;b<this->Ground->GetWidth();b++)
            if(Canvas[a][b]==0)
                CountOfFreeTiles++;

    int IndexOfNewGrub = rand() % CountOfFreeTiles;
    for(int a=0;a<this->Ground->GetHeight();a++)
        for(int b=0;b<this->Ground->GetWidth();b++)
        {
            if(Canvas[a][b]==0)
                IndexOfNewGrub--;
            else if(IndexOfNewGrub==0 && Canvas[a][b]==0)
                Grub = Point(a,b);
        }
}







