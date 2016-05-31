#ifndef CERVISEMESTRALKA_POINT_H
#define CERVISEMESTRALKA_POINT_H

namespace Game
{
    class Point
    {
        int PositionX = 0;
        int PositionY = 0;
    public:
        int GetPositionX();
        int GetPositionY();
        void SetPositionX(int X);
        void SetPositionY(int Y);
        Point();
        Point(int X, int Y);
        bool operator ==(const Point& Second) const;
    };

}
#endif //CERVISEMESTRALKA_POINT_H
