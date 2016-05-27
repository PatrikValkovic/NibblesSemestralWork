#include "PlaygroundFactory.h"

Game::PlayGround* Game::PlaygroundFactory::GetLevel(string Level)
{
    PlayGround* Playlevel = CreateLevelFromFile(Level);

    if (Playlevel == NULL)
        throw new Exceptions::InvalidArgumentException("Level with this name doesnt exists", __LINE__, __FILE__);

    return Playlevel;
}

Game::PlayGround* Game::PlaygroundFactory::FirstLevel()
{
    PlayGround* Area = new PlayGround("ClearMap");
    Area->Height = 11;
    Area->Width = 15;
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 2), Actions::moveRight});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 8), Actions::MoveLeft});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 2), Actions::MoveLeft});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 8), Actions::moveRight});

    return Area;
}

Game::PlayGround* Game::PlaygroundFactory::SecondLevel()
{
    PlayGround* Area = new PlayGround("BorderedMap");
    Area->Height = 11;
    Area->Width = 15;

    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 2), Actions::moveRight});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 8), Actions::MoveLeft});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(10, 2), Actions::MoveLeft});
    Area->StartingPositions.push_back(Game::PlayGround::StartPosition{Point(4, 8), Actions::moveRight});


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
    stringstream LevelContent(GetLevelInString(LevelName));
    return ParseLevelFromFile(LevelContent);
}
#include <iostream>
Game::PlayGround* Game::PlaygroundFactory::ParseLevelFromFile(istream &LevelContent)
{
    using Game::PlayGround;
    using Exceptions::Exception;

    PlayGround* Created = NULL;
    set<char> ValidCharacters = {'-', 'W', 'U', 'D', 'L', 'R'};

    try
    {
        string LevelName;
        cin >> LevelName;
        Created = new PlayGround(LevelName);
        LevelContent.ignore(numeric_limits<streamsize>::max(), '\n');    //ignore to enter
        if (!(LevelContent >> Created->Height >> Created->Width))        //read height and width
            throw new Exception("Wrong size", __LINE__, __FILE__);
        LevelContent.ignore(numeric_limits<streamsize>::max(), '\n');    //ignore to enter
        //read level
        for (int a = 0; a < Created->Height; a++)
        {
            for (int b = 0; b < Created->Width; b++)
            {
                char Readed;
                if (!LevelContent.get(Readed))
                    throw new Exception("Nothing readed", __LINE__, __FILE__);
                if (ValidCharacters.find(Readed) == ValidCharacters.end())
                    throw new Exception("Wrong character", __LINE__, __FILE__);

                AddElementIntoPlayground(Created, Readed, a, b);
            }
            LevelContent.ignore(numeric_limits<streamsize>::max(), '\n');    //ignore to enter
        }
    }
    catch (Exceptions::Exception* e)
    {
        delete Created;
        Created = NULL;

        throw new Exceptions::InvalidFormatException("Wrong format of level", __LINE__, __FILE__, e);
    }
    return Created;
}

void Game::PlaygroundFactory::AddElementIntoPlayground(PlayGround* Playground, char Readed,
                                                       int YPosition, int XPosition)
{
    using Game::PlayGround;
    if (Readed == '-')
        return;
    if (Readed == 'W')
    {
        Playground->Walls.push_back(Point(XPosition, YPosition));
        return;
    }

    PlayGround::StartPosition Starting;
    Starting.Position = Point(XPosition, YPosition);

    if (Readed == 'L')
        Starting.Direction = Actions::MoveLeft;
    else if (Readed == 'R')
        Starting.Direction = Actions::moveRight;
    else if (Readed == 'U')
        Starting.Direction = Actions::MoveUp;
    else if (Readed == 'D')
        Starting.Direction = Actions::MoveDown;

    Playground->StartingPositions.push_back(Starting);
    return;
}

string Game::PlaygroundFactory::GetLevelInString(string Level)
{
    using namespace std;

    string NameOfFile = GetNameOfFileForLevel(Level);
    if (NameOfFile.empty())
        throw new Exceptions::InvalidArgumentException("Level with name " + Level + " dont exists");

    ifstream FileWithLevel("data/Levels/" + NameOfFile);
    string Lev = LoadFromStream(FileWithLevel);
    FileWithLevel.close();
    return Lev;
}

string Game::PlaygroundFactory::LoadFromStream(istream &StreamWithLevel)
{
    const int SizeOfBuffer = 16;
    char Buffer[SizeOfBuffer];
    using namespace std;
    stringbuf ContentOfGame;
    while(StreamWithLevel.good())
    {
        StreamWithLevel.read(Buffer,SizeOfBuffer);
        ContentOfGame.sputn(Buffer,SizeOfBuffer);
    }

    return ContentOfGame.str();
}

string Game::PlaygroundFactory::GetNameOfFileForLevel(string Level)
{
    using namespace std;
    string FileToReturn;
    vector<string> Files = GetLevelsFileNames();
    for_each(Files.begin(), Files.end(), [&Level, &FileToReturn](string FileName) {
        if (LoadNameOfLevel(FileName) == Level && FileToReturn.empty())
            FileToReturn = FileName;
    });
    return FileToReturn;
}























