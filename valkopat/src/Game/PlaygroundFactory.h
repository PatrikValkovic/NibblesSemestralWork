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
    /**
     * Creates instances of Game::PlayGround
     */
    class PlaygroundFactory
    {
    public:
        /**
         * Create new Game::PlayGround with name NameOfLevel
         * @param NameOfLevel Name of level to find
         * @return New instance o Game::PlayGround
         */
        static PlayGround* GetLevel(string NameOfLevel);

        /**
         * Load level with name NameOfLevel and return its content as string
         * @param NameOfLevel Name of level to find
         * @return String containing data of level
         */
        static string GetLevelInString(string NameOfLevel);

        /**
         * Get all aviable levels on this PC
         * @return Vector wtih names of all levels
         */
        static vector<string> GetAviableLevels();

        /**
         * Load level from stream, that contain data of level
         * @param LevelContent Stream with data of level
         * @return New instance of Game::PlayGround
         */
        static PlayGround* ParseLevelFromStream(istream& LevelContent);
    private:

        /**
         * Load level from harddisk
         * @param NameOfLevel Name of level
         * @return New instance of Game::PlayGround
         */
        static PlayGround* CreateLevelFromFile(string NameOfLevel);

        /**
         * @deprecated
         */
        static PlayGround* FirstLevel();
        /**
         * @deprecated
         */
        static PlayGround* SecondLevel();

        /**
         * Return names of all files in data/Levels directory
         * @return Vector of files names
         */
        static vector<string> GetLevelsFileNames();

        /**
         * Parse name of level from file
         * @param Filename name of File to load
         * @return Name of level
         */
        static string LoadNameOfLevel(string Filename);

        /**
         * Load content of stream into string
         * @param StreamWithLevel Stream with content to load
         * @return String with data that was in stream
         */
        static string LoadFromStream(istream &StreamWithLevel);

        /**
         * Find name of file, that contain specific Level
         * @param Level Name of level
         * @return Name of file which data to level, "" if no file found
         */
        static string GetNameOfFileForLevel(string Level);

        /**
         * Create and add game element into Playground
         * @param Playground Playground to which add element
         * @param Readed Readed character
         * @param YPosition Y coordinate of new object
         * @param XPosition X Coordinate of new object
         */
        static void AddElementIntoPlayground(PlayGround* Playground,char Readed,int YPosition,int XPosition);
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUNDFACTORY_H
