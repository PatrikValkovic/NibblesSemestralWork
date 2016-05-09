#ifndef CERVISEMESTRALKA_POINT_H
#define CERVISEMESTRALKA_POINT_H

namespace Game
{
    class Point
    {
        int PositionX = 0;
        int PositionY = 0;
    protected:
        virtual int GetPositionX() { return PositionX; }
        virtual int GetPositionY() {return PositionY; }
        virtual void SetPositionX(int X) { PositionX = X;}
        virtual void SetPositionY(int Y) { PositionY = Y;}
    public:
        Point() {}
        Point(int X, int Y)
        {
            SetPositionX(X);
            SetPositionY(Y);
        }
    };
}
#endif //CERVISEMESTRALKA_POINT_H
