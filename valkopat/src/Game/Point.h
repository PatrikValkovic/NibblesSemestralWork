#ifndef CERVISEMESTRALKA_POINT_H
#define CERVISEMESTRALKA_POINT_H

namespace Game
{
    class Point
    {
        int PositionX = 0;
        int PositionY = 0;
    public:
        int GetPositionX() { return PositionX; }
        int GetPositionY() {return PositionY; }
        void SetPositionX(int X) { PositionX = X;}
        void SetPositionY(int Y) { PositionY = Y;}
        Point() {}
        Point(int X, int Y)
        {
            SetPositionX(X);
            SetPositionY(Y);
        }
    };
}
#endif //CERVISEMESTRALKA_POINT_H
