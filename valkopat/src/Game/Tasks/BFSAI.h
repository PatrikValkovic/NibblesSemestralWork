#ifndef CERVISEMESTRALKA_BFSAI_H
#define CERVISEMESTRALKA_BFSAI_H
#include <climits>
#include <set>
#include <queue>
#include <vector>
#include "BaseTask.h"
#include "../../Exceptions/InvalidArgumentException.h"
#include "../GameContent.h"
#include "../Worm.h"

namespace Game
{
    namespace Task
    {
        class BFSAI : public BaseTask
        {
        public:
            BFSAI(Worm* AIWorm,GameContent* Content);
            virtual void run();
        private:
            Worm* ControlledWorm;
            GameContent* ContentOfGame;

            Directions BFS(uint32_t** map, Point BeginOfSearch, Point EndPoint);
            vector<Point> GeneratePointsAround(Point AroundToGenerate);
            Directions ResolveDirection(Point From, Point To);
        };
    }
}


#endif //CERVISEMESTRALKA_BFSAI_H
