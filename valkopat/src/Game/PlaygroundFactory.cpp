#include "PlaygroundFactory.h"

Game::PlayGround* Game::PlaygroundFactory::GetLevel(string Level)
{
    PlayGround* Playlevel = NULL;
    if (Level == "ClearMap")
        Playlevel = FirstLevel();
    else if (Level == "BorderedMap")
        Playlevel = SecondLevel();
    else
        Playlevel = CreateLevelFromFile(Level);

    if (Playlevel == NULL)
        throw new Exceptions::InvalidArgumentException("Level with this name doesnt exists", __LINE__, __FILE__);

    return Playlevel;
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
    for_each(FilesWithLevels.begin(), FilesWithLevels.end(), [&Levels](string NameOfFile) {
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
    ifstream File("data/Levels/" + Filename);
    string NameOfLevel;
    File >> NameOfLevel;
    File.close();
    return NameOfLevel;
}

Game::PlayGround* Game::PlaygroundFactory::CreateLevelFromFile(string LevelName)
{
    using Game::PlayGround;

    PlayGround* CreatedPlayground = NULL;

    vector<string> Files = GetLevelsFileNames();
    for_each(Files.begin(), Files.end(), [&LevelName, &CreatedPlayground](string FileName) {
        if (LoadNameOfLevel(FileName) == LevelName && CreatedPlayground == NULL)
            CreatedPlayground = ParseLevelFromFile(FileName);
    });

    return CreatedPlayground;
}

Game::PlayGround* Game::PlaygroundFactory::ParseLevelFromFile(string FileName)
{
    using Game::PlayGround;
    using Exceptions::Exception;

    PlayGround* Created = new PlayGround();
    ifstream File("data/Levels/" + FileName);
    set<char> ValidCharacters = {'-', 'W', 'U', 'D', 'L', 'R'};

    try
    {
        File.ignore(numeric_limits<streamsize>::max(), '\n');    //ignore name of level
        if (!(File >> Created->Height >> Created->Width))        //read height and width
            throw new Exception("Wrong size", __LINE__, __FILE__);
        File.ignore(numeric_limits<streamsize>::max(), '\n');    //ignore to enter
        //read level
        for (int a = 0; a < Created->Height; a++)
        {
            for (int b = 0; b < Created->Width; b++)
            {
                char Readed;
                if (!File.get(Readed))
                    throw new Exception("Nothing readed", __LINE__, __FILE__);
                if (ValidCharacters.find(Readed) == ValidCharacters.end())
                    throw new Exception("Wrong character", __LINE__, __FILE__);

                AddElementIntoPlayground(Created, Readed, a, b);
            }
            File.ignore(numeric_limits<streamsize>::max(), '\n');    //ignore to enter
        }
    }
    catch (Exceptions::Exception* e)
    {
        delete Created;
        Created = NULL;
        File.close();

        throw new Exceptions::InvalidFormatException("File " + FileName + " have wrong format.", __LINE__, __FILE__, e);
    }
    File.close();
    return Created;
}

void Game::PlaygroundFactory::AddElementIntoPlayground(PlayGround* Playground, char Readed,
                                                       int YPosition, int XPosition)
{
    using Game::PlayGround;
    if(Readed=='-')
        return;
    if(Readed=='W')
    {
        Playground->Walls.push_back(Point(XPosition, YPosition));
        return;
    }

    PlayGround::StartPosition Starting;
    Starting.Position = Point(XPosition,YPosition);

    if(Readed=='L')
        Starting.Direction = Directions::Left;
    else if(Readed=='R')
        Starting.Direction = Directions::Right;
    else if(Readed=='U')
        Starting.Direction = Directions::Up;
    else if(Readed=='D')
        Starting.Direction = Directions::Down;

    Playground->StartingPositions.push_back(Starting);
    return;
}

















