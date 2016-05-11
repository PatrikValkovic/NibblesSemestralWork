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
        class Segment : public Point
        {
            friend class Worm;

            void SetPositionX(int X)
            { Point::SetPositionX(X); }

            void SetPositionY(int Y)
            { Point::SetPositionY(Y); }

        public:
            Segment() : Point()
            { }

            Segment(int X, int Y) : Point(X, Y)
            { }

            int GetPositionX()
            { return Point::GetPositionX(); };

            int GetPositionY()
            { return Point::GetPositionY(); };
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
    };
}


#endif //CERVISEMESTRALKA_WORM_H
