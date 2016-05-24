#include "BFSAI.h"


void Game::Task::BFSAI::run()
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




    this->ContentOfGame->DeleteArrayForGame(Canvas);
}

Game::Task::BFSAI::BFSAI(Worm* AIWorm, GameContent* Content)
        : ControlledWorm(AIWorm), ContentOfGame(Content)
{ }
