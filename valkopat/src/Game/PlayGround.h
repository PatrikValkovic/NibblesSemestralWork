#ifndef CERVISEMESTRALKA_PLAYGROUND_H
#define CERVISEMESTRALKA_PLAYGROUND_H
#include <vector>
#include "../Exceptions/OutOfRangeException.h"
#include "Enums.h"
#include "Point.h"

namespace Game
{
    /**
     * Represent map in game
     */
    class PlayGround
    {
        friend class PlaygroundFactory;

        /**
         * Width of map
         */
        int Width;
        /**
         * Height of map
         */
        int Height;
    public:
        /**
         * Helper class that stored informations about starting position
         */
        class StartPosition
        {
        public:
            /**
             * Coords of starting position
             */
            Point Position;
            /**
             * Begin direction of this starting position
             */
            Actions Direction;
        };

    private:
        /**
         * Vector of all walls on map
         */
        std::vector<Point> Walls;
        /**
         * Vector of all starting positions on map
         */
        std::vector<StartPosition> StartingPositions;
        /**
         * Indexer indicates which starting position return next
         */
        int StartPositionIndex = 0;
    public:
        /**
         * Create new instance of PlayGround
         * @param LevelName Level of name
         * @return New instance of PlayGround
         */
        PlayGround(string LevelName);

        /**
         * Name of current map
         */
        const std::string NameOfLevel;

        /**
         * Get vector of all walls on map
         * @return Vector of position of walls on map
         */
        std::vector<Point> GetWalls() const;

        /**
         * Return unique start position for current map
         * @return Start position for next Game::Worm
         */
        StartPosition GetNextStartPosition();

        /**
         * How many worms could play on current map
         * @return
         */
        int CountOfStartPositions() const;

        /**
         * Return width of map
         * @return Width of map
         */
        int GetWidth() const;
        /**
         * Return height of map
         * @return Height of map
         */
        int GetHeight() const;
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUND_H
