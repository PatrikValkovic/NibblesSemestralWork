#include "PlaygroundFactory.h"

Game::PlayGround* Game::PlaygroundFactory::GetLevel(int Level)
{
    switch(Level)
    {
        case 1:
            return FirstLevel();
        case 2:
            return SecondLevel();
        default:
            throw new Exceptions::OutOfRangeException();
    }
    return NULL;
}

Game::PlayGround* Game::PlaygroundFactory::FirstLevel()
{
    PlayGround* Area = new PlayGround();
    Area->Height = 11;
    Area->Width = 15;
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4,5),Directions::Right});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10,8),Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10,5),Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4,8),Directions::Right});

    return Area;
}

Game::PlayGround* Game::PlaygroundFactory::SecondLevel()
{
    PlayGround* Area = new PlayGround();
    Area->Height = 11;
    Area->Width = 15;

    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4,5),Directions::Right});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10,8),Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10,5),Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4,8),Directions::Right});


    for(int a=0;a<Area->Width;a++)
    {
        Area->Walls.push_back(Point(a,0));
        Area->Walls.push_back(Point(a,Area->Height-1));
    }
    for(int a=1;a<Area->Height-1;a++)
    {
        Area->Walls.push_back(Point(0,a));
        Area->Walls.push_back(Point(Area->Width-1,a));
    }
    //Area->Walls.push_back(Point());

    return Area;
}

map<int,string> Game::PlaygroundFactory::GetCountOfAviableLevels()
{
    map<int,string> Levels;
    Levels.insert(pair<int,string>(1,"ClearMap"));
    Levels.insert(pair<int,string>(2,"BorderedMap"));
    return Levels;
}







