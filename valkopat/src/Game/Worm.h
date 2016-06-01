#ifndef CERVISEMESTRALKA_WORM_H
#define CERVISEMESTRALKA_WORM_H
#include <string>
#include <vector>
#include "Enums.h"
#include "Point.h"

namespace Game
{
    class Worm
    {
    public:
        class Segment
        {
            friend class Worm;

            Point Coords;

        public:
            Segment() : Coords()
            { }

            Segment(int X, int Y) : Coords(X, Y)
            { }

            int GetPositionX() const
            { return Coords.GetPositionX(); };

            int GetPositionY() const
            { return Coords.GetPositionY(); };

            void SetPositionX(int X)
            { Coords.SetPositionX(X); }

            void SetPositionY(int Y)
            { Coords.SetPositionY(Y); }

            explicit operator Point() const
            { return Coords; }

        };

    private:
        static const int SizeAtBegin = 3;

        std::string name;
        std::vector<Segment> Segments;
        Actions MoveDirection;
        bool Playing = true;
        int Id;
    public:
        Worm(int PositionX, int PositionY, Actions Direction, int Id = 0);

        std::string GetName() const;
        void SetName(std::string NewName);
        Actions GetMoveDirection() const;
        void SetMoveDirection(Actions Direction);
        bool IsPlaying() const;
        void StopPlaying();
        void DecideDirection(Actions Direction, int& Down, int& Right) const;

        std::vector<Segment> GetSegment() const;
        void Move(Actions Direction);
        void ValidatePosition(int MaxWidth, int MaxHeight);
        void IncrementSize();

        int GetId() const;
    };
}


#endif //CERVISEMESTRALKA_WORM_H
