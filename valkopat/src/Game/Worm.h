#ifndef CERVISEMESTRALKA_WORM_H
#define CERVISEMESTRALKA_WORM_H
#include <string>
#include <vector>
#include "Enums.h"

namespace Game
{
    class Worm
    {
    public:
        class Segment
        {
            friend class Worm;
            int PositionX = 0;
            int PositionY = 0;
        public:
            Segment(){}
            Segment(int X, int Y) : PositionX(X), PositionY(Y) {}
            int GetPositionX() {return PositionX;};
            int GetPositionY() {return PositionY;};

        };
    private:
        static const int SizeAtBegin = 3;

        std::string name;
        std::vector<Segment> Segments;

        void DecideDirection(Directions Direction, int& Down, int& Right) const;
    public:
        Worm(int PositionX,int PositionY, Directions Direction);

        std::vector<Segment> GetSegment() const;

        void Move(Directions Direction);
    };
}


#endif //CERVISEMESTRALKA_WORM_H
