#include "RandomAI.h"

void Game::Task::RandomAI::run()
{
    using std::set;

    char** Canvas = this->ContentOfGame->CreateArrayForGame();

    vector<Point> Walls = this->ContentOfGame->Ground->GetWalls();
    for_each(Walls.begin(),Walls.end(),[&Canvas](Point W){
        Canvas[W.GetPositionY()][W.GetPositionX()] = 'W';
    });

    vector<Worm::Segment> Segments = this->ControlledWorm->GetSegment();
    for_each(++Segments.begin(),Segments.end(),[&Canvas](Worm::Segment S){
       Canvas[S.GetPositionY()][S.GetPositionX()] = 'S';
    });

    set<Directions> AviableDirections = {Directions::Up, Directions::Down, Directions::Left, Directions::Right};
    Worm::Segment HeadSegment = this->ControlledWorm->GetSegment().at(0);
    while(true)
    {
        int NextMove = rand() % AviableDirections.size();
        set<Directions>::iterator MoveIter = AviableDirections.begin();
        for(int a=0;a<NextMove;a++)
            MoveIter++;

        int DownMove;
        int RightMove;
        this->ControlledWorm->DecideDirection(*MoveIter,DownMove,RightMove);

        if(Canvas[HeadSegment.GetPositionY()+DownMove][HeadSegment.GetPositionX()+RightMove]==0)
        {
            this->ControlledWorm->SetMoveDirection(*MoveIter);
            break;
        }
        AviableDirections.erase(MoveIter);
    }
    this->ContentOfGame->DeleteArrayForGame(Canvas);
}

Game::Task::RandomAI::RandomAI(Worm* AIWorm, GameContent* Content)
        : ControlledWorm(AIWorm), ContentOfGame(Content)
{ }



