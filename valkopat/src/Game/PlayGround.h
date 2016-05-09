#ifndef CERVISEMESTRALKA_PLAYGROUND_H
#define CERVISEMESTRALKA_PLAYGROUND_H
#include <vector>
#include "../Exceptions/OutOfRangeException.h"
#include "Enums.h"
#include "Point.h"
#include "PlaygroundFactory.h"

namespace Game
{

    class PlayGround
    {
        friend class PlaygroundFactory;

        int Width;
        int Height;
    public:
        class StartPosition
        {
        public:
            Point Position;
            Directions Direction;
        };

    private:
        std::vector<Point> Walls;
        std::vector<StartPosition> StartingPositions;
        int StartPositionIndex = 0;
    public:

        std::vector<Point> GetWalls() const;

        StartPosition GetNextStartPosition();

        int GetWidth() const;
        int GetHeight() const;
    };
}


#endif //CERVISEMESTRALKA_PLAYGROUND_H
