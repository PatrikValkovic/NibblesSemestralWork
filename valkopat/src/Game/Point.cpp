#include "Point.h"

namespace Game
{
    int Point::GetPositionX() const
    {
        return this->PositionX;
    }

    int Point::GetPositionY() const
    {
        return this->PositionY;
    }

    void Point::SetPositionX(int X)
    {
        this->PositionX = X;
    }

    void Point::SetPositionY(int Y)
    {
        this->PositionY = Y;
    }

    Point::Point()
    { }

    Point::Point(int X, int Y)
    {
        SetPositionX(X);
        SetPositionY(Y);
    }

    bool Point::operator==(const Point& Second) const
    {
        return PositionY==Second.PositionY && PositionX==Second.PositionX;
    }


}
