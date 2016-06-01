#ifndef CERVISEMESTRALKA_WORM_H
#define CERVISEMESTRALKA_WORM_H
#include <string>
#include <vector>
#include "Enums.h"
#include "Point.h"

namespace Game
{
    /**
     * Class represent playable worm in game
     */
    class Worm
    {
    public:
        /**
         * Helper class that stores infor about parts of Game::Worm
         */
        class Segment
        {
            friend class Worm;

            /**
             * Position of this segment
             */
            Point Coords;

        public:
            /**
             * Create new instance of Segment with default position [0,0]
             * @return New instance of Segment
             */
            Segment() : Coords()
            {}

            /**
             * Create new instance of Segment with position [X,Y]
             * @param X X coordination of segment
             * @param Y Y coordination of segment
             * @return New instance of segment
             */
            Segment(int X, int Y) : Coords(X, Y)
            {}

            /**
             * @return X coordination of segment
             */
            int GetPositionX() const
            { return Coords.GetPositionX(); };

            /**
             * @return Y coordinate of segment
             */
            int GetPositionY() const
            { return Coords.GetPositionY(); };

            /**
             * Set X Coordinate of segment
             * @param X X Coordinate to set
             */
            void SetPositionX(int X)
            { Coords.SetPositionX(X); }

            /**
             * Set Y Coordinate of segment
             * @param Y Y Coordinate of segment
             */
            void SetPositionY(int Y)
            { Coords.SetPositionY(Y); }

            /**
             * Recast to Point
             * @return instance of Point with same position as segment had
             */
            explicit operator Point() const
            { return Coords; }

        };

    private:
        /**
         * Starting length of Worm
         */
        static const int SizeAtBegin = 3;

        /**
         * Name of worm
         */
        std::string name;

        /**
         * Vector of all Segments, that worm have\n
         * Head is first segment
         */
        std::vector<Segment> Segments;

        /**
         * Actual direction, where Worm heading
         */
        Actions MoveDirection;

        /**
         * True if is Worm still in game, false if is dead
         */
        bool Playing = true;

        /**
         * Id of Worm
         */
        int Id;
    public:

        /**
         * Create new instance of Worm
         * @param PositionX X coordinate of head
         * @param PositionY Y coordiante of head
         * @param Direction Direction of worm
         * @param Id Id of form, default is 0
         * @return New instance of Worm
         */
        Worm(int PositionX, int PositionY, Actions Direction, int Id = 0);

        /**
         * @return Name of worm
         */
        std::string GetName() const;
        /**
         * Set name of Worm
         * @param NewName Name to set
         */
        void SetName(std::string NewName);

        /**
         * @return Returns actual direction, where worm heading
         */
        Actions GetMoveDirection() const;
        /**
         * Change heading direction
         * @param Direction Direction where to newly head
         */
        void SetMoveDirection(Actions Direction);

        /**
         * @return True if is Worm still in game, false otherwise
         */
        bool IsPlaying() const;

        /**
         * Kill worm
         */
        void StopPlaying();

        /**
         * Decide, how many steps can do
         * @param Direction Where to head
         * @param Down How many steps could Worm move down
         * @param Right How many steps could Worm move right
         */
        void DecideDirection(Actions Direction, int& Down, int& Right) const;

        /**
         * @return Return all segments of worm, Head is irst
         */
        std::vector<Segment> GetSegment() const;

        /**
         * Move worm in directory of Direction
         * @param Direction Which directory move the worm
         */
        void Move(Actions Direction);

        /**
         * Determines if it is not part of the segment outside the specified coordinates\n
         * If yes, move that part to other side
         * @param MaxWidth Maximum width, where could segments be
         * @param MaxHeight Maximum height, where could segment be
         */
        void ValidatePosition(int MaxWidth, int MaxHeight);

        /**
         * Create new segment and append it to end of worm
         */
        void IncrementSize();

        /**
         * @return ID of Worm
         */
        int GetId() const;
    };
}


#endif //CERVISEMESTRALKA_WORM_H
