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

            int GetPositionX()
            { return Coords.GetPositionX(); };

            int GetPositionY()
            { return Coords.GetPositionY(); };

            void SetPositionX(int X)
            { Coords.SetPositionX(X); }

            void SetPositionY(int Y)
            { Coords.SetPositionY(Y); }
        };

    private:
        static const int SizeAtBegin = 3;

        std::string name;
        std::vector<Segment> Segments;
        void DecideDirection(Directions Direction, int& Down, int& Right) const;
        Directions MoveDirection;
        bool Playing = true;
    public:
        Worm(int PositionX, int PositionY, Directions Direction);

        std::string GetName() const;
        void SetName(std::string NewName);
        Directions GetMoveDirection() const;
        void SetMoveDirection(Directions Direction);
        bool IsPlaying();
        void StopPlaying();

        std::vector<Segment> GetSegment() const;
        void Move(Directions Direction);
        void ValidatePosition(int MaxWidth,int MaxHeight);
        void IncrementSize();
    };
}


#endif //CERVISEMESTRALKA_WORM_H
