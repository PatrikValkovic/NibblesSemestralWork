#include "Worm.h"

std::vector<Game::Worm::Segment> Game::Worm::GetSegment() const
{
    return this->Segments;
}

Game::Worm::Worm(int PositionX, int PositionY, Directions Direction)
{
    int RightAdding = 0;
    int DownAdding = 0;

    DecideDirection(Direction,DownAdding,RightAdding);
    RightAdding *= -1; DownAdding *= -1;

    for(int a=0;a<SizeAtBegin;a++)
        Segments.push_back(Segment(PositionX + a*RightAdding,PositionY+a*DownAdding));
}

void Game::Worm::Move(Directions Direction)
{
    using namespace std;

    vector<Segment>::reverse_iterator First = Segments.rbegin();
    vector<Segment>::reverse_iterator Before = Segments.rbegin();
    Before++;
    vector<Segment>::reverse_iterator End = Segments.rend();
    for(;Before!=End;Before++, First++)
        *End = *Before;

    int DownMove;
    int RightMove;
    DecideDirection(Direction,DownMove,RightMove);

    vector<Segment>::iterator FirstSegment = Segments.begin();
    FirstSegment->SetPositionX(FirstSegment->GetPositionX() + RightMove);
    FirstSegment->SetPositionY(FirstSegment->GetPositionY()+DownMove);
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







