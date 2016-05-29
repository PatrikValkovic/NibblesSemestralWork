#include "Worm.h"

std::vector<Game::Worm::Segment> Game::Worm::GetSegment() const
{
    return this->Segments;
}

Game::Worm::Worm(int PositionX, int PositionY, Actions Direction, int Id)
    : Segments(), MoveDirection(Direction), Id(Id)
{
    int RightAdding = 0;
    int DownAdding = 0;

    DecideDirection(Direction,DownAdding,RightAdding);
    RightAdding *= -1; DownAdding *= -1;

    for(int a=0;a<SizeAtBegin;a++)
        Segments.push_back(Segment(PositionX + a*RightAdding,PositionY+a*DownAdding));
}

#include <iostream>
void Game::Worm::Move(Actions Direction)
{
    if(!IsPlaying())
        return;

    using namespace std;

    for(int a=(int)this->Segments.size()-1;a>=1;a--)
        Segments[a] = Segments[a-1];

    int DownMove;
    int RightMove;
    DecideDirection(Direction,DownMove,RightMove);


    Segments[0].SetPositionY(Segments[0].GetPositionY()+DownMove);
    Segments[0].SetPositionX(Segments[0].GetPositionX()+RightMove);

}

void Game::Worm::DecideDirection(Actions Direction, int& Down, int& Right) const
{
    Down = 0;
    Right = 0;
    if(Direction==Actions::MoveLeft)
        Right = -1;
    else if (Direction==Actions::moveRight)
        Right = 1;
    else if (Direction == Actions::MoveUp)
        Down = -1;
    else if (Direction == Actions::MoveDown)
        Down = 1;
}

std::string Game::Worm::GetName() const
{
    return this->name;
}

void Game::Worm::SetName(std::string NewName)
{
    this->name = NewName;
}

void Game::Worm::ValidatePosition(int MaxWidth, int MaxHeight)
{
    if(!IsPlaying())
        return;

    if(this->Segments[0].GetPositionX()<0)
        this->Segments[0].SetPositionX(MaxWidth-1);
    else if(this->Segments[0].GetPositionX()>=MaxWidth)
        this->Segments[0].SetPositionX(0);


    if(this->Segments[0].GetPositionY()<0)
        this->Segments[0].SetPositionY(MaxHeight-1);
    else if(this->Segments[0].GetPositionY()>=MaxHeight)
        this->Segments[0].SetPositionY(0);
}

void Game::Worm::SetMoveDirection(Game::Actions Direction)
{
    this->MoveDirection = Direction;
}

Game::Actions Game::Worm::GetMoveDirection() const
{
    return this->MoveDirection;
}

bool Game::Worm::IsPlaying()
{
    return this->Playing;
}

void Game::Worm::StopPlaying()
{
    this->Playing = false;
}

void Game::Worm::IncrementSize()
{
    using std::vector;
    vector<Segment>::iterator SegmentsIter =  this->Segments.end();
    Segment LastSegment = *(--SegmentsIter);
    Segment LastButOneSegment = *(--SegmentsIter);

    int MoveRight = LastButOneSegment.GetPositionX() - LastButOneSegment.GetPositionX();
    int MoveDown = LastButOneSegment.GetPositionY() - LastButOneSegment.GetPositionY();
    Segment CreatedSegment = LastSegment;
    LastSegment.SetPositionX(LastSegment.GetPositionX()-MoveRight);
    LastSegment.SetPositionY(LastSegment.GetPositionY()-MoveDown);

    this->Segments.push_back(CreatedSegment);
}

int Game::Worm::GetId()
{
    return this->Id;
}

























