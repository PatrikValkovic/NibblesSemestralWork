#ifndef CERVISEMESTRALKA_BFSAI_H
#define CERVISEMESTRALKA_BFSAI_H
#include <climits>
#include <set>
#include <queue>
#include <vector>
#include "BaseAITask.h"
#include "../../Exceptions/InvalidArgumentException.h"

namespace Game
{
    namespace Task
    {
        class BFSAI : public BaseAITask
        {
        public:
            BFSAI(Worm* AIWorm,GameContent* Content);
            virtual void run();
            virtual BaseAITask* CreateInstance(Worm* WormToControl,GameContent* Game);
        private:
            Actions BFS(uint32_t** map, Point BeginOfSearch, Point EndPoint);
            vector<Point> GeneratePointsAround(Point AroundToGenerate);
            Actions ResolveDirection(Point From, Point To);
        };
    }
}


#endif //CERVISEMESTRALKA_BFSAI_H
