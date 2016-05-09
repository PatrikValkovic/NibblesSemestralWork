#include "PlayGround.h"

Game::PlayGround::StartPosition Game::PlayGround::GetNextStartPosition()
{
    if(StartPositionIndex>=StartingPositions.size())
        throw new Exceptions::OutOfRangeException();

    return StartingPositions[StartPositionIndex++];
}

std::vector<Game::Point> Game::PlayGround::GetWalls() const
{
    return Walls;
}

int Game::PlayGround::GetHeight() const
{
    return Height;
}

int Game::PlayGround::GetWidth() const
{
    return Width;
}
