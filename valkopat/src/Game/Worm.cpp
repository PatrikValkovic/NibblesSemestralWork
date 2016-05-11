#include "Worm.h"

std::vector<Game::Worm::Segment> Game::Worm::GetSegment() const
{
    return this->Segments;
}

Game::Worm::Worm(int PositionX, int PositionY, Directions Direction)
    : Segments(), MoveDirection(Direction)
{
    int RightAdding = 0;
    int DownAdding = 0;

    DecideDirection(Direction,DownAdding,RightAdding);
    RightAdding *= -1; DownAdding *= -1;

    for(int a=0;a<SizeAtBegin;a++)
        Segments.push_back(Segment(PositionX + a*RightAdding,PositionY+a*DownAdding));
}

#include <iostream>
void Game::Worm::Move(Directions Direction)
{
    using namespace std;

    for(int a=(int)this->Segments.size()-1;a>=1;a--)
        Segments[a] = Segments[a-1];

    int DownMove;
    int RightMove;
    DecideDirection(Direction,DownMove,RightMove);


    Segments[0].SetPositionY(Segments[0].GetPositionY()+DownMove);
    Segments[0].SetPositionX(Segments[0].GetPositionX()+RightMove);

}

void Game::Worm::DecideDirection(Directions Direction, int& Down, int& Right) const
{
    Down = 0;
    Right = 0;
    if(Direction==Directions::Left)
        Right = -1;
    else if (Direction==Directions::Right)
        Right = 1;
    else if (Direction == Directions::Up)
        Down = -1;
    else if (Direction == Directions::Down)
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
    if(this->Segments[0].GetPositionX()<0)
        this->Segments[0].SetPositionX(MaxWidth-1);
    else if(this->Segments[0].GetPositionX()>=MaxWidth)
        this->Segments[0].SetPositionX(0);


    if(this->Segments[0].GetPositionY()<0)
        this->Segments[0].SetPositionY(MaxHeight-1);
    else if(this->Segments[0].GetPositionY()>=MaxHeight)
        this->Segments[0].SetPositionY(0);
}

void Game::Worm::SetMoveDirection(Game::Directions Direction)
{
    this->MoveDirection = Direction;
}

Game::Directions Game::Worm::GetMoveDirection() const
{
    return this->MoveDirection;
}

















