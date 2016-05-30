#ifndef CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#define CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <dirent.h>
#include <algorithm>
#include <limits>
#include <sstream>
#include <streambuf>
#include "../Exceptions/OutOfRangeException.h"
#include "../Exceptions/InvalidArgumentException.h"
#include "../Exceptions/InvalidFormatException.h"
#include "PlayGround.h"

using namespace std;

namespace Game
{
    class PlaygroundFactory
    {
    public:
        static PlayGround* GetLevel(string Level);
        static string GetLevelInString(string LevelName);
        static vector<string> GetAviableLevels();
        static PlayGround* CreateLevelFromFile(string LevelName);
        static PlayGround* ParseLevelFromStream(istream& LevelContent);
    private:
        static PlayGround* FirstLevel();
        static PlayGround* SecondLevel();

        static vector<string> GetLevelsFileNames();
        static string LoadNameOfLevel(string Filename);
        static string LoadFromStream(istream &StreamWithLevel);
        static string GetNameOfFileForLevel(string Level);
        static void AddElementIntoPlayground(PlayGround* Playground,char Readed,int YPosition,int XPosition);
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
