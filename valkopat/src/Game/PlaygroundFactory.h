#ifndef CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#define CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <dirent.h>
#include <algorithm>
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
        static vector<string> GetAviableLevels();
    private:
        static PlayGround* FirstLevel();
        static PlayGround* SecondLevel();

        static vector<string> GetLevelsFileNames();
        static string LoadNameOfLevel(string Filename);
        static PlayGround* CreateLevelFromFile(string LevelName);
        static PlayGround* ParseLevelFromFile(string FileName);
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
