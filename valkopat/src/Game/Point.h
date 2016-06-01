#ifndef CERVISEMESTRALKA_POINT_H
#define CERVISEMESTRALKA_POINT_H

namespace Game
{
    /**
     * Class represent Point in 2D space
     */
    class Point
    {
        /**
         * X Coordinate
         */
        int PositionX = 0;
        /**
         * Y Coordinate
         */
        int PositionY = 0;
    public:
        /**
         * @return X Coordinate of point
         */
        int GetPositionX();
        /**
         * @return Y Coordinate of Point
         */
        int GetPositionY();
        /**
         * Set X Coordinate of point
         * @param X X coordinate to set
         */
        void SetPositionX(int X);
        /**
         * Set Y Coordinate of point
         * @param Y Y coordinate to set
         */
        void SetPositionY(int Y);
        /**
         * Create new isntance of Point with default coordinates [0,0]
         * @return New instance of Point
         */
        Point();
        /**
         * Create new instance of Point with coordinates [X,Y]
         * @param X X coordiante
         * @param Y Y Coordinate
         * @return New instance of Point
         */
        Point(int X, int Y);

        /**
         * Equal operator that check, if points are equal
         * @param Second Sec Point to cmopare
         * @return True if have same coordinates, false otherwise
         */
        bool operator ==(const Point& Second) const;
    };

}
#endif //CERVISEMESTRALKA_POINT_H
