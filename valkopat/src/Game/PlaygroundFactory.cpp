#include "PlaygroundFactory.h"

Game::PlayGround* Game::PlaygroundFactory::GetLevel(string Level)
{
    if (Level == "ClearMap")
        return FirstLevel();
    else if (Level == "BorderedMap")
        return SecondLevel();
    else
        throw new Exceptions::OutOfRangeException();
    return NULL;
}

Game::PlayGround* Game::PlaygroundFactory::FirstLevel()
{
    PlayGround* Area = new PlayGround();
    Area->Height = 11;
    Area->Width = 15;
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 2), Directions::Right});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 8), Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 2), Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 8), Directions::Right});

    return Area;
}

Game::PlayGround* Game::PlaygroundFactory::SecondLevel()
{
    PlayGround* Area = new PlayGround();
    Area->Height = 11;
    Area->Width = 15;

    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 2), Directions::Right});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 8), Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 2), Directions::Left});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 8), Directions::Right});


    for (int a = 0; a < Area->Width; a++)
    {
        Area->Walls.push_back(Point(a, 0));
        Area->Walls.push_back(Point(a, Area->Height - 1));
    }
    for (int a = 1; a < Area->Height - 1; a++)
    {
        Area->Walls.push_back(Point(0, a));
        Area->Walls.push_back(Point(Area->Width - 1, a));
    }

    return Area;
}

vector<string> Game::PlaygroundFactory::GetAviableLevels()
{
    vector<string> Levels;
    Levels.push_back("ClearMap");
    Levels.push_back("BorderedMap");

    vector<string> FilesWithLevels = GetLevelsFileNames();
    for_each(FilesWithLevels.begin(),FilesWithLevels.end(),[&Levels](string NameOfFile){
        Levels.push_back(LoadNameOfLevel(NameOfFile));
    });

    return Levels;
}

vector<string> Game::PlaygroundFactory::GetLevelsFileNames()
{
    DIR* DataDirectory = opendir("./data/Levels");
    if (DataDirectory == NULL)
        throw new Exceptions::Exception("Directory for translation not found", __LINE__, __FILE__);

    vector<string> Files;
    struct dirent* DirEntry;
    while ((DirEntry = readdir(DataDirectory)) != NULL)
        if (DirEntry->d_type == 0x8)
            Files.push_back(DirEntry->d_name);

    closedir(DataDirectory);

    return Files;
}

string Game::PlaygroundFactory::LoadNameOfLevel(string Filename)
{
    ifstream File("data/Levels/"+Filename);
    string NameOfLevel;
    File >> NameOfLevel;
    File.close();
    return NameOfLevel;
}











