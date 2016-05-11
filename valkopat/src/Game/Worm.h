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
    public:
        Worm(int PositionX, int PositionY, Directions Direction);

        std::vector<Segment> GetSegment() const;

        void Move(Directions Direction);

        std::string GetName() const;

        void SetName(std::string NewName);

        void ValidatePosition(int MaxWidth,int MaxHeight);
    };
}


#endif //CERVISEMESTRALKA_WORM_H
